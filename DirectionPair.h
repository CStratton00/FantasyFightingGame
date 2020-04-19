//
// Created by Collin Stratton on 4/14/20.
//

#ifndef FANTASYFIGHTINGGAME_DIRECTIONPAIR_H
#define FANTASYFIGHTINGGAME_DIRECTIONPAIR_H


class DirectionPair { // Class is used to create a vector of locations and directions
private:
    char direction;
    int pos;

public:
    DirectionPair(char d, int p) : direction(d), pos(p) {}
    char GetDirection() {return direction;}
    int GetNewPos() {return pos;}
};


#endif //FANTASYFIGHTINGGAME_DIRECTIONPAIR_H
