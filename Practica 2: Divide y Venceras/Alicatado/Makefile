SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++ -g
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/alicatar

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/alicatar: $(OBJ)/alicatar.o $(OBJ)/imagen.o $(OBJ)/imagenES.o 
	$(CXX) -o $(BIN)/alicatar  $(OBJ)/alicatar.o $(OBJ)/imagen.o $(OBJ)/imagenES.o 

$(OBJ)/alicatar.o: $(SRC)/alicatar.cpp $(INC)/imagenES.h $(INC)/imagen.h $(INC)/paleta.h 
	$(CXX) $(CPPFLAGS) $(SRC)/alicatar.cpp -o $(OBJ)/alicatar.o
$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o
		
$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h 
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o	


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
