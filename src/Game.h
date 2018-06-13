#ifndef TOWERBLOCKS_GAME_H
#define TOWERBLOCKS_GAME_H

#include "oxygine-framework.h"
#include <forward_list>
#include "Unit.h"
#include "Crane.h"
#include "Background.h"
#include "Tower.h"

using namespace oxygine;

DECLARE_SMART(Game, spGame);

class Game : public oxygine::Actor {
  using List = std::forward_list<spUnit>;

public:
  void init();

  void doThrowBlock();

  List* getUnits() { return &_units; }

  bool isGameOver() const { return _lifes == 0; }

private:
  List _units;
  spBackground _background;
  spCrane _crane;
  spTower _tower;

  spTextField _textScores;
  spTextField _textLifes;
  spTextField _textTowerHeight;

  float _towerLine;
  unsigned int _lifes {5};

  void doUpdate(const oxygine::UpdateState& us) override;

};

#endif //TOWERBLOCKS_GAME_H
