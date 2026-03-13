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
Chair(int l, double p[]) {
    prices = new double[SIZE];
    legs = 1;

    for (int i = 0; i < SIZE; i++) {
        prices[i] = p[i];
    }
}

// setters and getters 
void setLegs(int l) {legs = 1; }

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

void print() {
    cout << "CHAIR DATA - legs: " << legs << endl;

    cout << "Price history: ";
    for (int i = 0; i < SIZE; i++)
        cout << prices[i] << " ";

    cout << endl;
    cout << "Historical avg price: " << getAveragePrices();
    cout << endl << endl;
}
};

int main() {
    cout << fixed << setprecision(2);

    srand(time(0));

    cout << "DEFAULT CHAIR CREATED WITH RANDOM DATA\n\n";

    // default constructor than setters
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    cout << "PARAMETER CONSTRUCTOR CHAIR\n\n";

    //parameter constructor test
    double priceArray[SIZE] = {525.25, 434.34, 252.52};

    Chair *livingChair = new Chair(3, priceArray);
    livingChair->print();

    delete livingChair;
    livingChair = nullptr;

    cout << "ARRAY OF CHAIRS USING DEFAULT CONSTRUCTORS \n\n";

    //dynamic array of chair objects
    //default constructors that automatically populate data
    Chair *collection = new Chair[SIZE];

    for (int i = 0; i < SIZE; i++)
        collection[i].print();

    delete[] collection;

    return 0;
}