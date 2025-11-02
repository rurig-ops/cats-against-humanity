#include <iostream>
#include "clase.h"
using namespace std;

int main() {
    Cat cat1("Magu", 50, 80, 30, 80);
    Cat cat2("Dracat Mihaita", 80, 20, 60, 50);
    Cat cat3("Lucius", 30, 90, 20, 90);
    Cat cat4("Sebi");

    CatOverlord overlord;
    overlord.addCat(cat1);
    overlord.addCat(cat2);
    overlord.addCat(cat3);
    overlord.addCat(cat4);

    Humanity humans;

    bool gameEnd = false;
    while (!gameEnd) {
        overlord.printStatus();
        overlord.sortCatsByEvilness();
        overlord.printCats();
        cout << humans << endl;

        cout << "\nChoose action:\n1. Feed a cat\n2. Encourage a cat\n3. Train cat Evilness\n4. Send cat on mission\n5. Next day\n6. Quit\n> ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: overlord.feedCatInteractive(); break;
            case 2: overlord.encourageCatInteractive(); break;
            case 3: overlord.trainCatEvilInteractive(); break;
            case 4: overlord.sendOnMissionInteractive(humans); break;
            case 5: overlord.nextDay(); cout << "Day advanced.\n"; break;
            case 6: gameEnd = true; break;
            default: cout << "Invalid choice!\n"; break;
        }

        if (humans.isGameOver()) { cout << "Game Over! Humans discovered the cat conspiracy!\n"; break; }
    }

    cout << ":3\n";
    return 0;
}
