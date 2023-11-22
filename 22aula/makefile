parametrosCompilacao=-Wall -std=c++20
nomePrograma=aula

all: $(nomePrograma)

$(nomePrograma): main.o Pessoa.o
	g++ -o $(nomePrograma) main.o Pessoa.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Pessoa.o: Pessoa.cpp
	g++ -c Pessoa.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
