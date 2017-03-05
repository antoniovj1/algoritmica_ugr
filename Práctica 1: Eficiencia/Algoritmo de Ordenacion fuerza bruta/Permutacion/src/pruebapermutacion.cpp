#include "permutacion.h"
#include <vector>
#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>   // Recursos para medir tiempos
using namespace std;
using namespace std::chrono;

bool isOrdenadoPermutacion(const int *v, const Permutacion &perm , int tam ) {
    bool ordenado = true;
    const vector<unsigned int> s= (*(perm.begin()));

    for (unsigned int i=0;i<s.size()-1 && ordenado;i++){
        if(v[s[i]-1] > v[s[i+1]-1]){
            ordenado = false;
        }
    }

    return ordenado;
}

void permutacion(int *v, Permutacion &per ,int tam){
    bool ordenado = false;
    do {
        ordenado = isOrdenadoPermutacion(v,per,tam);
    } while (!ordenado && per.GeneraSiguiente());
}

void sintaxis() {
    cerr << "Sintaxis:" << endl;
    cerr << "  TAM: Tamaño del vector (>0)" << endl;
    cerr << "  Caso: 1 -> Mejor 2 -> Peor 3 -> Promedio" << endl;
    exit(EXIT_FAILURE);
}

void inicializar(int *v, int tam, int caso) {
    switch (caso) {
        case 1:
        for (int i = 0; i < tam; i++)
            v[i] = i;
        break;

        case 2:
        for (int i = 0; i < tam; i++)
            v[i] = tam - i;
        break;

        case 3:
        for (int i = 0; i < tam; i++)
            v[i] = rand();
        break;
    }
}

int main(int argc, char * argv[]) {
    // Lectura de parámetros
    if (argc!=3)
        sintaxis();
    int tam=atoi(argv[1]);     // Tamaño del vector
    int caso=atoi(argv[2]);    // Valor máximo
    if (tam<=0 || (caso!=1 && caso !=2 && caso != 3))
        sintaxis();

    // Generación del vector aleatorio
    int *v=new int[tam];       // Reserva de memoria
    
    srand(time(0));
    inicializar(v,tam,caso);

    high_resolution_clock::time_point start,//punto de inicio
    end; //punto de fin
    duration<double> tiempo_transcurrido;  //objeto para medir la duracion de end 						   // y start


    //En el caso promedio se ejecuta varias veces y se hace la media
    int veces = (caso == 3 )? 5 : 1;

    for (int i = 0 ; i < veces  ; i++) {
        Permutacion per(tam);
        if(caso == 3) {
            Permutacion per(tam);
            inicializar(v,tam,caso);
        } 
            
        start = high_resolution_clock::now(); //iniciamos el punto de inicio

        permutacion(v,per,tam);

        end = high_resolution_clock::now(); //anotamos el punto de de fin
        //el tiempo transcurrido es
        tiempo_transcurrido += duration_cast<duration<double> >(end - start);
    }

     tiempo_transcurrido /= veces;

    // Mostramos resultados
    cout << tam << "\t" <<tiempo_transcurrido.count() << endl;

    delete [] v;     // Liberamos memoria dinámica
}
