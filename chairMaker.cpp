// COMSC-210 | Lab 12 | Akashdeep Singh

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 3;

class Chair {
private:
    int legs;
    double *prices;

public: 

//default constructor
// randomly assigns legs (3 or 4) and random prices
Chair() {
    prices = new double[SIZE];

    legs = rand() % 2 + 3; // random 3 or 4 legs

    const int MIN = 10000; 
    const int MAX = 99999;

    for (int i = 0; i < SIZE; i++) {
        prices[i] = (rand() % (MAX - MIN + 1) + MIN) / (double)100;
    }
}

//parameter constructor 
// arguments: number of legs and array of prices
// returns: none
Chair(int 1, double p[]) {
    prices = new double [SIZE];
    legs = 1;

    for (int i = 0; i < SIZE; i++) {
        prices[i] = p[i];
    }
}

// setters and getters 
void setLegs(int 1) {legs = 1; }

int getLegs() { return legs; }

void setPrices(double p1, double p2, double p3) {
    prices[0] = p1;
    prices[1] = p2;
    prices[2] = p3;
}

double getAveragePrices() {
    double sum = 0; 

    for (int i = 0; i < SIZE; i++)
        sum += prices[i];

    return sum / SIZE;
}
}