#ifndef TOWERBLOCKS_UNIT_H
#define TOWERBLOCKS_UNIT_H

#include "oxygine-framework.h"

class Game; // forward declaration

DECLARE_SMART(Unit, spUnit);

/// Base class for Game objects
class Unit : public oxygine::Object
{
public:
  void init(const oxygine::Vector2& pos, Game* game);

  void update(const oxygine::UpdateState& us);

  const oxygine::Vector2& getPosition() const { return _view->getPosition(); }

protected:
  virtual void _init() {}
  virtual void _update(const oxygine::UpdateState& us) {}

  oxygine::spActor _view;
  Game* _game{ nullptr };
};

#endif // TOWERBLOCKS_UNIT_H
