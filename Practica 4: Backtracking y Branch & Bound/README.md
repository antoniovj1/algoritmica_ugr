# Práctica 4: Backtracking y Branch & Bound

### 1. Descripción del problema: Busca Amistades

La empresa Friendship se ocupa de encontrar amistades formadas entre dos personas. Con
tal objetivo tenemos un conjunto de personas (con número par de personas) y tenemos que
encontrar las parejas de amigos que minimicen la discrepancia global.
Para obtener estas parejas, por cada individuo tenemos el nivel de afinidad sobre distintas
aficiones o formas de vida. Esta información la tenemos recogida en los fichero
group<n>.txt.
Así por ejemplo el fichero group_small.txt es el siguiente:


```
#Valores entre 0-10.1.Practica deportes, 2 #Frecuencia de lectura 3 Escucha musica 4 Gusta las
fiestas
6 4
5 10 9 10
10 5 5 0
0 2 6 1
10 0 0 0
5 5 5 0
1 2 3 3
```

La primera línea es un comentario que indica los aspectos encuestados a cada individuo. En
este caso tenemos 6 individuos y 4 características. Las cuestiones son respondidas dando un
valor en el rango [0,10], 0 siendo la menor afinidad y 10 mayor afinidad. En este fichero las
cuestiones realizados son:
1. Si práctica deportes
2. Frecuencia de Lectura
3. Escucha música
4. Si le gusta las fiestas.

Por ejemplo el primer individuo ha contestando 5 10 9 10 a cada una de las cuestiones. Por lo
tanto le gusta la lectura, y las fiestas, algo menos la música y regular los deportes.
Con esta información de gustos por cada individuo podemos obtener una matriz de
discrepancias entre individuos siendo calculada como la la suma de las diferencias en valor absoluto por cada una de las respuestas. 

Por ejemplo la matriz de discrepancia para el fichero group_small.txt sería el
siguiente:

```
Discrepancias:
inf 24 25 34 19 25
24 inf 15 10 5 17
25 15 inf 19 10 6
34 10 19 inf 15 17
19 5 10 15 inf 12
25 17 6 17 12 inf 
```

Como se puede observar la discrepancia sobre sí mismo se ha puesto a infinito (inf).
Nuestro objetivo es obtener las mejores parejas de individuos que minimicen la discrepancia
total. 


### 2. Solución voraz
En primer lugar este problema vamos a resolverlo con la técnica Voraz. Una función de
selección trivial sería ir recorriendo los individuos y buscar entre los libres aquel que
muestre menor discrepancia con él. 

```
prompt% bin/friendship_voraz datos/group_small.txt
```

### 3. Solucion Backtracking
#### 3.1 Sin poda
Se aplica backtracking cuando encuentra una solución (obtiene todos los
emparejamientos).

#### 3.2 Con poda
Se aplica backtracking cuando la solución parcial tiene una discrepancia estimada
mayor que la mejor solución actual.
```
prompt% bin/friendship_backtracking datos/group_small.txt
```


### 4. Branch & Bound 
También vamos a resolver este problema usando la técnica Branch & Bound. Al igual que
backtracking usará un árbol permutacional. Lo novedoso con esta técnica es que se ramifica
por el nodo que tenga una discrepancia estimada menor hasta el momento. Además se usa
una cota superior y una cota inferior de la solución que se puede llegar a obtener a partir de
un nodo. 

```
prompt% bin/friendship_branchbound datos/group_small.tx
```