#!/bin/csh
@ inicio = 1
@ fin = 200000
@ incremento = 2500
@ i = $inicio

echo `make`

echo > tornillos.dat


while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "     Tornillos"
  echo `./bin/pruebatornillos $i ` >> tornillos.dat

@ i+= $incremento
end
