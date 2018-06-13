#include "Crane.h"
#include "Resource.h"
#include "Game.h"
#include <cmath>

void Crane::_update(const oxygine::UpdateState &us) {
  if (_length > 0) {
    _acceleration = gravity / _length * std::sin(_angle);
    _velocity += _acceleration / us.dt * _speed;
    _angle += _velocity / us.dt * _speed;

    float x = _game->getSize().x / 2 + std::sin(_angle) * _length;
    float y = std::cos(_angle) * 0.5f * _length;

    _view->setPosition(x, y);
  }

  if (_state != States::Working) {
    if (_state == States::ToBase) {
      if (_length <= 0) {
        _state = States::Waiting;
        _length = 0;
      }
      _length -= 5;
    }
  }
}

void Crane::_init() {

  oxygine::spSprite magnit = new oxygine::Sprite;
  magnit->setResAnim(res::ui.getResAnim("Game_CraneMagnit"));
  magnit->setAnchor(0.5f, 1.0f);
  magnit->attachTo(_view);
  magnit->setPriority(100);
}

spSprite Crane::doThrowBlock() {
  if (_state != States::Working) {
    return nullptr;
  }

  _state = States::ToBase;

  _block->detach();
  _block->setPosition(_view->getPosition());

  return _block;
}

void Crane::doNewBlock() {
  if (_state != States::Waiting) {
    return;
  }

  int blockNum = static_cast<int>(scalar::randFloat(0.0f, 7.0f)) + 1;

  _block = new oxygine::Sprite;
  _block->setResAnim(res::ui.getResAnim("Block" + std::to_string(blockNum)));
  _block->setAnchor(0.5f, 0.25f);
  _block->attachTo(_view);

  _length = _game->getSize().x / 2 - _game->getSize().x * 0.20f;
  _velocity = 0.0f;
  _acceleration = 0.0f;
  _angle = (-0.5f * pi);

  _state = States::Working;
}
