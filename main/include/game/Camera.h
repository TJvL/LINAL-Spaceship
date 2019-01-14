//
// Created by thomas on 14-1-19.
//

#ifndef LINAL_SPACESHIP_CAMERA_H
#define LINAL_SPACESHIP_CAMERA_H

#include "NullDrawable.h"
#include "Updatable.h"
#include "../math/Mesh.h"

class Camera : public Updatable {
 public:
  Camera(Mesh camera);
  ~Camera();
  const Mesh &getCamera() const;
  sf::Drawable &update(const deltaTime &deltaTime, const std::map<sf::Keyboard::Key, bool> &keyboard) override;
 private:
  void setMovement(const sf::Keyboard::Key &key, const bool isPressed);
  void moveVertical(Mesh &mesh, float moveAmount);
  void moveHorizontal(Mesh &mesh, float moveAmount);
  bool movingForwards_;
  bool movingBackwards_;
  bool movingLeft_;
  bool movingRight_;
  Mesh camera_;
  NullDrawable *drawable_;
};

#endif //LINAL_SPACESHIP_CAMERA_H
