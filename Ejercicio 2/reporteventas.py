import random
import sys
import time

def generar_random(inicio, fin):
    return random.randint(inicio, fin)

def agregar_cero(num_verificar):
    if num_verificar < 10:
        return "0" + str(num_verificar)
    else:
        return str(num_verificar)

def obtener_municipio(rand_departamento):
    switcher = {
        1: (1, 8),
        2: (1, 10),
        3: (1, 21),
        4: (1, 23),
        5: (1, 12),
        6: (1, 16),
        7: (1, 19),
        8: (1, 28),
        9: (1, 9),
        10: (1, 17),
        11: (1, 4),
        12: (1, 19),
        13: (1, 28),
        14: (1, 16),
        15: (1, 23),
        16: (1, 28),
        17: (1, 9),
        18: (1, 11),
    }
    return generar_random(*switcher.get(rand_departamento, (0, 0)))

def obtener_dia_compra(rand_mes_fecha):
    switcher = {
        1: (1, 31),
        2: (1, 28),
        3: (1, 31),
        4: (1, 30),
        5: (1, 31),
        6: (1, 30),
        7: (1, 31),
        8: (1, 31),
        9: (1, 30),
        10: (1, 31),
        11: (1, 30),
        12: (1, 31),
    }
    return generar_random(*switcher.get(rand_mes_fecha, (0, 0)))

def generar_identidad(rand_departamento, rand_anio_identidad, rand_num_identidad):
    cadena_identidad = agregar_cero(rand_departamento)
    cadena_identidad += agregar_cero(obtener_municipio(rand_departamento)) + "-"
    cadena_identidad += str(rand_anio_identidad) + "-"
    cadena_identidad += str(rand_num_identidad)
    return cadena_identidad

def generar_fecha(rand_mes_fecha, rand_anio_fecha):
    cadena_fecha = agregar_cero(rand_mes_fecha) + "/"
    cadena_fecha += agregar_cero(obtener_dia_compra(rand_mes_fecha)) + "/"
    cadena_fecha += str(rand_anio_fecha)
    return cadena_fecha

def generar_hora(rand_hora, rand_minuto, rand_segundo):
    cadena_hora = agregar_cero(rand_hora) + ":"
    cadena_hora += agregar_cero(rand_minuto) + ":"
    cadena_hora += agregar_cero(rand_segundo)
    return cadena_hora

def generar_total(min_compra, max_compra):
    return round(random.uniform(min_compra, max_compra), 2)

if __name__ == "__main__":
    start_total = time.time()
    if len(sys.argv) != 2:
        print("Debe de correr el programa de la siguiente forma: python3 ejercicio_2.py numVentas")
        sys.exit(1)

    num_ventas_generar = int(sys.argv[1])
    random.seed(time.time())

    nombre_sucursales = [
        "La Colonia Las Hadas", "La Colonia La Kennedy", "La Colonia La Granja",
        "La Colonia La Hacienda", "La Colonia Galerias", "La Colonia Villas del Sol",
        "La Colonia Anillo Periferico", "La Colonia Las Torres"
    ]
    ventas = []

    start_ventas = time.time()
    for _ in range(num_ventas_generar):
        rand_departamento = generar_random(1, 18)
        rand_anio_identidad = generar_random(1920, 2005)
        rand_num_identidad = generar_random(10000, 99999)
        cadena_identidad = generar_identidad(rand_departamento, rand_anio_identidad, rand_num_identidad)
        sucursal = random.choice(nombre_sucursales)
        rand_mes_fecha = generar_random(1, 12)
        rand_anio_fecha = generar_random(2011, 2023)
        cadena_fecha = generar_fecha(rand_mes_fecha, rand_anio_fecha)
        rand_hora = generar_random(7, 22)
        rand_minuto = generar_random(0, 59)
        rand_segundo = generar_random(0, 59)
        cadena_hora = generar_hora(rand_hora, rand_minuto, rand_segundo)
        total = generar_total(10.0, 10000.0)
        cadena_total = "L. " + str(total)
        venta = f"{cadena_identidad}, {sucursal}, {cadena_fecha}, {cadena_hora}, {cadena_total}"
        ventas.append(venta)
    end_ventas = time.time()

    ventas_concatenadas = "\n".join(ventas)

    end_concat = time.time()

    tiempo_total = end_total - start_total
    tiempo_ventas = end_ventas - start_ventas
    tiempo_concatenacion = end_concat - start_concat

    print("Reporte de Ventas:\n", ventas_concatenadas)
    print("Tiempo total de ejecucion:", tiempo_total, "segundos")
    print("Tiempo de generación de ventas aleatorias:", tiempo_ventas, "segundos")
    print("Tiempo total de concatenación:", tiempo_concatenacion, "segundos")
