//
// Created by Collin Stratton on 4/7/20.
// File contains ShopItems, Weapons, Health, and Armor Classes
//

#ifndef FANTASYFIGHTINGGAME_SHOPITEMS_H
#define FANTASYFIGHTINGGAME_SHOPITEMS_H

#include <string>
#include <iostream>

using namespace std;

class ShopItems { // parent class for all the items to purchase in the shop
private:
    string name;
    int cost;
    bool purchased;

public:
    ShopItems(string n, int c, bool p) : name(n), cost(c), purchased(p) {}

    string GetName() {return name;}
    int GetCost() {return cost;}

    void SetName(string n) {name = n;}

    virtual double GetDamage() = 0;
    virtual double GetExtraDamage() = 0;
    virtual int GetInit() = 0;

    virtual void SetDamage(double d) = 0;
    virtual void SetExtraDamage(double ed) = 0;
    virtual void SetInit(int i) = 0;

    virtual int GetLife() = 0;

    virtual int GetDefense() = 0;
    virtual void SetDefense(int d) = 0;

    virtual void DisplayStats() = 0;
};

class Weapon : public ShopItems { // daughter class that sets specific values for a weapon
private:
    double damage, extraDamage;
    int init;

public:
    Weapon(string n = "", int c = 1, bool p = false, double d = 0.00, double ed = 0.00, int i = 0) : ShopItems(n, c, p) {
        damage = d;
        extraDamage = ed;
        init = i;
    }

    double GetDamage() {return damage;}
    double GetExtraDamage() {return extraDamage;}
    int GetInit() {return init;}

    void SetDamage(double d) {damage = d;}
    void SetExtraDamage(double ed) {extraDamage = ed;}
    void SetInit(int i) {init = i;}

    int GetLife() {return 0;};

    int GetDefense() {return 0;};
    void SetDefense(int d) {};

    void DisplayStats() {
        cout << "<\tWeapon Stats\t>" << endl;
        cout << "Weapon Name: " << GetName() << endl;
        cout << "Damage: " << GetDamage() << endl;
        cout << "Extra Damage: " << GetExtraDamage() << endl;
        cout << "Init: " << GetInit() << endl;
        cout << "Cost: " << GetCost() << endl << endl;
    }
};

class Health : public ShopItems { // daughter class that sets specific values for a health to be added to the player
private:
    int life;

public:
    Health(string n = "Health", int c = 1, bool p = false, int l = 10) : ShopItems(n, c, p) {
        life = l;
    }

    int GetLife() {return life;}

    double GetDamage() {return 0;}
    double GetExtraDamage() {return 0;}
    int GetInit() {return 0;}

    void SetDamage(double d) {}
    void SetExtraDamage(double ed) {}
    void SetInit(int i) {}

    int GetDefense() {return 0;};
    void SetDefense(int d) {};

    void DisplayStats() {
        cout << "<\tHealth Potion Stats\t>" << endl;
        cout << "Potion Name: " << GetName() << endl;
        cout << "Health Increase: " << GetLife() << endl;
        cout << "Cost: " << GetCost() << endl << endl;
    }
};

class Armor : public ShopItems { // daughter class that sets specific values for a armor to be added to the player
private:
    int defense;

public:
    Armor(string n = "Leather", int c = 1, bool p = false, int d = 0) : ShopItems(n, c, p) {
        defense = d;
    }

    int GetDefense() {return defense;}
    void SetDefense(int d) {defense = d;}

    double GetDamage() {return 0;}
    double GetExtraDamage() {return 0;}
    int GetInit() {return 0;}

    void SetDamage(double d) {}
    void SetExtraDamage(double ed) {}
    void SetInit(int i) {}

    int GetLife() {return 0;};

    void DisplayStats() {
        cout << "<\tArmor Stats\t>" << endl;
        cout << "Armor Name: " << GetName() << endl;
        cout << "Defense: " << GetDefense() << endl;
        cout << "Cost: " << GetCost() << endl << endl;
    }
};

#endif //FANTASYFIGHTINGGAME_SHOPITEMS_H
