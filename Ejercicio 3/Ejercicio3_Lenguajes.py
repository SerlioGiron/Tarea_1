import sys
import random
import time

# Definir variable global para tiempo de inicio de actualización
actualizacion_tiempo_inicio = 0

def main():
    if len(sys.argv) != 3:
        print("Debe proporcionar dos argumentos: N y T")
        return

    global actualizacion_tiempo_inicio  # Declarar que se está utilizando la variable global
    N = int(sys.argv[1])
    T = int(sys.argv[2])

    generacion_tiempo_inicio = int(time.time() * 1000)

    random.seed()
    matriz = [[round(random.uniform(-30.0, 50.0), 1) for _ in range(N)] for _ in range(N)]

    generacion_tiempo = int(time.time() * 1000) - generacion_tiempo_inicio

    # Metodo de redistribución de calor
    global actualizacion_tiempo_inicio  # Declarar que se está utilizando la variable global
    actualizacion_tiempo_inicio = int(time.time() * 1000)
    actualizar_temp(matriz, T, 1)
    actualizacion_tiempo = int(time.time() * 1000) - actualizacion_tiempo_inicio

    # Imprimir resultados
    imprimir_tiempos(generacion_tiempo, actualizacion_tiempo)

def imprimir_matriz(matriz, mensaje):
    temp_promedio, desviaciones = calcular_promedios_desviaciones(matriz)

    print(f"\n{mensaje}")
    for row in matriz:
        print(" ".join(f"[{temp:.1f}]" for temp in row))

    # Desviación estándar: Suma de las desviaciones entre la cantidad de elementos
    desv_estandar = desviaciones / (len(matriz) ** 2)

    # Mostrar los cálculos generados de la matriz
    print(f"\nTemperatura promedio de la matriz: {round(temp_promedio, 1)}")
    print(f"Desviación estándar: {round(desv_estandar, 2)}\n")

    # Mostrar el tiempo que tomó generar los cálculos
    calculo_tiempo = int(time.time() * 1000) - actualizacion_tiempo_inicio
    print(f"Tiempo de cálculo de promedios y desviaciones estándar: {calculo_tiempo} milisegundos")

def calcular_promedios_desviaciones(matriz):
    temp_promedio = sum(sum(row) for row in matriz) / (len(matriz) ** 2)
    desviaciones = sum((temp - temp_promedio) ** 2 for row in matriz for temp in row)
    return temp_promedio, desviaciones

def imprimir_tiempos(generacion_tiempo, actualizacion_tiempo):
    tiempo_total_ejecucion = generacion_tiempo + actualizacion_tiempo
    print(f"\nTiempo total de ejecución: {tiempo_total_ejecucion} milisegundos")
    print(f"Tiempo de generación de temperaturas: {generacion_tiempo} milisegundos")
    print(f"Tiempo de actualización de temperaturas: {actualizacion_tiempo} milisegundos")

def actualizar_temp(matriz, T, cont):
    matriz_nueva = [row[:] for row in matriz]

    if cont <= T:
        for i in range(len(matriz)):
            for j in range(len(matriz[i])):
                numerador = 0
                denominador = 0

                for k in range(-1, 2):
                    for l in range(-1, 2):
                        peso = 1 / 8.0

                        if k == 0 and l == 0:
                            peso = 1 / 4.0
                        elif k == l or k + l == 2:
                            peso = 1 / 16.0

                        if i + k < 0 or i + k >= len(matriz) or j + l < 0 or j + l >= len(matriz[i]):
                            peso = 1 / 4.0
                            numerador += matriz[i][j] * peso
                        else:
                            numerador += matriz[i + k][j + l] * peso

                        denominador += peso

                # Actualizar temperatura de la celda actual
                promedio = numerador / denominador
                matriz_nueva[i][j] = round(promedio, 1)

        imprimir_matriz(matriz, f"Paso {cont}")
        actualizar_temp(matriz_nueva, T, cont + 1)

if __name__ == "__main__":
    main()
