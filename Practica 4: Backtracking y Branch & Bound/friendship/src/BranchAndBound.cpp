#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <queue>
#include "Apermutacion.h"
#include "MatrizDiscrepancias.h"


class nodo {
  public:
    int dactual;
    int CI;
    int DE;
    int CS;
    Apermutacion ab = Apermutacion(1);

    nodo(int d,int ci,int de,int cs, Apermutacion a) {
        dactual = d;
        CI = ci;
        DE = de;
        CS = cs;
        ab = a;
    }

    nodo() { };

    bool operator <(const nodo &n) const {
        return DE > n.DE;
    }
};


int Suma_Discrepancias(const Apermutacion &P, const vector <vector<int>> &B) {
    int suma = 0;
    int i = 0;
    Apermutacion::const_iterator it;

    cout << P << endl;
    cout << B << endl;

    for (it = P.begin(); it != P.end(); ++it) {
        if(i == *it-1){
            return numeric_limits<int>::max();
        }
        suma += B[i][*it - 1];
        ++i;
    }

    return suma;
}

bool contains(vector<int> v, int x) {
    if (std::find(v.begin(), v.end(), x) != v.end()) {
        return true;
    } else {
        return false;
    }
}

int buscarPareja(int x, vector <pair<int, int>> v) {
    for (pair<int, int> y: v) {
        if (y.second == x) {
            return y.first;
        }
    }
    return -1;
}

vector<vector<int>> obtenerNoAsignados(const vector<vector<int>> &O, const Apermutacion &A) {
    vector<vector<int>> noAsignados;
    vector<int> asignados;
    asignados.push_back(A.GetLevel());
    Apermutacion::const_iterator it;
    for(it = A.begin(); it != A.end(); ++it) {
        asignados.push_back(*it-1);
    }

    for(int i = 0 ; i < O.size(); i++) {
        if(!contains(asignados,i)) {
            noAsignados.push_back(O[i]);
        }
    }

    return noAsignados;
}

vector<int> getNoAsignados(int i, vector<int> v) {
    vector<int> noAsignados;
    for(int j = 0; j <=i ; j++) {
        if(!contains(v,j)) {
            noAsignados.push_back(j);
        }
    }
    return noAsignados;
}

int cotaSuperior(const vector<vector<int>> &matriz, vector<int> asignados) {
    vector <pair<int, int>> sol;
    vector<int> selec;
    vector<int> noAsignados= getNoAsignados(matriz.size()-1,asignados);
    int max = numeric_limits<int>::max();
    int per1, per2, min;

    for (int i: noAsignados) {
        per1=i;
        min = max;

        if (!contains(selec, per1)) {
            for (int j: noAsignados) {
                if (matriz[per1][j] < min && !contains(selec, j)) {
                    min = matriz[per1][j];
                    per2 = j;
                }
            }
        } else {
            per2 = buscarPareja(per1, sol);
        }

        selec.push_back(per1);
        selec.push_back(per2);
        sol.push_back(make_pair(per1, per2));
    }

    int disc = 0;
    for (int k = 0; k < sol.size(); ++k) {
        disc += matriz[sol[k].first][sol[k].second];
    }

    return disc;
}

int cotaInferior(const vector<vector<int>> &matriz, vector<int> asignados) {
    vector <pair<int, int>> sol;

    vector<int> noAsignados = getNoAsignados(matriz.size()-1,asignados);

    int max = numeric_limits<int>::max();
    int per1, per2, min;

    for (int i: noAsignados) {
        per1 = i;
        min = max;

        for (int j: noAsignados) {
            if (matriz[per1][j] < min) {
                min = matriz[per1][j];
                per2 = j;
            }
        }
        sol.push_back(make_pair(per1, per2));
    }

    int disc = 0;
    for (int k = 0; k < sol.size(); ++k) {
        disc += matriz[sol[k].first][sol[k].second];
    }

    return disc;
}

vector<int> obtenerAsignaciones(const Apermutacion &P) {
    vector<int> asignados;
    Apermutacion::const_iterator it;

    for (it = P.begin(); it != P.end(); ++it) {
        asignados.push_back(*it-1);
    }

    int i = P.GetLevel();

    while(i>=0) {
        asignados.push_back(i);
        --i;
    }
    sort(asignados.begin(), asignados.end());

    return asignados;
}

int asignParejas(int n, Apermutacion &ab, const vector <vector<int>> &D) {
    Apermutacion P(n);
    Apermutacion mejor_permutacion(n);
    vector<int> asignados(0);
    int CI = cotaInferior(D,asignados);
    int CS = cotaSuperior(D,asignados);
    int C = CS;
    int DE = (CI+CS)/2;
    int dactual = 0;
    int best_discrepancia = numeric_limits<int>::max();
    int nodos_recorridos = 0;
    bool seguir = true;
    priority_queue<nodo> pq;

    do {
        asignados = obtenerAsignaciones(P);
        dactual = Suma_Discrepancias(P,D)*2;
        CI = dactual + cotaInferior(D,asignados);
        if(CI <= C ) { //Si lo mejor es peor que la cota podamos
            CS = dactual + cotaSuperior(D,asignados);

            DE = (CI+CS)/2;
            C = (C < CS)?C:CS;
            nodo a(dactual,CI,DE,CS,P);
            pq.push(a); //Aniadimos el nodo a la cola
        }

        P.GeneraSiguienteAnchura();
        if(P.GetLevel() > 0) seguir = false;
    } while(seguir);


    while(!pq.empty()) { //Mientras queden nodos
        nodo nn = pq.top();
        pq.pop();
        nodos_recorridos++;

        if(nn.CI <= C) { //Si lo mejor es peor que la cota podamos
            vector<vector<int>> hijos = nn.ab.GeneraHijos();

            for(int i = 0 ;  i < hijos.size(); i++) {
                Apermutacion H(hijos[i],nn.ab.GetLevel()+1);
                dactual = Suma_Discrepancias(H,D)*2;
                asignados = obtenerAsignaciones(H);
                CS = dactual + cotaSuperior(D,asignados);
                CI = dactual + cotaInferior(D,asignados);
                DE = (CI+CS)/2;

                if(H.GetLevel() == n/2 -1 && dactual < best_discrepancia) {
                    cout << "NIVEL: " << H.GetLevel() << endl;
                    cout << asignados.size()<< endl;
                    best_discrepancia = dactual;
                    if(C > dactual) C = dactual;
                    mejor_permutacion = H;
                } else {
                    if(CI <= C) {
                        nodo nuevo(dactual,CI,DE,CS,H);
                        pq.push(nuevo);
                        if(C > CS) C = CS;
                    }
                }
            } // for
        } // if
    } //while

    int total = P.NumeroSecuenciasPosibles();

    cout << "Numero de nodos recorridos " << nodos_recorridos
         << " ,total nodos " << total
         << " ,Porcentaje " << (nodos_recorridos / (double) total) * 100.0 << endl;

    ab = mejor_permutacion;
    cout << ab << endl;

    return best_discrepancia;
}

void printSolucion(const Apermutacion &P) {
    int i = 1;
    Apermutacion::const_iterator it;

    vector<pair<int,int>> aux;

    for (it = P.begin(); it != P.end(); ++it) {
        cout << "Persona: " << i << " con persona: " << *it << endl;
        aux.push_back(make_pair(*it,i));
        i++;
    }

    /* for(pair<int,int> i: aux) {
         cout << "Persona: " << i.first << " con persona: " << i.second << endl;
     }*/
}

void sintaxis() {
    cerr << "Sintaxis:" << endl;
    cerr << "  ./bactb archivo_gustos.txt" << endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        sintaxis();
    }

    ifstream f(argv[1]);

    vector <vector<int>> matriz = matrizDiscrepancias(f);
    Apermutacion P(matriz.size());

    cout << matriz << endl;

    int discrepancia = asignParejas(matriz.size(), P, matriz);

    cout << "\nDiscrepancia con Branch & Bound: " << discrepancia << endl << endl;

    printSolucion(P);

}




