#if !defined(TELA_DESENHO_HPP)
#define TELA_DESENHO_HPP

#include <list>

#include "Forma.hpp"
class TelaDesenho {
   public:
    TelaDesenho();
    ~TelaDesenho();
    void adicionaForma(Forma* forma);
    double calcularAreaTotal() const;

   private:
    static size_t num_formas;
    std::list<Forma*> formas;
};

#endif  // TELA_DESENHO_HPP
