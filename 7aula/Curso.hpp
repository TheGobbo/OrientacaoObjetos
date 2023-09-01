#if !defined(CURSO_HPP)
#define CURSO_HPP

/*
1. Crie uma classe Curso para representar cursos (ex.: BCC, IBM, …). A classe
deve conter dados membro como nomeCurso, anoCriacao, cargaHorariaMinima, …
Adicione um membro dentro de Disciplina, que representa o curso ao qual a
disciplina está vinculada. Dentro de disciplina, o curso deve ser uma referência
a um objeto. Para que isso funcione, todos os construtores de Disciplina devem
receber o curso a que a disciplina pertence como parâmetro (lembre-se que não
existe referência não inicializada). Note também que uma disciplina não poderá
mudar de curso, já que uma referência depois de inicializada, não pode “apontar”
para outro objeto.

2. Modifique todos os sets e construtores das classes para que os parâmetros
possuam o mesmo nome dos dados membro. Na lista de inicializador de membro dos
construtores não utilize o this.O compilador já sabe que o conteúdo que está
entre chaves se refere ao parâmetro, e o que está fora das chaves é o dado
membro. Exemplo: Pessoa::Pessoa(std::string nome):nome{nome} { }
*/
#include <string>

class Curso {
   public:
    Curso();
    Curso(std::string nome, short int anoCriacao, short int cargaHorariaMinima);

    void setNome(std::string nome);
    std::string getNome();

    void setAnoCriacao(short int anoCriacao);
    short int getAnoCriacao();

    void setCargaHorariaMinima(short int cargaHorariaMinima);
    short int getCargaHorariaMinima();

    void show();

   private:
    std::string nome;
    short int anoCriacao{0};
    short int cargaHorariaMinima{0};
};

#endif  // CURSO_HPP
