import pygame
import rpath
class Ship:
    def __init__(self,sf_game):
        self.screen = sf_game.screen
        self.settings = sf_game.settings
        self.screen_rect = sf_game.screen.get_rect()  #把窗口（screen）的矩形区域缓存下来

        """.convert_alpha() 只是性能优化，不加也能正常显示透明 PNG，但每帧都会额外做一次格式转换，
            图一多就掉帧；加了之后像素格式对齐，blit 变成纯内存拷贝，速度更快。"""
        self.frames = []
        for i in range(8):
            self.frames.append(pygame.image.load(rpath.rpath(f'assets/images/ship/Sprite-000{i}.png')).convert_alpha())
        self.image = self.frames[0]




        self.rect = self.image.get_rect()
        self.rect.midbottom = self.screen_rect.center

        self.x = float(self.rect.x)
        self.y = float(self.rect.y)
        self.move_tick = 0
        self.hp = self.settings.ship_hp
        self.MaxHp = self.settings.ship_MaxHp
        #is_hit
        self.hitted = False
        self.hitted_tick = 0
        #is_death
        self.death_frames = []
        for i in range(1,11):
            self.death_frames.append(pygame.image.load(rpath.rpath(f'assets/images/ship/death/{i}.png')).convert_alpha())
        self.death = False
        self.death_tick = 0
        self.death_xy = [0,0]

    def center_ship(self):
        self.rect.midbottom = self.screen_rect.center
        self.x = float(self.rect.x)
        self.y = float(self.rect.y)

    def update(self):
        now_hit = pygame.time.get_ticks()
        if self.hitted and now_hit < self.hitted_tick:
            self.image = pygame.image.load(rpath.rpath('assets/images/ship/is_hit.png')).convert_alpha()
        else:
            self.hitted = False
            self.image = self.frames[(pygame.time.get_ticks() // 40) % 8]


        now_move = pygame.time.get_ticks()
        if now_move - self.move_tick >= 2:
            keys = pygame.key.get_pressed()
            if keys[pygame.K_d] and self.rect.right < self.screen_rect.centerx + 290:
                self.x += self.settings.ship_speed
            if keys[pygame.K_a] and self.rect.left > self.screen_rect.centerx - 310:
                self.x -= self.settings.ship_speed
            if keys[pygame.K_w] and self.rect.top > self.screen_rect.centery - 300:
                self.y -= self.settings.ship_speed
            if keys[pygame.K_s] and self.rect.bottom < self.screen_rect.centery + 330:
                self.y += self.settings.ship_speed
            self.move_tick = now_move

        self.rect.x = self.x
        self.rect.y = self.y

    def blitme(self):
        self.screen.blit(self.image,self.rect)

