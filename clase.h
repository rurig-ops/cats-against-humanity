#ifndef CLASE_H
#define CLASE_H

#include <string>
#include <vector>
#include <ostream>
using namespace std;

class Cat {
private:
    string name;
    int evilness, cuteness, hunger, loyalty;
public:
    Cat(string n, int e, int c, int h, int l);
    Cat(const Cat&);
    Cat& operator=(const Cat&);
    ~Cat();

    friend ostream& operator<<(ostream&, const Cat&);

    [[nodiscard]]const string& getName() const;
   [[nodiscard]] int getEvilness() const;
    [[nodiscard]]int getCuteness() const;
    [[nodiscard]]int getHunger() const;
    [[nodiscard]]int getLoyalty() const;

    void feed(int);
    void trainEvil(int);
    void rewardLoyalty(int);
    void increaseHunger(int);
};

class Humanity {
private:
    int suspicion, maxSuspicion;
public:
    explicit Humanity(int start = 0, int maxS = 100);
    void increaseSuspicion(int);
    void decreaseSuspicion(int);
    [[nodiscard]]bool isGameOver() const;
    friend ostream& operator<<(ostream&, const Humanity&);
};

class Mission {
public:
    enum MissionType { EVIL, PR };

private:
    string name;
    int difficulty, rewardMoney, rewardChaos;
    int hungerCost, minEvilness, minLoyalty, minCuteness;
    MissionType type;

public:
    Mission(const string&, int, int, int, int, int, int, int, MissionType);
    static Mission randomMission();

    [[nodiscard]]const string& getName() const;
    [[nodiscard]]int getRewardMoney() const;
    [[nodiscard]]int getRewardChaos() const;
    [[nodiscard]]int getHungerCost() const;
    [[nodiscard]]int getDifficulty() const;
    [[nodiscard]]MissionType getType() const;

    [[nodiscard]]bool attempt(const Cat&) const;
    friend ostream& operator<<(ostream&, const Mission&);
};

class CatOverlord {
private:
    vector<Cat> cats;
    vector<Mission> missions;
    int money, chaosPoints, actionPoints;

public:
    explicit CatOverlord(int startMoney = 50, int startChaos = 10, int startAP = 6);

    friend ostream& operator<<(ostream&, const CatOverlord&);

    void addCat(const Cat&);
    void feedCat(int, int);
    void encourageCat(int, int);
    void trainCatEvil(int, int);
    bool sendOnMission(int, const Mission&, Humanity&);
    void nextDay();

    // NEW
    Cat generateRandomCat();
    void adoptCat();
    vector<Mission>& getMissions();

};

#endif
