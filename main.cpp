#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "player.h"
#include "enemy.h"
#include <random>
using namespace std;

void delayScroll(int delayInMS, int lineCount);

int main() {
  string playerName;
  string intro =
  "            _____         \n"
  "        __ /__    \\__    \n"
  "     _ /      \\    __\\  \n"
  "    /          \\__ /  \\ \n"
  "   |   O          O   |   \n"
  "   |      ______      /   \n"
  "    \\     \\____/     /  \n"
  "     \\______________/    \n\n"
  "--------------------------\n"
  "--- PET ROCK ADVENTURE ---\n"
  "--------------------------  ";

  cout << intro << endl;
  cout << "Name Your Rock: ";
  getline(cin, playerName);
  cout << endl << "That's a great name!" << endl;

  cout << "It looks like " << playerName << " is ready for an adventure. ";
  cout << "Time to go out and explore..." << endl;

  this_thread::sleep_for(chrono::milliseconds(3000));
  
  delayScroll(100, 10);
  
  character *generateEnemy(){
    string nameTemp;
    string descTemp;
    int levelTemp;

    random_device rd;
    int enemySelect = rd() % 3;
    switch(enemySelect) {
      case 0:
        nameTemp = "Umbrella";
        descTemp = "- It dries you from the rain!";
        int levelTemp = 1;
        break;
      case 1:
        nameTemp = "Sunglasses";
        descTemp = "- To protect you from the sun!";
        int levelTemp = 2;
        break;

      case 2:
        nameTemp = "Parachute";
        descTemp = "- Slows your descent to the ground!";
        int levelTemp = 3;
        break;  
    }

    character *e = new enemy(nameTemp, descTemp);
    e->setStats(levelTemp);
    return e;

  }

}


void encounterEnemy(character *player, character *enemy) {
  while(player->isAlive() && enemy->isAlive()) {
    delayScroll(1500, 1);
    player->fight(enemy);
    if(enemy->currentHealth > 0) {
        delayScroll(1500, 1);
        enemy->fight(player);
    }
  }

  if(player->isAlive() == false) {
    cout << "DEFEAT! Looks like " << enemy->name << " knocked out " << player->name << "!" << endl;
    cout << "Hope you had fun! Try to survive a bit longer." << endl;
  }
  else {
    cout << "VICTORY! Looks like " << player->name << " destroyed " << enemy->name << "!" << endl;
    cout << "Let's continue the adventure!" << endl;

    this_thread::sleep_for(chrono::milliseconds(2000));
    delayScroll(100, 10);
    fightDecisions(player);
  }

}

void fightDecisions(character *player) {
  character *anEnemy = generateEnemy();
  cout << "You encounter "; 
  anEnemy->describe();
  cout << "The enemy has " << enemy->currentHealth << " health!" << endl;
  cout << "The enemy has " << enemy->damage << " Attack!" << endl;

}

void delayScroll(int delayInMS, int lineCount) {
  for(int i = 0; i < lineCount; i++) {
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(delayInMS));
  }
}
