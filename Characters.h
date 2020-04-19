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
    Characters() { // Creates all the characters in the game
        srand (time(NULL));

        characters = new Player("Player", 250, 0, "Sword", (rand() % 5 + 3), 0, 1, true, 0, 20, false); // 0
        characterVec.push_back(characters);
        characters = new Monster("Shop", 0, 5, "", 0, 0, 0, true, 0); // 1
        characterVec.push_back(characters);
        characters = new Monster("Shop", 0, 9, "", 0, 0, 0, true, 0); // 2
        characterVec.push_back(characters);
        characters = new Monster("Shop", 0, 19, "", 0, 0, 0, true, 0); // 3
        characterVec.push_back(characters);

        characters = new Monster("Bandit", 20, 3, "Dagger", (rand() % 5 + 1), 0, 2, true, (rand() % 10 + 1)); // 4
        characterVec.push_back(characters);
        characters = new Monster("Bandit", 20, 6, "Dagger", (rand() % 5 + 1), 0, 2, true, (rand() % 10 + 1)); // 5
        characterVec.push_back(characters);

        characters = new Monster("Spider", 25, 8, "Webs", (rand() % 5 + 6), 0, 4, true, (rand() % 10 + 6)); // 6
        characterVec.push_back(characters);
        characters = new Monster("Spider", 25, 10, "Webs", (rand() % 5 + 6), 0, 4, true, (rand() % 10 + 6)); // 7
        characterVec.push_back(characters);
        characters = new Monster("Spider", 25, 11, "Webs", (rand() % 5 + 6), 0, 4, true, (rand() % 10 + 6)); // 8
        characterVec.push_back(characters);

        characters = new Monster("Marauder", 40, 12, "Axe", (rand() % 5 + 11), 1, 3, true, (rand() % 10 + 21)); // 9
        characterVec.push_back(characters);
        characters = new Monster("Marauder", 40, 14, "Axe", (rand() % 5 + 11), 1, 3, true, (rand() % 10 + 21)); // 10
        characterVec.push_back(characters);
        characters = new Monster("Marauder", 40, 18, "Axe", (rand() % 5 + 11), 1, 3, true, (rand() % 10 + 21)); // 11
        characterVec.push_back(characters);

        characters = new Boss(); // 12
        characterVec.push_back(characters);
    }

    // Checks for shop and monster at player position
    bool isShop(int playerPos) {for(int i = 1; i < characterVec.size(); i++) {if(playerPos == characterVec[i]->GetPosition() && characterVec[i]->GetName() == "Shop") {return true;}}}
    bool isMonster(int playerPos) {for(int i = 1; i < characterVec.size(); i++) {if(playerPos == characterVec[i]->GetPosition() && characterVec[i]->GetName() != "Shop") {return true;}}}

    // Checks to see if entities are alive
    bool isPlayerAlive() {return characterVec[0]->GetHealth() > 0;}
    bool isMonsterAlive(int playerPos) {for(int i = 1; i < characterVec.size(); i++) {if(playerPos == characterVec[i]->GetPosition() && characterVec[i]->GetHealth() > 0) {return true;}}}
    bool isBossAlive() {return characterVec[12]->GetHealth() > 0;}

    // Grabs useful information from Monsters at the player position
    string GetMonsterName(int playerPos) {for(int i = 1; i < characterVec.size(); i++) {if(playerPos == characterVec[i]->GetPosition()) {return characterVec[i]->GetName();}}}
    double GetMonsterHealth(int playerPos) {for(int i = 1; i < characterVec.size(); i++) {if(playerPos == characterVec[i]->GetPosition()) {return characterVec[i]->GetHealth();}}}
    double GetMonsterDamage(double playerPos) {for(int i = 1; i < characterVec.size(); i++) {if(playerPos == characterVec[i]->GetPosition()) {return characterVec[i]->GetDamage();}}}
    double GetMonsterExtraDamage(int playerPos) {for(int i = 1; i < characterVec.size(); i++) {if(playerPos == characterVec[i]->GetPosition()) {return characterVec[i]->GetExtraDamage();}}}
    int GetMonsterInit(int playerPos) {for(int i = 1; i < characterVec.size(); i++) {if(playerPos == characterVec[i]->GetPosition()) {return characterVec[i]->GetInit();}}}
    int GetMonsterGold(int playerPos) {for(int i = 1; i < characterVec.size(); i++) {if(playerPos == characterVec[i]->GetPosition()) {return characterVec[i]->GetGold();}}}

    // Grabs useful information about the boss
    string GetBossName() {return characterVec[12]->GetName();}
    int GetBossPosition() {return characterVec[12]->GetPosition();}
    double GetBossDamage() {return characterVec[12]->GetDamage();}
    double GetBossExtraDamage() {return characterVec[12]->GetExtraDamage();}
    int GetBossInit() {return characterVec[12]->GetInit();}
    double GetBossHealth() {return characterVec[12]->GetHealth();}

    // Sets the health of the boss and monster after receiving damage
    void DamageMonsterHealth(int playerPos, double damage) {for(int i = 1; i < characterVec.size(); i++) {if(playerPos == characterVec[i]->GetPosition()) {characterVec[i]->SetHealth(characterVec[i]->GetHealth() - damage);}}}
    void DamageBossHealth(double damage) {characterVec[12]->SetHealth(characterVec[12]->GetHealth() - damage);}

    // Sets the health of the player and monster
    void SetMonsterHealth(int x, double health) {characterVec[x]->SetHealth(health);}
    void SetBossHealth(double health) {characterVec[12]->SetHealth(health);}

    // Grabs useful information about the player
    string GetPlayerName() {return characterVec[0]->GetName();}
    int GetPlayerPosition() {return characterVec[0]->GetPosition();}
    double GetPlayerDamage() {return characterVec[0]->GetDamage();}
    double GetPlayerExtraDamage() {return characterVec[0]->GetExtraDamage();}
    int GetPlayerArmor() {return characterVec[0]->GetDefense();}
    int GetPlayerInit() {return characterVec[0]->GetInit();}
    double GetPlayerHealth() {return characterVec[0]->GetHealth();}
    int GetPlayerGold() {return characterVec[0]->GetGold();}

    // Sets data for the player
    void SetPlayerName(string playerName) {characterVec[0]->SetName(playerName);}
    void SetPlayerPosition(int playerPos) {characterVec[0]->SetPosition(playerPos);}
    void SetPlayerWeapon(double d, double ed, int i, int g) {
        characterVec[0]->SetDamage(d);
        characterVec[0]->SetExtraDamage(ed);
        characterVec[0]->SetInit(i);
        characterVec[0]->SetGold(g);
    }
    void DamagePlayerHealth(double h) {if(characterVec[0]->GetHealth() - h < characterVec[0]->GetHealth()) {characterVec[0]->SetHealth(characterVec[0]->GetHealth() - h);}}
    void SetPlayerHealth(double h, int g) {
        characterVec[0]->SetHealth(h);
        characterVec[0]->SetGold(g);
    }
    void SetPlayerArmor(int d, int g) {
        characterVec[0]->SetDefense(d);
        characterVec[0]->SetGold(g);
    }
    void SetPlayerGold(int g) {characterVec[0]->SetGold(g + characterVec[0]->GetGold());}
    void DisplayPlayerStats() {characterVec[0]->DisplayStats();}
};


#endif //FANTASYFIGHTINGGAME_CHARACTERS_H
