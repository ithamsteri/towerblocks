#include "Background.h"
#include "Game.h"
#include "Resource.h"

void
Background::offsetDown(float offset, int ms)
{
  for (const auto& object : _objects) {
    auto pos = object->getPosition();
    object->addTween(Actor::TweenPosition(pos.x, pos.y + offset), ms);
  }
}

void
Background::addCloud()
{
  spSprite cloud = new Sprite;
  cloud->setResAnim(res::ui.getResAnim("Cloud1"));
  cloud->setPosition(-1 * cloud->getSize().x, -1 * cloud->getSize().y);
  cloud->attachTo(_view);
  cloud->addTween(Actor::TweenX(_game->getSize().x), 20000, -1, true); // TODO: Change value 20000 on random value

  _objects.push_front(cloud);
}

void
Background::_init()
{
  // create start background
  spSprite bgStart = new Sprite;
  bgStart->setResAnim(res::ui.getResAnim("Game_bg_start"));
  bgStart->attachTo(_view);

  _objects.push_front(bgStart);
}
