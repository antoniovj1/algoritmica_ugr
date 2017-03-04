/**
@file Ordenaci�n por mezcla
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>   // Recursos para medir tiempos

using namespace std::chrono;
using namespace std;



/* ************************************************************ */
/*  M�todo de ordenaci�n por mezcla  */

/**
@brief Ordena un vector por el m�todo de mezcla.

@param T: vector de elementos. Debe tener num_elem elementos.
Es MODIFICADO.
@param num_elem: n�mero de elementos. num_elem > 0.

Cambia el orden de los elementos de T de forma que los dispone
en sentido creciente de menor a mayor.
Aplica el algoritmo de mezcla.
*/
inline static
void mergesort(int T[], int num_elem);



/**
@brief Ordena parte de un vector por el m�todo de mezcla.

@param T: vector de elementos. Tiene un n�mero de elementos
mayor o igual a final. Es MODIFICADO.
@param inicial: Posici�n que marca el incio de la parte del
vector a ordenar.
@param final: Posici�n detr�s de la �ltima de la parte del
vector a ordenar.
inicial < final.

Cambia el orden de los elementos de T entre las posiciones
inicial y final - 1 de forma que los dispone en sentido creciente
de menor a mayor.
Aplica el algoritmo de la mezcla.
*/
static void mergesort_lims(int T[], int inicial, int final);


/**
@brief Ordena un vector por el m�todo de inserci�n.

@param T: vector de elementos. Debe tener num_elem elementos.
Es MODIFICADO.
@param num_elem: n�mero de elementos. num_elem > 0.

Cambia el orden de los elementos de T de forma que los dispone
en sentido creciente de menor a mayor.
Aplica el algoritmo de inserci�n.
*/
inline static
void insercion(int T[], int num_elem);


/**
@brief Ordena parte de un vector por el m�todo de inserci�n.

@param T: vector de elementos. Tiene un n�mero de elementos
mayor o igual a final. Es MODIFICADO.
@param inicial: Posici�n que marca el incio de la parte del
vector a ordenar.
@param final: Posici�n detr�s de la �ltima de la parte del
vector a ordenar.
inicial < final.

Cambia el orden de los elementos de T entre las posiciones
inicial y final - 1 de forma que los dispone en sentido creciente
de menor a mayor.
Aplica el algoritmo de la inserci�n.
*/
static void insercion_lims(int T[], int inicial, int final);


/**
@brief Mezcla dos vectores ordenados sobre otro.

@param T: vector de elementos. Tiene un n�mero de elementos
mayor o igual a final. Es MODIFICADO.
@param inicial: Posici�n que marca el incio de la parte del
vector a escribir.
@param final: Posici�n detr�s de la �ltima de la parte del
vector a escribir
inicial < final.
@param U: Vector con los elementos ordenados.
@param V: Vector con los elementos ordenados.
El n�mero de elementos de U y V sumados debe coincidir
con final - inicial.

En los elementos de T entre las posiciones inicial y final - 1
pone ordenados en sentido creciente, de menor a mayor, los
elementos de los vectores U y V.
*/
static void fusion(int T[], int inicial, int final, int U[], int V[]);



/**
Implementaci�n de las funciones
**/


inline static void insercion(int T[], int num_elem)
{
    insercion_lims(T, 0, num_elem);
}


static void insercion_lims(int T[], int inicial, int final)
{
    int i, j;
    int aux;
    for (i = inicial + 1; i < final; i++) {
        j = i;
        while ((T[j] < T[j-1]) && (j > 0)) {
            aux = T[j];
            T[j] = T[j-1];
            T[j-1] = aux;
            j--;
        };
    };
}


int UMBRAL_MS = 100;

void mergesort(int T[], int num_elem)
{
    mergesort_lims(T, 0, num_elem);
}

static void mergesort_lims(int T[], int inicial, int final)
{
    if (final - inicial < UMBRAL_MS)
    {
        insercion_lims(T, inicial, final);
    } else {
        int k = (final - inicial)/2;

        int * U = new int [k - inicial + 1];
        assert(U);
        int l, l2;
        for (l = 0, l2 = inicial; l < k; l++, l2++)
        U[l] = T[l2];
        U[l] = INT_MAX;

        int * V = new int [final - k + 1];
        assert(V);
        for (l = 0, l2 = k; l < final - k; l++, l2++)
        V[l] = T[l2];
        V[l] = INT_MAX;

        mergesort_lims(U, 0, k);
        mergesort_lims(V, 0, final - k);
        fusion(T, inicial, final, U, V);
        delete [] U;
        delete [] V;
    };
}


static void fusion(int T[], int inicial, int final, int U[], int V[])
{
    int j = 0;
    int k = 0;
    for (int i = inicial; i < final; i++)
    {
        if (U[j] < V[k]) {
            T[i] = U[j];
            j++;
        } else{
            T[i] = V[k];
            k++;
        };
    };
}


void sintaxis() {
    cerr << "Sintaxis:" << endl;
    cerr << "  TAM: Tamaño del vector (>0)" << endl;
    cerr << "  Caso: 1 -> Mejor 2 -> Peor 3 -> Promedio" << endl;
    cerr << "  Umbral insercion" << endl;

    exit(EXIT_FAILURE);
}

void inicializar(int *v, int tam, int caso)
{
    switch (caso)
    {
        case 1:
        for (int i = 0; i < tam; i++)
        v[i] = i;
        break;

        case 2:
        for (int i = 0; i < tam; i++)
        v[i] = tam - i;
        break;

        case 3:
        srand(time(0));
        for (int i = 0; i < tam; i++)
        v[i] = rand();
        break;
    }
}


int main(int argc, char * argv[])
{

   // Lectura de parámetros
    if (argc!=4)
      sintaxis();
    int tam=atoi(argv[1]);     // Tamaño del vector
    int caso=atoi(argv[2]);    // Valor máximo
    UMBRAL_MS = atoi(argv[3]);

    if (tam<=0 || (caso!=1 && caso !=2 && caso != 3))
      sintaxis();

    // Generación del vector aleatorio
    int *v=new int[tam];       // Reserva de memoria
    inicializar(v,tam,caso);

    high_resolution_clock::time_point start,//punto de inicio
    end; //punto de fin
    duration<double> tiempo_transcurrido;  //objeto para medir la duracion de end 						   // y start

    start = high_resolution_clock::now(); //iniciamos el punto de inicio

    mergesort(v,tam);

    end = high_resolution_clock::now(); //anotamos el punto de de fin
    //el tiempo transcurrido es
    tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

    // Mostramos resultados
    cout << tam << "\t" <<tiempo_transcurrido.count() << endl;

    delete [] v;     // Liberamos memoria dinámica

    return 0;
};
