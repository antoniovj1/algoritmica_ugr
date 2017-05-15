#!/bin/csh
@ inicio = 1
@ fin = 10000000
@ incremento = 250000
@ i = $inicio


echo > cifra_voraz.dat


while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "     Cifra Voraz"
  echo `./bin/cifra_voraz $i ` >> cifra_voraz.dat

@ i+= $incremento
end

@ inicio = 1
@ fin = 1000000
@ incremento = 25000
@ i = $inicio

echo > suma_voraz.dat

while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "      Suma Voraz"
  echo `./bin/suma_voraz $i ` >> suma_voraz.dat

@ i+= $incremento
end

@ inicio = 1
@ fin = 10000
@ incremento = 250
@ i = $inicio

echo > suma_dinamica.dat

while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "      Suma Dinamica"
  echo `./bin/suma_dinamica $i ` >> suma_dinamica.dat

@ i+= $incremento
end

@ inicio = 1
@ fin = 10000
@ incremento = 250
@ i = $inicio

echo > cifra_dinamica.dat

while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "      cifra Dinamica"
  echo `./bin/cifra_dinamica $i ` >> cifra_dinamica.dat

@ i+= $incremento
end