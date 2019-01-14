//
// Created by thomas on 14-1-19.
//

#ifndef LINAL_SPACESHIP_NULLDRAWABLE_H
#define LINAL_SPACESHIP_NULLDRAWABLE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class NullDrawable : public sf::Drawable {
 public:
  inline void draw(sf::RenderTarget &target, sf::RenderStates states) const override {}
};

#endif //LINAL_SPACESHIP_NULLDRAWABLE_H
