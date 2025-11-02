#include <iostream>
#include "clase.h"
using namespace std;

//                                    :3

Cat::Cat(string n, int e, int c, int h, int l)
    : name(n), evilness(e), cuteness(c), hunger(h), loyalty(l) {}

//constructor copiere
Cat::Cat(const Cat &other)
    : name(other.name), evilness(other.evilness), cuteness(other.cuteness), hunger(other.hunger), loyalty(other.loyalty) {}

Cat::~Cat() {}

//op =
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

const string& Cat::getName() const { return name; }
int Cat::getEvilness() const { return evilness; }
int Cat::getCuteness() const { return cuteness; }
int Cat::getHunger() const { return hunger; }
int Cat::getLoyalty() const { return loyalty; }

void Cat::feed(int cant) {
    hunger -= cant;
    if (hunger < 0) hunger = 0;
    cout << name << " was fed. Hunger: " << hunger << endl;
}

void Cat::trainEvil(int cant) {
    evilness += cant;
    if (evilness > 100) evilness = 100;
    cout << name << " trained fiendishly. Evilness: " << evilness << endl;
}

void Cat::pet(int cant) {
    cuteness += cant;
    if (cuteness > 100) cuteness = 100;
    cout << name << " got some pets. Cuteness: " << cuteness << endl;
}

void Cat::rewardLoyalty(int cant) {
    loyalty += cant;
    if (loyalty > 100) loyalty = 100;
    cout << name << " is more loyal now! Loyalty: " << loyalty << endl;
}

void Cat::increaseHunger(int cant) {
    hunger += cant;
    if (hunger > 100) hunger = 100;
}

//                                             :3

Humanity::Humanity(int start, int maxS) : suspicion(start), maxSuspicion(maxS) {}

void Humanity::increaseSuspicion(int val) {
    suspicion += val;
    if (suspicion > maxSuspicion) suspicion = maxSuspicion;

    cout << "Human suspicion increased: "
         << suspicion << "/" << maxSuspicion << endl;

    if (isGameOver())
        cout << "Humans discovered the cat conspiracy! Game Over!" << endl;
}

void Humanity::decreaseSuspicion(int val) {
    suspicion -= val;
    if (suspicion < 0) suspicion = 0;

    cout << "Suspicion lowered: "
         << suspicion << "/" << maxSuspicion << endl;
}

bool Humanity::isGameOver() const {
    return suspicion >= maxSuspicion;
}

ostream& operator<<(ostream& os, const Humanity& h) {
    os << "Human Suspicion: " << h.suspicion << "/" << h.maxSuspicion;
    return os;
}

//                                    :3

Mission::Mission(const string& n, int diff, int money, int chaos, int hunger, int minE, int minL, MissionType t)
    : name(n), difficulty(diff), rewardMoney(money), rewardChaos(chaos), hungerCost(hunger),
      minEvilness(minE), minLoyalty(minL), type(t) {}

bool Mission::attempt(Cat& c) const {
    return c.getEvilness() >= minEvilness && c.getLoyalty() >= minLoyalty;
}

ostream& operator<<(ostream& os, const Mission& m) {
    os << "Mission: " << m.name
       << " | Type: " << (m.type == Mission::EVIL ? "EVIL" : "PR")
       << " | Difficulty: " << m.difficulty
       << " | Reward: " << m.rewardMoney
       << " | Chaos: " << m.rewardChaos;
    return os;
}

//                                              :3

CatOverlord::CatOverlord(int startMoney, int startChaos, int startAP)
    : money(startMoney), chaosPoints(startChaos), actionPoints(startAP) {}

void CatOverlord::addCat(const Cat& c) {
    cats.push_back(c);
}

void CatOverlord::feedCat(int i, int cant) {
    if (actionPoints <= 0) return;
    cats[i].feed(cant);
    actionPoints--;
}

void CatOverlord::encourageCat(int i, int cant) {
    if (actionPoints <= 0) return;
    cats[i].rewardLoyalty(cant);
    actionPoints--;
}

void CatOverlord::sendOnMission(int i, const Mission& m, Humanity& humans) {
    if (actionPoints < 2) {
        cout << "Not enough action points to send a cat on a mission!" << endl;
        return;
    }

    bool success = m.attempt(cats[i]);

    cout << cats[i].getName() << " was sent on mission: " << m.getName() << "..." << endl;

    if (m.getType() == Mission::EVIL) {
        if (success) {
            money += m.getRewardMoney();
            chaosPoints += m.getRewardChaos();
            cout << "Mission SUCCESS! " << cats[i].getName() << " completed " << m.getName() << endl;
        } else {
            humans.increaseSuspicion(m.getDifficulty());
            cout << "Mission FAILED! " << cats[i].getName() << " could not complete " << m.getName() << endl;
        }
    } else{ // PR mission
        if (success) {
            humans.decreaseSuspicion(m.getDifficulty());
            cout << "PR Mission SUCCESS! " << cats[i].getName()
                 << " lowered suspicion with " << m.getName() << endl;
        } else {
            humans.increaseSuspicion(m.getDifficulty() * 2);
            cout << "PR Mission FAILED! " << cats[i].getName()
                 << "'s attempt at " << m.getName() << " backfired!" << endl;
        }
    }

    cats[i].increaseHunger(m.getHungerCost());
    actionPoints -= 2;
}

void CatOverlord::nextDay() {
    actionPoints = 6; // reset action points daily
    for (auto &c : cats)
        c.increaseHunger(15);
}

int CatOverlord::getMoney() const { return money; }
int CatOverlord::getChaos() const { return chaosPoints; }
int CatOverlord::getActionPoints() const { return actionPoints; }

ostream& operator<<(ostream& os, const CatOverlord& o) {
    os << "Money: " << o.money << " | Chaos: " << o.chaosPoints
       << " | AP: " << o.actionPoints << "\n";
    for (size_t i = 0; i < o.cats.size(); i++)
        os << "[" << i << "] " << o.cats[i] << "\n";
    return os;
}
