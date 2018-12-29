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
#include "Camera.h"

// Class is used to translate this domains math data to SFML drawable vertices.
class WireModel : public sf::Drawable {
 public:
  WireModel(Mesh mesh, Camera const &camera);

  void prepareDraw();

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  Mesh mesh_;
 private:
  mutable sf::VertexArray vertices_;
  Camera const &camera_;
};

#endif //LINAL_SPACESHIP_WIREMODEL_H
