package poligonos;

import java.util.Random;
import java.util.ArrayList;

public class Poligonos {

    public static void main(String[] args) {

        long inicioEjecucion = System.currentTimeMillis(); //Inicio de Ejecucion

        Random random = new Random(); //Variables para Generar los Angulos
        int radius = 200;
        double puntos = 10;
        double angulo = 360 / Integer.parseInt(args[1]);
        double cont = 0;
        ArrayList<Double> angulos = new ArrayList<>();

        angulos.add(cont);
        for (int i = 0; i < puntos; i++) {
            cont += angulo;
            angulos.add(cont);
        }

        ArrayList<Double> distanciaPerimetros = new ArrayList<>();

        //Generacion de Poligonos y Calculo de Perimetros
        long totalGeneracionPoligonos = 0;
        long totalCalculoPerimetros = 0;

        for (int i = 0; i < Integer.parseInt(args[0]); i++) {
            ArrayList<Integer> pointsx = new ArrayList<>();
            ArrayList<Integer> pointsy = new ArrayList<>();

             //Generacion de Poligonos
            long inicioGeneracionPoligonos = System.currentTimeMillis();
            for (double angle : angulos) {
                double randomNumber_alterar = 0.01 + random.nextDouble() * 0.99;
                int x = (int) (randomNumber_alterar * radius * Math.cos(Math.toRadians(angle)));
                int y = (int) (randomNumber_alterar * radius * Math.sin(Math.toRadians(angle)));
                x += 200;
                y += 200;
                pointsx.add(x);
                pointsy.add(y);
            }
            long finGeneracionPoligonos = System.currentTimeMillis();
            totalGeneracionPoligonos += (finGeneracionPoligonos - inicioGeneracionPoligonos);

            //Calculo de Perimetros
            long inicioCalculoPerimetros = System.currentTimeMillis();
            for (int j = 0; j < pointsx.size(); j++) {
                double xUno, xDos, yUno, yDos, xCoordinate, yCoordinate, xSquared, ySquared, insideSum, squareRoot;
                xUno = pointsx.get(j);
                yUno = pointsy.get(j);
                if (j == pointsx.size() - 1) {
                    xDos = pointsx.get(0);
                    yDos = pointsy.get(0);
                } else {
                    xDos = pointsx.get(j + 1);
                    yDos = pointsy.get(j + 1);
                }
                System.out.println("Coordenadas " + j + ": (" + (xUno - 200) + ", " + (yUno - 200) + "), (" + (xDos - 200) + ", " + (yDos - 200) + ")");
                xCoordinate = xDos - xUno;
                yCoordinate = yDos - yUno;
                xSquared = xCoordinate * xCoordinate;
                ySquared = yCoordinate * yCoordinate;
                insideSum = xSquared + ySquared;
                squareRoot = Math.sqrt(insideSum);

                distanciaPerimetros.add(squareRoot);
                System.out.println("Distancia " + j + ": " + squareRoot);
            }
            long finCalculoPerimetros = System.currentTimeMillis();
            totalCalculoPerimetros += (finCalculoPerimetros - inicioCalculoPerimetros);

            System.out.println("Fin del Poligono " + (i+1) + '\n');
        }

        double sumPerimetros = 0;
        for (int i = 0; i < distanciaPerimetros.size(); i++) {
            sumPerimetros += distanciaPerimetros.get(i);
        }
        double avgPerimetros = 0;
        avgPerimetros = sumPerimetros / distanciaPerimetros.size();
        System.out.println("Suma Total: " + sumPerimetros);
        System.out.println("El Promedio de los Perimetros Es: " + avgPerimetros + '\n');

        long finEjecucion = System.currentTimeMillis();
        long totalEjecucion = (finEjecucion - inicioEjecucion);

        System.out.println("Tiempo de Generacion de Poligonos: " + (totalGeneracionPoligonos) + " milisegundos");
        System.out.println("Tiempo de Calculo de Todos los Perimetros: " + (totalCalculoPerimetros) + " milisegundos");
        System.out.println("Tiempo Total de Ejecucion: " + totalEjecucion + " milisegundos");
    }
}