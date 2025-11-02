#include <iostream>
#include "clase.h"
using namespace std;

int main() {

    // making the cats
    Cat cat1("Magu", 50, 80, 30, 80);
    Cat cat2("Dracat Mihaita", 80, 20, 60, 50);
    Cat cat3("Lucius", 30, 90, 20, 90);

    cout << "List of cats" << endl;
    cout << cat1 << endl;
    cout << cat2 << endl;
    cout << cat3 << endl << endl;

    cat1.feed(20);
    cat2.trainEvil(15);
    cat3.pet(25);
    cat1.rewardLoyalty(10);
    cat2.increaseHunger(30);

    cout << "\n Cats stats" << endl;
    cout << cat1 << endl;
    cout << cat2 << endl;
    cout << cat3 << endl << endl;

    CatOverlord overlord(100, 0);
    overlord.addCat(cat1);
    overlord.addCat(cat2);
    overlord.addCat(cat3);

    cout << "\n Overlord stats" << endl;
    cout << overlord << endl;

    overlord.feedCat(0, 15);       // hranim Magu
    overlord.encourageCat(1, 20);  // loialitate pt Dracat Mihaita

    cout << "\n Overlord stats " << endl;
    cout << overlord << endl;

    // making evil missions
    Mission bankHeist("Bank Heist",50, 500, 30, 25,60, 40,
        Mission::EVIL);

    Mission pizzaSteal("Steal Pizza",10, 20, 5, 5,5, 10,
        Mission::EVIL);

    // making good missions
    Mission cuteVideo("Make Funny Cat Compilation",15, 0, 0, 5,10, 20,
        Mission::PR);

    Mission tiktokMission("TikTok Cute Chaos",30, 0, 5, 10,20, 30,
        Mission::PR);

    cout << "\n Missions " << endl;
    cout << bankHeist << endl;
    cout << pizzaSteal << endl;
    cout << cuteVideo << endl;
    cout << tiktokMission << endl << endl;

    Humanity humans;

    cout << humans << endl << endl;

    overlord.sendOnMission(0, bankHeist, humans);
    overlord.sendOnMission(1, pizzaSteal, humans);
    overlord.sendOnMission(2, cuteVideo, humans);

    cout << "\n Overlord stats" << endl;
    cout << overlord << endl;

    cout << humans << endl;

    if (humans.isGameOver()) return 0;

    overlord.nextDay();

    cout << "\n Overlord stats" << endl;
    cout << overlord << endl;

    Cat copyCat = cat1;
    CatOverlord copyOverlord = overlord;

    cout << "\n Cat clone " << endl;
    cout << copyCat << endl;

    cout << "\n Overlord clone " << endl;
    cout << copyOverlord << endl;

    return 0;
}
