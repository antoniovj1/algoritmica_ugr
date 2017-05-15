# Práctica 3: Voraces y Progrmación Dinámica

### 1. Suma hasta un número
#### 1.1. Descripción del Problema
Dado un conjunto de números S y un número M, el objetivo es obtener el subconjunto de S
que sume M. En caso de que no exista dar la suma inferior más cercana.

Por ejemplo:
```
S={2,3,4,1} y M = 8
Una solución es 3+4+1
```
#### 1.2. Técnica Voraz
Obtener una solución de este problema usando la técnica Voraz. 

##### 1.2.1. Programa Voraz
El programa Voraz se ejecuta desde la linea de órdenes de la siguiente forma:
prompt%> voraz_maximo datos/conjunto.txt 10
Los parámetros de este programa son:
1. Nombre del fichero con el conjunto de números S
2. Numero M que queremos obtener usando la suma de elementos de S

#### 1.3. Programación Dinámica
Una vez que hemos asegurado que se cumple el principio de optimalidad de Bellman,
podemos buscar una solución con la técnica de Programación Dinámica. 

##### 1.3.1. Programa PD
El programa PD se ejecuta desde la linea de órdenes de la siguiente forma:
prompt%> PD_maximo datos/conjunto.txt 10
Los parámetros de este programa son:
1. Nombre del fichero con el conjunto de números S
2. Numero M que queremos obtener usando la suma de elementos de S


### 2. Cifras
Este problema consiste en dado un conjunto de números S y un número M el objetivo es
obtener el valor M con un subconjunto de S en el que las operaciones que se pueden realizar
son: +,-,* y /. La división si no tiene un resto 0 no se puede aplicar.

Por ejemplo:
```
Supongamos que S={10,11,2,100,90,80,30.40,21} y que M= 3
Una solución sería 10+11+2+100-90-30
```

#### 2.2. Técnica Voraz
Obtener una solución de este problema usando la técnica Voraz. 

##### 2.2.1. Programa Voraz
El programa Voraz se ejecuta desde la linea de órdenes de la siguiente forma:
prompt%> voraz_cifras datos/conjunto.txt 10
Los parámetros de este programa son:
1. Nombre del fichero con el conjunto de números S
2. Numero M que queremos obtener usando la suma de elementos de S

#### 2.3. Programación Dinámica
Una vez que hemos asegurado que se cumple el principio de optimalidad de Bellman,
podemos buscar una solución con la técnica de Programación Dinámica. 

##### 2.3.1. Programa PD
El programa PD se ejecuta desde la linea de órdenes de la siguiente forma:
prompt%> PD_cifras datos/conjunto.txt 10
Los parámetros de este programa son:
1. Nombre del fichero con el conjunto de números S
2. Numero M que queremos obtener usando la suma de elementos de S
