/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 13/08/2023 21h50
*/
#ifndef RETANGULO_HPP
#define RETANGULO_HPP

class Retangulo {
   public:
    Retangulo();
    Retangulo(double largura, double altura);

    double getLargura();
    void setLargura(double largura = 7);
    double getAltura();
    void setAltura(double altura = 7);

    double getPerimetro();
    double getArea();

    bool isQuadrado();
    void show();

   private:
    double x = 10;
    double y;
};

#endif