SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebatornillos

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/pruebatornillos: $(OBJ)/pruebatornillos.o
	$(CXX) -o $(BIN)/pruebatornillos  $(OBJ)/pruebatornillos.o 

$(OBJ)/pruebatornillos.o: $(SRC)/pruebatornillos.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)/pruebatornillos.cpp -o $(OBJ)/pruebatornillos.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
