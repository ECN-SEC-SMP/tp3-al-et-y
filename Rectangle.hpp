#pragma once

#include "PointT.hpp"
#include "Forme.hpp"
#include <iostream>
#include <array>

template <typename T>
class Rectangle;

template <typename T>
std::ostream &operator<<(std::ostream &, Rectangle<T> const &);

// Classe Rectangle, dérivée de la classe forme
template <typename T>
class Rectangle : public Forme<T>
{
public:
    // Constructeur
    Rectangle();

    // Accesseurs
    T getH() const { return this->h; }
    T getL() const { return this->l; }

    // Mutateurs
    T setH(T h) { this->h = h; }
    T setL(T l) { this->l = l; }

    // Méthodes
    template <typename TPerimetre>
    std::array<PointT<T>, 4> vertices() const
    {
        T x0 = this->getPoint().getX();
        T y0 = this->getPoint().getY();
        T x1 = x0 + l;
        T y1 = y0 + h;

        return {PointT<T>(x0, y0),
                PointT<T>(x1, y0),
                PointT<T>(x1, y1),
                PointT<T>(x0, y1)};
    }

private:
    T h; // Hauteur du rectangle
    T l; // Largeur du rectangle
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Rectangle<T> const &R)
{
    o << "(" << R.getPoint().getX() << "," << R.getPoint().getY() << "), " << R.getH() << "," << R.getL() << std::endl;
    return o;
}
