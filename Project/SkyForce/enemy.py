import pygame
from pygame.sprite import Sprite

class Enemy(Sprite):
    def __init__(self, sf_game):
        super().__init__()
        self.screen = sf_game.screen
        self.settings = sf_game.settings
        self.image = pygame.image.load ('images/enemy/enemy.png')
        self.rect = self.image.get_rect()

        self.rect.x = self.rect.width
        self.rect.y = self.rect.height


    def update(self):
        self.rect.x += (self.settings.enemy_speed * self.settings.fleet_direction)

    def check_edges(self):
        screen_rect = self.screen.get_rect()
        if self.rect.right >= screen_rect.right or self.rect.left <= 0 :
            return True
        



