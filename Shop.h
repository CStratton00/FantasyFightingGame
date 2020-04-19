//
// Created by Collin Stratton on 4/11/20.
//

#ifndef FANTASYFIGHTINGGAME_SHOP_H
#define FANTASYFIGHTINGGAME_SHOP_H

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include "ShopItems.h"
#include "Characters.h"

using namespace std;

class Shop {
private:
   ShopItems* shopItems;
   vector <ShopItems*> shopVec;
   Characters* player;

public:
    Shop(Characters * p) { // Creates all the items you can buy in the shop
        srand (time(NULL));
        player = p;

        shopItems = new Weapon("Rusty Sword", 5, false, (rand() % 5 + 5), 0, 2); // 0
        shopVec.push_back(shopItems);
        shopItems = new Weapon("Steel Sword", 20, false, (rand() % 5 + 15), 0, 3); // 1
        shopVec.push_back(shopItems);
        shopItems = new Weapon("Blood Sword", 30, false, (rand() % 5 + 15), 5, 6); // 2
        shopVec.push_back(shopItems);
        shopItems = new Weapon("Bow of the Great Elf", 50, false, (rand() % 5 + 20), 0, 10); // 3
        shopVec.push_back(shopItems);

        shopItems = new Health("Health Potion", 5, false, 25); // 4
        shopVec.push_back(shopItems);
        shopItems = new Health("Health Potion +", 10, false, 50); // 5
        shopVec.push_back(shopItems);
        shopItems = new Health("Health Potion ++", 15, false, 75); // 6
        shopVec.push_back(shopItems);

        shopItems = new Armor("Garbo Leather Armor", 10, false, 5); // 7
        shopVec.push_back(shopItems);
        shopItems = new Armor("Chain Mail Armor", 15, false, 10); // 8
        shopVec.push_back(shopItems);
        shopItems = new Armor("Plated Chain Mail Armor", 20, false, 20); // 9
        shopVec.push_back(shopItems);
        shopItems = new Armor("Plot Armor", 40, false, 50); // 10
        shopVec.push_back(shopItems);
    }

    void DisplayStats() { // displays all the stats of the times in the shop in a list format
        for(int i = 0; i < shopVec.size(); i++) {
            cout << endl << i + 1 << ". ";
            shopVec[i]->DisplayStats();
        }
    }
    void Menu() { // assigns data to player based on what they purchased
        int input;

        DisplayStats();
        cout << "You have " << player->GetPlayerGold() << " pieces of gold" << endl;
        cout << "What would you like to purchase (type '0'): "; cin >> input;
        int money = player->GetPlayerGold();
        int cost;
        if(input - 1 >= 0) {cost = shopVec[input - 1]->GetCost();} else {cost = 1000;}

        if(money - cost < 0) {
            cout << "Insufficient Funds/No Purchase Made" << endl;
        } else {
            if(input - 1 < 4) {
                player->SetPlayerWeapon(shopVec[input - 1]->GetDamage(), shopVec[input - 1]->GetExtraDamage(), shopVec[input - 1]->GetInit(), (money - cost));
                cout << endl << "You have purchased: " << shopVec[input - 1]->GetName() << endl;
                cout << "You have " << player->GetPlayerGold() << " pieces of gold left" << endl << endl;
            } else if (input - 1 < 7) {
                if(player->GetPlayerHealth() + shopVec[input - 1]->GetLife() > 250) {
                    player->SetPlayerHealth(250, (money - cost));
                } else {
                    player->SetPlayerHealth(player->GetPlayerHealth() + shopVec[input - 1]->GetLife(), (money - cost));
                }
                cout << endl << "You have purchased: " << shopVec[input - 1]->GetName() << endl;
                cout << "You have " << player->GetPlayerGold() << " pieces of gold left" << endl << endl;
            } else {
                player->SetPlayerArmor(shopVec[input - 1]->GetDefense(), (money - cost));
                cout << endl << "You have purchased: " << shopVec[input - 1]->GetName() << endl;
                cout << "You have " << player->GetPlayerGold() << " pieces of gold left" << endl << endl;
            }
        }
    }
};


#endif //FANTASYFIGHTINGGAME_SHOP_H
