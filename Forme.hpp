#pragma once

#include "PointT.hpp"
#include <iostream>
#include <array>

// C++ 14: types par défaut dans les templates
template <typename TPoint, typename TPerimetre = float, typename TSurface = float>
class Forme;

template <typename T>
std::ostream &operator<<(std::ostream &, Forme<T> const &);

// Classe forme
template <typename TPoint, typename TPerimetre, typename TSurface>
class Forme
{
private:
    PointT<TPoint> centre; // Centre de la forme

public:
    // Constructeurs
    Forme(PointT<TPoint> const & p); // Création d'une forme en fonction d'un point P

    // Accesseurs
    PointT<TPoint> getPoint() {return centre;}

    // Mutateurs
    void setCentre(PointT<TPoint> value);

    // Méthodes
    virtual TPerimetre perimetre() = 0; // Périmètre de la forme, fonction virtuelle

    virtual TSurface surface() = 0; // Aire de la surface, fonction virtuelle

    virtual std::array<PointT<TPoint>, 4> boundingBox() = 0; // Liste des points, fonction virtuelle

    friend std::ostream &operator<< <TPoint>(std::ostream &, Forme const &);
};

// Création d'une forme en fonction d'un point P
template <typename TPoint, typename TPerimetre, typename TSurface>
Forme<TPoint, TPerimetre, TSurface>::Forme(PointT<TPoint>const & p) : centre(p)
{
}

// Surcharge de l'opérateur cout, pour afficher un point
template <typename TPoint, typename TPerimetre, typename TSurface>
std::ostream &operator<<(std::ostream &o, Forme<TPoint, TPerimetre, TSurface> const &R)
{
    o << "(" << R.getPoint().getX() << "," << R.getPoint().getY() << ")" << std::endl;
    return o;
}