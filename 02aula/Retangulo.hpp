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
    Retangulo novoRetangulo(Retangulo *novoRetangulo);
    Retangulo novoRetangulo(double x, double y);
    bool isQuadrado();
    double calcArea();
    void show();

    double x;
    double y;
};

#endif