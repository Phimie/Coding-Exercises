class Settings:
    """存储所有设置"""

    def __init__(self):
        """初始化游戏设置"""
        #屏幕设置
        self.screen_width = 2000
        self.screen_height = 1200
        self.bg_color = (255,255,255)
        
        self.ship_speed = 1

        self.bullet_speed = 2
        self.bullet_width = 3
        self.bullet_height = 15
        self.bullet_color = (60,60,60)
