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

echo > voraz_maximo.dat

while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "      Suma Voraz"
  echo `./bin/voraz_maximo $i ` >> voraz_maximo.dat

@ i+= $incremento
end

@ inicio = 1
@ fin = 10000
@ incremento = 250
@ i = $inicio

echo > PD_maximo.dat

while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "      Suma Dinamica"
  echo `./bin/PD_maximo $i ` >> PD_maximo.dat

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