SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -std=c++11


all: $(BIN)/cifra_voraz $(BIN)/suma_voraz $(BIN)/suma_dinamica

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/cifra_voraz: $(OBJ)/cifra_voraz.o
	$(CXX) -o $(BIN)/cifra_voraz  $(OBJ)/cifra_voraz.o

$(OBJ)/cifra_voraz.o: $(SRC)/cifra_voraz.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/cifra_voraz.cpp -o $(OBJ)/cifra_voraz.o

$(BIN)/suma_voraz: $(OBJ)/suma_voraz.o
	$(CXX) -o $(BIN)/suma_voraz  $(OBJ)/suma_voraz.o

$(OBJ)/suma_voraz.o: $(SRC)/suma_voraz.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/suma_voraz.cpp -o $(OBJ)/suma_voraz.o

$(BIN)/suma_dinamica: $(OBJ)/suma_dinamica.o
	$(CXX) -o $(BIN)/suma_dinamica  $(OBJ)/suma_dinamica.o

$(OBJ)/suma_dinamica.o: $(SRC)/suma_dinamica.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/suma_dinamica.cpp -o $(OBJ)/suma_dinamica.o

$(BIN)/cifra_dinamica: $(OBJ)/cifra_dinamica.o
	$(CXX) -o $(BIN)/cifra_dinamica  $(OBJ)/cifra_dinamica.o

$(OBJ)/cifra_dinamica.o: $(SRC)/cifra_dinamica.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/cifra_dinamica.cpp -o $(OBJ)/cifra_dinamica.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
