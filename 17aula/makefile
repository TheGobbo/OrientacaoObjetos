parametrosCompilacao=-Wall --std=c++11#-Wshadow
nomePrograma=aula

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(nomePrograma)

$(nomePrograma): $(OBJS)
	g++ -o $(nomePrograma) $(OBJS) $(parametrosCompilacao)

# %.o: %.cpp
$(OBJS): %.o : %.cpp
	g++ -c $< -o $@ $(parametrosCompilacao)

run: $(nomePrograma)
	./$(nomePrograma)

clean:
	rm -f *.o *.gch $(nomePrograma)
