#include <iostream>
#include "PointT.hpp"
#include "Rectangle.hpp"
#include "Carre.hpp"
#include "ListeFormes.hpp"

int main()
{

    // Test du constructeur a deux parametres
    PointT<float> p1(2.0, 3.0);
    std::cout << "Point p1 (constructeur parametre) : " << p1 << std::endl;

    // Test du constructeur de copie
    PointT<float> p2(p1);
    std::cout << "Point p2 (constructeur de copie a partir de p1) : " << p2 << std::endl;

    // Test des accesseurs
    std::cout << "Abscisse de p1 : " << p1.getX() << std::endl;
    std::cout << "Ordonnee de p1 : " << p1.getY() << std::endl;

    // Test des mutateurs
    p1.setX(10.0);
    p1.setY(20.0);
    std::cout << "p1 apres modification via les mutateurs : " << p1 << std::endl;

    // Test de translater()
    std::cout << "Translation de p1 de ( -3 , +5 )... ";
    p1.translater(-3.0, 5.0);
    std::cout << "p1 apres translation : " << p1 << std::endl;

    // Test sur un autre point
    PointT<float> p3(0.0, 0.0);
    std::cout << "p3 : " << p3 << std::endl;
    p3.translater(4.5, -2.5);
    std::cout << "p3 apres translation (4.5, -2.5) : " << p3 << std::endl;

    // Création d'un rectangle
    Rectangle<int> r1(PointT<int>(0, 0), 10, 5);
    std::cout << "Rectangle r1 : " << r1 << std::endl;
    std::cout << "Périmètre : " << r1.perimetre() << std::endl;
    std::cout << "Surface   : " << r1.surface() << std::endl;

    // Création d’un carré
    Carre<int> c1(PointT<int>(3, 4), 6);
    std::cout << "Carré c1 : " << c1 << std::endl;
    std::cout << "Périmètre : " << c1.perimetre() << std::endl;
    std::cout << "Surface   : " << c1.surface() << std::endl;

    ListeFormes<int> liste;

    Rectangle<int> r2(PointT<int>(0, 0), 10, 20);
    Carre<int>     c2(PointT<int>(5, 5), 6);

    liste.ajouter(&r2);
    liste.ajouter(&c2);

    auto bb = liste.boundingBox();

    std::cout << "Boîte englobante :" << std::endl;
    for (auto &p : bb.boundingBox())
        std::cout << "(" << p.getX() << "," << p.getY() << ")\n";
}