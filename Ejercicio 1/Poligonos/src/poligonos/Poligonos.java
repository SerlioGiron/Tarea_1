/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package poligonos;

import java.util.Random;
import java.util.ArrayList;

/**
 *
 * @author serli
 */
public class Poligonos {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Create a Random object
        Random random = new Random();

        // Generate a random integer between 0 (inclusive) and 100 (exclusive)
//        int radius = random.nextInt(1000);
        int radius = 200;

        System.out.println("radius: " + radius);

        double puntos = 45;
        double angulo = 360 / puntos;

        double cont = 0;
        ArrayList<Double> angulos = new ArrayList<>();

        angulos.add(cont);
        for (int i = 0; i < puntos; i++) {
            cont += angulo;
            angulos.add(cont);

        }
//        angulos.remove(angulos.size() - 1);

        for (int i = 0; i < angulos.size(); i++) {
            System.out.println(angulos.get(i) + " ");
        }

        ArrayList<Integer> pointsx = new ArrayList<>();
        ArrayList<Integer> pointsy = new ArrayList<>();
        for (double angle : angulos) {
            System.out.println("angulo: " + angle);
//            System.out.println("x double -> " + (radius * Math.cos(angle)));
//            System.out.println("y double -> " + (radius * Math.sin(angle)));
            double randomNumber_alterar = 0.01 + random.nextDouble() * 0.99;
            int x = (int) (randomNumber_alterar * radius * Math.cos(Math.toRadians(angle)));
            int y = (int) (randomNumber_alterar * radius * Math.sin(Math.toRadians(angle)));
            System.out.println("x -> " + x);
            System.out.println("y -> " + y);
            x += 200;
            y += 200;
            pointsx.add(x);
            pointsy.add(y);

        }

//        for (int i = 0; i < pointsx.size() - 1; i++) {
//            System.out.println( "x -> " + pointsx.get(i));
//            System.out.println( "y -> " + pointsy.get(i));
//        }
        new jRisk(pointsx, pointsy);

    }

}
