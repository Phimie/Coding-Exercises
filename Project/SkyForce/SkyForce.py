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
        self.screen_rect = self.screen.get_rect()
        pygame.event.pump()
        pygame.display.set_allow_screensaver(False)
        pygame.display.set_caption("SkyForce")
        pygame.display.set_icon(pygame.image.load(rpath.rpath("assets/images/icon/SF.ico")).convert_alpha())
        self.bg_img = pygame.image.load(rpath.rpath("assets/images/background/background.png")).convert_alpha()
        self.hp_img = pygame.image.load(rpath.rpath("assets/images/ship/hp.png")).convert_alpha()
        self.hpBar_img = pygame.image.load(rpath.rpath("assets/images/ship/hp_bar.png")).convert_alpha()
        self.gameRunTimes = 0

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
        self.bullet_count = self.settings.bullet_count
        self.death_tick = 0
        self.dying = False

        #处理数字(得分)
        self.digits = []
        for i in range(10):
            self.digits.append(pygame.image.load(rpath.rpath(f'assets/images/digits/{i}.png')).convert_alpha())
        #处理数字(子弹数)
        self.bullet_digits = []
        for i in range(10):
            self.bullet_digits.append(pygame.image.load(rpath.rpath(f'assets/images/bullets/bullet_digits/{i}.png')).convert_alpha())
        
        #audio
        pygame.mixer.init()
        pygame.mixer.set_num_channels(64)
        pygame.mixer.music.load(rpath.rpath("assets/audio/background.mp3"))
        pygame.mixer.music.play(loops=-1, fade_ms=1000)
        pygame.mixer.music.set_volume(0.2)
        self.snd_hit   = pygame.mixer.Sound(rpath.rpath("assets/audio/hit.wav"))
        self.snd_hit.set_volume(0.1)
        self.snd_shoot = pygame.mixer.Sound(rpath.rpath("assets/audio/shoot.wav"))
        self.snd_shoot.set_volume(0.1)
        self.snd_explode = pygame.mixer.Sound(rpath.rpath("assets/audio/explode.wav"))
        self.snd_explode.set_volume(0.1)
        self.channel_explode = pygame.mixer.Channel(0)
        self.snd_score = pygame.mixer.Sound(rpath.rpath("assets/audio/score.wav"))
        self.snd_score.set_volume(0.2)
        self.snd_click = pygame.mixer.Sound(rpath.rpath("assets/audio/click.wav"))
        self.snd_click.set_volume(0.6)
        self.snd_gameover = pygame.mixer.Sound(rpath.rpath("assets/audio/gameover.wav"))
        self.snd_gameover.set_volume(0.5)
        




    #check    
    def _check_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                if self.max_score > self.all_max_score:
                    self.all_max_score = self.max_score
                print (f"最后一局最大分数为:{self.max_score}")
                print (f"历史最高最大分数为:{self.all_max_score}")
                print (f"游戏局数为:{self.gameRunTimes}")
                sys.exit()
            elif event.type == pygame.MOUSEBUTTONDOWN and not self.game_active:
                mouse_pos = pygame.mouse.get_pos()
                mouse_x, mouse_y = mouse_pos
                self._check_play_button(mouse_x, mouse_y)
            if event.type == pygame.MOUSEBUTTONDOWN and self.game_active == True:
                self._fire_bullet()

    def _check_play_button(self, mouse_x, mouse_y):
        if (self.play_button.rect.x < mouse_x and 
            self.play_button.rect.x + self.play_button.width >= mouse_x and 
            self.play_button.rect.y < mouse_y and 
            self.play_button.rect.y + self.play_button.height >= mouse_y and 
            not self.game_active and
            not self.dying
            ):
            self.game_active = True
            self.snd_click.play()
            

    #bullet
    def _fire_bullet(self):
        if self.bullet_count > 0:
            mouse_pos = pygame.mouse.get_pos()
            new_bullet = Bullet(self,mouse_pos)
            self.bullets.add(new_bullet)
            self.bullet_count -= 1
            self.snd_shoot.play(maxtime=0)

        
    def _update_bullets(self):
        self.bullets.update()
        
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
                        self.channel_explode.play(self.snd_explode)
                    else:
                        enemy.hitted = True
                        enemy.hitted_tick = pygame.time.get_ticks() + 150
                        self.bullets.remove(bullet)
                        enemy.rect.y -= 50
                        self.snd_hit.play(maxtime=0)
                        break



    #enemy
    def _create_enemy(self):
        new_enemy  = Enemy(self)
        new_enemy.rect.x = new_enemy.spawn_xy[0]
        new_enemy.rect.y = new_enemy.spawn_xy[1]
        self.enemys.append(new_enemy)


    def _update_enemy(self):
        for enemy in self.enemys:
            enemy.update()

        for enemy in self.enemys:
            #撞击
            if (self.ship.rect.x + 10 + self.ship.rect.width - 15 >= enemy.rect.x + 10 and
                self.ship.rect.x + 10 <= enemy.rect.x + enemy.rect.width - 5 and
                self.ship.rect.y + 10 + self.ship.rect.height - 15 >= enemy.rect.y + 10 and
                self.ship.rect.y + 10 <= enemy.rect.y + enemy.rect.height - 10):
 
                #扣血
                if self.ship.hp - 51 > 0 :
                    self.ship.hp -= 51
                    if (self.ship.hp < 0):
                        self.ship.hp = 0
                    self.ship.hitted = True
                    self.ship.hitted_tick = pygame.time.get_ticks() + 250
                    enemy.death = True
                    enemy.death_tick = pygame.time.get_ticks() + 400
                    enemy.death_xy = [enemy.rect.x,enemy.rect.y]
                    self.dead_enemies.append(enemy)
                    self.enemys.remove(enemy)
                    #扣分
                    if self.score > 0:
                        if self.score >= 17:
                            self.score -= 17
                        else:
                            self.score = 0
                    self.bullet_count += 3
                    self.max_score = self.score
                    self.channel_explode.play(self.snd_explode)
                    print (f"现在还剩:{self.ship.hp}点血量")
                #死亡
                else:
                    self.ship.hp = 0
                    self.ship.death = True
                    self.gameRunTimes += 1
                    self.ship.death_tick = pygame.time.get_ticks() + 400
                    self.ship.death_xy = [self.ship.rect.x,self.ship.rect.y]
                    self.game_active = False
                    self.death_tick = pygame.time.get_ticks()
                    self.enemys.clear()
                    self.bullets.empty()
                    self.snd_gameover.play()





    #game
    def _update_screen(self):
        self.screen.blit(self.bg_img,(0, -260))

        #绘制ship
        if not self.ship.death and self.game_active:
            self.ship.blitme()

        # 绘制enemy死亡动画
        now_enemyDeath = pygame.time.get_ticks()
        for dead in self.dead_enemies[:]:
            frame_index = (now_enemyDeath - (dead.death_tick - 400)) // 50
            if frame_index < 9:
                self.screen.blit(dead.death_frames[frame_index], dead.death_xy)
            else:
                self.screen.blit(dead.death_frames[7], dead.death_xy)
                self.dead_enemies.remove(dead)

        # 绘制ship死亡动画
        if self.ship.death:
            now_shipDeath = pygame.time.get_ticks()
            frame_index = (now_shipDeath - (self.ship.death_tick - 400)) // 50
            if frame_index < 9:
                self.screen.blit(self.ship.death_frames[frame_index], self.ship.death_xy)
            else:
                self.screen.blit(self.ship.death_frames[9], self.ship.death_xy)

        #绘制子弹
        for bullet in self.bullets.sprites():
            self.screen.blit(bullet.image,bullet.rect)
        
        if self.game_active:
            #绘制敌人
            for enemy in self.enemys:
                self.screen.blit(enemy.image,enemy.rect)

                
            #绘制子弹数量UI
            self.screen.blit(pygame.image.load(rpath.rpath(f'assets/images/bullets/bullet_count.png')).convert_alpha(),(10,self.settings.screen_height - 70))
            m = len(str(self.bullet_count))
            x_num = 110 + (m - 1) * 32
            for i in str(self.bullet_count)[::-1]:
                img_bullet = self.bullet_digits[int(i)]
                x_num -= img_bullet.get_width()
                self.screen.blit(img_bullet, (x_num, self.settings.screen_height - 56))


            #绘制血条
            self.bar_width = (185/self.ship.MaxHp)*self.ship.hp
            self.screen.blit(self.hp_img,(10,30))
            self.screen.blit(self.hpBar_img,(78,35))
            pygame.draw.rect(self.screen, (236, 30 ,4),pygame.Rect(82,38,self.bar_width,21))

            #绘制得分
            x_score = self.settings.screen_width - 10
            for i in str(self.score)[::-1]:
                img = self.digits[int(i)]
                x_score -= img.get_width()
                self.screen.blit(img, (x_score, 10))

        #绘制button
        if not self.game_active and not self.dying:
            self.play_button.draw_button()


        pygame.display.flip()
    #游戏结束逻辑
    def _game_over(self,now_time):
        self.dying = True
        if now_time - self.death_tick >= 700:
            self.ship.center_ship()
            self.score = 0
            self.bullet_count = 20
            self.ship.hp = self.ship.MaxHp
            self.ship.death = False
            self.ship.death_tick = 0
            self.ship.hitted = False
            self.ship.hitted_tick = 0
            if self.max_score > self.all_max_score:
                self.all_max_score = self.max_score
            self.dying = False



    def run_game(self):
        while True:
            self._check_events()
            if self.game_active:
                self.ship.update()
                self._update_bullets()
                self._update_enemy()
                now_creat_enemy = pygame.time.get_ticks()
                if now_creat_enemy - self.spawn_tick >= 500:
                    self._create_enemy()
                    self.spawn_tick = now_creat_enemy
            elif not self.game_active and self.gameRunTimes >= 1:
                self._game_over(pygame.time.get_ticks())

            self._update_screen()

#入口
if __name__ == '__main__':
    sf = SkyForce()
    sf.run_game()