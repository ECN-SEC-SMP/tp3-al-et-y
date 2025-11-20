#pragma once

// Bibliothèques
#include <iostream>

template<typename T>
class PointT;

template <typename T>
std::ostream& operator<<(std::ostream &, PointT<T> const&);

// Classe Point, à partir d'un template 'T'
template <typename T>
class PointT
{
protected:
    PointT<T> p;
    T x;
    T y;

public:
    // Constructeurs
    PointT(T x, T y) // Création d'un point en fonction de x et de y
    {
        this->x = x;
        this->y = y;
    }

    PointT(const PointT<T> &arg, T x, T y);

    // Accesseurs
    T getX() const { return this->x; }
    T getY() const { return this->y; }
    T getP() const { return this->p; }

    // Mutateurs
    T setX(T new_x) { this->x = new_x; }
    T setY(T new_y) { this->y = new_y; }
    T setP(T new_p) { this->p = new_p; }

    // Méthodes
    T translater(const T &new_x, const T &new_y); // Translation
};

// Création d'un point, copie superficielle
template <typename T>
PointT<T>::PointT(const PointT<T> &arg, T x, T y)
{
    this->p = arg;
    this->x = x;
    this->y = y;
}

// Fonction de translation de la classe PointT, prend en argument deux coordonnées du même type
template <typename T>
T translater(const T &new_x, const T &new_y)
{
    this->x = new_x + this->x;
    this->y = new_y + this->y;
}

// Surcharge opérateur cout, pour afficher un point
template <typename T>
std::ostream& operator<<(std::ostream &o, const PointT<T> &arg)
{
    o << "(" << "Nom :" << arg.getP() << ", " << "X :" << arg.getX() << ", " << "Y :" << arg.getY() << ")" << std::endl;
    return o;
}