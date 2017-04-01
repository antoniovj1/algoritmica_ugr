#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>   // Recursos para medir tiempos
#include <utility>
#include <vector>

#include <queue>

using namespace std;
using namespace std::chrono;

//Obtiene el maximo y el minimo de un vector O(n)
pair<int,int> moda(const vector<int> &v) {

    int pivote = v.at(0);
    vector<int> heterogeneo,homogeneo;

    vector<vector<int> > grupos_homogeneos;
    do {
        for(int i: v) {
            if(i < pivote || i > pivote) {
                heterogeneo.push_back(i);
            } else {
                homogeneo.push_back(i);
            }
        }
    }while(heterogeneo.size() > homogeneo.size());



}

void sintaxis() {
    cerr << "Sintaxis:" << endl;
    cerr << "  TAM: Tamaño del vector (>0)" << endl;
    exit(EXIT_FAILURE);
}

void inicializar(vector<int> &v, int tam) {
    for (int i = 0; i < tam; i++)
        v.push_back(rand());
}

int main(int argc, char * argv[]) {
    // Lectura de parámetros
    if (argc!=2)
        sintaxis();
    int tam=atoi(argv[1]);     // Tamaño del vector
    if (tam<=0)
        sintaxis();

    // Generación del vector aleatorio
    vector<int> v;
    srand(time(0));
    inicializar(v,tam);

    high_resolution_clock::time_point start,//punto de inicio
                          end; //punto de fin
    duration<double> tiempo_transcurrido;  //objeto para medir la duracion de end 						   // y start

    start = high_resolution_clock::now(); //iniciamos el punto de inicio
    moda(v);
    end = high_resolution_clock::now(); //anotamos el punto de de fin

    //el tiempo transcurrido es
    tiempo_transcurrido += duration_cast<duration<double> >(end - start);

    // Mostramos resultados
    //cout << "MAX: " << p.first << " , MIN: " << p.second << endl;
    cout << tam << "\t" <<tiempo_transcurrido.count() << endl;

}
