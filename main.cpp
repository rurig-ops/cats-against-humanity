#include <iostream>
#include "clase.h"
using namespace std;

int main() {
    //pisici
    Cat cat1("Magu", 50, 80, 30, 80);
    Cat cat2("Dracat Mihaita", 80, 20, 60, 50);
    Cat cat3("Lucius", 30, 90, 20, 90);

    //overlord
    CatOverlord overlord;
    overlord.addCat(cat1);
    overlord.addCat(cat2);
    overlord.addCat(cat3);

    //humanity
    Humanity humans;

    //misiuni
    Mission bankHeist("Steal Socks", 15, 5, 30, 25, 35, 10, 0, Mission::EVIL);
    Mission pizzaSteal("Infiltrate the government", 45, 40, 5, 5, 66, 50, 0, Mission::EVIL);
    Mission funnyCompilation("Funny Cat Compilation", 5, 0, 0, 5, 0, 0, 20, Mission::PR);

    bool gameEnd = false;
    while (gameEnd == false) {
        cout << "\n Cat Overlord Status " << endl;
        cout << overlord << endl;
        cout << humans << endl;

        cout << "\nChoose action:\n";
        cout << "1. Feed a cat\n2. Encourage a cat\n3. Train cat Evilness\n4. Send cat on mission\n5. Next day\n6. Quit\n> ";

        int choice;
        cin >> choice;

        int index, amount;
        switch (choice) {
            case 1:
                cout << "Select cat index to feed: ";
                cin >> index;
                cout << "Amount to feed: ";
                cin >> amount;
                overlord.feedCat(index, amount);
                break;
            case 2:
                cout << "Select cat index to encourage: ";
                cin >> index;
                cout << "Amount to increase loyalty: ";
                cin >> amount;
                overlord.encourageCat(index, amount);
                break;
            case 3:
                cout << "Select cat index to train evilness: ";
                cin >> index;
                cout << "Amount to train evilness: ";
                cin >> amount;
                overlord.trainCatEvil(index, amount);
                break;
            case 4:
                cout << "Select cat index to send on mission: ";
                cin >> index;
                cout << "Select mission:\n1. Bank Heist\n2. Steal Pizza\n3. Funny Compilation\n> ";
                int missionChoice;
                cin >> missionChoice;
                if (missionChoice == 1)
                    gameEnd = overlord.sendOnMission(index, bankHeist, humans);
                else if (missionChoice == 2)
                    gameEnd = overlord.sendOnMission(index, pizzaSteal, humans);
                else if (missionChoice == 3)
                    gameEnd = overlord.sendOnMission(index, funnyCompilation, humans);
                break;
            case 5:
                overlord.nextDay();
                cout << "Day advanced. Action points reset and hunger increased.\n";
                break;
            case 6:
                gameEnd = true;
                break;
            default:
                cout << "Invalid choice!\n";
        }

        if (humans.isGameOver()) {
            cout << "Game Over! Humans discovered the cat conspiracy!\n";
            break;
        }
    }

    cout << ":3";

    return 0;
}
