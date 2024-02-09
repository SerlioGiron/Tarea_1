#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include <string>
#define M_PI 3.14159265358979323846
using namespace std;

double randomNextDouble()
{
    mt19937 rng(std::random_device{}());
    uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng);
}

int main(int argc, char *argv[])
{

    // For de M Poligonos
    for (size_t mPoligonos = 0; mPoligonos < std::stoi(argv[1]); mPoligonos++) {
        
        int radius = 200;
        double puntos = std::stoi(argv[2]);
        double angulo = 360 / puntos;
        double cont = 0;

        vector<double> angulos;

        angulos.push_back(cont);
        for (size_t i = 0; i < puntos; i++) {
            cont += angulo;
            angulos.push_back(cont);
        }

        vector<int> pointsx;
        vector<int> pointsy;
        for (double angle : angulos) {
            double random_number = randomNextDouble();
            double randonNumber_alterar = 0.01 + random_number * 0.99;
            double angle_radians = angle * M_PI / 180.0;
            int x = (randonNumber_alterar * radius * cos(angle * M_PI / 180.0));
            int y = (randonNumber_alterar * radius * sin(angle * M_PI / 180.0));
            x += 200;
            y += 200;
            pointsx.push_back(x);
            pointsy.push_back(y);
        }

        vector<double> distanciaPerimetros;
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
            // std::cout << "Coordenadas " << i << ": (" << (xUno - 200) << ", " << (yUno - 200) << ") and (" << (xDos - 200) << ", " << (yDos - 200) << ")" << endl;
            xCoordinate = xDos - xUno;
            yCoordinate = yDos - yUno;
            xSquared = xCoordinate * xCoordinate;
            ySquared = yCoordinate * yCoordinate;
            insideSum = xSquared + ySquared;
            squareRoot = sqrt(insideSum);

            distanciaPerimetros.push_back(squareRoot);
            std::cout << "Distancia " << i << ": " << squareRoot << "\n" << endl;
        }

        double sumPerimetros = 0;
        for (size_t i = 0; i < distanciaPerimetros.size(); i++) {
            sumPerimetros += distanciaPerimetros.at(i);
        }
        double avgPerimetros = 0;
        avgPerimetros = sumPerimetros / distanciaPerimetros.size();
        std::cout << "El Promedio de los Perimetros En El Poligono " << mPoligonos + 1 << " Es: " << avgPerimetros << endl;
    }
    return 0;
}
