# Autor: Eduardo Gobbo Willi V.G.
# GRR20203892
# ultima modificacao 07/08/2023 21h50

parametrosCompilacao=-Wall #-Wshadow
nomePrograma=3aula

all: $(nomePrograma)

$(nomePrograma): main.o Pessoa.o Retangulo.o
	g++ -o $(nomePrograma) main.o Pessoa.o Retangulo.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Pessoa.o: Pessoa.hpp Pessoa.cpp
	g++ -c Pessoa.cpp $(parametrosCompilacao)

Retangulo.o : Retangulo.hpp Retangulo.cpp
	g++ -c Retangulo.cpp $(parametrosCompilacao)

clean:
	rm -f *.o 

clear: clean
	rm -f *.gch $(nomePrograma)
