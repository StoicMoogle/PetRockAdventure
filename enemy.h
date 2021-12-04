#include "character.h"
using namespace std;

class enemy : public character {
  public:
  enemy(string enteredName, string enteredDescription) : character(string enteredName, string enteredDescription) {};

  void fight(character *other);
  bool isAlive();
  void setStats(int level);
};
