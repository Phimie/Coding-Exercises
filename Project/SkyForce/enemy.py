import pygame
import random
import rpath
class Enemy():
    def __init__(self, sf_game):
        super().__init__()
        self.screen = sf_game.screen
        self.settings = sf_game.settings
        self.image = pygame.image.load (rpath.rpath('assets/images/enemy/enemy.png')).convert_alpha()
        self.rect = self.image.get_rect()

        self.rect.x = random.randint(100,self.settings.screen_width - self.rect.width)
        self.rect.y = random.randint(-300, -self.rect.height)
        self.direction = random.choice([1,-1])
        self.move_tick = 0
        self.enemy_speed = random.choice([1,2,3,4])
        self.enemy_drop_speed = random.choice([1,2])

    def update(self):
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
        



