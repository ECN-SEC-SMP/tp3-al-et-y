#pragma once

#include <vector>
#include <limits>
#include "Forme.hpp"
#include "Rectangle.hpp"

template <typename TPoint, typename TPerimetre = float, typename TSurface = float>
class ListeFormes
{
private:
    std::vector<Forme<TPoint, TPerimetre, TSurface>*> formes;

public:

    // Ajouter une forme dans la liste
    void ajouter(Forme<TPoint, TPerimetre, TSurface>* f) {
        formes.push_back(f);
    }

    std::size_t taille() const {
        return formes.size();
    }

    Forme<TPoint, TPerimetre, TSurface>* operator[](std::size_t i) {
        return formes[i];
    }

    // Surface totale de toutes les formes
    TSurface surfaceTotale() const {
        TSurface total{};
        for (auto f : formes)
            total += f->surface();
        return total;
    }

    // Boîte englobante exprimée sous forme de rectangle
    Rectangle<TPoint, TPerimetre, TSurface> boundingBox() const {

        if (formes.empty()) {
            return Rectangle<TPoint, TPerimetre, TSurface>(
                PointT<TPoint>(0,0), 0, 0
            );
        }

        TPoint xmin = std::numeric_limits<TPoint>::max();
        TPoint ymin = std::numeric_limits<TPoint>::max();
        TPoint xmax = std::numeric_limits<TPoint>::lowest();
        TPoint ymax = std::numeric_limits<TPoint>::lowest();

        // On visite la boundingBox (4 sommets) de chaque forme
        for (auto f : formes) {
            auto bb = f->boundingBox();   // array<4 points>

            for (const auto& pt : bb) {
                xmin = std::min(xmin, pt.getX());
                ymin = std::min(ymin, pt.getY());
                xmax = std::max(xmax, pt.getX());
                ymax = std::max(ymax, pt.getY());
            }
        }

        // Construire le rectangle final
        return Rectangle<TPoint, TPerimetre, TSurface>(
            PointT<TPoint>(xmin, ymin),     // Coin bas gauche
            ymax - ymin,                    // Hauteur
            xmax - xmin                     // Largeur
        );
    }
};
