#ifndef TOWERBLOCKS_STAGE_H
#define TOWERBLOCKS_STAGE_H

#include "Unit.h"
#include <list>

using namespace oxygine;

DECLARE_SMART(Background, spBackground);

/// The Background is responsible for background objects.
class Background : public Unit
{
public:
  void offsetDown(float offset, int ms);
  void addCloud();

protected:
  std::list<spSprite> _objects;

  void _init() override;
  void _update(const UpdateState& us) override;
};

#endif // TOWERBLOCKS_STAGE_H
