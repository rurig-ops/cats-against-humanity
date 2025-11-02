#include "clase.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// :3

Cat::Cat(string n, int e, int c, int h, int l)
: name(n), evilness(e), cuteness(c), hunger(h), loyalty(l) {}

Cat::Cat(const Cat& o)
: name(o.name), evilness(o.evilness), cuteness(o.cuteness), hunger(o.hunger), loyalty(o.loyalty) {}

Cat::~Cat() {}

Cat& Cat::operator=(const Cat& o) {
    if (this != &o) {
        name = o.name; evilness = o.evilness;
        cuteness = o.cuteness; hunger = o.hunger; loyalty = o.loyalty;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Cat& c) {
    os << c.name << " | Evil:" << c.evilness
       << " Cute:" << c.cuteness
       << " Hunger:" << c.hunger
       << " Loyalty:" << c.loyalty;
    return os;
}

const string& Cat::getName() const { return name; }
int Cat::getEvilness() const { return evilness; }
int Cat::getCuteness() const { return cuteness; }
int Cat::getHunger() const { return hunger; }
int Cat::getLoyalty() const { return loyalty; }

void Cat::feed(int c) { hunger = max(0, hunger - c); cout << name << " eats.\n"; }
void Cat::trainEvil(int c) { evilness = min(100, evilness + c); cout << name << " trains evil.\n"; }
void Cat::rewardLoyalty(int c) { loyalty = min(100, loyalty + c); cout << name << " purrs happily.\n"; }
void Cat::increaseHunger(int c) { hunger = min(100, hunger + c); }

// :3

Humanity::Humanity(int s, int m) : suspicion(s), maxSuspicion(m) {}

void Humanity::increaseSuspicion(int v) { suspicion = min(maxSuspicion, suspicion + v); }
void Humanity::decreaseSuspicion(int v) { suspicion = max(0, suspicion - v); }
bool Humanity::isGameOver() const { return suspicion >= maxSuspicion; }

ostream& operator<<(ostream& os, const Humanity& h) {
    return os << "Suspicion: " << h.suspicion << "/" << h.maxSuspicion;
}

// :3

Mission::Mission(const string& n, int diff, int money, int chaos, int hunger, int minE, int minL, int minC, MissionType t)
: name(n), difficulty(diff), rewardMoney(money), rewardChaos(chaos), hungerCost(hunger),
  minEvilness(minE), minLoyalty(minL), minCuteness(minC), type(t) {}

Mission Mission::randomMission() {
    static string names[] = {
        "Steal Tuna", "Hack NASA With Meows", "Charm Internet",
        "Destroy Dog Park", "Meow At 3 AM", "Steal Socks", "Claw Curtains"
    };

    string n = names[rand() % 7];
    MissionType t = (rand() % 2 ? EVIL : PR);

    return Mission(
        n, rand()%40+10,
        (t == EVIL ? rand()%50+10 : 0),
        (t == EVIL ? rand()%30+5 : 0),
        rand()%20+5,
        rand()%60, rand()%60, rand()%60, t
    );
}

const string& Mission::getName() const { return name; }
int Mission::getRewardMoney() const { return rewardMoney; }
int Mission::getRewardChaos() const { return rewardChaos; }
int Mission::getHungerCost() const { return hungerCost; }
int Mission::getDifficulty() const { return difficulty; }
Mission::MissionType Mission::getType() const { return type; }

bool Mission::attempt(const Cat& c) const {
    if (type == EVIL) return c.getEvilness() >= minEvilness && c.getLoyalty() >= minLoyalty;
    return c.getCuteness() >= minCuteness && c.getLoyalty() >= minLoyalty;
}

ostream& operator<<(ostream& os, const Mission& m) {
    return os << m.name << " (" << (m.type==Mission::EVIL?"EVIL":"PR")
              << ") diff:" << m.difficulty;
}

// :3

CatOverlord::CatOverlord(int m, int c, int ap)
: money(m), chaosPoints(c), actionPoints(ap) {
    srand(time(0));
    for (int i=0;i<3;i++) missions.push_back(Mission::randomMission());
}

ostream& operator<<(ostream& os, const CatOverlord& o) {
    os << "Money:" << o.money << " Chaos:" << o.chaosPoints << " AP:" << o.actionPoints << "\n";
    for (int i=0;i<o.cats.size();i++) os << "[" << i << "] " << o.cats[i] << "\n";
    return os;
}

void CatOverlord::addCat(const Cat& c) { cats.push_back(c); }

vector<Mission>& CatOverlord::getMissions() { return missions; }

void CatOverlord::feedCat(int i, int c) {
    if (actionPoints<=0 || c>money) return;
    cats[i].feed(c); money-=c; actionPoints--;
}
void CatOverlord::encourageCat(int i, int c) {
    if (actionPoints<=0) return;
    cats[i].rewardLoyalty(c); actionPoints--;
}
void CatOverlord::trainCatEvil(int i, int c) {
    if (actionPoints<=0 || c>money) return;
    cats[i].trainEvil(c); money-=c; actionPoints--;
}

bool CatOverlord::sendOnMission(int i, const Mission& m, Humanity& H) {
    if (actionPoints < 2) return false;

    bool ok = m.attempt(cats[i]);
    actionPoints -= 2;
    cats[i].increaseHunger(m.getHungerCost());

    if (m.getType()==Mission::EVIL) {
        if (ok){ money+=m.getRewardMoney(); chaosPoints+=m.getRewardChaos(); }
        else H.increaseSuspicion(m.getDifficulty());
    }
    else {
        if (ok) H.decreaseSuspicion(m.getDifficulty());
        else H.increaseSuspicion(m.getDifficulty()*2);
    }

    return H.isGameOver() || chaosPoints >= 100;
}

void CatOverlord::nextDay() {
    actionPoints = 6;
    for (auto& c: cats) c.increaseHunger(15);
    missions.clear();
    for (int i=0;i<3;i++) missions.push_back(Mission::randomMission());
    cout << "A new day... and new missions!\n";
}

Cat CatOverlord::generateRandomCat() {
    static string names[] = {"Whiskertron","Shadowpaw","Flufflord","Meowgician","Sneakpaws"};
    return Cat(names[rand()%5], rand()%101, rand()%101, rand()%51, rand()%101);
}

void CatOverlord::adoptCat() {
    if (money < 30) { cout << "Need 30 money!\n"; return; }
    Cat c = generateRandomCat();
    cout << "New cat discovered!\n" << c << "\nAdopt for 30? (1/0): ";
    int x; cin >> x;
    if (x){ cats.push_back(c); money -= 30; cout << "Cat adopted!\n"; }
    else cout << "Cat leaves...\n";
}
