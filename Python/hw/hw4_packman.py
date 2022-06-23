import turtle
import random
def draw_rectangle(pen, x, y, w=50, h=50, pencolor='black', fillcolor='grey'):
    pen.showturtle()
    pen.speed(100)
    pen.penup()
    pen.goto(x,y)
    pen.pendown()
    
    pen.color(pencolor)
    pen.fillcolor(fillcolor)
    pen.begin_fill()
    pen.forward(w)
    pen.left(90)
    pen.forward(h)
    pen.left(90)
    pen.forward(w)
    pen.left(90)
    pen.forward(h)
    pen.left(90)
    pen.end_fill()
    
    pen.hideturtle()
def mirro_size(pen, x, y, w=550, h=550, pencolor='black'):
    pen.showturtle()
    pen.speed(100)
    pen.penup()
    pen.goto(x,y)
    pen.pendown()
    
    pen.color(pencolor)
    pen.forward(w)
    pen.left(90)
    pen.forward(h)
    pen.left(90)
    pen.forward(w)
    pen.left(90)
    pen.forward(h)
    pen.left(90)
    
    pen.hideturtle()
def jewelry_show(screen, pen, x, y) :
    img = 'images/gem.gif'
    screen.addshape(img)
    pen.shape(img)
    pen.penup()
    pen.goto(x,y)
    
    pen.showturtle()
def packman_show(screen, pen, x, y) :
    d_img = {'right':'images/right.gif',  'left':'images/left.gif',
         'up':'images/up.gif',  'down':'images/down.gif' }
    
    for key in d_img:
        screen.addshape(d_img[key])
        
    pen.shape(d_img['right'])
    pen.penup()
    pen.goto(x, y)
    pen.showturtle()
    
    num = random.randint(0,3)
    
    while x!=250 or y!=-250:
        if num==0:
            if x<250 and  not(((x/50)+1,y/50) in block_position):
                pen.shape(d_img['right'])
                pen.goto(x+50, y)
                x = x+50
                num = random.randint(0,3)
            else:
                num = random.randint(0,3)
        elif num==1:
            if x>-250 and not(((x/50)-1,y/50) in block_position):
                pen.shape(d_img['left'])
                pen.goto(x-50, y)
                x = x-50
                num = random.randint(0,3)
            else: 
                num = random.randint(0,3)
        elif num==2:
            if y<250 and not(((x/50), y/50+1) in block_position):
                pen.shape(d_img['up'])
                pen.goto(x, y+50)
                y = y+50
                num = random.randint(0,3)
            else: 
                num = random.randint(0,3)
        elif num==3:
            if y>-250 and not(((x/50), y/50-1) in block_position):
                pen.shape(d_img['down'])
                pen.goto(x, y-50)
                y = y-50
                num = random.randint(0,3)
            else: 
                num = random.randint(0,3)
d_img = {'right':'images/right.gif',  'left':'images/left.gif',
         'up':'images/up.gif',  'down':'images/down.gif' }
block_position = (
    (-3,5),(-2,5),(0,5),(3,5),
    (-5,4),(-2,4),(0,4),(2,4),(3,4),(4,4),
    (-5,3),(-4,3),(-2,3),(0,3),
    (-4,2),(0,2),(1,2),(2,2),(4,2),(5,2),
    (-2,1),(1,1),(4,1),
    (-4,0),(-3,0),(-2,0),(0,0),(1,0),(3,0),(4,0), 
    (-5,-1),(-4,-1),(4,-1),
    (-2,-2),(-1,-2),(0,-2),(2,-2),(4,-2),
    (-4,-3),(-3,-3),(-2,-3),(2,-3),
    (-2,-4),(-1,-4),(0,-4),(1,-4),(2,-4),(3,-4),(4,-4),
    (-5,-5),(-4,-5),(-3,-5),(-2,-5)
)

jewelry_position = (5,-5)
def main():
    screen = turtle.Screen()
    pen1 = turtle.Turtle()
    pen2 = turtle.Turtle()  
    pen3 = turtle.Turtle()
    
    turtle.setup(width = 600, height = 600)
    mirro_size(pen1, -250-25, -250-25)
    
    for x,y in block_position:
        draw_rectangle(pen1, (x*50)-25, (y*50)-25 )
        
    jewelry_show(screen, pen2, jewelry_position[0]*50, jewelry_position[1]*50)
        
    packman_show(screen, pen3, -5*50, 5*50)
    
    turtle.done()
main()
