#pragma once


// EN COURS
#include "Rectangle.hpp"
#include <iostream>

template <typename T>
class Carre;

template <typename T>
std::ostream &operator<<(std::ostream &, Carre<T> const &);

// Classe Carré (hérite de Rectangle) : impose h == l
template <typename T>
class Carre : public Rectangle<T>
{
public:
    // Constructeurs
    Carre() : Rectangle<T>() {}
    Carre(PointT<T> const &p, T cote) : Rectangle<T>(p, cote, cote) {}
    virtual ~Carre() = default;

    // Accesseur pour le côté
    T getCote() const { return this->getH(); }

    // Mutateur qui maintient h == l
    void setCote(T cote)
    {
        Rectangle<T>::setH(cote);
        Rectangle<T>::setL(cote);
    }

    // Redéfinition (cache/hide) des mutateurs de Rectangle pour conserver l'invariant du carré
    T setH(T h)
    {
        setCote(h);
        return h;
    }
    T setL(T l)
    {
        setCote(l);
        return l;
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Carre<T> const &c)
{
    o << "Carre: origine=(" << c.getPoint().getX() << "," << c.getPoint().getY()
      << "), cote=" << c.getCote();
    return o;
}