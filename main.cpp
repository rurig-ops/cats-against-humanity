#include <iostream>
#include "clase.h"
using namespace std;

int main() {

    Cat cat1("Magu", 50, 80, 30, 80);
    Cat cat2("Dracat Mihaita", 80, 20, 60, 50);
    Cat cat3("Lucius", 30, 90, 20, 90);

    cout << "=== Initial Cats ===" << endl;
    cout << cat1 << endl;
    cout << cat2 << endl;
    cout << cat3 << endl << endl;

    cat1.feed(20);
    cat2.trainEvil(15);
    cat3.pet(25);
    cat1.rewardLoyalty(10);
    cat2.increaseHunger(30);

    cout << "\n Cats after actions " << endl;
    cout << cat1 << endl;
    cout << cat2 << endl;
    cout << cat3 << endl << endl;

    CatOverlord overlord(100, 0);
    overlord.addCat(cat1);
    overlord.addCat(cat2);
    overlord.addCat(cat3);

    cout << "\n Overlord initial " << endl;
    cout << overlord << endl;

    overlord.feedCat(0, 15);       // hranim prima pisica
    overlord.encourageCat(1, 20);  // crestem loyalty la a doua pisica

    cout << "\n Overlord after feed & encourage " << endl;
    cout << overlord << endl;

    Mission bankHeist("Bank Heist", 50, 500, 30, 25, 60, 40);
    Mission pizzaSteal("Steal Pizza", 10, 20, 5, 5, 5, 10);

    overlord.sendOnMission(0, bankHeist);   // Magu merge la Bank Heist
    overlord.sendOnMission(1, pizzaSteal);  // Mihaita Dracat merge la Steal Pizza
    overlord.sendOnMission(2, pizzaSteal);  // Lucius merge la Steal Pizza

    cout << "\n Overlord after missions " << endl;
    cout << overlord << endl;

    overlord.nextDay();

    cout << "\n Overlord next day " << endl;
    cout << overlord << endl;

    Cat copyCat = cat1;            // constructor copiere
    CatOverlord copyOverlord = overlord; // operator=

    cout << "\n Cat clone " << endl;
    cout << copyCat << endl;

    cout << "\n Overlord clone " << endl;
    cout << copyOverlord << endl;

    return 0;
}
