#!/bin/csh
@ inicio = 100
@ fin = 1000000
@ incremento = 100
@ i = $inicio

echo `g++ ./APO/usoapo.cpp -o ./APO/apo.out`
echo `g++ ./ABB/usoabb.cpp -o ./ABB/abb.out`


echo > apo_mejor.dat
echo > apo_peor.dat
echo > apo_promedio.dat

echo > abb_mejor.dat
echo > abb_peor.dat
echo > abb_promedio.dat


while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "     Arbol Parcialmente Ordenado"
  echo `./APO/apo.out $i 1` >> apo_mejor.dat
  echo `./APO/apo.out $i 2` >> apo_peor.dat
  echo `./APO/apo.out $i 3` >> apo_promedio.dat

  echo "     Arbol Binario de Busqueda"
  echo `./ABB/abb.out $i 1` >> abb_mejor.dat
  echo `./ABB/abb.out $i 2` >> abb_peor.dat
  echo `./ABB/abb.out $i 3` >> abb_promedio.dat

@ i+= $incremento
end
