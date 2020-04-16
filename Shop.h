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
    Shop() {
        srand (time(NULL));

        shopItems = new Weapon("Rusty Sword", 5, false, (rand() % 5 + 1), 0, 1); // 0
        shopItems = new Weapon("Steel Sword", 25, false, (rand() % 5 + 15), 0, 3); // 1
        shopItems = new Weapon("Blood Sword", 50, false, (rand() % 5 + 15), 5, 6); // 2
        shopItems = new Weapon("Bow of the Great Elf", 75, false, (rand() % 5 + 20), 0, 10); // 3

        shopItems = new Health("Health Potion", 15, false, 25); // 4
        shopItems = new Health("Health Potion +", 25, false, 50); // 5
        shopItems = new Health("Health Potion ++", 40, false, 75); // 6

        shopItems = new Armor("Garbo Leather Armor", 10, false, 5); // 7
        shopItems = new Armor("Chain Mail Armor", 20, false, 10); // 8
        shopItems = new Armor("Plated Chain Mail Armor", 30, false, 20); // 9
        shopItems = new Armor("Plot Armor", 50, false, 50); // 10
    }

    void DisplayStats() {
        for(int i = 0; i < shopVec.size(); i++) {
            cout << i + 1 << ". ";
            shopItems[i].DisplayStats();
        }
    }
    void Menu() {
        int input;

        DisplayStats();
        cout << "What would you like to purchase: "; cin >> input;
        int money = player->GetPlayerGold();
        int cost = shopVec[input - 1]->GetCost();

        if(money - cost < 0) {
            cout << "Insufficient Funds";
        } else {
            if(input - 1 < 4) {
                player->SetPlayerWeapon(shopVec[input - 1]->GetName(), shopVec[input - 1]->GetDamage(), shopVec[input - 1]->GetExtraDamage(), shopVec[input - 1]->GetInit(), (money - cost));
            } else if (input - 1 < 7) {
                if(player->GetPlayerHealth() + shopVec[input - 1]->GetLife() > 100) {
                    player->SetPlayerHealth(100, (money - cost));
                } else {
                    player->SetPlayerHealth(player->GetPlayerHealth() + shopVec[input - 1]->GetLife(), (money - cost));
                }
            } else {
                player->SetPlayerArmor(shopVec[input - 1]->GetDefense(), (money - cost));
            }
        }
        shopVec[input - 1]->SetPurchased(true);
    }
};


#endif //FANTASYFIGHTINGGAME_SHOP_H
