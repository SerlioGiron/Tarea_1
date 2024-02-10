#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include <string>
#include <ctime>
#define M_PI 3.14159265358979323846
using namespace std;

double randomNextDouble()
{
    mt19937 rng(std::random_device{}());
    uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng);
}

int randomNextInt()
{
    random_device rd;
    mt19937 gen(rd());
    
    // Define the distribution
    uniform_int_distribution<> dis(1, 1000);
    
    // Generate a random number
    int random_num = dis(gen);
    return random_num;
}

int main(int argc, char *argv[])
{

    time_t inicioEjecucion = time(nullptr); //Inicio de Ejecucion

    double random_radius = randomNextInt();
    // int radius = 200; //Variables para Generar los Angulos
    double puntos = std::stoi(argv[2]);
    double angulo = 360 / puntos;
    double cont = 0; 
    vector<double> angulos;

    angulos.push_back(cont);
    for (size_t i = 0; i < puntos; i++) {
        cont += angulo;
        angulos.push_back(cont);
    }

    vector<double> distanciaPerimetros;

    //Generacion de Poligonos y Calculo de Perimetros
    long totalGeneracionPoligonos = 0;
    long totalCalculoPerimetros = 0;

    for (size_t mPoligonos = 0; mPoligonos < std::stoi(argv[1]); mPoligonos++) {
        vector<int> pointsx;
        vector<int> pointsy;

        //Generacion de Poligonos
        long inicioGeneracionPoligonos = time(nullptr);
        for (double angle : angulos) {
            double random_number = randomNextDouble();
            int x = (random_number * random_radius * cos(angle * M_PI / 180.0));
            int y = (random_number * random_radius * sin(angle * M_PI / 180.0));
            x += 200;
            y += 200;
            pointsx.push_back(x);
            pointsy.push_back(y);
        }
        long finGeneracionPoligonos = time(nullptr);
        totalGeneracionPoligonos += (difftime(finGeneracionPoligonos, inicioGeneracionPoligonos) * 1000.0);

        //Calculo de Perimetros
        long inicioCalculoPerimetros = time(nullptr);
        for (size_t i = 0; i < pointsx.size(); i++) {
            double xUno, xDos, yUno, yDos, xCoordinate, yCoordinate, xSquared, ySquared, insideSum, squareRoot;
            xUno = pointsx.at(i);
            yUno = pointsy.at(i);
            if (i == pointsx.size() - 1) {
                xDos = pointsx.at(0);
                yDos = pointsy.at(0);
            } else {
                xDos = pointsx.at(i + 1);
                yDos = pointsy.at(i + 1);
            }
            //std::cout << "Coordenadas " << i << ": (" << (xUno - 200) << ", " << (yUno - 200) << ") and (" << (xDos - 200) << ", " << (yDos - 200) << ")" << endl;
            xCoordinate = xDos - xUno;
            yCoordinate = yDos - yUno;
            xSquared = xCoordinate * xCoordinate;
            ySquared = yCoordinate * yCoordinate;
            insideSum = xSquared + ySquared;
            squareRoot = sqrt(insideSum);

            distanciaPerimetros.push_back(squareRoot);
            //std::cout << "Distancia " << i << ": " << squareRoot << endl;
        }
        long finCalculoPerimetros = time(nullptr);
        totalCalculoPerimetros += (difftime(finCalculoPerimetros, inicioCalculoPerimetros) * 1000.0);

        //std::cout << "Fin del Poligono " << mPoligonos + 1 << "\n" << endl;
    }

    double sumPerimetros = 0;
    for (size_t i = 0; i < distanciaPerimetros.size(); i++) {
        sumPerimetros += distanciaPerimetros.at(i);
    }
    double avgPerimetros = 0;
    avgPerimetros = sumPerimetros / distanciaPerimetros.size();
    //std::cout << "Suma Total: " << sumPerimetros << endl;
    std::cout << "El Promedio de los Perimetros Es: " << avgPerimetros << '\n' << endl;

    long finEjecucion = time(nullptr);
    long totalEjecucion = difftime(finEjecucion, inicioEjecucion) * 1000.0;

    cout << "Tiempo de Generacion de Poligonos: " << (totalGeneracionPoligonos) << " milisegundos" << endl;
    cout << "Tiempo de Calculo de Todos los Perimetros: " << (totalCalculoPerimetros) << " milisegundos" << endl;
    cout << "Tiempo Total de Ejecucion: " << totalEjecucion << " milisegundos" << endl;
    return 0;
}