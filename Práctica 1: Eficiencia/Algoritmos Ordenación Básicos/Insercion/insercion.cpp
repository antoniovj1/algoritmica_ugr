#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>// Recursos para medir tiempos
using namespace std;
using namespace std::chrono;

int insercion(int *v, int tam){
 int temp, j;
 for(int i=1;i<=tam-1;i++) {
        temp=v[i];
        j=i-1;
        while((temp<v[j])&&(j>=0)){
            v[j+1]=v[j];    //moves element forwvrd
            j=j-1;
        }

        v[j+1]=temp;    //insert element in proper place
    }
}

void sintaxis() {
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "  Caso: 1 -> Mejor 2 -> Peor 3 -> Promedio" << endl;
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

int main(int argc, char * argv[]) {
  // Lectura de parámetros
  if (argc!=3)
    sintaxis();
  int tam=atoi(argv[1]);     // Tamaño del vector
  int caso=atoi(argv[2]);    // Valor máximo
  if (tam<=0 || (caso!=1 && caso !=2 && caso != 3))
    sintaxis();

  // Generación del vector aleatorio
  int *v=new int[tam];       // Reserva de memoria
  inicializar(v,tam,caso);

 high_resolution_clock::time_point start,//punto de inicio
                                  end; //punto de fin
 duration<double> tiempo_transcurrido;  //objeto para medir la duracion de end 						   // y start

 start = high_resolution_clock::now(); //iniciamos el punto de inicio

  insercion(v,tam);

 end = high_resolution_clock::now(); //anotamos el punto de de fin
 //el tiempo transcurrido es
 tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

  // Mostramos resultados
  cout << tam << "\t" <<tiempo_transcurrido.count() << endl;

  delete [] v;     // Liberamos memoria dinámica
}
