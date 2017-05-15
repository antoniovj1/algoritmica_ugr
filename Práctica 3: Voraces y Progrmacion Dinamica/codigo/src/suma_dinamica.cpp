#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;
using namespace std::chrono;


vector<int> rellenarTabla(vector<vector<int> > &tabla, vector<int> c, int obj) {
    for(unsigned int i = 0; i< tabla[0].size(); i++) {
        tabla[0][i] = i;
    }

    for(unsigned int i = 1; i < tabla.size(); i++) {
        for( unsigned int j = 0; j < tabla[i].size(); j++) {
            if(i == 0) {
                tabla[i][j] = 0;
            } else if (c[i] == 0) {
                tabla[i][j] = j;
            } else if (c[i] > int(j)) {
                tabla[i][j] = tabla[i-1][j];
            } else {
                tabla[i][j] = min( tabla[i-1][j], tabla[i-1][j-c[i]]);
            }
        }
    }

    vector <int> solucion;

    int i,j;
    i = c.size()-1;
    j = obj;

    //recomponer la solución
    while(j != 0 && i != 0) {
        if(tabla[i-1][j] == tabla[i][j]) {
            i = i -1;
        } else {
            solucion.push_back(c[i]);
            j = j-c[i];
            i = i -1;
        }
    }

    return solucion;
}

void imprimir(vector<vector<int> > tabla_solucion, vector<int> candidatos, vector<int> sol,int objetivo) {
    cout << "\n ---> Matriz solución:\n\n";

    cout << "      ";
    for ( unsigned int i = 0 ; i < tabla_solucion[0].size() ; i++ ) {
        cout <<  setw(5) << " m=" + to_string(i);
    }

    cout << endl;

    for ( unsigned int i = 0 ; i < tabla_solucion.size() ; i++ ) {
        cout << left << setw(8) << "k = " + to_string(candidatos[i]);
        for( unsigned int j = 0; j < tabla_solucion[i].size(); j++) {
            cout <<setw(4) << tabla_solucion[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nObjetivo: " << objetivo;
    cout << "\nSolucion: { ";
    int obtenido = 0;
    for(int i: sol) {
        cout << i << " ";
        obtenido+=i;
    }
    cout << "} == " <<obtenido << endl;
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
    std::vector<int> candidatos;
    candidatos.push_back(0);

     int objetivo;

     if (argc!=2)
         sintaxis();

     int tam=atoi(argv[1]);     // n_candidatos

     for(int i = 0; i < tam; i++) {
         candidatos.push_back(1);
     }

     objetivo =  tam;

     vector<vector<int> > tabla_solucion(candidatos.size());
     for ( unsigned int i = 0 ; i < candidatos.size() ; i++ )
         tabla_solucion[i].resize(objetivo+1);


      high_resolution_clock::time_point start, end;
      duration<double> tiempo_transcurrido;

      start = high_resolution_clock::now();

      vector <int> sol= rellenarTabla(tabla_solucion,candidatos,objetivo);

      end = high_resolution_clock::now();

      tiempo_transcurrido = duration_cast<duration<double> >(end - start);

      cout << tam << "\t" <<tiempo_transcurrido.count() << endl;
      **/

    /**/
    if (argc!=3)
        sintaxis(1);

    std::vector<int> candidatos;
    candidatos.push_back(0);

    int objetivo = atoi(argv[2]);

    std::ifstream infile(argv[1]);
    int i;

    while(infile >> i) {
        candidatos.push_back(i);
    }

    vector<vector<int> > tabla_solucion(candidatos.size());
    for ( unsigned int i = 0 ; i < candidatos.size() ; i++ )
        tabla_solucion[i].resize(objetivo+1);

    vector <int> sol= rellenarTabla(tabla_solucion,candidatos,objetivo);

    imprimir(tabla_solucion,candidatos,sol,objetivo);

    /**/
}