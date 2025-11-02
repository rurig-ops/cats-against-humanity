#ifndef CLASE_H
#define CLASE_H

#include <string>
#include <vector>
#include <ostream>
using namespace std;

//                                        :3

class Cat {
private:
    string name;
    int evilness;
    int cuteness;
    int hunger;
    int loyalty;

public:
    Cat(string n, int e, int c, int h, int l);
    Cat(const Cat &other);
    ~Cat();
    Cat& operator=(const Cat& other);
    friend ostream& operator<<(ostream& os, const Cat& c);

    const string& getName() const;
    int getEvilness() const;
    int getCuteness() const;
    int getHunger() const;
    int getLoyalty() const;

    void feed(int cant);
    void trainEvil(int cant);
    void pet(int cant);
    void rewardLoyalty(int cant);
    void increaseHunger(int cant);
};

//                                           :3

class Humanity {
private:
    int suspicion;
    int maxSuspicion;

public:
    explicit Humanity(int start = 0, int maxS = 100);

    void increaseSuspicion(int val);
    void decreaseSuspicion(int val);

    int getSuspicion() const { return suspicion; }
    int getMaxSuspicion() const { return maxSuspicion; }
    bool isGameOver() const;

    friend ostream& operator<<(ostream& os, const Humanity& h);
};

//                                         :3

class Mission {
public:
    enum MissionType { EVIL, PR };

private:
    string name;
    int difficulty;
    int rewardMoney;
    int rewardChaos;
    int hungerCost;
    int minEvilness;
    int minLoyalty;
    int minCuteness;
    MissionType type;

public:
    Mission(const string& n, int diff, int money, int chaos, int hunger, int minE, int minL, int minC, MissionType t);

    const string& getName() const { return name; }
    int getRewardMoney() const { return rewardMoney; }
    int getRewardChaos() const { return rewardChaos; }
    int getHungerCost() const { return hungerCost; }
    int getDifficulty() const { return difficulty; }
    MissionType getType() const { return type; }

    bool attempt(Cat& c) const;

    friend ostream& operator<<(ostream& os, const Mission& m);
};

//                                          :3

class CatOverlord {
private:
    vector<Cat> cats;
    int money;
    int chaosPoints;
    int actionPoints;

public:
    explicit CatOverlord(int startMoney = 50, int startChaos = 10, int startAP = 6);
    friend ostream& operator<<(ostream& os, const CatOverlord& o);

    void addCat(const Cat& c);
    void feedCat(int index, int cant);
    void encourageCat(int index, int cant);
    void nextDay();
    bool sendOnMission(int index, const Mission& m, Humanity& humans);

    int getMoney() const;
    int getChaos() const;
    int getActionPoints() const;
};

#endif
