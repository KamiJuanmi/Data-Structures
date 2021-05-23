SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

all:$(BIN)/cocinero_integral

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/Doxy-file


# ************ Compilación de módulos ************
$(BIN)/cocinero_integral: $(OBJ)/cocinero_integral.o $(OBJ)/Receta.o $(OBJ)/Recetas.o $(OBJ)/Ingrediente.o $(OBJ)/Ingredientes.o $(OBJ)/Instrucciones.o $(OBJ)/Acciones.o
	$(CXX) -o $(BIN)/cocinero_integral	$(OBJ)/cocinero_integral.o  $(OBJ)/Receta.o $(OBJ)/Recetas.o $(OBJ)/Ingrediente.o $(OBJ)/Ingredientes.o $(OBJ)/Instrucciones.o $(OBJ)/Acciones.o

$(OBJ)/Ingredientes.o: $(SRC)/Ingredientes.cpp $(INC)/Ingredientes.h $(INC)/Ingrediente.h
	$(CXX) $(CPPFLAGS)  $(SRC)/Ingredientes.cpp -o  $(OBJ)/Ingredientes.o

$(OBJ)/Ingrediente.o: $(SRC)/Ingrediente.cpp $(INC)/Ingrediente.h
	$(CXX) $(CPPFLAGS)  $(SRC)/Ingrediente.cpp -o  $(OBJ)/Ingrediente.o

$(OBJ)/Receta.o: $(SRC)/Receta.cpp $(INC)/Receta.h $(INC)/Ingrediente.h $(INC)/Instrucciones.h $(INC)/color.h
	$(CXX) $(CPPFLAGS)  $(SRC)/Receta.cpp -o  $(OBJ)/Receta.o

$(OBJ)/Recetas.o: $(SRC)/Recetas.cpp $(INC)/Recetas.h $(INC)/Receta.h
	$(CXX) $(CPPFLAGS)  $(SRC)/Recetas.cpp -o  $(OBJ)/Recetas.o

$(OBJ)/Instrucciones.o: $(SRC)/Instrucciones.cpp $(INC)/Acciones.h $(INC)/Instrucciones.h $(INC)/arbolbinario.h $(INC)/arbolbinario.tpp
	$(CXX) $(CPPFLAGS)  $(SRC)/Instrucciones.cpp -o  $(OBJ)/Instrucciones.o

$(OBJ)/Acciones.o: $(SRC)/Acciones.cpp $(INC)/Acciones.h
	$(CXX) $(CPPFLAGS)  $(SRC)/Acciones.cpp -o  $(OBJ)/Acciones.o

$(OBJ)/cocinero_integral.o: $(SRC)/cocinero_integral.cpp $(INC)/Acciones.h $(INC)/Receta.h $(INC)/Recetas.h $(INC)/Ingrediente.h $(INC)/Ingredientes.h $(INC)/color.h
	$(CXX) $(CPPFLAGS)  $(SRC)/cocinero_integral.cpp -o  $(OBJ)/cocinero_integral.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*

