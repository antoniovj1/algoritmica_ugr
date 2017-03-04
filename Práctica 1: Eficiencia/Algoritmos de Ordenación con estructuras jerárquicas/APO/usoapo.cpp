#include <iostream>
#include <cstdlib> // Para generación de números pseudoaleatorios
#include <chrono>  // Recursos para medir tiempos
#include "apo.h"

using namespace std;
using namespace std::chrono;

void ordenar(APO<int> &a)
{
    while(!a.vacio())
    {
	//os << aux.minimo() << " ";
	a.borrar_minimo();
    }
}

void sintaxis()
{
    cerr << "Sintaxis:" << endl;
    cerr << "  TAM: Número de elementos (>0)" << endl;
    cerr << "  Caso: 1 -> Mejor 2 -> Peor 3 -> Promedio" << endl;
    exit(EXIT_FAILURE);
}

void inicializar(APO<int> &a, int tam, int caso)
{
    switch (caso)
    {
    case 1:
	for (int i = 0; i < tam; i++)
	    a.insertar(i);
	break;

    case 2:
	for (int i = 0; i < tam; i++)
	    a.insertar(tam - i);
	break;

    case 3:
	for (int i = 0; i < tam; i++)
	    a.insertar(rand());
	break;
    }
}

int main(int argc, char *argv[])
{
    // Lectura de parámetros
    if (argc != 3)
	sintaxis();
    int tam = atoi(argv[1]);  // Tamaño del vector
    int caso = atoi(argv[2]); // Valor máximo
    if (tam <= 0 || (caso != 1 && caso != 2 && caso != 3))
	sintaxis();

    // Generación del vector aleatorio
    APO<int> a; // Reserva de memoria
    srand(time(0));
    inicializar(a, tam, caso);

    high_resolution_clock::time_point start, //punto de inicio
	end;				     //punto de fin
    duration<double> tiempo_transcurrido;    //objeto para medir la duracion de end 						   // y start

    //En el caso promedio se ejecuta varias veces y se hace la media
    int veces = (caso == 3 )? 15 : 1;
    
    for (int i = 0 ; i < veces; i++) {
        if(caso == 3) inicializar(v,tam,caso);

        start = high_resolution_clock::now(); //iniciamos el punto de inicio

        ordenar(a);

        end = high_resolution_clock::now(); //anotamos el punto de de fin
        //el tiempo transcurrido es
        tiempo_transcurrido += duration_cast<duration<double> >(end - start);
    }
    
    tiempo_transcurrido /= veces;
    // Mostramos resultados
    cout << tam << "\t" << tiempo_transcurrido.count() << endl;
}
