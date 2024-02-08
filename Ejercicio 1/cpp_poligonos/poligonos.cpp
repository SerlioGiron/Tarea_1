#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#define M_PI 3.14159265358979323846
using namespace std;

int main()
{
    // random.nextDouble()
    //  mt19937 rng(std::random_device{}());
    //  uniform_real_distribution<double> dist(0.0, 1.0);
    //  double random_number = dist(rng);
    //  cout << "Random double between 0.0 and 1.0: " << random_number << std::endl;

    int radius = 200;

    double puntos = 45;
    double angulo = 360 / puntos;

    double cont = 0;
    vector<double> angulos;

    angulos.push_back(cont);
    for (size_t i = 0; i < puntos; i++)
    {
        cont += angulo;
        angulos.push_back(cont);
    }

    vector<int> pointsx;
    vector<int> pointsy;
    for (double angle : angulos)
    {
        mt19937 rng(std::random_device{}());
        uniform_real_distribution<double> dist(0.0, 1.0);
        double random_number = dist(rng);

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
    for (size_t i = 0; i < pointsx.size(); i++)
    {
        double xUno, xDos, yUno, yDos, xCoordinate, yCoordinate, xSquared, ySquared, insideSum, squareRoot;
        xUno = pointsx.at(i);
        yUno = pointsy.at(i);
        if (i == pointsx.size() - 1)
        {
            xDos = pointsx.at(0);
            yDos = pointsy.at(0);
        }
        else
        {
            xDos = pointsx.at(i + 1);
            yDos = pointsy.at(i + 1);
        }
        cout << "Coordenadas " << i << ": (" << (xUno - 200) << ", " << (yUno - 200) << ") and (" << (xDos - 200) << ", " << (yDos - 200) << ")" << endl;
        xCoordinate = xDos - xUno;
        yCoordinate = yDos - yUno;

        xSquared = xCoordinate * xCoordinate;
        ySquared = yCoordinate * yCoordinate;

        insideSum = xSquared + ySquared;

        squareRoot = sqrt(insideSum);
        distanciaPerimetros.push_back(squareRoot);
        cout << "Distancia " << i << ": " << squareRoot << "\n" << endl;
    }

    double sumPerimetros = 0;
    for (size_t i = 0; i < distanciaPerimetros.size(); i++)
    {
        sumPerimetros += distanciaPerimetros.at(i);
    }
    double avgPerimetros = 0;
    avgPerimetros = sumPerimetros / distanciaPerimetros.size();

    cout << "El Promedio de los Perimetros Es: " << avgPerimetros << endl;

    return 0;
}
