import pygame

class Ship:
    def __init__(self,sf_game):
        self.screen = sf_game.screen
        self.settings = sf_game.settings
        self.screen_rect = sf_game.screen.get_rect()  #把窗口（screen）的矩形区域缓存下来

        """.convert_alpha() 只是性能优化，不加也能正常显示透明 PNG，但每帧都会额外做一次格式转换，
            图一多就掉帧；加了之后像素格式对齐，blit 变成纯内存拷贝，速度更快。"""
        self.frames = []
        for i in range(8):
            self.frames.append(pygame.image.load(f'images/Sprite-000{i}.png').convert_alpha())

        self.image = self.frames[0]

        self.rect = self.image.get_rect()
        self.rect.midbottom = self.screen_rect.midbottom

        self.x = float(self.rect.x)
        self.y = float(self.rect.y)
        self.moving_right = False
        self.moving_left = False
        self.moving_up = False
        self.moving_down = False

    def update(self):

        self.image = self.frames[(pygame.time.get_ticks() // 80) % 8]

        if self.moving_right and self.rect.right < self.screen_rect.right:
            self.x += self.settings.ship_speed
        if self.moving_left and self.rect.left > 0:
            self.x -= self.settings.ship_speed
        if self.moving_up and self.rect.top > 0:
            self.y -= self.settings.ship_speed
        if self.moving_down and self.rect.bottom < self.screen_rect.bottom:
            self.y += self.settings.ship_speed

        self.rect.x = self.x
        self.rect.y = self.y

    def blitme(self):
        self.screen.blit(self.image,self.rect)

