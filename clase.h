
#ifndef CLASE_H
#define CLASE_H

#include <string>
using namespace std;

class Cat {
private:
    string name;
    int evilness;
    int cuteness;
    int hunger; //0 inseamna nu ii e foame, 100 e lihnit
    int loyalty;

public:
    Cat(string n, int e, int c, int h, int l);
    Cat(const Cat &other); //constructor copiere
    ~Cat();

    string getName() const;
    int getEvilness() const;
    int getCuteness() const;
    int getHunger() const;
    int getLoyalty() const;

    void feed(int cant);
    void trainEvil(int cant);
    void pet(int cant);
    void rewardLoyalty(int cant);
};

#endif //CLASE_H
