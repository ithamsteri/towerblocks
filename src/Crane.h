#ifndef TOWERBLOCKS_CRANE_H
#define TOWERBLOCKS_CRANE_H

#include "Unit.h"
#include "oxygine-framework.h"

using namespace oxygine;

DECLARE_SMART(Crane, spCrane);

/// Crane is mechanical pendulum.
class Crane : public Unit {
public:
  void doNewBlock();

  spSprite doThrowBlock();

protected:
  const float pi = std::acos(-1.0f);
  const float gravity = -0.981f;

  enum class States {
    FromBase, Working, ToBase, Waiting,
  };

  void _init() override;
  void _update(const UpdateState &us) override;

  // block for magnit
  spSprite _block;

  // Pendulum simulation parameters
  float _length{0.00f}, _speed{-8.5f}, _velocity{0.0f}, _acceleration{0.0f},
      _angle{0.5f * pi};

  // TODO: Start with FromBase state
  States _state = { States::Waiting };
};

#endif // TOWERBLOCKS_CRANE_H
