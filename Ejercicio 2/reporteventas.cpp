#include <iostream>
#include<vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int generarRandom(int inicio, int fin) {
    return rand() % (fin - inicio + 1) + inicio;
}
string agregarCero(int numVerificar) {
    string numString;
    if (numVerificar < 10) {
        numString = "0" + to_string(numVerificar);
    }
    else {
        numString = to_string(numVerificar);
    }
    return numString;
}
int obtenerMunicipio(int randDepartamento) {
    int numMunicipio = 0;
    switch (randDepartamento) {
        case 1: {
            numMunicipio = generarRandom(1,8);
        }
        case 2: {
            numMunicipio = generarRandom(1, 10);
        }
        case 3: {
            numMunicipio = generarRandom(1, 21);
        }
        case 4: {
            numMunicipio = generarRandom(1, 23);
        }
        case 5: {
            numMunicipio = generarRandom(1, 12);
        }
        case 6: {
            numMunicipio = generarRandom(1, 16);
        }
        case 7: {
            numMunicipio = generarRandom(1, 19);
        }
        case 8: {
            numMunicipio = generarRandom(1, 28);
        }
        case 9: {
            numMunicipio = generarRandom(1, 9);
        }
        case 10: {
            numMunicipio = generarRandom(1, 17);
        }
        case 11: {
            numMunicipio = generarRandom(1, 4);
        }
        case 12: {
            numMunicipio = generarRandom(1, 19);
        }
        case 13: {
            numMunicipio = generarRandom(1, 28);
        }
        case 14: {
            numMunicipio = generarRandom(1, 16);
        }
        case 15: {
            numMunicipio = generarRandom(1, 23);
        }
        case 16: {
            numMunicipio = generarRandom(1, 28);
        }
        case 17:{
            numMunicipio = generarRandom(1, 9);
        }
        case 18: {
            numMunicipio = generarRandom(1, 11);
        }  
    }
    return numMunicipio;
}
int obtenerDiaCompra(int randMesFecha) {
    int diaCompra = 0;
    switch (randMesFecha) {
        case 1: {
            diaCompra =  generarRandom(1, 31);
        }
        case 2: {
            diaCompra = generarRandom(1, 28);
        }
        case 3: {
            diaCompra = generarRandom(1, 31);
        }
        case 4: {
            diaCompra = generarRandom(1, 30);
        }
        case 5: {
            diaCompra = generarRandom(1, 31);
        }
        case 6: {
            diaCompra = generarRandom(1, 30);
        }
        case 7: {
            diaCompra = generarRandom(1, 31);
        }
        case 8: {
            diaCompra = generarRandom(1, 31);
        }
        case 9: {
            diaCompra = generarRandom(1, 30);
        }
        case 10: {
            diaCompra = generarRandom(1, 31);
        }
        case 11: {
            diaCompra = generarRandom(1, 30);
        }
        case 12: {
            diaCompra = generarRandom(1, 31);
        }
    }
    return diaCompra;
}
string generarIdentidad(int randDepartamento, int randAnioIdentidad, int randNumIdentidad) {
    string cadenaIdentidad;
    cadenaIdentidad += agregarCero(randDepartamento);
    cadenaIdentidad += agregarCero(obtenerMunicipio(randDepartamento)) + "-";
    cadenaIdentidad += to_string(randAnioIdentidad) + "-";
    cadenaIdentidad += to_string(randNumIdentidad);
    return cadenaIdentidad;
}
string generarFecha(int randMesFecha, int randAnioFecha){
    string cadenaFecha;
    cadenaFecha += agregarCero(randMesFecha) + "/";
    cadenaFecha += agregarCero(obtenerDiaCompra(randMesFecha)) + "/";
    cadenaFecha += to_string(randAnioFecha);
    return cadenaFecha;
}
string generarHora(int randHora, int randMinuto, int randSegundo) {
    string cadenaHora;
    cadenaHora += agregarCero(randHora) + ":";
    cadenaHora += agregarCero(randMinuto) + ":";
    cadenaHora += agregarCero(randSegundo);
    return cadenaHora;
}
float generarTotal(float minCompra, float maxCompra) {
    float random_num = static_cast<float>(rand()) / RAND_MAX;
    float totalGenerado = minCompra + random_num * (maxCompra - minCompra);
    return totalGenerado;
}
int main(int argc, char* argv[]){
    clock_t start_total = clock();
    if (argc != 2) {
        cerr << "Debe de correr el programa de la siguiente forma: ./ejercicio_2_c++.exe numVentas";
        return 1;
    }
    int numVentasGenerar = atoi(argv[1]);
    srand(static_cast<unsigned int>(time(NULL)));
    vector<string> nombreSucursales = {"La Colonia Las Hadas","La Colonia La Kennedy","La Colonia La Granja","La Colonia La Hacienda","La Colonia Galerias","La Colonia Villas del Sol","La Colonia Anillo Periferico","La Colonia Las Torres"};
    vector<string> ventas;
    clock_t start_ventas = clock();
    for (int i = 0; i < numVentasGenerar; i++){
        string venta;
        int randDepartamento = generarRandom(1, 18);
        int randAnioIdentidad = generarRandom(1920, 2005);
        int randNumIdentidad = generarRandom(10000, 99999);
        string cadenaIdentidad = generarIdentidad(randDepartamento, randAnioIdentidad, randNumIdentidad);
        string sucursal = nombreSucursales[generarRandom(0,7)];
        int randMesFecha = generarRandom(1, 12);
        int randAnioFecha = generarRandom(2011,2023);
        string cadenaFecha = generarFecha(randMesFecha, randAnioFecha);
        int randHora = generarRandom(7, 22);
        int randMinuto = generarRandom(0, 59);
        int randSegundo = generarRandom(0, 59);
        string cadenaHora = generarHora(randHora, randMinuto, randSegundo);
        float total = generarTotal(10.0, 10000.0);
        string cadenaTotal = "L. " + to_string(total);
        venta = cadenaIdentidad + ", " + sucursal + ", " + cadenaFecha + ", " + cadenaHora + ", " + cadenaTotal;
        ventas.push_back(venta);
    }
    clock_t end_ventas = clock();
    string ventasConcatenadas;
    clock_t start_concat = clock();
    for (int i = 0; i < numVentasGenerar; i++)
    {
        ventasConcatenadas += ventas[i] + "\n";
    }
    clock_t end_concat = clock();
    double tiempo_total = (double)(clock() - start_total) / CLOCKS_PER_SEC;
    double tiempo_ventas = (double)(end_ventas - start_ventas) / CLOCKS_PER_SEC;
    double tiempo_concatenacion = (double)(end_concat - start_concat) / CLOCKS_PER_SEC;
    cout << "Reporte de Ventas:\n" << ventasConcatenadas;
    std::cout << "Tiempo total de ejecucion: " << tiempo_total << " segundos\n";
    std::cout << "Tiempo de generaci贸n de ventas aleatorias: " << tiempo_ventas << " segundos\n";
    std::cout << "Tiempo total de concatenacion: " << tiempo_concatenacion << " segundos\n";
}