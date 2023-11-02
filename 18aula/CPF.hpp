#ifndef CPF_HPP
#define CPF_HPP

#include <cstdint>
#include <iomanip>

namespace ufpr {
class CPF {
    friend std::ostream& operator<<(std::ostream& stream, const CPF& cpf);
    friend std::istream& operator>>(std::istream& stream, CPF& cpf);

   public:
    CPF(const uint64_t numero);
    virtual ~CPF() = default;
    uint64_t getNumero() const;
    void setNumero(const uint64_t numero);

    bool operator==(const CPF& outro) const;
    bool operator!=(const CPF& outro) const;
    bool operator<(const CPF& outro) const;
    bool operator>(const CPF& outro) const;
    bool operator<=(const CPF& outro) const;
    bool operator>=(const CPF& outro) const;

    short operator[](const int idx) const;
    uint64_t operator()(const int start, const int end) const;

    const CPF& operator=(const CPF& outro);
    const CPF& operator=(const uint64_t numero);

   private:
    bool validarCPF(uint64_t cpfTeste) const;
    uint64_t numero;
};
}  // namespace ufpr
#endif