#if !defined(NEGATIVO_INVALIDO)
#define NEGATIVO_INVALIDO

#include <stdexcept>

namespace ufpr{
class NegativoInvalido : public std::runtime_error{
   public:
    const int valor;
    NegativoInvalido(const int valor);
    NegativoInvalido(const short valor);
    virtual ~NegativoInvalido() = default;
};
}

#endif // NEGATIVO_INVALIDO
