//
// Created by thomas on 19-12-18.
//

#include "../../include/game/WireModel.h"

WireModel::WireModel(Mesh mesh)
    : mesh_(mesh)
    , vertices_(sf::Lines, mesh_.numberOfEdges()*2) {}

void WireModel::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}
