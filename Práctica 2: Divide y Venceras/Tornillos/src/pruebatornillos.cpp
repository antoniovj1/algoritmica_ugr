#include <vector>
#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>   // Recursos para medir tiempos
#include <algorithm> 
#include <utility>

using namespace std;
using namespace std::chrono;


vector<pair<int,int> > agrupartt(vector<int> &tornillos, vector<int> &tuercas){
    
    //Caso base
    if(tornillos.size() <= 1) {
        vector<pair<int,int> > tt;
        if(tornillos.size() == 1){
            pair<int,int> tornillo_tuerca(tornillos.at(0),tuercas.at(0));
            tt.push_back(tornillo_tuerca);
        }
        return tt;
    } else {

        int tornillo_pivote = tornillos.at((int)tornillos.size()/2);
        vector<int> tuercas_menores,tuercas_mayores,tuerca_igual;

        for(int i: tuercas){
            if(i < tornillo_pivote){
                tuercas_menores.push_back(i);
            } else if (i > tornillo_pivote){
                tuercas_mayores.push_back(i);
            } else {
                tuerca_igual.push_back(i);
            }
        }

        int tuerca_pivote = tuerca_igual.at(0);
        vector<int> tornillos_menores,tornillos_mayores,tornillo_igual;

        for(int i: tornillos){
            if(i < tuerca_pivote){
                tornillos_menores.push_back(i);
            } else if (i > tuerca_pivote){
                tornillos_mayores.push_back(i);
            } else {
                tornillo_igual.push_back(i);
            }
        }

        vector<pair<int,int> > tt1,tt2,tt3;

        //Llamadas recursivas
        tt1 = agrupartt(tornillo_igual,tuerca_igual);
        tt2 = agrupartt(tornillos_mayores,tuercas_mayores);
        tt3 = agrupartt(tornillos_menores,tuercas_menores);

        //Recomponer la solución
        vector<pair<int,int> > tornillos_tuercas;
        tornillos_tuercas.insert(tornillos_tuercas.end(),tt1.begin(),tt1.end());
        tornillos_tuercas.insert(tornillos_tuercas.end(),tt2.begin(),tt2.end());
        tornillos_tuercas.insert(tornillos_tuercas.end(),tt3.begin(),tt3.end());

        return tornillos_tuercas;
    }
}

void sintaxis() {
    cerr << "Sintaxis:" << endl;
    cerr << "  TAM: Tamaño del vector (>0)" << endl;
    exit(EXIT_FAILURE);
}

void inicializar(vector<int> &tornillos , vector<int> &tuercas, int tam) {
    for (int i = 0; i < tam; i++){        
        tornillos.push_back(i);
        tuercas.push_back(i);
    }
    random_shuffle(tuercas.begin(), tuercas.end());
}

int main(int argc, char * argv[]) {
    // Lectura de parámetros
    if (argc!=2)
        sintaxis();
    int tam=atoi(argv[1]);     // Tamaño del vector
    if (tam<=0)
        sintaxis();

    // Generación del vector aleatorio
    vector<int> tornillos,tuercas;       // Reserva de memoria
    
    srand(time(0));
    inicializar(tornillos,tuercas,tam);

    high_resolution_clock::time_point start,//punto de inicio
    end; //punto de fin
    duration<double> tiempo_transcurrido;  //objeto para medir la duracion de end 						   // y start
 
        start = high_resolution_clock::now(); //iniciamos el punto de inicio

        vector<pair<int,int> > tornillos_tuercas = agrupartt(tornillos, tuercas);

        end = high_resolution_clock::now(); //anotamos el punto de de fin
        //el tiempo transcurrido es
        tiempo_transcurrido += duration_cast<duration<double> >(end - start);

    for(pair<int,int> i: tornillos_tuercas){
        cout<< i.first << " , " << i.second << endl;    
    }

    // Mostramos resultados
    cout << tam << "\t" <<tiempo_transcurrido.count() << endl;

}
