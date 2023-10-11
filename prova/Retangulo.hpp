#if !defined(RETANGULO_HPP)
#define RETANGULO_HPP

#include "Forma.hpp"

class Retangulo : public Forma {
   public:
    Retangulo(double largura, double altura);
    virtual ~Retangulo() = default;

    void setAltura(double altura);
    double getAltura() const;

    void setLargura(double largura);
    double getLargura() const;

    double calculaArea() const override;

   private:
    double altura;
    double largura;
};

#endif  // RETANGULO_HPP