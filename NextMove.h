//
// Created by Collin Stratton on 4/14/20.
//

#ifndef FANTASYFIGHTINGGAME_NEXTMOVE_H
#define FANTASYFIGHTINGGAME_NEXTMOVE_H

#include <string>
#include <vector>
#include "DirectionPair.h"

using namespace std;

class NextMove { // Class used store data about the description, location, and directions of a given player position
private:
    string description;
    vector <DirectionPair> newPos;

public:
    NextMove(string e) {
        description = e;
    }

    string GetDescription() {return description;}

    vector<DirectionPair> GetDirectionPair() { // Returns the the vector DirectionPair
        vector<DirectionPair> copy;
        for (int i = 0; i < newPos.size(); i++) {copy.push_back(newPos[i]);}
        return copy;
    }

    void ClearPair() {newPos.clear();}
    void AddPair(char d, int p) { // Creates a new DirectionPair vector
        DirectionPair dp(d, p);
        newPos.push_back(dp);
    }
    void SetDescription(string d) {description = d;}
};


#endif //FANTASYFIGHTINGGAME_NEXTMOVE_H
