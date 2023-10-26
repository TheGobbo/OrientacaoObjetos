#if !defined(CIRCULO_HPP)
#define CIRCULO_HPP

#include "Forma.hpp"

class Circulo : public Forma {
   public:
    Circulo(double raio);
    virtual ~Circulo() = default;

    void setRaio(double raio);
    double getRaio() const;

    double calculaArea() const override;

   private:
    static double pi2;
    double raio;
};

#endif  // CIRCULO_HPP
