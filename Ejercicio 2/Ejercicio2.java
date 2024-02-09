package ejercicio2_java;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
/**
 *
 * @author diego
 */
public class Ejercicio2_java {

    /**
     * @param args the command line arguments
     */
    static Random rand = new Random();

    public static int generarRandom(int inicio, int fin) {
        return rand.nextInt(fin - inicio + 1) + inicio;
    }

    public static String agregarCero(int numVerificar) {
        String numString;
        if (numVerificar < 10) {
            numString = "0" + numVerificar;
        } else {
            numString = Integer.toString(numVerificar);
        }
        return numString;
    }

    public static int obtenerMunicipio(int randDepartamento) {
        int numMunicipio = 0;
        switch (randDepartamento) {
            case 1 -> numMunicipio = generarRandom(1, 8);
            case 2 -> numMunicipio = generarRandom(1, 10);
            case 3 -> numMunicipio = generarRandom(1, 21);
            case 4 -> numMunicipio = generarRandom(1, 23);
            case 5 -> numMunicipio = generarRandom(1, 12);
            case 6 -> numMunicipio = generarRandom(1, 16);
            case 7 -> numMunicipio = generarRandom(1, 19);
            case 8 -> numMunicipio = generarRandom(1, 28);
            case 9 -> numMunicipio = generarRandom(1, 9);
            case 10 -> numMunicipio = generarRandom(1, 17);
            case 11 -> numMunicipio = generarRandom(1, 4);
            case 12 -> numMunicipio = generarRandom(1, 19);
            case 13 -> numMunicipio = generarRandom(1, 28);
            case 14 -> numMunicipio = generarRandom(1, 16);
            case 15 -> numMunicipio = generarRandom(1, 23);
            case 16 -> numMunicipio = generarRandom(1, 28);
            case 17 -> numMunicipio = generarRandom(1, 9);
            case 18 -> numMunicipio = generarRandom(1, 11);
        }
        return numMunicipio;
    }

    public static int obtenerDiaCompra(int randMesFecha) {
        int diaCompra = 0;
        switch (randMesFecha) {
            case 1 -> diaCompra = generarRandom(1, 31);
            case 2 -> diaCompra = generarRandom(1, 28);
            case 3 -> diaCompra = generarRandom(1, 31);
            case 4 -> diaCompra = generarRandom(1, 30);
            case 5 -> diaCompra = generarRandom(1, 31);
            case 6 -> diaCompra = generarRandom(1, 30);
            case 7 -> diaCompra = generarRandom(1, 31);
            case 8 -> diaCompra = generarRandom(1, 31);
            case 9 -> diaCompra = generarRandom(1, 30);
            case 10 -> diaCompra = generarRandom(1, 31);
            case 11 -> diaCompra = generarRandom(1, 30);
            case 12 -> diaCompra = generarRandom(1, 31);
        }
        return diaCompra;
    }

    public static String generarIdentidad(int randDepartamento, int randAnioIdentidad, int randNumIdentidad) {
        StringBuilder cadenaIdentidad = new StringBuilder();
        cadenaIdentidad.append(agregarCero(randDepartamento));
        cadenaIdentidad.append(agregarCero(obtenerMunicipio(randDepartamento))).append("-");
        cadenaIdentidad.append(randAnioIdentidad).append("-");
        cadenaIdentidad.append(randNumIdentidad);
        return cadenaIdentidad.toString();
    }

    public static String generarFecha(int randMesFecha, int randAnioFecha) {
        StringBuilder cadenaFecha = new StringBuilder();
        cadenaFecha.append(agregarCero(randMesFecha)).append("/");
        cadenaFecha.append(agregarCero(obtenerDiaCompra(randMesFecha))).append("/");
        cadenaFecha.append(randAnioFecha);
        return cadenaFecha.toString();
    }

    public static String generarHora(int randHora, int randMinuto, int randSegundo) {
        StringBuilder cadenaHora = new StringBuilder();
        cadenaHora.append(agregarCero(randHora)).append(":");
        cadenaHora.append(agregarCero(randMinuto)).append(":");
        cadenaHora.append(agregarCero(randSegundo));
        return cadenaHora.toString();
    }

    public static float generarTotal(float minCompra, float maxCompra) {
        return minCompra + rand.nextFloat() * (maxCompra - minCompra);
    }

    public static void main(String[] args) {
        long start_total = System.currentTimeMillis();

        if (args.length != 1) {
            System.err.println("Debe de correr el programa de la siguiente forma: java ejercicio2_java numVentas");
            System.exit(1);
        }

        int numVentasGenerar = Integer.parseInt(args[0]);
        //int numVentasGenerar = System.out.println("Ingrese numero de ventas a generar: ");
        List<String> nombreSucursales = List.of("La Colonia Las Hadas", "La Colonia La Kennedy", "La Colonia La Granja",
                "La Colonia La Hacienda", "La Colonia Galerias", "La Colonia Villas del Sol",
                "La Colonia Anillo Periferico", "La Colonia Las Torres");
        List<String> ventas = new ArrayList<>();

        long start_ventas = System.currentTimeMillis();

        for (int i = 0; i < numVentasGenerar; i++) {
            int randDepartamento = generarRandom(1, 18);
            int randAnioIdentidad = generarRandom(1920, 2005);
            int randNumIdentidad = generarRandom(10000, 99999);
            String cadenaIdentidad = generarIdentidad(randDepartamento, randAnioIdentidad, randNumIdentidad);

            String sucursal = nombreSucursales.get(generarRandom(0, 7));

            int randMesFecha = generarRandom(1, 12);
            int randAnioFecha = generarRandom(2011, 2023);
            String cadenaFecha = generarFecha(randMesFecha, randAnioFecha);

            int randHora = generarRandom(7, 22);
            int randMinuto = generarRandom(0, 59);
            int randSegundo = generarRandom(0, 59);
            String cadenaHora = generarHora(randHora, randMinuto, randSegundo);

            float total = generarTotal(10.0f, 10000.0f);
            String cadenaTotal = "L. " + total;

            String venta = cadenaIdentidad + ", " + sucursal + ", " + cadenaFecha + ", " + cadenaHora + ", " + cadenaTotal;
            ventas.add(venta);
        }

        long end_ventas = System.currentTimeMillis();

        String ventasConcatenadas = "";
        long start_concat = System.currentTimeMillis();

        for (String venta : ventas) {
            ventasConcatenadas += venta + "\n";
        }

        long end_concat = System.currentTimeMillis();

        double tiempo_total = (double) (System.currentTimeMillis() - start_total) / 1000;
        double tiempo_ventas = (double) (end_ventas - start_ventas) / 1000;
        double tiempo_concatenacion = (double) (end_concat - start_concat) / 1000;

        System.out.println("Reporte de Ventas:\n" + ventasConcatenadas);
        System.out.println("Tiempo total de ejecucion: " + tiempo_total + " segundos");
        System.out.println("Tiempo de generación de ventas aleatorias: " + tiempo_ventas + " segundos");
        System.out.println("Tiempo total de concatenacion: " + tiempo_concatenacion + " segundos");
    }
    
}
