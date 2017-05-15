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


pair<char,int> minimo(pair<char,int> n, pair<char,int> s,
                      pair<char,int> r, pair<char,int> m,
                      pair<char,int> d) {

    if(n.second <= s.second && n.second <= r.second && n.second <= m.second && n.second <= d.second ) {
        // cout << "A veces la mejor decisión es no tomar ninguna decisión, y esa es también una decisión" << endl;
        return n;
    } else if (s.second <= r.second && s.second <= m.second && s.second <= d.second) {
        // cout << "SUMAR " << endl;
        return s;

    } else if (r.second <= m.second && r.second <= d.second) {
        // cout << "RESTAR " << endl;
        return r;

    } else if (m.second <= d.second) {
        // cout << "MULTIPLICAR "<< endl;
        return m;

    } else {
        // cout << "DIVIDIR " << endl;
        return d;
    }
}

vector<pair<char,int> > rellenarTabla(vector<vector<pair<char,int> > > &tabla, vector<int> c, int obj) {

    int limit = std::numeric_limits<int>::max();
    pair<char,int> nada,suma,resta,multiplicacion,division,MIN;

    for(unsigned int i = 0; i< tabla[0].size(); i++) {
        tabla[0][i].second = i;
        tabla[0][i].first = '.';
    }

    for(int i = 1; i < tabla.size(); i++) {
        for( int j = 0; j < tabla[i].size(); j++) {
            if(i == 0) {
                tabla[i][j].second = 0;
                tabla[i][j].first = '.';
            } else if (c[i] == 0) {
                tabla[i][j].second = j;
                tabla[i][j].first = '.';

            } else {

                nada.second = tabla[i-1][j].second;
                nada.first = '.';

                if(j-c[i] < 0) {
                    suma.second = limit;
                    suma.first = '+';
                } else {
                    suma.second = tabla[i-1][j-c[i]].second;
                    suma.first = '+';
                }

                if(j+c[i] >= tabla[0].size()-1) {
                    resta.second = limit;
                    resta.first = '-';
                } else {
                    resta.second = tabla[i-1][j+c[i]].second;
                    resta.first = '-';
                }

                if(j*c[i] >= tabla[0].size()-1) {
                    division.second = limit;
                    division.first = '/';
                } else {
                    division.second = tabla[i-1][j*c[i]].second;
                    division.first = '/';
                }

                if(j%c[i] != 0) {
                    multiplicacion.second = limit;
                    multiplicacion.first = '*';
                } else {
                    multiplicacion.second = tabla[i-1][j/c[i]].second;
                    multiplicacion.first = '*';
                }

                MIN = minimo(nada,suma,resta,division,multiplicacion);

                tabla[i][j] = MIN;
            }
        }
    }

    vector <pair<char,int> > solucion;

    //recomponer la solución
    int i,j;
    i = c.size()-1;
    j = obj;

    while(j != 0 && i != 0) {
        if(tabla[i-1][j].second == tabla[i][j].second) {
            i = i -1;
        } else {
            solucion.push_back(make_pair(tabla[i][j].first, c[i]));
            j = j-c[i];
            i = i -1;
        }
    }

    return solucion;
}

void imprimir(vector<vector<pair<char,int> > > tabla_solucion, vector<int> candidatos, vector<pair<char,int> >sol,int objetivo) {
    cout << "\n ---> Matriz solución:\n\n";

    cout << "      ";
    for ( unsigned int i = 0 ; i < tabla_solucion[0].size() ; i++ ) {
        cout <<  setw(5) << " m=" + to_string(i);
    }

    cout << endl;

    for ( unsigned int i = 0 ; i < tabla_solucion.size() ; i++ ) {
        cout << left << setw(8) << "k = " + to_string(candidatos[i]);
        for( unsigned int j = 0; j < tabla_solucion[i].size(); j++) {
            cout <<setw(4) << tabla_solucion[i][j].first + to_string(tabla_solucion[i][j].second) << " ";
        }
        cout << endl;
    }

    cout << "\nObjetivo: " << objetivo;
    cout << "\nSolucion: { ";
    int obtenido = 0;
    for (int i = 0; i < sol.size(); i++) {
        if(i == sol.size()-1) {
            cout <<" " << sol[i].second  << " ";
            obtenido = sol[i].second;
        } else {
            cout << sol[i].second <<" " << sol[i].first  << " ";
        }
    }

    cout << "} " << endl;
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
      //PARA MEDIR TIEMPOS

      std::vector<int> candidatos;
      candidatos.push_back(0);

      int objetivo;

      if (argc!=2)
          sintaxis();

      int tam = atoi(argv[1]);     // n_candidatos

      for(int i = 0; i < tam; i++) {
          candidatos.push_back(1);
      }

      objetivo =  tam;
      int max = *max_element(candidatos.begin(), candidatos.end());

      vector<vector<pair<char,int> > > tabla_solucion(candidatos.size());
      for ( unsigned int i = 0 ; i < candidatos.size() ; i++ )
          tabla_solucion[i].resize(max*objetivo+1);

      high_resolution_clock::time_point start, end;
      duration<double> tiempo_transcurrido;

      start = high_resolution_clock::now();

      vector <pair <char,int> > sol = rellenarTabla(tabla_solucion,candidatos,objetivo);

      end = high_resolution_clock::now();

      tiempo_transcurrido = duration_cast<duration<double> >(end - start);

      cout << tam << "\t" <<tiempo_transcurrido.count() << endl;
      **/
    /**/
    if(argc != 3) {
        sintaxis(1);
    }

    std::vector<int> candidatos;
    candidatos.push_back(0);

    int objetivo = atoi(argv[2]);

    std::ifstream infile(argv[1]);
    int i;

    while(infile >> i) {
        candidatos.push_back(i);
    }

    int max = *max_element(candidatos.begin(), candidatos.end());

    vector<vector<pair<char,int> > > tabla_solucion(candidatos.size());
    for ( unsigned int i = 0 ; i < candidatos.size() ; i++ )
        tabla_solucion[i].resize(max*objetivo+1);

    vector <pair <char,int> > sol = rellenarTabla(tabla_solucion,candidatos,objetivo);

    imprimir(tabla_solucion,candidatos,sol,objetivo);
    /**/
}