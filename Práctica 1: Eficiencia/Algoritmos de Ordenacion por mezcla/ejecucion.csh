#!/bin/csh
@ inicio = 100
@ fin = 100000
@ incremento = 1000
@ i = $inicio

echo `g++ mergesort.cpp -o mergesort.out`

echo > merge500_mejor.dat
echo > merge500_peor.dat
echo > merge500_promedio.dat

echo > merge250_mejor.dat
echo > merge250_peor.dat
echo > merge250_promedio.dat

echo > merge100_mejor.dat
echo > merge100_peor.dat
echo > merge100_promedio.dat

echo > merge50_mejor.dat
echo > merge50_peor.dat
echo > merge50_promedio.dat

echo > merge25_mejor.dat
echo > merge25_peor.dat
echo > merge25_promedio.dat

echo > merge5_mejor.dat
echo > merge5_peor.dat
echo > merge5_promedio.dat

while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "     Mergesort Umbral: 500"
  echo `./mergesort.out $i 1 500` >> merge500_mejor.dat
  echo `./mergesort.out $i 2 500` >> merge500_peor.dat
  echo `./mergesort.out $i 3 500` >> merge500_promedio.dat

  echo  "     Mergesort Umbral: 250"
  echo `./mergesort.out $i 1 250` >> merge250_mejor.dat
  echo `./mergesort.out $i 2 250` >> merge250_peor.dat
  echo `./mergesort.out $i 3 250` >> merge250_promedio.dat

  echo  "     Mergesort Umbral: 100"
  echo `./mergesort.out $i 1 100` >> merge100_mejor.dat
  echo `./mergesort.out $i 2 100` >> merge100_peor.dat
  echo `./mergesort.out $i 3 100` >> merge100_promedio.dat

  echo  "     Mergesort Umbral: 50"
  echo `./mergesort.out $i 1 50` >> merge50_mejor.dat
  echo `./mergesort.out $i 2 50` >> merge50_peor.dat
  echo `./mergesort.out $i 3 50` >> merge50_promedio.dat

  echo  "     Mergesort Umbral: 25"
  echo `./mergesort.out $i 1 25` >> merge25_mejor.dat
  echo `./mergesort.out $i 2 25` >> merge25_peor.dat
  echo `./mergesort.out $i 3 25` >> merge25_promedio.dat

  echo  "     Mergesort Umbral: 5"
  echo `./mergesort.out $i 1 5` >> merge5_mejor.dat
  echo `./mergesort.out $i 2 5` >> merge5_peor.dat
  echo `./mergesort.out $i 3 5` >> merge5_promedio.dat

@ i+= $incremento
end
