
//
// Created by Collin Stratton on 4/7/20.
//

#ifndef FANTASYFIGHTINGGAME_ENTITY_H
#define FANTASYFIGHTINGGAME_ENTITY_H

#include "ShopItems.h"

class Entity {
private:
    string name;
    double health;
    Weapon* weapon{};
    int position;
    bool alive;

public:
    explicit Entity(string name = "", double h = 10.00, int p = 1, string n = "Sword", double d = 10.00, double ed = 0.00, int i = 1, bool l = true) {
        name = name;
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
    bool isAlive() {return alive;}
    virtual int GetDefense() = 0;
    virtual int GetGold() = 0;
    virtual bool isFighting() = 0;

    void SetName(string n) {name = n;}
    void SetHealth(double h) {health = h;}
    void SetDamage(double d) {weapon->SetDamage(d);}
    void SetExtraDamage(double ed) {weapon->SetExtraDamage(ed);}
    void SetInit(int i) {weapon->SetInit(i);}
    void SetPosition(int p) {position = p;}
    void SetLivingStatus(bool l) {alive = l;}
    virtual void SetDefense(int d) = 0;
    virtual void SetGold(int g) = 0;
    virtual void SetFighting(bool f) = 0;
};

class Player : public Entity {
private:
    Armor* armor;
    int gold;
    bool fighting;

public:
    explicit Player(string name = "Player", double h = 100.00, int p = 0, string n = "Sword", double d = 5.00, double ed = 0.00, int i = 1, bool l = true, int de = 0, int g = 0, bool f = false) : Entity(n, h, p, n, d, ed, i, l) {
        gold = g;
        fighting = f;
        armor->SetDefense(de);
    }

    int GetDefense() {return armor->GetDefense();}
    int GetGold() {return gold;}
    bool isFighting() {return fighting;}

    void SetDefense(int d) {armor->SetDefense(d);}
    void SetGold(int g) {gold = g;}
    void SetFighting(bool f) {fighting = f;}
};

class Monster : public Entity {
private:
    int gold;

public:
    explicit Monster(string name = "Bandit", double h = 10.00, int p = 1, string n = "Sword", double d = 10.00, double ed = 0.00, int i = 1, bool l = true, int g = 10) : Entity(n, h, p, n, d, ed, i, l) {gold = g;}

    int GetDefense() {}
    int GetGold() {}
    bool isFighting() {}

    void SetDefense(int d) {}
    void SetGold(int g) {}
    void SetFighting(bool f) {}
};

class Boss : public Entity {
public:
    explicit Boss(string name = "Spirit Beast", double h = 100.00, int p = 21, string n = "Claws", double d = (rand() % 10 + 11), double ed = (rand() % 5 + 1), int i = 5, bool l = true) : Entity(n, h, p, n, d, ed, i, l) {}

    int GetDefense() {}
    int GetGold() {}
    bool isFighting() {}

    void SetDefense(int d) {}
    void SetGold(int g) {}
    void SetFighting(bool f) {}
};

#endif //FANTASYFIGHTINGGAME_ENTITY_H
