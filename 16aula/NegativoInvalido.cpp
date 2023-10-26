
#include "NegativoInvalido.hpp"

NegativoInvalido::NegativoInvalido(const int valor)
    : std::runtime_error{"Valor deve ser positivo"}, valor{valor} {}

NegativoInvalido::NegativoInvalido(const short valor)
    : std::runtime_error{"Valor deve ser positivo"}, valor{valor} {}
