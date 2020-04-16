//
// Created by Collin Stratton on 4/12/20.
//

#ifndef FANTASYFIGHTINGGAME_CHARACTERS_H
#define FANTASYFIGHTINGGAME_CHARACTERS_H

#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Entity.h"

using namespace std;

class Characters {
private:
    Entity* characters;
    vector <Entity*> characterVec;

public:
    Characters() {
        srand (time(NULL));

        characters = new Player("Player", 100, 0, "Sword", 5, 0, 1, true, 0, 0, false); // 0
        characters = new Monster("Shop", 0, 5, "", 0, 0, 0, true, 0); // 1
        characters = new Monster("Shop", 0, 9, "", 0, 0, 0, true, 0); // 2
        characters = new Monster("Shop", 0, 19, "", 0, 0, 0, true, 0); // 3

        characters = new Monster("Bandit", 20, 3, "Dagger", (rand() % 5 + 1), 0, 2, true, (rand() % 10 + 1)); // 4
        characters = new Monster("Bandit", 20, 6, "Dagger", (rand() % 5 + 1), 0, 2, true, (rand() % 10 + 1)); // 5

        characters = new Monster("Spider", 25, 8, "Webs", (rand() % 5 + 6), 0, 4, true, (rand() % 10 + 6)); // 6
        characters = new Monster("Spider", 25, 10, "Webs", (rand() % 5 + 6), 0, 4, true, (rand() % 10 + 6)); // 7
        characters = new Monster("Spider", 25, 11, "Webs", (rand() % 5 + 6), 0, 4, true, (rand() % 10 + 6)); // 8

        characters = new Monster("Marauder", 40, 12, "Axe", (rand() % 5 + 11), 1, 3, true, (rand() % 10 + 21)); // 9
        characters = new Monster("Marauder", 40, 14, "Axe", (rand() % 5 + 11), 1, 3, true, (rand() % 10 + 21)); // 10
        characters = new Monster("Marauder", 40, 18, "Axe", (rand() % 5 + 11), 1, 3, true, (rand() % 10 + 21)); // 11

        characters = new Boss(); // 12
    }

    bool isShop(int playerPos) {for(int i = 1; i < characterVec.size(); i++) {if(playerPos == characterVec[i]->GetPosition() && characterVec[i]->GetName() == "Shop") {return true;}}}
    bool isMonster(int playerPos) {for(int i = 1; i < characterVec.size(); i++) {if(playerPos == characterVec[i]->GetPosition()) {return true;}}}

    bool isPlayerAlive() {return characterVec[0]->GetHealth() > 0;}
    bool isMonsterAlive(int x) {return characterVec[x]->GetHealth() > 0;}
    bool isBossAlive() {return characterVec[12]->GetHealth() > 0;}

    string GetMonsterName(int x) {return characterVec[x]->GetName();}
    int GetMonsterInit(int x) {return characterVec[x]->GetInit();}
    double GetMonsterDamage(double x) {return characterVec[x]->GetDamage();}
    double GetMonsterExtraDamage(int x) {return characterVec[x]->GetExtraDamage();}
    double GetMonsterHealth(int x) {return characterVec[x]->GetHealth();}
    int GetBossInit() {return characterVec[12]->GetInit();}

    void SetMonsterHealth(int x, double y) {characterVec[x]->SetHealth(characterVec[x]->GetHealth() - y);}

    string GetPlayerName() {return characterVec[0]->GetName();}
    int GetPlayerPosition() {return characterVec[0]->GetPosition();}
    double GetPlayerDamage() {return characterVec[0]->GetDamage();}
    double GetPlayerExtraDamage() {return characterVec[0]->GetExtraDamage();}
    int GetPlayerInit() {return characterVec[0]->GetInit();}
    double GetPlayerHealth() {return characterVec[0]->GetHealth();}
    int GetPlayerGold() {return characterVec[0]->GetGold();}

    void SetPlayerPosition(int playerPos) {characterVec[0]->SetPosition(playerPos);}
    void SetPlayerFighting(bool fighting) {characterVec[0]->SetFighting(fighting);}
    void SetPlayerWeapon(string name, double d, double ed, int i, int g) {
        characterVec[0]->SetName(name);
        characterVec[0]->SetDamage(d);
        characterVec[0]->SetExtraDamage(ed);
        characterVec[0]->SetInit(i);
        characterVec[0]->SetGold(g);
    }
    void DamagePlayerHealth(double h) {characterVec[0]->SetHealth(characterVec[0]->GetHealth() - h);}
    void SetPlayerHealth(double h, int g) {
        characterVec[0]->SetHealth(h);
        characterVec[0]->SetGold(g);
    }
    void SetPlayerArmor(int d, int g) {
        characterVec[0]->SetDefense(d);
        characterVec[0]->SetGold(g);
    }
};


#endif //FANTASYFIGHTINGGAME_CHARACTERS_H
