import java.util.Random;

public class Ejercicio3_Lenguajes {

    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Debe proporcionar dos argumentos: N y T");
            return;
        }

        int N = Integer.parseInt(args[0]);
        int T = Integer.parseInt(args[1]);

        long startTime = System.currentTimeMillis();

        Random random = new Random();
        double[][] matriz = new double[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // Generar una temperatura al azar entre -30.0 y 50.0 celcius
                double temperatura = -30.0 + (random.nextDouble() * 70.0);
                matriz[i][j] = Math.round(temperatura * 10.0) / 10.0;
            }
        }

        long generacionTiempo = System.currentTimeMillis() - startTime;

        // Metodo de redistribución de calor
        startTime = System.currentTimeMillis();
        actualizarTemp(matriz, T, 1);
        long actualizacionTiempo = System.currentTimeMillis() - startTime;

        System.out
                .println("\nTiempo total de ejecución: " + (generacionTiempo + actualizacionTiempo) + " milisegundos");
        System.out.println("Tiempo de generación de temperaturas: " + generacionTiempo + " milisegundos");
        System.out.println("Tiempo de actualización de temperaturas: " + actualizacionTiempo + " milisegundos");
    }

    public static void imprimirMatriz(double[][] matriz, String mensaje) {
        double tempPromedio = tempPromedio(matriz), desviaciones = 0.0;

        System.out.print("\n" + mensaje);
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz.length; j++) {
                // System.out.print("[" + matriz[i][j] + "]\t");
                // Calcular y acumular las desviaciones
                desviaciones += Math.pow(matriz[i][j] - tempPromedio, 2);
            }
            // System.out.println("");
        }

        long startTime = System.currentTimeMillis();

        // Desviación estándar: Suma de las desviaciones entre la cantidad de elementos
        double desvEstandar = desviaciones / Math.pow(matriz.length, 2);

        // Mostrar los cálculos generados de la matriz
        System.out.println("\nTemperatura promedio de la matriz: " + Math.round(tempPromedio * 20.0) / 20.0);
        System.out.println("Desviación estándar: " + Math.round(desvEstandar * 40.0) / 40.0 + "\n");

        // Mostrar el tiempo que tomó generar los cálculos
        long calculoTiempo = System.currentTimeMillis() - startTime;
        System.out
                .println("Tiempo de cálculo de promedios y desviaciones estándar: " +
                        calculoTiempo + " milisegundos");
    }

    public static double tempPromedio(double[][] matriz) {
        double numerador = 0;
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz.length; j++) {
                numerador += matriz[i][j];
            }
        }
        // Promedio: Suma de los elementos entre la cantidad de elementos
        double promedio = numerador / Math.pow(matriz.length, 2);
        return promedio;
    }

    public static double[][] actualizarTemp(double[][] matriz, int T, int cont) {
        double[][] matrizNueva = new double[matriz.length][matriz.length];
        if (cont <= T) {
            for (int i = 0; i < matriz.length; i++) {
                for (int j = 0; j < matriz.length; j++) {

                    double numerador = 0, denominador = 0;

                    for (int k = -1; k < 2; k++) {
                        for (int l = -1; l < 2; l++) {

                            // Aisgnar los pesos correspondientes
                            // para el calculo del promedio ponderado

                            // Promedio ponderado =
                            // (elemento1*peso1) + (...) + (elementoN*pesoN) / (peso1 + ... + pesoN)
                            double peso = (double) 1 / 8;

                            if (k == 0 && l == 0) {
                                // Elemento actual
                                peso = (double) 1 / 4;
                            } else if (k == l || k + l == 2) {
                                // Vecinos de las esquinas
                                peso = (double) 1 / 16;
                            }

                            // Acumular valores del numerador
                            if (i + k >= matriz.length || i + k < 0
                                    || j + l >= matriz.length || j + l < 0) {
                                // Validar las celdas de los bordes
                                peso = 1 / 4;
                                numerador += matriz[i][j] * peso;
                            } else {
                                numerador += matriz[i + k][j + l] * peso;
                            }

                            // Acumular valores del denominador
                            denominador += peso;
                        }
                    }

                    // Actualizar temperatura de la celda actual
                    double promedio = numerador / denominador;
                    matrizNueva[i][j] = Math.round(promedio * 10.0) / 10.0;
                }
            }
            // Mostrar la nueva matriz y los calculos generados
            imprimirMatriz(matriz, "Paso " + cont);
            // Llamado recursivo
            actualizarTemp(matrizNueva, T, ++cont);
        }
        return matrizNueva;
    }
}
