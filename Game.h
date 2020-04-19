//
// Created by Collin Stratton on 4/7/20.
//

#ifndef FANTASYFIGHTINGGAME_GAME_H
#define FANTASYFIGHTINGGAME_GAME_H

#include "Characters.h"
#include "Shop.h"
#include "NextMove.h"
#include "SaveLoadGame.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

class Game {
private:
    Characters* entities;
    Shop* shopItems;
    NextMove* nextMove;

public:
    Game() { // constructor
        nextMove = new NextMove("");
        entities = new Characters();
        shopItems = new Shop(entities);
    }

    void Description(int playerPos) { // Displays descriptions of the environment
        nextMove->ClearPair();
        ifstream fin("description.n");                       // Grabs the text
        if(!fin) {
            cout << "File not found - exiting";
            exit(2);
        }

        string s;
        while(fin) {
            getline(fin, s);
            stringstream check1(s);
            string intermediate1, intermediate2;
            int location;

            getline(check1, intermediate1, '/');     // Gets the first value in every line

            int pos;
            istringstream(intermediate1) >> pos;                 // Converts the value into an int

            if(pos == playerPos) {                               // Checks the converted value against the player position
                getline(check1, intermediate1, '/');
                nextMove->SetDescription(intermediate1);
                while(getline(check1, intermediate1, '/')) {
                    getline(check1, intermediate2, '/');
                    istringstream(intermediate2) >> location;
                    nextMove->AddPair(intermediate1[0], location);
                }
            }
        }

        cout << nextMove->GetDescription() << endl;

        fin.close();
    }

    void BossFight() {
        int pInit = entities->GetPlayerInit();
        int bInit = entities->GetBossInit();
        do { // loop until the monster or player is dead
            if(pInit >= bInit && entities->isPlayerAlive() && entities->isBossAlive()) { // Player gets first initiative
                cout << endl << entities->GetPlayerName() << " gets initiative" << endl;
                double damageDealt = entities->GetPlayerDamage();
                double extraDamage = entities->GetPlayerExtraDamage(); // Player damage retrieved
                entities->DamageBossHealth((damageDealt + extraDamage)); // Damage removed from boss health
                sleep_until(system_clock::now() + seconds(2));
                cout << entities->GetPlayerName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                cout << entities->GetBossName() << " has " << entities->GetBossHealth() << " points of health left" << endl << endl;
                sleep_until(system_clock::now() + seconds(1));

                if((pInit/2) > bInit && entities->isPlayerAlive() && entities->isBossAlive()) { // Player gets second initiative if there init is two times higher than the monsters
                    cout << endl << entities->GetPlayerName() << " gets initiative" << endl;
                    damageDealt = entities->GetPlayerDamage();
                    extraDamage = entities->GetPlayerExtraDamage(); // Player damage retrieved
                    entities->DamageBossHealth((damageDealt + extraDamage)); // Damage removed from boss health
                    sleep_until(system_clock::now() + seconds(2));
                    cout << entities->GetPlayerName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                    cout << entities->GetBossName() << " has " << entities->GetBossHealth() << " points of health left" << endl << endl;
                    sleep_until(system_clock::now() + seconds(1));

                    if(entities->isPlayerAlive() && entities->isBossAlive()) {
                        cout << entities->GetBossName() << " gets initiative" << endl; // Boss gets final turn
                        damageDealt = entities->GetBossDamage();
                        extraDamage = entities->GetBossExtraDamage(); // retrieves boss damage
                        entities->DamagePlayerHealth((damageDealt + extraDamage) - entities->GetPlayerArmor()); // Damage - Defense value removed from player health
                        sleep_until(system_clock::now() + seconds(2));
                        cout << entities->GetBossName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                        cout << entities->GetPlayerName() << " blocked " << entities->GetPlayerArmor() << " points of damage" << endl;
                        cout << entities->GetPlayerName() << " has " << entities->GetPlayerHealth() << " points of health left" << endl;
                        sleep_until(system_clock::now() + seconds(1));
                    }
                } else if(entities->isPlayerAlive() && entities->isBossAlive()) {
                    cout << entities->GetBossName() << " gets initiative" << endl; // Boss gets final turn
                    damageDealt = entities->GetBossDamage();
                    extraDamage = entities->GetBossExtraDamage(); // retrieves boss damage
                    entities->DamagePlayerHealth((damageDealt + extraDamage) - entities->GetPlayerArmor()); // Damage - Defense value removed from player health
                    sleep_until(system_clock::now() + seconds(2));
                    cout << entities->GetBossName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                    cout << entities->GetPlayerName() << " blocked " << entities->GetPlayerArmor() << " points of damage" << endl;
                    cout << entities->GetPlayerName() << " has " << entities->GetPlayerHealth() << " points of health left" << endl;
                    sleep_until(system_clock::now() + seconds(1));
                }
            } else if(entities->isPlayerAlive() && entities->isBossAlive()) { // Monster gets first initiative
                cout << entities->GetBossName() << " gets initiative" << endl; // Boss gets final turn
                double damageDealt = entities->GetBossDamage();
                double extraDamage = entities->GetBossExtraDamage(); // retrieves boss damage
                entities->DamagePlayerHealth((damageDealt + extraDamage) - entities->GetPlayerArmor()); // Damage - Defense value removed from player health
                sleep_until(system_clock::now() + seconds(2));
                cout << entities->GetBossName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                cout << entities->GetPlayerName() << " blocked " << entities->GetPlayerArmor() << " points of damage" << endl;
                cout << entities->GetPlayerName() << " has " << entities->GetPlayerHealth() << " points of health left" << endl;
                sleep_until(system_clock::now() + seconds(1));

                if((bInit/2) >= pInit && entities->isPlayerAlive() && entities->isBossAlive()) { // Monster gets second initiative if their init is two times higher than the players
                    cout << entities->GetBossName() << " gets initiative" << endl; // Boss gets final turn
                    damageDealt = entities->GetBossDamage();
                    extraDamage = entities->GetBossExtraDamage(); // retrieves boss damage
                    entities->DamagePlayerHealth((damageDealt + extraDamage) - entities->GetPlayerArmor()); // Damage - Defense value removed from player health
                    sleep_until(system_clock::now() + seconds(2));
                    cout << entities->GetBossName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                    cout << entities->GetPlayerName() << " blocked " << entities->GetPlayerArmor() << " points of damage" << endl;
                    cout << entities->GetPlayerName() << " has " << entities->GetPlayerHealth() << " points of health left" << endl;
                    sleep_until(system_clock::now() + seconds(1));

                    if(entities->isPlayerAlive() && entities->isBossAlive()) {
                        cout << endl << entities->GetPlayerName() << " gets initiative" << endl;
                        damageDealt = entities->GetPlayerDamage();
                        extraDamage = entities->GetPlayerExtraDamage(); // Player damage retrieved
                        entities->DamageBossHealth((damageDealt + extraDamage)); // Damage removed from boss health
                        sleep_until(system_clock::now() + seconds(2));
                        cout << entities->GetPlayerName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                        cout << entities->GetBossName() << " has " << entities->GetBossHealth() << " points of health left" << endl << endl;
                        sleep_until(system_clock::now() + seconds(1));
                    }
                } else if(entities->isPlayerAlive() && entities->isBossAlive()) {
                    cout << endl << entities->GetPlayerName() << " gets initiative" << endl;
                    damageDealt = entities->GetPlayerDamage();
                    extraDamage = entities->GetPlayerExtraDamage(); // Player damage retrieved
                    entities->DamageBossHealth((damageDealt + extraDamage)); // Damage removed from boss health
                    sleep_until(system_clock::now() + seconds(2));
                    cout << entities->GetPlayerName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                    cout << entities->GetBossName() << " has " << entities->GetBossHealth() << " points of health left" << endl << endl;
                    sleep_until(system_clock::now() + seconds(1));
                }
            }
        } while(entities->isPlayerAlive() && entities->isBossAlive());
        if(entities->isPlayerAlive()) {entities->SetPlayerPosition(22);} else {entities->SetPlayerPosition(23);}
    }

    void Fighting(int mPos) {
        int pInit = entities->GetPlayerInit();
        int mInit = entities->GetMonsterInit(mPos);
        do { // loop until the monster or player is dead
            if(pInit >= mInit && entities->isPlayerAlive() && entities->isMonsterAlive(entities->GetPlayerPosition())) { // Player gets first initiative
                cout << endl << entities->GetPlayerName() << " gets initiative" << endl;
                double damageDealt = entities->GetPlayerDamage();
                double extraDamage = entities->GetPlayerExtraDamage(); // Player damage retrieved
                entities->DamageMonsterHealth(entities->GetPlayerPosition(), (damageDealt + extraDamage)); // Damage removed from monster health
                sleep_until(system_clock::now() + seconds(2));
                cout << entities->GetPlayerName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " has " << entities->GetMonsterHealth(entities->GetPlayerPosition()) << " points of health left" << endl << endl;
                sleep_until(system_clock::now() + seconds(1));

                if((pInit/2) > mInit && entities->isPlayerAlive() && entities->isMonsterAlive(entities->GetPlayerPosition())) { // Player gets second initiative if there init is two times higher than the monsters
                    cout << entities->GetPlayerName() << " gets second initiative" << endl;
                    damageDealt = entities->GetPlayerDamage();
                    extraDamage = entities->GetPlayerExtraDamage(); // Player damage retrieved
                    entities->DamageMonsterHealth(entities->GetPlayerPosition(), (damageDealt + extraDamage)); // Damage removed from monster health
                    sleep_until(system_clock::now() + seconds(2));
                    cout << entities->GetPlayerName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " has " << entities->GetMonsterHealth(entities->GetPlayerPosition()) << " points of health left" << endl << endl;
                    sleep_until(system_clock::now() + seconds(1));

                    if(entities->isPlayerAlive() && entities->isMonsterAlive(entities->GetPlayerPosition())) {
                        cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " gets initiative" << endl; // Monster gets final turn
                        damageDealt = entities->GetMonsterDamage(entities->GetPlayerPosition());
                        extraDamage = entities->GetMonsterExtraDamage(entities->GetPlayerPosition()); // retrieves monster damage
                        entities->DamagePlayerHealth((damageDealt + extraDamage) - entities->GetPlayerArmor()); // Damage - Defense value removed from monster health
                        sleep_until(system_clock::now() + seconds(2));
                        cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                        cout << entities->GetPlayerName() << " blocked " << entities->GetPlayerArmor() << " points of damage" << endl;
                        cout << entities->GetPlayerName() << " has " << entities->GetPlayerHealth() << " points of health left" << endl;
                        sleep_until(system_clock::now() + seconds(1));
                    }
                } else if(entities->isPlayerAlive() && entities->isMonsterAlive(entities->GetPlayerPosition())){
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " gets initiative" << endl; // Monster gets final turn
                    damageDealt = entities->GetMonsterDamage(entities->GetPlayerPosition());
                    extraDamage = entities->GetMonsterExtraDamage(entities->GetPlayerPosition()); // retrieves monster damage
                    entities->DamagePlayerHealth((damageDealt + extraDamage) - entities->GetPlayerArmor()); // Damage - Defense value removed from monster health
                    sleep_until(system_clock::now() + seconds(2));
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                    cout << entities->GetPlayerName() << " blocked " << entities->GetPlayerArmor() << " points of damage" << endl;
                    cout << entities->GetPlayerName() << " has " << entities->GetPlayerHealth() << " points of health left" << endl;
                    sleep_until(system_clock::now() + seconds(1));
                }
            } else if(entities->isPlayerAlive() && entities->isMonsterAlive(entities->GetPlayerPosition())){ // Monster gets first initiative
                cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " gets initiative" << endl;
                double damageDealt = entities->GetMonsterDamage(entities->GetPlayerPosition());
                double extraDamage = entities->GetMonsterExtraDamage(entities->GetPlayerPosition()); // retrieves monster damage
                entities->DamagePlayerHealth((damageDealt + extraDamage) - entities->GetPlayerArmor()); // Damage - Defense value removed from monster health
                sleep_until(system_clock::now() + seconds(2));
                cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                cout << entities->GetPlayerName() << " blocked " << entities->GetPlayerArmor() << " points of damage" << endl;
                cout << entities->GetPlayerName() << " has " << entities->GetPlayerHealth() << " points of health left" << endl;
                sleep_until(system_clock::now() + seconds(1));

                if((mInit/2) >= pInit && entities->isPlayerAlive() && entities->isMonsterAlive(entities->GetPlayerPosition())) { // Monster gets second initiative if their init is two times higher than the players
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " gets initiative" << endl;
                    damageDealt = entities->GetMonsterDamage(entities->GetPlayerPosition());
                    extraDamage = entities->GetMonsterExtraDamage(entities->GetPlayerPosition()); // retrieves monster damage
                    entities->DamagePlayerHealth((damageDealt + extraDamage) - entities->GetPlayerArmor()); // Damage - Defense value removed from monster health
                    sleep_until(system_clock::now() + seconds(2));
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                    cout << entities->GetPlayerName() << " blocked " << entities->GetPlayerArmor() << " points of damage" << endl;
                    cout << entities->GetPlayerName() << " has " << entities->GetPlayerHealth() << " points of health left" << endl;
                    sleep_until(system_clock::now() + seconds(1));

                    if(entities->isPlayerAlive() && entities->isMonsterAlive(entities->GetPlayerPosition())) {
                        cout << endl << entities->GetPlayerName() << " gets initiative" << endl; // Player gets final turn
                        damageDealt = entities->GetPlayerDamage();
                        extraDamage = entities->GetPlayerExtraDamage(); // Player damage retrieved
                        entities->DamageMonsterHealth(entities->GetPlayerPosition(), (damageDealt + extraDamage)); // Damage removed from monster health
                        sleep_until(system_clock::now() + seconds(2));
                        cout << entities->GetPlayerName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                        cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " has " << entities->GetMonsterHealth(entities->GetPlayerPosition()) << " points of health left" << endl << endl;
                        sleep_until(system_clock::now() + seconds(1));
                    }
                } else if(entities->isPlayerAlive() && entities->isMonsterAlive(entities->GetPlayerPosition())) {
                    cout << endl << entities->GetPlayerName() << " gets initiative" << endl; // Player gets final turn
                    damageDealt = entities->GetPlayerDamage();
                    extraDamage = entities->GetPlayerExtraDamage(); // Player damage retrieved
                    entities->DamageMonsterHealth(entities->GetPlayerPosition(), (damageDealt + extraDamage)); // Damage removed from monster health
                    sleep_until(system_clock::now() + seconds(2));
                    cout << entities->GetPlayerName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl; // cout statements to show what happened
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " has " << entities->GetMonsterHealth(entities->GetPlayerPosition()) << " points of health left" << endl << endl;
                    sleep_until(system_clock::now() + seconds(1));
                }
            }
        } while(entities->isPlayerAlive() && entities->isMonsterAlive(entities->GetPlayerPosition()));
        if(entities->isPlayerAlive()) { // assign gold to play if they are still alive
            int gold = entities->GetMonsterGold(entities->GetPlayerPosition());
            entities->SetPlayerGold(gold);
            cout << endl << entities->GetPlayerName() << " received " << gold << " pieces of gold" << endl;
        }
    }

    void Action() {
        char userInput, shop, stats, save;
        shop = 'b';
        stats = 'p';
        save = 'g';
        if(entities->isShop(entities->GetPlayerPosition()) && entities->isPlayerAlive()) {cout << "You may input 'b' to access shop wares and buy equipment." << endl;} // checks if there is a shop at playerPos

        cout << "You can go: ";
        if(entities->isPlayerAlive()) {for(int i = 0; i < nextMove->GetDirectionPair().size(); i++) {cout << nextMove->GetDirectionPair()[i].GetDirection() << " ";}} // Gets player directions
        cout << endl;

        if(entities->isPlayerAlive()) {cout << "Where would you like to proceed: "; cin >> userInput;}
        // show player directions
        for (int i = 0; i < nextMove->GetDirectionPair().size(); i++) {if(nextMove->GetDirectionPair()[i].GetDirection() == userInput) {entities->SetPlayerPosition(nextMove->GetDirectionPair()[i].GetNewPos());}}
        if(entities->isShop(entities->GetPlayerPosition()) && userInput == shop) {shopItems->Menu();} // displays shop
        if(userInput == stats) {entities->DisplayPlayerStats();} // displays character stats
        if(userInput == save) {SaveGame();}
    }

    void SaveGame() {
        cout << "Saving Game..." << endl;

        ofstream output;
        output.open("Save.n", ios::trunc);

        if (!output) {
            cerr << "File not found" << endl;
            exit(3);
        }

        SaveLoadGame saveInfo;

        saveInfo.SetpName(entities->GetPlayerName());
        saveInfo.SetpHealth(entities->GetPlayerHealth());
        saveInfo.SetpPos(entities->GetPlayerPosition());
        saveInfo.SetpDamage(entities->GetPlayerDamage());
        saveInfo.SetpExtraDamage(entities->GetPlayerExtraDamage());
        saveInfo.SetpInit(entities->GetPlayerInit());
        saveInfo.SetpDefense(entities->GetPlayerArmor());
        saveInfo.SetpGold(entities->GetPlayerGold());
        saveInfo.SetmHealth1(entities->GetMonsterHealth(3));
        saveInfo.SetmHealth2(entities->GetMonsterHealth(6));
        saveInfo.SetmHealth3(entities->GetMonsterHealth(8));
        saveInfo.SetmHealth4(entities->GetMonsterHealth(10));
        saveInfo.SetmHealth5(entities->GetMonsterHealth(11));
        saveInfo.SetmHealth6(entities->GetMonsterHealth(12));
        saveInfo.SetmHealth7(entities->GetMonsterHealth(14));
        saveInfo.SetmHealth8(entities->GetMonsterHealth(18));
        saveInfo.SetbHealth(entities->GetBossHealth());

        output << saveInfo.GetpName() << " " << saveInfo.GetpHealth() << " " << saveInfo.GetpPos() << " " << saveInfo.GetpDamage() << " " << saveInfo.GetpExtraDamage() << " " << saveInfo.GetpInit() << " " << saveInfo.GetpDefense() << " " << saveInfo.GetpGold() << " " << saveInfo.GetmHealth1() << " " << saveInfo.GetmHealth2() << " " << saveInfo.GetmHealth3() << " " << saveInfo.GetmHealth4() << " " << saveInfo.GetmHealth5() << " " << saveInfo.GetmHealth6() << " " << saveInfo.GetmHealth7() << " " << saveInfo.GetmHealth8() << " " << saveInfo.GetbHealth();

        output.close();
        cout << "Game Saved" << endl;
    }

    void LoadGame() {
        ifstream fin("Save.n");

        if (!fin) {
            cerr << "File not found" << endl;
            cout << "Starting New Game" << endl;
        } else {
            string p_name;
            double p_health, p_damage, p_extraDamage, m_health1, m_health2, m_health3, m_health4, m_health5, m_health6, m_health7, m_health8, b_health;
            int p_pos, p_init, p_defense, p_gold;

            fin >> p_name >> p_health >> p_pos >> p_damage >> p_extraDamage >> p_init >> p_defense >> p_gold >> m_health1 >> m_health2 >> m_health3 >> m_health4 >> m_health5 >> m_health6 >> m_health7 >> m_health8 >> b_health;
            entities->SetPlayerName(p_name);
            entities->SetPlayerHealth(p_health, p_gold);
            entities->SetPlayerWeapon(p_damage, p_extraDamage, p_init, p_gold);
            entities->SetPlayerPosition(p_pos);
            entities->SetPlayerArmor(p_defense, p_gold);
            entities->SetMonsterHealth(4, m_health1);
            entities->SetMonsterHealth(5, m_health2);
            entities->SetMonsterHealth(6, m_health3);
            entities->SetMonsterHealth(7, m_health4);
            entities->SetMonsterHealth(8, m_health5);
            entities->SetMonsterHealth(9, m_health6);
            entities->SetMonsterHealth(10, m_health7);
            entities->SetMonsterHealth(11, m_health8);
            entities->SetBossHealth(b_health);
        }
    }

    void PlayGame() {
        char input;
        string name;

        cout << "<\tInstructions\t>" << endl;
        cout << "-> input 'p' at any time to display player stats" << endl;
        cout << "-> input 'g' at any time to save game" << endl;
        cout << "-> fighting is automated, your goal is to get better weapons to attack earlier and deal more damage" << endl;
        cout << "-> explore the map and find to boss to complete the game" << endl;


        cout << "New or Load Game (N/L): "; cin >> input;
        if(input == 'L') {
            cout << "Loading New Game..." << endl;
            LoadGame();
        }

        do {
            Description(entities->GetPlayerPosition());
            sleep_until(system_clock::now() + seconds(1));
            if(entities->GetPlayerPosition() == 0) {
                cout << "Enter Player Name: "; cin >> name;
                entities->SetPlayerName(name);
                sleep_until(system_clock::now() + seconds(1));
                cout << "Welcome " << entities->GetPlayerName() << "! Would you like to start your adventure? [Yes/No]: " << endl;
            }

            if(entities->isMonster(entities->GetPlayerPosition()) && entities->isMonsterAlive(entities->GetPlayerPosition()) && entities->GetMonsterName(entities->GetPlayerPosition()) != entities->GetBossName()) { // checks to see if there is a monster at player position
                cout << "To proceed, you must defeat the monster before you" << endl << endl;
                Fighting(entities->GetPlayerPosition());
            }
            if(entities->GetBossPosition() == entities->GetPlayerPosition()) {
                cout << "You have reached the boss fight. I hope you have prepared yourself enough..." << endl; // boss fight check
                BossFight();
                break;
            }
            if(entities->isPlayerAlive() && entities->isBossAlive()) {Action();}
        } while(entities->isBossAlive() && entities->isPlayerAlive());
        Description(entities->GetPlayerPosition());
    }
};

#endif //FANTASYFIGHTINGGAME_GAME_H
