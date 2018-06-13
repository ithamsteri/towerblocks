# TowerBlocks game

![alt text](screenshot.png "screenshot")

Gameplay video: https://youtu.be/Z2A7I9lAfYM

## How to build

```bash
# Clone git repositories
git clone https://github.com/ithamsteri/towerblocks
git clone https://github.com/oxygine/oxygine-framework

# Set path for oxygine framework and generate build scripts
export OXYGINE_PATH=`pwd`/oxygine-framework
cmake -H./towerblocks -BBuild

# Build game
cd Build
cmake --build .

# Start game in data directory
cd ../towerblocks/data
./../../Build/towerblock
```