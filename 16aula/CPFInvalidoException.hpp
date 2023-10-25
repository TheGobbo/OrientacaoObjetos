#if !defined(CPF_INVALIDO_EXCEPTION)
#define CPF_INVALIDO_EXCEPTION

#include <stdexcept>

class CPFInvalidoException : public std::runtime_error {
   public:
    const unsigned long cpf;
    CPFInvalidoException(const unsigned long cpf);
    virtual ~CPFInvalidoException() = default;
};

#endif // CPF_INVALIDO_EXCEPTION
