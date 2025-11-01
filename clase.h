#ifndef CLASE_H
#define CLASE_H

#include <string>
#include <vector>
#include <ostream>

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
    Cat& operator=(const Cat& other);
    friend ostream& operator<<(ostream& os, const Cat& c);

    [[nodiscard]] string getName() const;
    [[nodiscard]] int getEvilness() const;
    [[nodiscard]] int getCuteness() const;
    [[nodiscard]] int getHunger() const;
    [[nodiscard]] int getLoyalty() const;

    void feed(int cant);
    void trainEvil(int cant);
    void pet(int cant);
    void rewardLoyalty(int cant);
    void increaseHunger(int cant);
};

//                        :3

class Mission {
private:
    string name;
    int difficulty;
    int rewardMoney;
    int rewardChaos;
    int hungerCost;
    int minEvilness;
    int minLoyalty;

public:
    Mission(const string& n, int diff, int money, int chaos, int hunger, int minE, int minL);

    [[nodiscard]] int getRewardMoney() const { return rewardMoney; }
    [[nodiscard]] int getRewardChaos() const { return rewardChaos; }
    [[nodiscard]] int getHungerCost() const { return hungerCost; }

    bool attempt(Cat& c) const;

    friend ostream& operator<<(ostream& os, const Mission& m);
};


//                                 :3

class CatOverlord {
private:
    vector<Cat> cats;
    int money;
    int chaosPoints;
    int actionPoints;

public:
    CatOverlord();
    CatOverlord(int money, int chaos);
    CatOverlord(const CatOverlord& other);
    CatOverlord& operator=(const CatOverlord& other);
    friend ostream& operator<<(ostream& os, const CatOverlord& o);

    void addCat(const Cat& c);
    void feedCat(int index, int cant);
    void encourageCat(int index, int cant);
    void nextDay();
    void sendOnMission(int index, const Mission& m);

    [[nodiscard]] int getMoney() const;
    [[nodiscard]] int getChaos() const;
    [[nodiscard]] int getActionPoints() const;
};

//               :3



#endif //CLASE_H
