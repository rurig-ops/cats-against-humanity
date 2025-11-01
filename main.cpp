#include <iostream>
#include "clase.h"
using namespace std;

int main() {

    Cat cat1("Magu", 50, 80, 30, 80);
    Cat cat2("Dracat Mihaita", 80, 20, 60, 50);
    Cat cat3("Lucius", 30, 90, 20, 90);

    cout << "Cats" << endl;
    cout << cat1 << endl;
    cout << cat2 << endl;
    cout << cat3 << endl << endl;

    cat1.feed(20);
    cat2.trainEvil(15);
    cat3.pet(25);
    cat1.rewardLoyalty(10);
    cat2.increaseHunger(30);

    cout << "\n Cats stats " << endl;
    cout << cat1 << endl;
    cout << cat2 << endl;
    cout << cat3 << endl << endl;

    CatOverlord overlord(100, 0);

    overlord.addCat(cat1);
    overlord.addCat(cat2);
    overlord.addCat(cat3);

    cout << "\n The Overlord" << endl;
    cout << overlord << endl;

    overlord.feedCat(0, 15);       // Magu
    overlord.encourageCat(1, 20);  // Mihaita Dracat

    cout << "\n Stats " << endl;
    cout << overlord << endl;

    overlord.sendOnMission(1, 50); // evilness 95
    overlord.sendOnMission(2, 25);

    cout << "\n Stats " << endl;
    cout << overlord << endl;

    overlord.nextDay();

    cout << "\n Stats next day" << endl;
    cout << overlord << endl;

    Cat copyCat = cat1; // constructor copiere
    CatOverlord copyOverlord= overlord; // operator=

    cout << "\n Cat clone" << endl;
    cout << copyCat << endl;

    cout << "\n Overlord clone" << endl;
    cout << copyOverlord << endl;

    return 0;
}
