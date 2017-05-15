SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -std=c++11


all: $(BIN)/voraz_cifras $(BIN)/voraz_maximo $(BIN)/PD_maximo $(BIN)/PD_cifras

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/voraz_cifras: $(OBJ)/voraz_cifras.o
	$(CXX) -o $(BIN)/voraz_cifras  $(OBJ)/voraz_cifras.o

$(OBJ)/voraz_cifras.o: $(SRC)/voraz_cifras.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/voraz_cifras.cpp -o $(OBJ)/voraz_cifras.o

$(BIN)/voraz_maximo: $(OBJ)/voraz_maximo.o
	$(CXX) -o $(BIN)/voraz_maximo  $(OBJ)/voraz_maximo.o

$(OBJ)/voraz_maximo.o: $(SRC)/voraz_maximo.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/voraz_maximo.cpp -o $(OBJ)/voraz_maximo.o

$(BIN)/PD_maximo: $(OBJ)/PD_maximo.o
	$(CXX) -o $(BIN)/PD_maximo  $(OBJ)/PD_maximo.o

$(OBJ)/PD_maximo.o: $(SRC)/PD_maximo.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/PD_maximo.cpp -o $(OBJ)/PD_maximo.o

$(BIN)/PD_cifras: $(OBJ)/PD_cifras.o
	$(CXX) -o $(BIN)/PD_cifras  $(OBJ)/PD_cifras.o

$(OBJ)/PD_cifras.o: $(SRC)/PD_cifras.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/PD_cifras.cpp -o $(OBJ)/PD_cifras.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
