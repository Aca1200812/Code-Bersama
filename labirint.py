from pygame import *

win_width = 700
win_height = 500
window = display.set_mode((win_width, win_height))
display.set_caption('Maze Game')
back = (0, 0, 0)
window.fill(back)

class GameSprite(sprite.Sprite):
    def __init__(self, picture, w, h, x, y):
        super().__init__()
        self.image = transform.scale(image.load(picture),(w, h))
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y

    def reset(self):
        window.blit(self.image, (self.rect.x, self.rect.y))

class Player(GameSprite):
    def __init__(self, picture, w, h, x, y, x_speed, y_speed):
        GameSprite.__init__(self, picture, w, h, x, y)
        self.x_speed = x_speed
        self.y_speed = y_speed

    def update(self):
        self.rect.x += self.x_speed
        platforms_touched = sprite.spritecollide(self, barriers, False)
        if self.x_speed > 0: 
            for p in platforms_touched:
                self.rect.right = min(self.rect.right, p.rect.left)
        elif self.x_speed < 0: 
            for p in platforms_touched:
                self.rect.left = max(self.rect.left, p.rect.right)
                
        self.rect.y += self.y_speed
        platforms_touched = sprite.spritecollide(self, barriers, False)
        if self.y_speed > 0: 
            for p in platforms_touched:
                self.rect.bottom = min(self.rect.bottom, p.rect.top)
        elif self.y_speed < 0: 
            for p in platforms_touched:
                self.rect.top = max(self.rect.top, p.rect.bottom)
        if self.rect.left < 0:
            self.rect.left = 0
        if self.rect.right > win_width:
            self.rect.right = win_width
        if self.rect.top < 0:
            self.rect.top = 0
        if self.rect.bottom > win_height:
            self.rect.bottom = win_height

    def fire(self):
        bullet = Bullet('bullet.png', 10, 5, self.rect.right, self.rect.centery, 15)
        bullets.add(bullet)



class Enemy(GameSprite):
    def __init__(self, picture, w, h, x, y, speed, direction='kiri'):
        GameSprite.__init__(self, picture, w, h, x, y)
        self.speed = speed
        self.direction = direction
        self.top_limit = win_height // 4
        self.bottom_limit = (win_height * 3) // 4 - self.rect.height

    def update(self):
        if self.rect.y <= self.top_limit:
            self.direction = "bawah"
        if self.rect.y >= self.bottom_limit:
            self.direction = "atas"
        if self.direction == "atas":
            self.rect.y -= self.speed
        else:
            self.rect.y += self.speed

class Bullet(GameSprite):
    def __init__(self, picture, w, h, x, y, speed):
        GameSprite.__init__(self, picture, w, h, x, y)
        self.speed = speed

    def update(self):
        self.rect.x += self.speed
        if self.rect.x > win_width+10:
            self.kill()

wall_1 = GameSprite('platform2_v.png', 60, 300, win_width // 2 - 30, win_height // 2 - 150)
wall_2 = GameSprite('platform2.png', 225, 60, win_width // 2 - 250, win_height // 2 - 30)
barriers = sprite.Group()
barriers.add(wall_1)
barriers.add(wall_2)
enemy_1 = Enemy('cyborg.png', 60, 60, 600, 200, 2, 'kiri')
enemy_2 = Enemy('cyborg.png', 60, 60, 500, 250, 2, 'kanan')
monsters = sprite.Group()
monsters.add(enemy_1)
monsters.add(enemy_2)
final = GameSprite('pac-1.png', 60, 60, 600, 400)
hero = Player('hero.png', 60, 60, 0, 0, 0, 0)
bullets = sprite.Group()

finish = False
run = True
while run:
    time.delay(50)
    for e in event.get():
        if e.type == QUIT:
            run = False
        elif e.type == KEYDOWN:
            if finish:
                if e.key == K_r:
                    hero.rect.x = 0
                    hero.rect.y = 0
                    enemy_1.rect.x, enemy_1.rect.y = 600, 200
                    enemy_2.rect.x, enemy_2.rect.y = 500, 250
                    monsters.add(enemy_1)
                    monsters.add(enemy_2)
                    finish = False
            else:        
                if e.key == K_UP:
                    hero.y_speed = -5
                elif e.key == K_DOWN:
                    hero.y_speed = 5
                elif e.key == K_RIGHT:
                    hero.x_speed = 5
                elif e.key == K_LEFT:
                    hero.x_speed = -5
                elif e.key == K_SPACE:
                    hero.fire()
        elif e.type == KEYUP:
            if e.key == K_UP or e.key == K_DOWN:
                hero.y_speed = 0
            if e.key == K_RIGHT or e.key == K_LEFT:
                hero.x_speed = 0 

    if finish != True:
        window.fill(back)
        hero.reset()
        hero.update()
        barriers.draw(window)
        monsters.draw(window)
        monsters.update()
        final.reset()
        bullets.draw(window)
        bullets.update()
        sprite.groupcollide(bullets, monsters, False, True)
        sprite.groupcollide(bullets, barriers, True, False)
        if sprite.collide_rect(hero, final):
            winner = transform.scale(image.load('thumb.jpg'), (win_width, win_height))
            window.blit(winner, (0, 0))
            finish = True
        if sprite.spritecollide(hero, monsters, False):
            winner = transform.scale(image.load('game-over_1.png'), (win_width, win_height))
            window.blit(winner, (0, 0))
            finish = True
    display.update()