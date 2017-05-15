#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <string>


using namespace std;
using namespace std::chrono;


vector<int> solucion_voraz(vector<int> candidatos, int obj) {
    vector<int> solucion;
    int acumulado = 0;

    sort(candidatos.begin(),candidatos.end());
    reverse(candidatos.begin(),candidatos.end());

    for(int i: candidatos) {       //selecion
        if(acumulado+i <= obj) {   //factible
            solucion.push_back(i); //aniadir
            acumulado+=i;
        }

        if(acumulado == obj)
            break;
    }

    return solucion;
}

void sintaxis(int i=0) {
    if(i==1) {
        cerr << "Sintaxis:" << endl;
        cerr << "  Archivo_candidatos Objetivo " << endl;
    } else {
        cerr << "Sintaxis:" << endl;
        cerr << "  Numero_de_candidatos" << endl;
    }
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    /**
     vector<int> candidatos;

    int objetivo;

    if (argc!=2)
        sintaxis();

    int tam=atoi(argv[1]);     // n_candidatos

    for(int i = 0; i < tam; i++) {
    candidatos.push_back(1);
    }

    objetivo =  tam*2;

    high_resolution_clock::time_point start, end;
    duration<double> tiempo_transcurrido;

    start = high_resolution_clock::now();
    vector<int> solucion = solucion_voraz(candidatos,objetivo);
    end = high_resolution_clock::now();

    tiempo_transcurrido = duration_cast<duration<double> >(end - start);

    cout << tam << "\t" <<tiempo_transcurrido.count() << endl;
    **/
    /**/
    if (argc!=3)
        sintaxis(1);

    int objetivo = atoi(argv[2]);

    vector<int> candidatos;

    ifstream infile(argv[1]);
    int i;

    while(infile >> i) {
        candidatos.push_back(i);
    }

    vector<int> solucion = solucion_voraz(candidatos,objetivo);

    cout<<"Solucion: { ";
    for(int i: solucion) {
        cout << i << " ";
    }
    cout << "}";
    cout << "\nSuma: "<<accumulate(solucion.begin(),solucion.end(),0)<< " ---- Objetivo: " << objetivo << endl;
    /**/
}