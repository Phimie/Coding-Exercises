import pygame
import random
import rpath

class Enemy():
    def __init__(self, sf_game):
        super().__init__()
        self.screen = sf_game.screen
        self.settings = sf_game.settings
        self.screen_rect = sf_game.screen.get_rect()
        #image
        self.frames = []
        for i in range(8):
            self.frames.append(pygame.image.load(rpath.rpath(f'assets/images/enemy/Sprite-000{i}.png')).convert_alpha())
        self.image = self.frames[0]
        #xy
        self.rect = self.image.get_rect()

        self.spawn_xy = random.choice([[self.screen_rect.centerx + 220,self.screen_rect.centery - 290],[self.screen_rect.centerx - 300, self.screen_rect.centery - 290]])
        self.rect.x = self.spawn_xy[0]
        self.rect.y = self.spawn_xy[1]
        #move
        self.direction_x = random.choice([1,-1])
        self.direction_y = random.choice([1,-1])
        self.move_tick = 0
        self.enemy_speed = random.choice([1,2,3])
        self.enemy_drop_speed = 1
        #hp
        self.enemy_hp = 100
        #is_hit
        self.hitted = False
        self.hitted_tick = 0
        #is_death
        self.death_frames = []
        for i in range(1,11):
            self.death_frames.append(pygame.image.load(rpath.rpath(f'assets/images/enemy/death/{i}.png')).convert_alpha())
        self.death = False
        self.death_tick = 0
        self.death_xy = [0,0]

    def update(self):
        now_hit = pygame.time.get_ticks()
        if self.hitted and now_hit < self.hitted_tick:
            self.image = pygame.image.load(rpath.rpath('assets/images/enemy/hitted.png')).convert_alpha()
        else:
            self.hitted = False
            self.image = self.frames[(pygame.time.get_ticks() // 50) % 8]
        

        now_move = pygame.time.get_ticks()
        if now_move - self.move_tick >= 5:
            self.rect.x += (self.enemy_speed * self.direction_x)
            self.rect.y += (self.enemy_drop_speed *self.direction_y)
            self.move_tick = now_move
            
            edge = self.check_edges()
            if edge == 'x':
                self.direction_x *= -1
            elif edge == 'y':
                self.direction_y *= -1

    def check_edges(self):
        if self.rect.right >= self.screen_rect.centerx + 300:
            self.rect.right = self.screen_rect.centerx + 298
            return 'x'
        elif self.rect.left <= self.screen_rect.centerx - 300:
            self.rect.left = self.screen_rect.centerx - 298
            return 'x'
        elif self.rect.bottom >= self.screen_rect.centery + 320:
            self.rect.bottom = self.screen_rect.centery + 318
            return 'y'
        elif self.rect.bottom <= self.screen_rect.centery - 242:
            self.rect.bottom = self.screen_rect.centery - 240
            return 'y'
        return False
        



