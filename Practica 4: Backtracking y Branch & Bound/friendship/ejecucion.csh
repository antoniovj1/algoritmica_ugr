#!/bin/csh
@ inicio = 10
@ fin = 1500
@ incremento = 10
@ i = $inicio


echo > friendship_voraz.dat


while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "     friendship_voraz"
  echo `./bin/friendship_voraz $i ` >> friendship_voraz.dat

@ i+= $incremento
end

##########################################

@ inicio = 1
@ fin = 13
@ incremento = 1
@ i = $inicio

echo > friendship_backtracking_sin.dat

while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "      friendship_backtracking_sin"
  echo `./bin/friendship_backtracking_sin $i ` >> friendship_backtracking_sin.dat

@ i+= $incremento
end


##########################################

@ inicio = 1
@ fin = 14
@ incremento = 1
@ i = $inicio

echo > friendship_backtracking.dat

while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "      Suma Dinamica"
  echo `./bin/friendship_backtracking $i ` >> friendship_backtracking.dat

@ i+= $incremento
end


#########################################

@ inicio = 2
@ fin = 26
@ incremento = 2
@ i = $inicio

echo > friendship_branchbound.dat

while ( $i <= $fin )
  echo Ejecución tam = $i
  echo  "      cifra Dinamica"
  echo `./bin/friendship_branchbound $i ` >> friendship_branchbound.dat

@ i+= $incremento
end