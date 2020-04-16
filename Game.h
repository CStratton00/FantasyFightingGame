//
// Created by Collin Stratton on 4/7/20.
//

#ifndef FANTASYFIGHTINGGAME_GAME_H
#define FANTASYFIGHTINGGAME_GAME_H

#include "Characters.h"
#include "Shop.h"
#include "NextMove.h"
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
    bool gameType;
    Characters* entities;
    Shop* shopItems;
    NextMove* nextMove;

public:
    void Description(int playerPos) {                           // This Works
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

            if(pos == playerPos) {                              // Checks the converted value against the player position
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
        cout << "You can go: ";
        for(int i = 0; i < nextMove->GetDirectionPair().size(); i++) {cout << nextMove->GetDirectionPair()[i].GetDirection() << " ";}
        cout << endl;

        fin.close();
    }

    void Fighting(int mPos) {
        int pInit = entities->GetPlayerInit();
        int mInit = entities->GetMonsterInit(mPos);
        do {
            if(pInit > mInit) { // print stats during all of this
                cout << entities->GetPlayerName() << " gets initiative!" << endl;
                double damageDealt = entities->GetPlayerDamage();
                double extraDamage = entities->GetPlayerExtraDamage();
                entities->SetMonsterHealth(entities->GetPlayerPosition(), (damageDealt + extraDamage));
                cout << entities->GetPlayerName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl;
                cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " has " << entities->GetMonsterHealth(entities->GetPlayerPosition()) << " points of health left" << endl << endl;
                sleep_until(system_clock::now() + seconds(1));

                if((pInit/2) > mInit) {
                    cout << entities->GetPlayerName() << " gets second initiative!" << endl;
                    damageDealt = entities->GetPlayerDamage();
                    extraDamage = entities->GetPlayerExtraDamage();
                    entities->SetMonsterHealth(entities->GetPlayerPosition(), (damageDealt + extraDamage));
                    cout << entities->GetPlayerName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl;
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " has " << entities->GetMonsterHealth(entities->GetPlayerPosition()) << " points of health left" << endl << endl;
                    sleep_until(system_clock::now() + seconds(1));

                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " gets initiative" << endl;
                    damageDealt = entities->GetMonsterDamage(entities->GetPlayerPosition());
                    extraDamage = entities->GetMonsterExtraDamage(entities->GetPlayerPosition());
                    entities->DamagePlayerHealth(damageDealt + extraDamage);
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " dealt " << damageDealt + extraDamage << " points of damage" << endl;
                    cout << entities->GetPlayerName() << " has " << entities->GetPlayerHealth() << " points of health left" << endl;
                    sleep_until(system_clock::now() + seconds(1));
                } else {
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " gets initiative" << endl;
                    damageDealt = entities->GetMonsterDamage(entities->GetPlayerPosition());
                    extraDamage = entities->GetMonsterExtraDamage(entities->GetPlayerPosition());
                    entities->DamagePlayerHealth(damageDealt + extraDamage);
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " dealt " << damageDealt + extraDamage << " points of damage" << endl;
                    cout << entities->GetPlayerName() << " has " << entities->GetPlayerHealth() << " points of health left" << endl;
                    sleep_until(system_clock::now() + seconds(1));
                }
            } else {
                cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " gets initiative" << endl;
                double damageDealt = entities->GetMonsterDamage(entities->GetPlayerPosition());
                double extraDamage = entities->GetMonsterExtraDamage(entities->GetPlayerPosition());
                entities->DamagePlayerHealth(damageDealt + extraDamage);
                cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " dealt " << damageDealt + extraDamage << " points of damage" << endl;
                cout << entities->GetPlayerName() << " has " << entities->GetPlayerHealth() << " points of health left" << endl;
                sleep_until(system_clock::now() + seconds(1));

                if((mInit/2) > pInit) {
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " gets second initiative" << endl;
                    damageDealt = entities->GetMonsterDamage(entities->GetPlayerPosition());
                    extraDamage = entities->GetMonsterExtraDamage(entities->GetPlayerPosition());
                    entities->DamagePlayerHealth(damageDealt + extraDamage);
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " dealt " << damageDealt + extraDamage << " points of damage" << endl;
                    cout << entities->GetPlayerName() << " has " << entities->GetPlayerHealth() << " points of health left" << endl;
                    sleep_until(system_clock::now() + seconds(1));

                    cout << entities->GetPlayerName() << " gets initiative!" << endl;
                    damageDealt = entities->GetPlayerDamage();
                    extraDamage = entities->GetPlayerExtraDamage();
                    entities->SetMonsterHealth(entities->GetPlayerPosition(), (damageDealt + extraDamage));
                    cout << entities->GetPlayerName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl;
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " has " << entities->GetMonsterHealth(entities->GetPlayerPosition()) << " points of health left" << endl << endl;
                    sleep_until(system_clock::now() + seconds(1));
                } else {
                    cout << entities->GetPlayerName() << " gets initiative!" << endl;
                    damageDealt = entities->GetPlayerDamage();
                    extraDamage = entities->GetPlayerExtraDamage();
                    entities->SetMonsterHealth(entities->GetPlayerPosition(), (damageDealt + extraDamage));
                    cout << entities->GetPlayerName() << " dealt " << damageDealt + extraDamage << " points of damage" << endl;
                    cout << entities->GetMonsterName(entities->GetPlayerPosition()) << " has " << entities->GetMonsterHealth(entities->GetPlayerPosition()) << " points of health left" << endl << endl;
                    sleep_until(system_clock::now() + seconds(1));
                }
            }
        } while(entities->isPlayerAlive() && entities->isMonsterAlive(entities->GetPlayerPosition()));
    }

    void Action() {
        char userInput, shop;

        Description(entities->GetPlayerPosition());
        sleep_until(system_clock::now() + seconds(1));

        if(entities->isMonster(entities->GetPlayerPosition()) && entities->isMonsterAlive(entities->GetPlayerPosition())) {
            cout << "To proceed, you must defeat the monster before you" << endl;
            entities->SetPlayerFighting(true);
            Fighting(entities->GetPlayerPosition());
        }

        shop = 'b';
        if(entities->isShop(entities->GetPlayerPosition())) {cout << "You have found a wondering traveler! You may input 'b' to access their wares and buy equipment." << endl;}

        cout << "You can go: ";
        for(int i = 0; i < nextMove->GetDirectionPair().size(); i++) {cout << nextMove->GetDirectionPair()[i].GetDirection() << " ";}
        cout << endl;

        cout << "Where would you like to proceed: "; cin >> userInput;
        for(int i = 0; i < nextMove->GetDirectionPair().size(); i++) {
            if(nextMove->GetDirectionPair()[i].GetDirection() == userInput) {
                entities->SetPlayerPosition(nextMove->GetDirectionPair()[i].GetNewPos());
                break;
            }
        }
        if(entities->isShop(entities->GetPlayerPosition()) && userInput == shop) {
            shopItems->Menu();
        }
    }
};

#endif //FANTASYFIGHTINGGAME_GAME_H
