SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -pg  -I$(INC) -c
CPPFLAGS2 = -Wall -pg 

HDRS = $(INC)/*.h

all:  $(BIN)/prueba_APermutacion $(BIN)/Voraz

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************

$(BIN)/Voraz: $(OBJ)/MatrizDiscrepancias.o $(OBJ)/Voraz.o
	$(CXX) $(CPPFLAGS2) $^ -o $@ 

$(OBJ)/Voraz.o: $(SRC)/Voraz.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@
$(OBJ)/MatrizDiscrepancias.o: $(SRC)/MatrizDiscrepancias.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

	
$(BIN)/prueba_APermutacion: $(OBJ)/Apermutacion.o $(OBJ)/prueba_APermutacion.o
	$(CXX) $(CPPFLAGS2) $^ -o $@ 

$(OBJ)/prueba_APermutacion.o: $(SRC)/prueba_APermutacion.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@
$(OBJ)/Apermutacion.o: $(SRC)/Apermutacion.cpp $(HDRS)
	$(CXX) $(CPPFLAGS) $< -o $@

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
