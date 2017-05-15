#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <string>
#include <utility>
#include <limits>
#include <cmath>

using namespace std;
using namespace std::chrono;


float calculado(vector<int> elementos) {

    if(elementos.size() == 0) {
        return 0;
    }

    float total = elementos[1];

    for(unsigned int i = 2; i < elementos.size(); i+=2) {
        switch(elementos[i]) {
        case 0:
            total += elementos[i+1];
            break;
        case 1:
            total -= elementos[i+1];
            break;
        case 2:
            total *= elementos[i+1];
            break;
        case 3:
            total /= elementos[i+1];
            break;

        }
    }

    return total;
}

void factible(vector<int> &sol, int candidato, int obj, int &acumulado) {

    int n = abs(obj - acumulado);
    int s = abs(obj - (candidato + acumulado));
    int r = abs(obj - (candidato - acumulado));
    int m = abs(obj - (candidato * acumulado));
    int d;
    if(candidato != 0 && acumulado != 0 && acumulado%candidato == 0) {
        d = abs(obj - int(acumulado/candidato));
    } else {
        d = numeric_limits<int>::max();
    }

    //cout << "Acumulado " << acumulado << endl;

    if(n <= s && n <= r && n <= m && n <= d ) {
        // cout << "A veces la mejor decisión es no tomar ninguna decisión, y esa es también una decisión" << endl;
    } else if (s <= r && s <= m && s <= d) {
        sol.push_back(0);
        sol.push_back(candidato);
        acumulado+=candidato;
        // cout << "SUMAR " << candidato << endl;

    } else if (r <= m && r <= d) {
        sol.push_back(1);
        sol.push_back(candidato);
        acumulado-=candidato;
        // cout << "RESTAR " << candidato << endl;

    } else if (m <= d) {
        sol.push_back(2);
        sol.push_back(candidato);
        acumulado*=candidato;
        // cout << "MULTIPLICAR "<< candidato << endl;

    } else {
        sol.push_back(3);
        sol.push_back(candidato);
        acumulado/=candidato;
        // cout << "DIVIDIR " << candidato << endl;
    }

    return;
}

vector<int> solucion_voraz(vector<int> &candidatos, int obj) {
    vector<int> solucion;
    int acumulado = 0;
    bool fin = false;

    for(unsigned int i = 0; i < candidatos.size() && !fin; i++) {
        factible(solucion,candidatos[i],obj,acumulado);

        if(acumulado == obj)
            fin = true;
    }
    return solucion;
}

void imprimir(vector<int> elementos, int objetivo) {
    cout<<"Solucion: ";

    if(elementos.size() == 0) {
        cout << 0 << endl;
    }

    for(unsigned int i = 1; i < elementos.size(); i++) {
        if(i%2 == 0) {
            switch(elementos[i]) {
            case 0:
                cout << " + ";
                break;
            case 1:
                cout << " - ";
                break;
            case 2:
                cout << " * ";
                break;
            case 3:
                cout << " / ";
                break;
            }
        } else {
            cout << elementos[i];
        }
    }

    cout << endl;
    cout << "Obtenido: "<<calculado(elementos) << " ---- Objetivo: " << objetivo <<endl;

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
     candidatos.push_back(0);

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
    if(argc != 3) {
        sintaxis(1);
    }

    int objetivo = atoi(argv[2]);

    vector<int> candidatos;
    candidatos.push_back(0);

    ifstream infile(argv[1]);
    int i;

    while(infile >> i) {
        candidatos.push_back(i);
    }

    vector<int> solucion = solucion_voraz(candidatos,objetivo);

    imprimir(solucion,objetivo);
    /**/
}