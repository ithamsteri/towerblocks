#include "Crane.h"
#include "Game.h"
#include "Resource.h"
#include <cmath>

spSprite
Crane::doThrowBlock()
{
  if (_state != States::Working) {
    return nullptr;
  }

  _block->detach();
  _block->setPosition(_view->getPosition());

  // return crane to base
  auto t = _view->addTween(TweenDummy(), 50);
  t->addEventListener(TweenEvent::DONE, [this](Event*) { moveToBase(); });

  return _block;
}

void
Crane::_init()
{
  spSprite magnit = new Sprite;
  magnit->setResAnim(res::ui.getResAnim("Game_CraneMagnet"));
  magnit->setAnchor(0.5f, 1.0f);
  magnit->attachTo(_view);
  magnit->setPriority(50);

  // set starting position
  _basePosition = { _game->getSize().x / 2, -120 };
  _view->setPosition(_basePosition);

  // set length rope of crane
  _length = _game->getSize().x / 2 - _game->getSize().x * 0.20f;

  moveFromBase();
}

void
Crane::_update(const UpdateState& us)
{
  if (_state != States::Working) {
    return;
  }

  // TODO: Make Oxygine Tween for pendulum move
  _acceleration = gravity / _length * std::sin(_angle);
  _velocity += _acceleration / us.dt * _speed;
  _angle += _velocity / us.dt * _speed;

  float x = _game->getSize().x / 2 + std::sin(_angle) * _length;
  float y = std::cos(_angle) * 0.5f * _length;

  _view->setPosition(x, y);
}

void
Crane::moveFromBase()
{
  _state = States::FromBase;

  _block = getNewBlock();
  _block->attachTo(_view);

  // reset all parameters for pendulum
  _velocity = 0.0f;
  _acceleration = 0.0f;
  _angle = (-0.5f * pi);

  // TODO: "Don't Repeat Yourself (DRY)"
  float x = _game->getSize().x / 2 + std::sin(_angle) * _length;
  float y = std::cos(_angle) * 0.5f * _length;

  auto t = _view->addTween(Actor::TweenPosition(x, y), speedAnimation);
  t->addEventListener(TweenEvent::DONE, [this](Event*) { _state = States::Working; });
}

void
Crane::moveToBase()
{
  _state = States::ToBase;

  auto t = _view->addTween(Actor::TweenPosition(_basePosition), speedAnimation);
  t->addEventListener(TweenEvent::DONE, [this](Event*) { this->moveFromBase(); });
}

spSprite
Crane::getNewBlock() const
{
  int blockNum = static_cast<int>(scalar::randFloat(0.0f, 7.0f)) + 1;

  auto block = new Sprite;
  block->setResAnim(res::ui.getResAnim("Block" + std::to_string(blockNum)));
  block->setAnchor(0.5f, 0.25f);

  return block;
}