#include "Curso.hpp"

/*
Crie uma classe Curso para representar cursos (ex.: BCC, IBM, …). A classe deve conter dados membro como
nomeCurso, anoCriacao, cargaHorariaMinima, … Adicione um membro dentro de Disciplina, que representa o
curso ao qual a disciplina está vinculada. Dentro de disciplina, o curso deve ser uma referência a um objeto. Para
que isso funcione, todos os construtores de Disciplina devem receber o curso a que a disciplina pertence como
parâmetro (lembre-se que não existe referência não inicializada). Note também que uma disciplina não poderá
mudar de curso, já que uma referência depois de inicializada, não pode “apontar” para outro objeto.
*/

Curso::Curso() {} 
Curso::Curso(nome, anoCriacao, cargaHorariaMinima) : nome{nome}, anoCriacao{anoCriacao}, cargaHorariaMinima{cargaHorariaMinima} {}

Curso::void setNome(std::string nome) {
    this->nome = nome;
}
Curso::std::string getNome() {
    return this->nome;
}

Curso::void setAnoCriacao(short int anoCriacao) {
    this->anoCriacao = anoCriacao;
}
Curso::short int getAnoCriacao() {
    return this->anoCriacao;
}

Curso::void setCargaHorariaMinima(short int cargaHorariaMinima) {
    this->carcaHorariaMinima = carcaHorariaMinima ;
}
Curso::short int getCargaHorariaMinima() {
    return this->carcaHorariaMinima;
}