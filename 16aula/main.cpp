#include <iostream>

#include "Pessoa.hpp"
#include "ProfessorEngenheiro.hpp"
#include "CPFInvalidoException.hpp"
#include "NegativoInvalido.hpp"

int main(){
    ProfessorEngenheiro pe{"Maria", 11111111111,85, 40, 1234};
    std::cout << "Nome: " << pe.getNome() << "\tSalario R$" << pe.getSalario() <<",00\n";

    try{
        // pe.setCpf(123);
        // pe.setIdade(123);
        // pe.setCargaHoraria(-123);
        pe.setValorHora(-123);
        std::cout << "Sucesso! " << pe.getCpf() << ", " << pe.getIdade() << '\n';
    } 
    catch (const CPFInvalidoException& e) {
        std::cerr << "Erro de CPF: " << e.what() << e.cpf << '\n';
    }
    catch (const NegativoInvalido& e) {
        std::cerr << e.what() << ": " << e.valor << '\n';
    }
    catch(const int& e) {
        std::cerr << "recebeu erro: " << e << '\n';
        switch (e){
            case 1:
                std::cerr << "CPF invalido\n";
                break;
            
            default:
                std::cerr << "Erro desconhecido\n";
                break;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Argumento invalido: " <<  e.what() << '\n';
    } 
    catch (const std::exception& e) {
        std::cerr << "Erro generico: " << e.what() << '\n';
    }

    std::cout << pe.getCpf() << '\n';
    std::cout << pe.getIdade() << '\n';

    return 0;
}