#pragma once

#include "PointT.hpp"
#include <iostream>

template <typename T>
class Forme;

template <typename T>
std::ostream &operator<<(std::ostream &, Forme<T> const &);

// Classe forme, associée à la classe point
template <typename T>
class Forme
{
private:
    PointT<T> centre; // Centre de la forme

public:
    // Constructeurs
    Forme(PointT<T> p); // Création d'une forme en fonction d'un point P

    // Accesseurs
    PointT<T> getCentre();

    // Mutateurs
    void setCentre(PointT<T> value);

    // Méthodes
    //template <typename TPerimetre>
    //virtual TPerimetre perimetre() = 0; // Périmètre de la forme, fonction virtuelle

    //template <typename TSurface>
    //virtual TSurface surface() = 0; // Aire de la surface, fonction virtuelle

    friend std::ostream &operator<< <T>(std::ostream &, Forme const &);
};

// Création d'une forme en fonction d'un point P
template <typename T>
Forme<T>::Forme(PointT<T> p)
{
    centre = p;
}

// Surcharge de l'opérateur cout, pour afficher un point
template <typename T>
std::ostream &operator<<(std::ostream &o, Forme<T> const &R)
{
    o << "(" << R.getCentre().getX() << "," << R.getCentre().getY() << ")" << std::endl;
    return o;
}