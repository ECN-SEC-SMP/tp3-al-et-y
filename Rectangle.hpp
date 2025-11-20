#pragma once

#include "PointT.hpp"
#include "Forme.hpp"
#include <iostream>


template <typename T>
class Rectangle;

template <typename T>
std::ostream &operator<<(std::ostream &, Rectangle<T> const &);

// Classe Rectangle, dérivée de la classe forme
template <typename T>
class Rectangle : public Forme<T>
{
public:
    //Constructeur
    Rectangle()
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Rectangle<T> const &R)
{
    o << "(" << R.getPoint().getX() << "," << R.getPoint().getY() << "), " << R.getH() << "," << R.getL() << std::endl;
    return o;
}
