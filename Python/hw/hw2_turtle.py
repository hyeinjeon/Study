import turtle
def draw_line(pen, x1, y1, x2, y2, pencolor='black'):
    pen.showturtle()
    pen.speed(10)
    pen.penup()
    pen.goto(x1, y1)
    pen.pendown()
    
    pen.color(pencolor)
    pen.goto(x2, y2)
    pen.hideturtle()
def draw_squarePolygon(pen, x, y, radius, side, pencolor='black', fillcolor=None):
    pen.showturtle()
    pen.speed(10)
    pen.penup()
    pen.goto(x,y)
    pen.pendown()
    
    pen.color(pencolor)
    pen.fillcolor(fillcolor)
    pen.begin_fill()
    pen.circle(radius)
    pen.end_fill()
    
    pen.hideturtle()
def draw_rectangle(pen, x, y, w, h, pencolor='black', fillcolor=None):
    pen.showturtle()
    pen.speed(10)
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
def main():
    screen = turtle.Screen()
    pen = turtle.Turtle()
    
    x = (int)(-400)
    for n in range(-400, 401, 100):
        draw_line(pen, x, n, x+800, n, 'black')
    y = (int)(-400)
    for n in range(-400, 401, 100):
        draw_line(pen, n, y, n, y+800, 'black')
    
    y = (int)(-400)
    for n in range(-400, 301, 200):
        draw_rectangle(pen, n, y, 100, 100, 'black', 'red')
    for n in range(-300, 401, 200):
        draw_rectangle(pen, n, y, 100, 100, 'black', 'black')
    
    x = (int)(-200); r = (int)(200)
    for n in range(3):
        draw_squarePolygon(pen, x, -r, r, 100, 'black', 'red')
        r = r/2; x = x+(r*2)+r
        draw_squarePolygon(pen, x, -r, r, 100, 'black', 'blue')
        r = r/2; x = x+(r*2)+r

    turtle.done()
main()
