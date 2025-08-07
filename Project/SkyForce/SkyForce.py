import sys
import pygame
import random
from time import sleep
from settings import Settings
from ship import Ship
from bullet import Bullet
from enemy import Enemy
from button import Button


class SkyForce:
    def __init__(self):
        pygame.init()
        
        self.settings = Settings()

        self.screen = pygame.display.set_mode((self.settings.screen_width,self.settings.screen_height))
        pygame.display.set_caption("SkyForce")

        self.enemys = []
        self.ship = Ship(self)
        self.bullets = pygame.sprite.Group()
        self._create_enemy()
        self.play_button = Button(self)

        self.game_active = False
        self.score = 0
        self.spawn_tick = 0

        #处理数字
        self.digits = []
        for i in range(10):
            self.digits.append(pygame.image.load(f'assets/images/digits/{i}.png').convert_alpha())
        self.digit_w = self.digits[0].get_width()
        self.digit_h = self.digits[0].get_height()

    def _create_enemy(self):
        new_enemy  = Enemy(self)
        new_enemy.rect.x = random.randint(100, self.settings.screen_width - 100)
        new_enemy.rect.y = random.randint(-300,0)
        self.enemys.append(new_enemy)

    def _check_enemys_edges(self):
        for enemy in self.enemys:
            if enemy.check_edges():
                enemy.direction *= -1
                continue
    
    def _check_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                self._check_keydown_events(event) 
            elif event.type == pygame.KEYUP:
                self._check_keyup_events(event)
            elif event.type == pygame.MOUSEBUTTONDOWN:
                mouse_pos = pygame.mouse.get_pos()
                mouse_x, mouse_y = mouse_pos
                self._check_play_button(mouse_x, mouse_y)
            if event.type == pygame.MOUSEBUTTONDOWN and self.game_active == True:
                self._fire_bullet()
    
    def _check_play_button(self, mouse_x, mouse_y):
        if self.play_button.rect.x < mouse_x and self.play_button.rect.x + self.play_button.width >= mouse_x and self.play_button.rect.y < mouse_y and self.play_button.rect.y + self.play_button.height >= mouse_y and not self.game_active:
            self.game_active = True

    def _check_keydown_events(self, event):
        if event.key == pygame.K_d:
            self.ship.moving_right = True
        if event.key == pygame.K_a:
            self.ship.moving_left = True
        if event.key == pygame.K_w:
            self.ship.moving_up = True
        if event.key == pygame.K_s:
            self.ship.moving_down = True


    
    def _check_keyup_events(self, event):
        if event.key == pygame.K_d:
            self.ship.moving_right = False
        if event.key == pygame.K_a:
            self.ship.moving_left = False
        if event.key == pygame.K_w:
            self.ship.moving_up = False
        if event.key == pygame.K_s:
            self.ship.moving_down = False

    def _fire_bullet(self):
        new_bullet = Bullet(self)
        self.bullets.add(new_bullet)


    def _update_enemy(self):
        self._check_enemys_edges()
        for enemy in self.enemys:
            enemy.update()

        for enemy in self.enemys:
            if (self.ship.rect.x + self.ship.rect.width >= enemy.rect.x and self.ship.rect.x <= enemy.rect.x + enemy.rect.width and self.ship.rect.y + self.ship.rect.height >= enemy.rect.y and self.ship.rect.y <= enemy.rect.y + enemy.rect.height):
                self.enemys.clear()
                sleep(1)
                self.game_active = False
                self._create_enemy()
                self.ship.center_ship()
                self.score = 0
            if (enemy.rect.bottom >= self.settings.screen_height + 100):
                self.enemys.remove(enemy)
                self._create_enemy()
                self._create_enemy()
                self._create_enemy()





    def _update_screen(self):
        self.screen.fill(self.settings.bg_color)
        self.ship.blitme()

        for bullet in self.bullets.sprites():
            bullet.draw_bullet()

        for enemy in self.enemys:
            self.screen.blit(enemy.image,enemy.rect)

        x = self.settings.screen_width - 10
        for i in str(self.score)[::-1]:
            img = self.digits[int(i)]
            x -= img.get_width()
            self.screen.blit(img, (x, 10))        

        if not self.game_active:
            self.play_button.draw_button()

        pygame.display.flip()
        
    def _update_bullets(self):
        for bullet in self.bullets.copy():
            if bullet.rect.bottom <=-100:
                self.bullets.remove(bullet)
        for bullet in self.bullets.copy():
            for enemy in self.enemys:
                if (bullet.rect.x + bullet.rect.width  >= enemy.rect.x and bullet.rect.x <= enemy.rect.x + enemy.rect.width and bullet.rect.y + bullet.rect.height >= enemy.rect.y and bullet.rect.y <= enemy.rect.y + enemy.rect.height):
                    self.bullets.remove(bullet)
                    self.enemys.remove(enemy)
                    self.score += 2
                    break

    def run_game(self):
        while True:
            self._check_events()
            if self.game_active:
                self.ship.update()
                self.bullets.update()
                self._update_bullets()
                self._update_enemy()
                now = pygame.time.get_ticks()
                if now - self.spawn_tick >= 1200:
                    self._create_enemy()
                    self.spawn_tick = now
            self._update_screen()


if __name__ == '__main__':
    sf = SkyForce()
    sf.run_game()