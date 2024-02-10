#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <cmath>
#include <string>
#include <chrono>
#include <cstdint>
#include <ctime>
using namespace std::chrono;
using namespace std;

double tempPromedio1(double **matriz, int N)
{
    auto start = std::chrono::high_resolution_clock::now();
    double numerador = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            numerador += matriz[i][j];
        }
    }
    double promedio = numerador / pow(N, 2);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    elapsed = elapsed * 1000;
    std::cout << "Tiempo de calcular promedio: " << elapsed.count() << " ms" << std::endl;
    return promedio;
}

int imprimirMatriz(double **matriz, string mensaje, int N)
{
    double tempPromedio = tempPromedio1(matriz, N), desviaciones = 0.0;
    cout << "\n" + mensaje << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // cout << "[" << matriz[i][j] << "]\t";
            desviaciones += pow(matriz[i][j] - tempPromedio, 2);
        }
        // cout << "" << endl;
    }

    double desvEstandar = desviaciones / pow(N, 2);

    cout << "\nTemperatura promedio de la matriz: " << round(tempPromedio * 20.0) / 20.0 << endl;
    cout << "Desviación estándar: " << round(desvEstandar * 40.0) / 40.0 << "\n"
         << endl;
    return 0;
}

double **actualizarTemp(double **matriz, int T, int cont, int N)
{
    double **nuevamatriz = new double *[N];
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        nuevamatriz[i] = new double[N];
    }
    if (cont <= T)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                double numerador = 0, denominador = 0;
                for (int k = -1; k < 2; k++)
                {
                    for (int l = -1; l < 2; l++)
                    {
                        double peso = (double)1 / 8;

                        if (k == 0 && l == 0)
                        {
                            peso = (double)1 / 4;
                        }
                        else if (k == l || k + l == 2)
                        {
                            peso = (double)1 / 16;
                        }

                        if (i + k >= N || i + k < 0 || j + l >= N || j + l < 0)
                        {
                            peso = 1 / 4;
                            numerador += matriz[i][j] * peso;
                        }
                        else
                        {
                            numerador += matriz[i + k][j + l] * peso;
                        }

                        denominador += peso;
                    }
                }
                double promedio = numerador / denominador;
                *(*(nuevamatriz + i) + j) = round(promedio * 10.0) / 10.0;
            }
        }
        string men = "Paso: " + std::to_string(cont);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        elapsed = elapsed * 1000;
        std::cout << "Tiempo de actualizar temperatura: " << elapsed.count() << " ms" << std::endl;
        imprimirMatriz(matriz, men, N);
        actualizarTemp(nuevamatriz, T, ++cont, N);
    }
    return nuevamatriz;
}

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        cout << "Debe de ingresar 2 parametros" << endl;
        return 0;
    }
    int N = stoi(argv[1]);
    int T = stoi(argv[2]);
    double **matriz = new double *[N];

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    double random_number = dis(gen);

    for (int i = 0; i < N; i++)
    {
        matriz[i] = new double[N];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            double random_number = dis(gen);
            double temperatura = -30.0 + (random_number * 70.0);
            *(*(matriz + i) + j) = round(temperatura * 10.0) / 10.0;
        }
    }
    auto start = std::chrono::high_resolution_clock::now();
    actualizarTemp(matriz, T, 1, N);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    elapsed = elapsed * 1000;
    std::cout << "Tiempo de ejecución: " << elapsed.count() << " ms" << std::endl;
    return 0;
}
