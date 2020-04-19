//
// Created by Collin Stratton on 4/18/20.
//

#ifndef FANTASYFIGHTINGGAME_SAVELOADGAME_H
#define FANTASYFIGHTINGGAME_SAVELOADGAME_H

#include <string>

class SaveLoadGame { // Class used to save game data and load file data into the game
private:
    string p_name;
    double p_health, p_damage, p_extraDamage, m_health1, m_health2, m_health3, m_health4, m_health5, m_health6, m_health7, m_health8, b_health;
    int p_pos, p_init, p_defense, p_gold;

public:
    SaveLoadGame(string pN = "Player", double pH = 250.00, int pP = 0, double pD = 5.00, double pED = 0.00, int pI = 1, int pDE = 0, int pG = 0, double mH1 = 20, double mH2 = 20,
            double mH3 = 25, double mH4 = 25, double mH5 = 25, double mH6 = 40, double mH7 = 40, double mH8 = 40, double bH = 100) { // construct all vars
        p_name = pN;
        p_health = pH;
        p_pos = pP;
        p_damage = pD;
        p_extraDamage = pED;
        p_init = pI;
        p_defense = pDE;
        p_gold = pG;

        m_health1 = mH1;
        m_health2 = mH2;
        m_health3 = mH3;
        m_health4 = mH4;
        m_health5 = mH5;
        m_health6 = mH6;
        m_health7 = mH7;
        m_health8 = mH8;

        b_health = bH;
    }

    string GetpName() {return p_name;}
    int GetpPos() {return p_pos;}
    int GetpInit() {return p_init;}
    int GetpDefense() {return p_defense;}
    int GetpGold() {return p_gold;}
    double GetpHealth() {return p_health;}
    double GetpDamage() {return p_damage;}
    double GetpExtraDamage() {return p_extraDamage;}
    double GetmHealth1() {return m_health1;}
    double GetmHealth2() {return m_health2;}
    double GetmHealth3() {return m_health3;}
    double GetmHealth4() {return m_health4;}
    double GetmHealth5() {return m_health5;}
    double GetmHealth6() {return m_health6;}
    double GetmHealth7() {return m_health7;}
    double GetmHealth8() {return m_health8;}
    double GetbHealth() {return b_health;}

    void SetpName(string pN) {p_name = pN;}
    void SetpPos(int pP) {p_pos = pP;}
    void SetpInit(int pI) {p_init = pI;}
    void SetpDefense(int pDE) {p_defense = pDE;}
    void SetpGold(int pG) {p_gold = pG;}
    void SetpHealth(double pH) {p_health = pH;}
    void SetpDamage(double pD) {p_damage = pD;}
    void SetpExtraDamage(double pED) {p_extraDamage = pED;}
    void SetmHealth1(double mH1) {m_health1 = mH1;}
    void SetmHealth2(double mH2) {m_health2 = mH2;}
    void SetmHealth3(double mH3) {m_health3 = mH3;}
    void SetmHealth4(double mH4) {m_health4 = mH4;}
    void SetmHealth5(double mH5) {m_health5 = mH5;}
    void SetmHealth6(double mH6) {m_health6 = mH6;}
    void SetmHealth7(double mH7) {m_health7 = mH7;}
    void SetmHealth8(double mH8) {m_health8 = mH8;}
    void SetbHealth(double bH) {b_health = bH;}
 };


#endif //FANTASYFIGHTINGGAME_SAVELOADGAME_H
