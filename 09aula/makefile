parametrosCompilacao=-Wall #-Wshadow
nomePrograma=aula

fontes=$(wildcard *.cpp)
objetos=$(fontes:.cpp=.o)

all: $(nomePrograma)

%.o: %.cpp
	@g++ -c $< -o $@

$(nomePrograma): $(objetos)
	g++ -o $(nomePrograma) $(objetos) $(parametrosCompilacao)

clean:
	rm -f $(objetos) *.gch $(nomePrograma)
