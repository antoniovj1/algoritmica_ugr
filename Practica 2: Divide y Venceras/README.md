# Práctica 2: Divide y Vencerás

### 1. Máximo y Mínimo
Dado un conjunto de enteros diseñar un algoritmo DyV para encontrar el máximo y el
mínimo. Para ello implementar un programa que genere un vector con un determinado
número de enteros y obtener el máximo y mínimo de este conjunto. Para ello debéis
implementar la función:

```
pair<int ,int> Max_Min(const vector<int> & v);
```

1. Obtener la eficiencia teórica y empírica del algoritmo.
2. Dar un nivel entre [0,10] del nivel de dificultad de como has percibido este ejercicio.

### 2. Tornillos con sus tuercas.
Se dispone de un conjunto de n tornillos de diferente tamaño y sus correspondientes n
tuercas, de forma que cada tornillo encaja perfectamente con una y sólo una tuerca. Dado un
tornillo y una tuerca, uno es capaz de determinar si el tornillo es menor que la tuerca, mayor,
o encaja exactamente. Sin embargo, no hay forma de comparar dos tornillos o dos tuercas
entre ellos para decidir un orden. Se desea ordenar los dos conjuntos de forma que los
elementos que ocupan la misma posición en los dos conjuntos emparejen entre sí

Este programa obtiene el emparejamiento de tornillos y tuercas. Un ejemplo de llamada a este
programa desde la línea de órdenes:

```
prompt% tornillos 1000
```

Los parámetros de entrada son los siguientes:
1. El número de tuercas y tornillos que debe generar aleatoriamente.
El programa deberá generar aleatoriamente 1000 tornillos, a continuación con estos tamaños
de tornillos debe generar una permutación (ordenar de forma aleatoria) para obtener el
conjunto de tuercas, también 1000.

### 3. Enlosado de un Cuarto de Baño
A un maestro albañil de reconocido prestigio le encomiendan la tarea de enlosar los cuartos de baño
de un edificio en construcción. Para ello, y por motivos estéticos, le piden que utilice un determinado
tipo de losa en forma de ‘L’ .

El albañil debe tener en cuenta que, al enlosar cada cuarto de baño deberá dejar el hueco del
desagüe sin cubrir. El tamaño de cada cuarto de baño y la ubicación del desagüe puede variar,
aunque siempre se cumple la condición de que el suelo es cuadrado con un tamaño de lado
de 2^n * 20 cm, y el desagüe tiene un tamaño de 20 cm × 20 cm.
Bajo estas condiciones, el albañil sabe que siempre podrá cubrir el suelo (dejando el hueco del
desagüe) utilizando losas enteras sin necesidad de partir ninguna y, por supuesto, sin
superponerlas. Por tanto, se propone diseñar una forma sistemática para ubicar las losas
siguiendo un procedimiento divide y vencerás.

Este programa obtiene el alicatado del suelo de un cuarto de baño con un desagüe. Un
ejemplo de llamada a este programa desde la línea de órdenes:

```
prompt% alicatar 8 0 0 paleta.txt res_8_8_0_0.ppm
```


Los parámetros de entrada son los siguientes:
1. Dimensión del cuarto de baño (filas y columnas adoptarán este valor). Debe ser
potencia de 2.
2. Fila donde se sitúa el desagüe
3. Columna donde estará el desagüe
4. Fichero con la paleta de colores para obtener una representación gráfica del alicatado
5. Imagen resultante