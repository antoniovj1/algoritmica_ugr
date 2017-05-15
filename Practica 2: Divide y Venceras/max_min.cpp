#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>   // Recursos para medir tiempos
#include <utility>
#include <vector>

using namespace std;
using namespace std::chrono;

//Obtiene el maximo y el minimo de un vector O(n)
pair<int,int> max_min(const vector<int> &v){

    //Caso base -> El vector tiene solo un elemento
    if(v.size() == 1){
        return pair<int,int> (v[0],v[0]);
    } else {

        //Dividimos en dos mitades
        vector<int> v1(v.begin(), v.begin() + v.size()/2),
               v2(v.begin() + v.size()/2, v.end());
        
        //Llamadas recursivas 
        pair<int,int> m1 = max_min(v1);
        pair<int,int> m2 = max_min(v2);

        pair<int,int> result;
        //Recomponemos la solucion
        result.first = (m1.first > m2.first) ? result.first = m1.first : result.first = m2.first;
        result.second = (m1.second < m2.second) ? result.second = m1.second : result.second = m2.second;

        return result;
    }
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
        pair<int,int> p = max_min(v);
    end = high_resolution_clock::now(); //anotamos el punto de de fin
        
    //el tiempo transcurrido es
    tiempo_transcurrido += duration_cast<duration<double> >(end - start);
    
    // Mostramos resultados
    cout << "MAX: " << p.first << " , MIN: " << p.second << endl;
    cout << tam << "\t" <<tiempo_transcurrido.count() << endl;

}
