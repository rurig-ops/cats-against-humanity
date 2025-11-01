#include <iostream>
#include "clase.h"
using namespace std;

// ==================== Cat ====================

Cat::Cat(string n, int e, int c, int h, int l)
    :name(n), evilness(e), cuteness(c), hunger(h), loyalty(l) {}

Cat::Cat(const Cat &other)
    : name(other.name), evilness(other.evilness), cuteness(other.cuteness), hunger(other.hunger), loyalty(other.loyalty) {}

Cat::~Cat() {
    //cout << "Pisica " << name << " a fost anihilata" << endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        name = other.name;
        evilness = other.evilness;
        cuteness = other.cuteness;
        hunger = other.hunger;
        loyalty = other.loyalty;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Cat& c) {
    os << c.getName() << " | Evil: " << c.getEvilness()
       << " | Cute: " << c.getCuteness()
       << " | Hunger: " << c.getHunger()
       << " | Loyalty: " << c.getLoyalty();
    return os;
}

string Cat::getName() const { return name; }
int Cat::getEvilness() const { return evilness; }
int Cat::getCuteness() const { return cuteness; }
int Cat::getHunger() const { return hunger; }
int Cat::getLoyalty() const { return loyalty; }

void Cat::feed(int cant) {
    hunger -= cant;
    if (hunger < 0) hunger = 0;
    if (hunger > 100) hunger = 100;
    cout << name << " was fed. Hunger: " << hunger << endl;
}

void Cat::trainEvil(int cant) {
    evilness += cant;
    if (evilness < 0) evilness = 0;
    if (evilness > 100) evilness = 100;
    cout << name << " has become more vicious. Evilness: " << evilness << endl;
}

void Cat::pet(int cant) {
    cuteness += cant;
    if (cuteness < 0) cuteness = 0;
    if (cuteness > 100) cuteness = 100;
    cout << name << " is melting hearts on facebook. Cuteness: " << cuteness << endl;
}

void Cat::rewardLoyalty(int cant) {
    loyalty += cant;
    if (loyalty < 0) loyalty = 0;
    if (loyalty > 100) loyalty = 100;
    cout << name << " is more loyal. Loyalty: " << loyalty << endl;
}

void Cat::increaseHunger(int cant) {
    hunger += cant;
    if (hunger > 100) hunger = 100;
    if (hunger < 0) hunger = 0;
}

//                             :3

CatOverlord::CatOverlord() : money(0), chaosPoints(0), actionPoints(6) {}
CatOverlord::CatOverlord(int money, int chaos) : money(money), chaosPoints(chaos), actionPoints(6) {}

CatOverlord::CatOverlord(const CatOverlord& other)
    : cats(other.cats), money(other.money), chaosPoints(other.chaosPoints), actionPoints(other.actionPoints) {}

CatOverlord& CatOverlord::operator=(const CatOverlord& other) {
    if (this != &other) {
        cats = other.cats;
        money = other.money;
        chaosPoints = other.chaosPoints;
        actionPoints = other.actionPoints;
    }
    return *this;
}

void CatOverlord::addCat(const Cat& c) {
    cats.push_back(c);
}

void CatOverlord::feedCat(int index, int amount) {
    if (actionPoints > 0 && index >= 0 && index < (int)cats.size()) {
        cats[index].feed(amount);
        actionPoints--;
    }
}

void CatOverlord::encourageCat(int index, int amount) {
    if (actionPoints > 0 && index >= 0 && index < (int)cats.size()) {
        cats[index].rewardLoyalty(amount);
        actionPoints--;
    }
}

void CatOverlord::nextDay() {
    actionPoints = 6;
    constexpr int DAILY_HUNGER_INCREASE = 15;
    for (size_t i = 0; i < cats.size(); i++)
        cats[i].increaseHunger(DAILY_HUNGER_INCREASE);
}

void CatOverlord::sendOnMission(int index, int missionDifficulty) {
    if (actionPoints > 2 && index >= 0 && index < (int)cats.size()) {
        if (cats[index].getEvilness() > missionDifficulty) {
            money += missionDifficulty * 2;
            chaosPoints += missionDifficulty;
        }
        actionPoints -= 3;
    }
}

int CatOverlord::getMoney() const { return money; }
int CatOverlord::getChaos() const { return chaosPoints; }
int CatOverlord::getActionPoints() const { return actionPoints; }

ostream& operator<<(ostream& os, const CatOverlord& o) {
    os << "Money: " << o.money << " | Chaos: " << o.chaosPoints << " | AP: " << o.actionPoints << "\n";
    for (size_t i = 0; i < o.cats.size(); i++) {
        os << "  [" << i << "] " << o.cats[i] << "\n";
    }
    return os;
}
