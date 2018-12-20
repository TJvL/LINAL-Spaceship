//
// Created by thomas on 19-12-18.
//

#ifndef LINAL_SPACESHIP_WIREMODEL_H
#define LINAL_SPACESHIP_WIREMODEL_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include "../math/Mesh.h"

// Class is used to translate this domains math data to SFML drawable vertices.
class WireModel : public sf::Drawable {
 public:
  WireModel(Mesh &&mesh);

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
 private:
  Mesh mesh_;
  sf::VertexArray vertices_;
};

#endif //LINAL_SPACESHIP_WIREMODEL_H
