//
// Created by Collin Stratton on 4/7/20.
// File contains Entity, Player, Monster, and Boss Classes
//

#ifndef FANTASYFIGHTINGGAME_ENTITY_H
#define FANTASYFIGHTINGGAME_ENTITY_H

#include "ShopItems.h"

class Entity { // Parent class for all the entities in the game
private:
    string name;
    double health;
    Weapon* weapon{}; // uses weapon class to assign damage and initiative to entities
    int position;
    bool alive;

public:
    explicit Entity(string Name = "", double h = 10.00, int p = 1, string n = "Sword", double d = 10.00, double ed = 0.00, int i = 1, bool l = true) {
        weapon = new Weapon("", 1, false, 0, 0, 0);
        name = Name;
        health = h;
        position = p;
        weapon->SetName(n);
        weapon->SetDamage(d);
        weapon->SetExtraDamage(ed);
        weapon->SetInit(i);
        alive = l;
    }

    string GetName() {return name;}
    double GetHealth() {return health;}
    double GetDamage() {return weapon->GetDamage();}
    double GetExtraDamage() {return weapon->GetExtraDamage();}
    int GetInit() {return weapon->GetInit();}
    int GetPosition() {return position;}
    virtual int GetDefense() = 0;
    virtual int GetGold() = 0;

    void SetName(string n) {name = n;}
    void SetHealth(double h) {health = h;}
    void SetDamage(double d) {weapon->SetDamage(d);}
    void SetExtraDamage(double ed) {weapon->SetExtraDamage(ed);}
    void SetInit(int i) {weapon->SetInit(i);}
    void SetPosition(int p) {position = p;}
    virtual void SetDefense(int d) = 0;
    virtual void SetGold(int g) = 0;

    virtual void DisplayStats() = 0;
};

class Player : public Entity { // daughter class of entity that is used by the user to play the game
private:
    Armor* armor; // uses armor class to assign defense value
    int gold;
    bool fighting;

public:
    explicit Player(string Name = "Player", double h = 250.00, int p = 0, string n = "Sword", double d = 5.00, double ed = 0.00, int i = 1, bool l = true, int de = 0, int g = 0, bool f = false) : Entity(Name, h, p, n, d, ed, i, l) {
        armor = new Armor("", 0, false, 0);
        gold = g;
        fighting = f;
        armor->SetDefense(de);
    }

    int GetDefense() {return armor->GetDefense();}
    int GetGold() {return gold;}

    void SetDefense(int d) {armor->SetDefense(d);}
    void SetGold(int g) {gold = g;}

    void DisplayStats() {
        cout << endl << "<\tPlayer Stats\t>" << endl;
        cout << "Name: " << GetName() << endl;
        cout << "Health: " << GetHealth() << endl;
        cout << "Position: " << GetPosition() << endl;
        cout << "Weapon Damage Total: " << GetDamage() + GetExtraDamage() << endl;
        cout << "Weapon Initiative: " << GetInit() << endl;
        cout << "Defense Value: " << GetDefense() << endl;
        cout << "Gold: " << GetGold() << endl << endl;
    }
};

class Monster : public Entity { // daughter class of entity used to fight against the player
private:
    int gold;

public:
    explicit Monster(string name = "Bandit", double h = 10.00, int p = 1, string n = "Sword", double d = 10.00, double ed = 0.00, int i = 1, bool l = true, int g = 10) : Entity(name, h, p, n, d, ed, i, l) {gold = g;}

    int GetDefense() {return 0;}
    int GetGold() {return gold;}

    void SetDefense(int d) {}
    void SetGold(int g) {}

    void DisplayStats() {}
};

class Boss : public Entity { // daughter class of entity used as the final fight of the game
public:
    explicit Boss(string name = "Spirit Beast", double h = 150.00, int p = 21, string n = "Claws", double d = (rand() % 10 + 16), double ed = (rand() % 5 + 10), int i = 5, bool l = true) : Entity(name, h, p, n, d, ed, i, l) {}

    int GetDefense() {return 0;}
    int GetGold() {return 0;}

    void SetDefense(int d) {}
    void SetGold(int g) {}

    void DisplayStats() {}
};

#endif //FANTASYFIGHTINGGAME_ENTITY_H
