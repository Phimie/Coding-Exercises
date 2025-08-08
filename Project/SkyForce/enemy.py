import pygame
import random
import rpath

class Enemy():
    def __init__(self, sf_game):
        super().__init__()
        self.screen = sf_game.screen
        self.settings = sf_game.settings
        #image
        self.frames = []
        for i in range(8):
            self.frames.append(pygame.image.load(rpath.rpath(f'assets/images/enemy/Sprite-000{i}.png')).convert_alpha())
        self.image = self.frames[0]
        #xy
        self.rect = self.image.get_rect()
        self.rect.x = random.randint(100,self.settings.screen_width - self.rect.width)
        self.rect.y = random.randint(-300, -self.rect.height)
        #move
        self.direction = random.choice([1,-1])
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
        for i in range(8):
            self.death_frames.append(pygame.image.load(rpath.rpath(f'assets/images/enemy/death/Sprite-000{i}.png')).convert_alpha())
        self.death = False
        self.death_tick = 0
        self.death_xy = [0,0]

    def update(self):
        now = pygame.time.get_ticks()
        if self.hitted and now < self.hitted_tick:
            self.image = pygame.image.load(rpath.rpath('assets/images/enemy/hitted.png')).convert_alpha()
        else:
            hitted = False
            self.image = self.frames[(pygame.time.get_ticks() // 50) % 8]
        



        now = pygame.time.get_ticks()
        if now - self.move_tick >= 5:
            self.rect.x += (self.enemy_speed * self.direction)
            self.rect.y += self.enemy_drop_speed
            self.move_tick = now

    def check_edges(self):
        screen_rect = self.screen.get_rect()
        if self.rect.right >= screen_rect.right:
            self.rect.right = screen_rect.right - 2
            return True
        elif self.rect.left <= 0:
            self.rect.left = 2
            return True
        return False
        



