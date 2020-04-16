//
// Created by Collin Stratton on 4/7/20.
//

#ifndef FANTASYFIGHTINGGAME_SHOPITEMS_H
#define FANTASYFIGHTINGGAME_SHOPITEMS_H

#include <string>
#include <iostream>

using namespace std;

class ShopItems {
private:
    string name;
    int cost;
    bool purchased;

public:
    ShopItems(string n, int c, bool p) : name(n), cost(c), purchased(p) {}

    string GetName() {return name;}
    int GetCost() {return cost;}
    bool isPurchased() {return purchased;}

    void SetName(string n) {name = n;}
    void SetCost(int c) {cost = c;}
    void SetPurchased(int p) {purchased = p;}

    virtual double GetDamage() = 0;
    virtual double GetExtraDamage() = 0;
    virtual int GetInit() = 0;

    virtual void SetDamage(double d) = 0;
    virtual void SetExtraDamage(double ed) = 0;
    virtual void SetInit(int i) = 0;

    virtual int GetLife() = 0;
    virtual void SetLife(double l) = 0;

    virtual int GetDefense() = 0;
    virtual void SetDefense(int d) = 0;

    virtual void DisplayStats() = 0;
};

class Weapon : public ShopItems {
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

    int GetLife() {};
    void SetLife(double l) {};

    int GetDefense() {};
    void SetDefense(int d) {};

    void DisplayStats() {
        cout << "<\tWeapon Stats\t>" << endl;
        cout << "Weapon Name: " << GetName() << endl;
        cout << "Damage: " << GetDamage() << endl;
        cout << "Extra Damage: " << GetExtraDamage() << endl;
        cout << "Init: " << GetInit() << endl;
    }
};

class Health : public ShopItems {
private:
    int life;

public:
    Health(string n = "Health", int c = 1, bool p = false, int l = 10) : ShopItems(n, c, p) {
        life = l;
    }

    int GetLife() {return life;}
    void SetLife(double l) {life = l;}

    double GetDamage() {}
    double GetExtraDamage() {}
    int GetInit() {}

    void SetDamage(double d) {}
    void SetExtraDamage(double ed) {}
    void SetInit(int i) {}

    int GetDefense() {};
    void SetDefense(int d) {};

    void DisplayStats() {
        cout << "\tHealth Potion Stats\t" << endl;
        cout << "Potion Name: " << GetName() << endl;
        cout << "Health Increase: " << GetLife() << endl;
    }
};

class Armor : public ShopItems {
private:
    int defense;

public:
    Armor(string n = "Leather", int c = 1, bool p = false, int d = 0) : ShopItems(n, c, p) {
        defense = d;
    }

    int GetDefense() {return defense;}
    void SetDefense(int d) {defense = d;}

    double GetDamage() {}
    double GetExtraDamage() {}
    int GetInit() {}

    void SetDamage(double d) {}
    void SetExtraDamage(double ed) {}
    void SetInit(int i) {}

    int GetLife() {};
    void SetLife(double l) {};

    void DisplayStats() {
        cout << "\tArmor Stats\"" << endl;
        cout << "Armor Name: " << GetName() << endl;
        cout << "Defense: " << GetDefense() << endl;
    }
};

#endif //FANTASYFIGHTINGGAME_SHOPITEMS_H
