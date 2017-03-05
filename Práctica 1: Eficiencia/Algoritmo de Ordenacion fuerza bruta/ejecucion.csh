#!/bin/csh
@ inicio = 1
@ fin = 10
@ incremento = 1
@ i = $inicio

echo `cd ./Permutacion/ && make && cd ..`

echo > perm_mejor.dat
echo > perm_peor.dat
echo > perm_promedio.dat

while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "     Permutacion"
  echo `./Permutacion/bin/pruebapermutacion.out $i 1` >> perm_mejor.dat
  echo `./Permutacion/bin/pruebapermutacion.out $i 2` >> perm_peor.dat
  echo `./Permutacion/bin/pruebapermutacion.out $i 3` >> perm_promedio.dat

@ i+= $incremento
end
