/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
<<<<<<< HEAD
ultima modificacao 10/08/2023 21h50
=======
ultima modificacao 13/08/2023 21h50
>>>>>>> d151d8ab5e49688ade58162c21fae59e3789b686
*/
#ifndef RETANGULO_HPP
#define RETANGULO_HPP

<<<<<<< HEAD
#include <iostream>

=======
>>>>>>> d151d8ab5e49688ade58162c21fae59e3789b686
class Retangulo {
   public:
    Retangulo();
    Retangulo(double largura, double altura);

    double getLargura();
<<<<<<< HEAD
    void setLargura(double largura);
    double getAltura();
    void setAltura(double altura);
=======
    void setLargura(double largura = 7);
    double getAltura();
    void setAltura(double altura = 7);
>>>>>>> d151d8ab5e49688ade58162c21fae59e3789b686

    double getPerimetro();
    double getArea();

    bool isQuadrado();
    void show();

   private:
    double x = 10;
<<<<<<< HEAD
    double y = 10;
=======
    double y;
>>>>>>> d151d8ab5e49688ade58162c21fae59e3789b686
};

#endif