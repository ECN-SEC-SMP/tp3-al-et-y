#pragma once

#include "Rectangle.hpp"
#include <iostream>

template <typename TPoint, typename TPerimetre = float, typename TSurface = float>
class Carre;

template <typename T>
std::ostream &operator<<(std::ostream &, Carre<T> &);

// Classe Carré héritée de Rectangle, on force la largeur et la hauteur à la même valeur
template <typename TPoint, typename TPerimetre, typename TSurface>
class Carre : public Rectangle<TPoint, TPerimetre, TSurface>
{
public:
    // Constructeurs
    Carre() : Rectangle<TPoint>() {}
    Carre(PointT<TPoint> const &p, TPoint cote) : Rectangle<TPoint>(p, cote, cote) {}
    virtual ~Carre() = default;

    // Accesseur
    TPoint getCote() const { return this->getH(); }

    // Mutateur
    void setCote(TPoint cote)
    {
        Rectangle<TPoint>::setH(cote);
        Rectangle<TPoint>::setL(cote);
    }

    // Redéfinition des mutateurs de Rectangle pour conserver l'invariant du carré
    TPoint setH(TPoint h)
    {
        setCote(h);
        return h;
    }
    TPoint setL(TPoint l)
    {
        setCote(l);
        return l;
    }
};

// Surcharge de l'opérateur d'affichage pour la classe Carre
template <typename T>
std::ostream &operator<<(std::ostream &o, Carre<T> &c)
{
    o << "Carré: origine=(" << c.getPoint().getX() << "," << c.getPoint().getY()
      << "), cote=" << c.getCote();
    return o;
}