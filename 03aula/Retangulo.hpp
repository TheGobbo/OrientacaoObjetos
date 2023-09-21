/*
Autor: Eduardo Gobbo Willi V.G.
GRR20203892
ultima modificacao 10/08/2023 21h50
*/
#ifndef RETANGULO_HPP
#define RETANGULO_HPP

#include <iostream>

class Retangulo {
   public:
    void cadastrar(double novoX, double novoY);
    void cadastrar();

    double getX();
    void setX(double novoX);
    double getY();
    void setY(double novoY);
    double getPerimetro();
    double getArea();

    bool isQuadrado();
    void show();

   private:
    double x;
    double y;
};

#endif