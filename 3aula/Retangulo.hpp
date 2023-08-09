/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 07/08/2023 21h50
*/
#ifndef RETANGULO_HPP
#define RETANGULO_HPP

#include <iostream>

class Retangulo {
   public:
    double getX();
    void setX(double x);
    double getY();
    void setY(double y);

    void novoRetangulo(double x, double y);
    void novoRetangulo();
    bool isQuadrado();
    double getArea();
    void show();

   private:
    double x;
    double y;
};

#endif