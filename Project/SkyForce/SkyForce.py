import sys
import pygame
import random
import os
import rpath
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
        pygame.display.set_icon(pygame.image.load("assets/images/icon/SF.ico").convert_alpha())
        self.bg_img = pygame.image.load(rpath.rpath("assets/images/background/background.png")).convert()

        self.enemys = []
        self.dead_enemies = []
        self.ship = Ship(self)
        self.bullets = pygame.sprite.Group()
        self._create_enemy()
        self.play_button = Button(self)

        self.game_active = False
        self.score = 0
        self.max_score = 0
        self.all_max_score = 0
        self.spawn_tick = 0
        self.bullet_count = 20

        #处理数字(得分)
        self.digits = []
        for i in range(10):
            self.digits.append(pygame.image.load(rpath.rpath(f'assets/images/digits/{i}.png')).convert_alpha())
        #处理数字(子弹数)
        self.bullet_digits = []
        for i in range(10):
            self.bullet_digits.append(pygame.image.load(rpath.rpath(f'assets/images/bullets/bullet_digits/{i}.png')).convert_alpha())


    #check
    def _check_enemys_edges(self):
        for enemy in self.enemys:
            if enemy.check_edges():
                enemy.direction *= -1
                continue
    
    def _check_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                if self.max_score > self.all_max_score:
                    self.all_max_score = self.max_score
                print (f"最后一局最大分数为:{self.max_score}\n")
                print (f"历史最高最大分数为:{self.all_max_score}")
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

    #bullet
    def _fire_bullet(self):
        if self.bullet_count > 0:
            new_bullet = Bullet(self)
            self.bullets.add(new_bullet)
            self.bullet_count -= 1


    def _update_bullets(self):
        for bullet in self.bullets.copy():
            if bullet.rect.bottom <=-100:
                self.bullets.remove(bullet)
        
        #击中
        for bullet in self.bullets.copy():
            for enemy in self.enemys[:]:
                if (bullet.rect.x + bullet.rect.width  >= enemy.rect.x and bullet.rect.x <= enemy.rect.x + enemy.rect.width and bullet.rect.y + bullet.rect.height >= enemy.rect.y and bullet.rect.y <= enemy.rect.y + enemy.rect.height):
                    enemy.enemy_hp -= bullet.damage
                    if enemy.enemy_hp <= 0:
                        self.bullets.remove(bullet)
                        enemy.death = True
                        enemy.death_tick = pygame.time.get_ticks() + 400
                        enemy.death_xy = [enemy.rect.x,enemy.rect.y]
                        self.dead_enemies.append(enemy)
                        self.enemys.remove(enemy)
                        self.score += 2
                        self.bullet_count += 3
                        self.max_score = self.score
                    else:
                        enemy.hitted = True
                        enemy.hitted_tick = pygame.time.get_ticks() + 150
                        self.bullets.remove(bullet)
                        enemy.rect.y -= 50
                        break



    #enemy
    def _create_enemy(self):
        new_enemy  = Enemy(self)
        new_enemy.rect.x = random.randint(100, self.settings.screen_width - 100)
        new_enemy.rect.y = random.randint(-300,0)
        self.enemys.append(new_enemy)


    def _update_enemy(self):
        self._check_enemys_edges()
        for enemy in self.enemys:
            enemy.update()

        for enemy in self.enemys:
            #撞击
            if (self.ship.rect.x + 10 + self.ship.rect.width - 15 >= enemy.rect.x + 10 and
                self.ship.rect.x + 10 <= enemy.rect.x + enemy.rect.width - 5 and
                self.ship.rect.y + 10 + self.ship.rect.height - 15 >= enemy.rect.y + 10 and
                self.ship.rect.y + 10 <= enemy.rect.y + enemy.rect.height - 10):

                self.enemys.clear()
                sleep(1)
                self.game_active = False
                self._create_enemy()
                self.ship.center_ship()
                self.score = 0
                self.bullet_count = 20
                if self.max_score > self.all_max_score:
                    self.all_max_score = self.max_score
            #触底
            if (enemy.rect.bottom >= self.settings.screen_height + 100):
                self.enemys.remove(enemy)
                self._create_enemy()
                
                #扣分
                if self.score > 0:
                    if self.score >= 4:
                        self.score -= 4
                    else:
                        self.score = 0




    #game
    def _update_screen(self):
        self.screen.blit(self.bg_img,(0, 0))
        self.ship.blitme()

        # 绘制死亡动画
        now = pygame.time.get_ticks()
        for dead in self.dead_enemies[:]:
            frame_index = (now - (dead.death_tick - 400)) // 50
            if frame_index < 7:
                self.screen.blit(dead.death_frames[frame_index], dead.death_xy)
            else:
                self.screen.blit(dead.death_frames[7], dead.death_xy)
                self.dead_enemies.remove(dead)

        for bullet in self.bullets.sprites():
            bullet.draw_bullet()

        for enemy in self.enemys:
            self.screen.blit(enemy.image,enemy.rect)

        #绘制子弹
        self.screen.blit(pygame.image.load(rpath.rpath(f'assets/images/bullets/bullet_count.png')).convert_alpha(),(10,self.settings.screen_height - 70))
        m = len(str(self.bullet_count))
        x_num = 110 + (m - 1) * 32
        for i in str(self.bullet_count)[::-1]:
            img_bullet = self.bullet_digits[int(i)]
            x_num -= img_bullet.get_width()
            self.screen.blit(img_bullet, (x_num, self.settings.screen_height - 56))



        #绘制得分
        x_score = self.settings.screen_width - 10
        for i in str(self.score)[::-1]:
            img = self.digits[int(i)]
            x_score -= img.get_width()
            self.screen.blit(img, (x_score, 10))

        if not self.game_active:
            self.play_button.draw_button()

        pygame.display.flip()
        


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


#入口
if __name__ == '__main__':
    sf = SkyForce()
    sf.run_game()