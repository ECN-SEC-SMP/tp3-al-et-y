#pragma once

#include "PointT.hpp"
#include "Forme.hpp"
#include <iostream>
#include <array>

template <typename TPoint, typename TPerimetre = float, typename TSurface = float>
class Rectangle;

template <typename T>
std::ostream &operator<<(std::ostream &, Rectangle<T> &);

// Classe Rectangle, dérivée de la classe forme
// C++ 14: types par défaut dans les templates
template <typename TPoint, typename TPerimetre, typename TSurface>
class Rectangle : public Forme<TPoint, TPerimetre, TSurface>
{
private:
    TPoint h; // Hauteur du rectangle
    TPoint l; // Largeur du rectangle

public:
    // Constructeurs
    Rectangle() : Forme<TPoint>(), h(TPoint()), l(TPoint()) {};
    Rectangle(PointT<TPoint> const &p, TPoint h, TPoint l) : Forme<TPoint>(p), h(h), l(l) {}

    // Accesseurs
    TPoint getH() const { return this->h; }
    TPoint getL() const { return this->l; }

    // Mutateurs
    void setH(TPoint h) { this->h = h; }
    void setL(TPoint l) { this->l = l; }

    // Méthodes
    std::array<PointT<TPoint>, 4> boundingBox() override
    {
        TPoint x0 = this->getPoint().getX();
        TPoint y0 = this->getPoint().getY();
        TPoint x1 = x0 + l;
        TPoint y1 = y0 + h;

        return {PointT<TPoint>(x0, y0),
                PointT<TPoint>(x1, y0),
                PointT<TPoint>(x1, y1),
                PointT<TPoint>(x0, y1)};
    }

    TPerimetre perimetre() override {
        return (2*h)+(2*l);
    }

    TSurface surface() override {
        return h*l;
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Rectangle<T> &R)
{
    o << "(" << R.getPoint().getX() << "," << R.getPoint().getY() << "), " << R.getH() << "," << R.getL() << std::endl;
    return o;
}
