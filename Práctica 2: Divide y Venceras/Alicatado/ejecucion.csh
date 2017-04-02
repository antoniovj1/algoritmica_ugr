#!/bin/csh
@ inicio = 1
@ fin = 15
@ incremento = 1
@ i = $inicio
echo `make`

echo > alicatar.dat

while ( $i <= $fin )
  @ j = 2
  @ aux = 1

  while ($aux < $i)
    @ j*=2
    @ aux+=1
  end

  echo Ejecución tam = $j
  echo  "     Alicatar"
  echo `./bin/alicatar $j` >> alicatar.dat

@ i+= $incremento
end
