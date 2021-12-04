#include "character.h"
using namespace std;

class player : public character {
  public:
  player(string enteredName, string enteredDescription) : character(string enteredName, string enteredDescription) {};

  void fight(character *other);
  bool isAlive();
  void setStats(int level);
};
