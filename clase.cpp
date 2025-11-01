#include <iostream>
#include "Clase.h"
#include <string>
using namespace std;

Cat::Cat(string n, int e, int c, int h, int l)
    :name(n), evilness(e), cuteness(c), hunger(h), loyalty(l) {}

Cat::Cat(const Cat &other)
    : name(other.name), evilness(other.evilness),cuteness(other.cuteness),hunger(other.hunger),loyalty(other.loyalty) {}

Cat::~Cat() {
    cout<<"Pisica "<<name<<" a fost anihilata"<<endl;
}

string Cat::getName() const {return name;}
int Cat::getEvilness() const {return evilness;}
int Cat::getCuteness() const {return cuteness;}
int Cat::getHunger() const {return hunger;}
int Cat::getLoyalty() const {return loyalty;}

void Cat::feed(int cant) {
    hunger -= cant;
    if (hunger<0) {
        hunger = 0;
    }
    if (hunger>100) {
        hunger = 100;
    }
    cout<<name<<" was fed. Hunger: "<<hunger<<endl;
}

void Cat::trainEvil(int cant) {
    evilness += cant;
    if (evilness<0) {
        evilness = 0;
    }
    if (evilness>100) {
        evilness = 100;
    }
    cout<<name<<" has become more vicious. Evilness: "<<evilness<<endl;
}

void Cat::pet(int cant) {
    cuteness += cant;
    if (cuteness<0) {
        cuteness = 0;
    }
    if (cuteness>100) {
        cuteness = 100;
    }
    cout<<name<<" is melting hearts on facebook. Cuteness: "<<cuteness<<endl;
}

void Cat::rewardLoyalty(int cant) {
    loyalty += cant;
    if (loyalty<0) {
        loyalty = 0;
    }
    if (loyalty>100) {
        loyalty = 100;
    }
    cout<<name<<" is more loyal. Loyalty: "<<loyalty<<endl;
}
