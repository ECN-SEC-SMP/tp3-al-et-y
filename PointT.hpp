#pragma once

// Bibliothèques
#include <iostream>

template <typename T>
class PointT;

template <typename T>
std::ostream &operator<<(std::ostream &, PointT<T> const &);

// Classe Point, à partir d'un template 'T'
template <typename T>
class PointT
{
protected:
    T x;
    T y;

public:
    // Constructeurs
    PointT(T x, T y) // Création d'un point en fonction de x et de y
    {
        this->x = x;
        this->y = y;
    }

    //Constructeur de copie
    PointT(const PointT<T> &arg) {
        this->x = arg.x;
        this->y = arg.y;
    }

    // Accesseurs
    T getX() const { return x; }
    T getY() const { return y; }

    // Mutateurs
    T setX(T new_x) { x = new_x; }
    T setY(T new_y) { y = new_y; }

    // Méthodes
    // Fonction de translation de la classe PointT, prend en argument deux coordonnées du même type
    T translater(const T &dx, const T &dy)
    {
        this->x += dx;
        this->y += dy;
    }
};

// Surcharge opérateur cout, pour afficher un point
template <typename T>
std::ostream &operator<<(std::ostream &o, const PointT<T> &arg)
{
    o << "(" << "Nom :" << arg.getP() << ", " << "X :" << arg.getX() << ", " << "Y :" << arg.getY() << ")" << std::endl;
    return o;
}