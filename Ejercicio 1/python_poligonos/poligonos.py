import random
import math
import sys
import time

inicioEjecucion = time.time() #Inicio de Ejecucion

random.seed() #Variables para Generar los Angulos
radius = 200
puntos = int(sys.argv[2])
angulo = 360 / puntos
cont = 0
angulos = []

angulos.append(cont)
for i in range(int(puntos)):
    cont += angulo
    angulos.append(cont)

totalperimetros = 0
veces = int(sys.argv[1])
distanciaPerimetros = []

#Generacion de Poligonos y Calculo de Perimetros
totalGeneracionPoligonos = 0;
totalCalculoPerimetros = 0;

for j in range(veces):
    pointsx = []
    pointsy = []
    #Generacion de Poligonos
    inicioGeneracionPoligonos = time.time()
    for angle in angulos:
        randomNumber_alterar = 0.01 + random.random() * 0.99
        x = int(randomNumber_alterar * radius * math.cos(math.radians(angle)))
        y = int(randomNumber_alterar * radius * math.sin(math.radians(angle)))
        pointsx.append(x)
        pointsy.append(y)
    finGeneracionPoligonos = time.time()
    totalGeneracionPoligonos += (finGeneracionPoligonos - inicioGeneracionPoligonos)

    #Calculo de Perimetros
    inicioCalculoPerimetros = time.time()
    sumPerimetros = 0
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

        #print("Coordenadas {}: ({}, {}) and ({}, {})".format(i, xUno, yUno, xDos, yDos))        
        xCoordinate = xDos - xUno
        yCoordinate = yDos - yUno
        xSquared = xCoordinate * xCoordinate
        ySquared = yCoordinate * yCoordinate
        insideSum = xSquared + ySquared
        squareRoot = math.sqrt(insideSum)
        distanciaPerimetros.append(squareRoot)
        #print("Distancia {}: {}".format(i, squareRoot))
    finCalculoPerimetros = time.time()
    totalCalculoPerimetros += (finCalculoPerimetros - inicioCalculoPerimetros)
    ##print("Fin del Poligono ", j+1, "\n")

sumPerimetros = sum(distanciaPerimetros)
avgPerimetros = sumPerimetros / len(distanciaPerimetros)

print("Suma Total: ", sumPerimetros)
print("El Promedio de los Perimetros Es:", avgPerimetros, "\n")

finEjecucion = time.time()
totalEjecucion = (finEjecucion - inicioEjecucion)

print("Tiempo de Generacion de Poligonos: " , (totalGeneracionPoligonos*1000) , " milisegundos")
print("Tiempo de Calculo de Todos los Perimetros: " , (totalCalculoPerimetros*1000) , " milisegundos")
print("Tiempo Total de Ejecucion: " , (totalEjecucion*1000) , " milisegundos")