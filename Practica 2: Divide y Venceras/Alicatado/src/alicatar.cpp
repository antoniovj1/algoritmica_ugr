#include "imagen.h"
#include "paleta.h"
#include <fstream>
#include <utility>
#include <vector>
#include <chrono>   // Recursos para medir tiempos
#include <iomanip>

using namespace std::chrono;

int cuadrante(int x, int y, int lado, pair<int,int> desague) {
    if(desague.first-x < (int)lado/2) {
        if(desague.second-y < (int)lado/2) {
            return 1;
        } else {
            return 2;
        }
    } else {
        if(desague.second-y < (int)lado/2) {
            return 3;
        } else {
            return 4;
        }
    }
}


void alicatar(vector<vector<int> > &suelo, pair<int,int> desague, pair<int,int> esq, int lado=-1) {
    static int count = 0;
    int x,y;
    x = esq.first;
    y = esq.second;

    count++;

    if(lado == -1) {
        x = 0;
        y = 0;
        lado = suelo.at(0).size();
        suelo[desague.first][desague.second] = -1 ;
    }

    //CASO BASE
    if(lado == 2) {
        for(int i=0; i < 2; i++)
            for(int j=0; j <2 ; j++ )
                if(suelo.at(i+x).at(j+y) == 0)
                    suelo.at(i+x).at(j+y) = count;

        return;

        //LLAMADAS RECURSIVAS
    } else {

        int cua = cuadrante(x,y,lado,desague);
        int nlado = lado/2;

        pair<int,int> esq1(x, y);
        pair<int,int> des1(x+nlado-1,y+nlado-1);

        pair<int,int> esq2(x, y+nlado);
        pair<int,int> des2(x+nlado-1,y+nlado);

        pair<int,int> esq3(x+nlado, y);
        pair<int,int> des3(x+nlado,y+nlado-1);

        pair<int,int> esq4(x+nlado, y+nlado);
        pair<int,int> des4(x+nlado, y+nlado);

        if(cua == 1) {
            suelo.at(des2.first).at(des2.second) = count;
            suelo.at(des3.first).at(des3.second) = count;
            suelo.at(des4.first).at(des4.second) = count;

            alicatar(suelo,desague,esq1,nlado);
            alicatar(suelo,des2,esq2,nlado);
            alicatar(suelo,des3,esq3,nlado);
            alicatar(suelo,des4,esq4,nlado);

        } else if (cua == 2) {
            suelo.at(des1.first).at(des1.second) = count;
            suelo.at(des3.first).at(des3.second) = count;
            suelo.at(des4.first).at(des4.second) = count;

            alicatar(suelo,des1,esq1,nlado);
            alicatar(suelo,desague,esq2,nlado);
            alicatar(suelo,des3,esq3,nlado);
            alicatar(suelo,des4,esq4,nlado);

        } else if (cua == 3) {
            suelo.at(des1.first).at(des1.second) = count;
            suelo.at(des2.first).at(des2.second) = count;
            suelo.at(des4.first).at(des4.second) = count;

            alicatar(suelo,des1,esq1,nlado);
            alicatar(suelo,des2,esq2,nlado);
            alicatar(suelo,desague,esq3,nlado);
            alicatar(suelo,des4,esq4,nlado);
        } else {
            suelo.at(des1.first).at(des1.second) = count;
            suelo.at(des2.first).at(des2.second) = count;
            suelo.at(des3.first).at(des3.second) = count;

            alicatar(suelo,des1,esq1,nlado);
            alicatar(suelo,des2,esq2,nlado);
            alicatar(suelo,des3,esq3,nlado);
            alicatar(suelo,desague,esq4,nlado);
        }

        return;
    }
}

void pintar_suelo(const Paleta &P,const vector<vector<int> > &suelo,Imagen &I) {
    color c;
    Pixel p;

    int tam = suelo.size();

    int escala=I.num_filas()/tam;

    for(int i=0; i<tam; ++i) {
        for(int j=0; j<tam; ++j) {
            for(int f=i*escala; f<(i+1)*escala; ++f) {
                for(int x=j*escala; x<(j+1)*escala; ++x) {
                    if(suelo[i][j]==-1) {
                        c=color();
                    } else {
                        c=P.Get(suelo[i][j]%(P.Size()-1));
                    }

                    p=c;
                    p.transp=0;

                    I(f,x)=p;
                }
            }
        }
    }
}

bool valido(int n) {
    return (n>1 && ((n & (n-1)) == 0));
}

void sintaxis() {
    cerr << "Caso 1: Los parametros son: " << endl;
    cerr << "\t1. Tamaño suelo (2^n)\n" << endl;

    cerr << "Caso 2: Los parametros son: " << endl;
    cerr << "\t1. Tamaño suelo (2^n)" << endl;
    cerr << "\t2. Fila desague" << endl;
    cerr << "\t3. Columna desague" << endl;
    cerr << "\t4. Paleta" << endl;
    cerr << "\t5. Imagen de salida" << endl;

    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    if ((argc != 2 && argc != 6) || !valido(atoi(argv[1]))) {
        sintaxis();
    } else if (argc == 6) {

        if(valido(atoi(argv[1]))) {
            int tam = atoi(argv[1]);

            if(atoi(argv[2]) > tam-1 || atoi(argv[2]) < 0 || atoi(argv[3]) > tam-1 || atoi(argv[3]) < 0 ) {
                sintaxis();
            }
        }
    }

    int tam = atoi(argv[1]);
    vector<vector<int> > suelo(tam);

    for ( int i = 0 ; i < tam ; i++ )
        suelo.at(i).resize(tam);


    if(argc == 2) {
        pair<int,int> desague(0,0);

        high_resolution_clock::time_point start,//punto de inicio
                              end; //punto de fin
        duration<double> tiempo_transcurrido;  //objeto para medir la duracion de end 						   // y start

        start = high_resolution_clock::now(); //iniciamos el punto de inicio

        alicatar(suelo,desague,pair<int,int>(0,0));

        end = high_resolution_clock::now(); //anotamos el punto de de fin
        //el tiempo transcurrido es
        tiempo_transcurrido = duration_cast<duration<double> >(end - start);

        // Mostramos resultados
        cout << tam << "\t" <<tiempo_transcurrido.count() << endl;

    } else {

        pair<int,int> desague(atoi(argv[2]),atoi(argv[3]));

        alicatar(suelo,desague,pair<int,int>(0,0));

        Imagen I(1024, 1024);
        Paleta P;
        ifstream f(argv[4]);

        if (!f) {
            cout << "No puedo abrir " << argv[4] << endl;
            return 0;
        }

        f >> P;

        for(int i = 0; i < tam; i++) {
            for(int j = 0 ; j < tam; j++) {
                cout << setw(4) << suelo[i][j];
            }
            cout << endl;
        }
        cout << endl;

        pintar_suelo(P,suelo,I);
        I.EscribirImagen(argv[5]);
    }

}