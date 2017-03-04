#!/bin/csh
@ inicio = 100
@ fin = 100000
@ incremento = 1000
@ i = $inicio

echo `g++ ./Burbuja/burbuja.cpp -o ./Burbuja/burbuja.out`
echo `g++ ./Insercion/insercion.cpp -o ./Insercion/insercion.out`
echo `g++ ./Seleccion/seleccion.cpp -o ./Seleccion/seleccion.out`

echo > burbuja_mejor.dat
echo > burbuja_peor.dat
echo > burbuja_promedio.dat

echo > insercion_mejor.dat
echo > insercion_peor.dat
echo > insercion_promedio.dat

echo > seleccion_mejor.dat
echo > seleccion_peor.dat
echo > seleccion_promedio.dat


while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "     Burbuja"
  echo `./Burbuja/burbuja.out $i 1` >> burbuja_mejor.dat
  echo `./Burbuja/burbuja.out $i 2` >> burbuja_peor.dat
  echo `./Burbuja/burbuja.out $i 3` >> burbuja_promedio.dat

  echo "     Insercion"
  echo `./Insercion/insercion.out $i 1` >> insercion_mejor.dat
  echo `./Insercion/insercion.out $i 2` >> insercion_peor.dat
  echo `./Insercion/insercion.out $i 3` >> insercion_promedio.dat

  echo "     Seleccion"
  echo `./Seleccion/seleccion.out $i 1` >> seleccion_mejor.dat
  echo `./Seleccion/seleccion.out $i 2` >> seleccion_peor.dat
  echo `./Seleccion/seleccion.out $i 3` >> seleccion_promedio.dat

@ i+= $incremento
end
