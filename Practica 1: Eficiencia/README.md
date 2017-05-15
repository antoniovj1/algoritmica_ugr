# Práctica 1: Eficiencia

### 1. Algoritmos de Ordenación Básicos.

Para los algoritmos de ordenación Inserción, Selección y Burbuja implementadlos y obtener su
orden de eficiencia en el peor, mejor y caso promedio. Así como tiempos empíricos y ajustar a
estos datos la eficiencia teórica en el peor caso con objeto de ajustar las constantes.

### 2. Algoritmos de Ordenación con estructuras jerárquicas.

Dados los T.D.A ABB (árbol binario de búsqueda) y APO (árbol parcialmente ordenado)
generar un algoritmo de ordenación insertando las claves en el árbol considerado. En el caso
que sea ABB si lo recorremos en inorden obtendremos los datos ordenados y si es un APO
consultando y borrando el mínimo. Implementar tales algoritmos y obtener igualmente la
eficiencia en el peor, mejor y caso promedio.

### 3. Algoritmo de Ordenación: fuerza bruta.

Dado el código que obtiene las permutaciones de 1 a n, permutaciones.cpp, establecer un
algoritmo de ordenación tal que cada permutación determina una ordenación de los
elementos de entrada. Para cada ordenación de elementos según la permutación considerada
se comprobará si los elementos ya están ordenados. Por ejemplo si nuestros elementos son
{7,5,4} tendríamos las siguientes posibilidades:

| Permutación | Vector Permutado |
| :----------:|:----------------:| 
| 1 2 3 | 7 5 4 |
| 1 3 2 | 7 4 5 |
| 2 1 3 | 5 7 4 |
| 2 3 1 | 5 4 7 |
| 3 1 2 | 4 7 5 |
| 3 2 1 | 4 5 7 |

Como se puede observar la única permutación que obtiene los elementos ordenados del vector
original es 3 2 1 dando lugar al vector {4 ,5 ,7}. Implementar tal algoritmo y obtener
igualmente la eficiencia en el peor, mejor y caso promedio. Igualmente obtener los tiempos
empíricos y ajustar a estos datos la eficiencia teórica en el peor caso.

### 4. Algoritmos de Ordenación por Mezcla

Estudie el código del algoritmo recursivo disponible en el fichero mergesort.cpp. En él, se
integran dos algoritmos de ordenación: inserción y mezcla (o mergesort). El parámetro
UMBRAL_MS condiciona el tamaño mínimo del vector para utilizar el algoritmo de inserción
en vez de seguir aplicando de forma recursiva el mergesort. Obtener la eficiencia teórica en
el mejor, peor y caso promedio.

Realice un análisis de la eficiencia empírica y haga el ajuste de ambas curvas. Incluya
también, para este caso, un pequeño estudio de cómo afecta el parámetro UMBRAL_MS a la
eficiencia del algoritmo. Para ello, pruebe distintos valores del mismo y analice los resultados
obtenidos.

Cambiar el algoritmo básico por los algoritmos jerárquicos desarrollados en el apartado 2 y
el algoritmo de ordenación basado en la fuerza bruta. Estudiar UMBRAL_MS en cada uno de
los casos. 