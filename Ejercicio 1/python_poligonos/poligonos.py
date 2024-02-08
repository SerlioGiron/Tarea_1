import random
import math

random.seed()

radius = 200
puntos = 6
angulo = 360 / puntos

cont = 0
angulos = []

angulos.append(cont)
for i in range(int(puntos)):
    cont += angulo
    angulos.append(cont)

print("\n")
pointsx = []
pointsy = []
for angle in angulos:
    print("angulo:", angle)
    randomNumber_alterar = 0.01 + random.random() * 0.99
    x = int(randomNumber_alterar * radius * math.cos(math.radians(angle)))
    y = int(randomNumber_alterar * radius * math.sin(math.radians(angle)))
    print("x:", x)
    print("y:", y)
    # x += 200
    # y += 200
    pointsx.append(x)
    pointsy.append(y)

distanciaPerimetros = []
for i in range(len(pointsx)):
    xUno, xDos, yUno, yDos, xCoordinate, yCoordinate, xSquared, ySquared, insideSum, squareRoot = 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    
    xUno = pointsx[i]
    yUno = pointsy[i]
    
    if i == len(pointsx) - 1:
        xDos = pointsx[0]
        yDos = pointsy[0]
    else:
        xDos = pointsx[i + 1]
        yDos = pointsy[i + 1]
    
    print("Coordenadas {}: ({}, {}) and ({}, {})".format(i, xUno - 200, yUno - 200, xDos - 200, yDos - 200))
    
    xCoordinate = xDos - xUno
    yCoordinate = yDos - yUno
    
    xSquared = xCoordinate * xCoordinate
    ySquared = yCoordinate * yCoordinate
    
    insideSum = xSquared + ySquared
    
    squareRoot = math.sqrt(insideSum)
    distanciaPerimetros.append(squareRoot)
    print("Distancia {}: {}".format(i, squareRoot))

sumPerimetros = sum(distanciaPerimetros)
avgPerimetros = sumPerimetros / len(distanciaPerimetros)

print("El Promedio de los Perimetros Es:", avgPerimetros)
