#include <iostream>
#include "clase.h"
using namespace std;

int main() {
    srand(time(nullptr));

    CatOverlord overlord;
    Humanity humans;

    overlord.addCat(Cat("Magu", 50,80,30,80));
    overlord.addCat(Cat("Dracat",80,20,60,50));
    overlord.addCat(Cat("Lucius",30,90,20,90));

    bool end = false;
    while (!end) {
        cout << "\n=== CAT OVERLORD ===\n" << overlord << humans << "\n";
        cout << "1.Feed 2.Encourage 3.Train Evil 4.Send Mission\n";
        cout << "5.Next Day 6.Quit 7.Adopt Cat 8.Show Missions\n> ";

        int ch; cin >> ch;
        int i, amt, m;

        switch(ch) {
            case 1: cout<<"Cat index:";cin>>i; cout<<"Food:";cin>>amt; overlord.feedCat(i,amt); break;
            case 2: cout<<"Cat index:";cin>>i; cout<<"Loyalty:";cin>>amt; overlord.encourageCat(i,amt); break;
            case 3: cout<<"Cat index:";cin>>i; cout<<"Evil:";cin>>amt; overlord.trainCatEvil(i,amt); break;
            case 4:
                cout<<"Cat index:";cin>>i;
                cout<<"Missions:\n";
                for (int k=0;k<(int)overlord.getMissions().size();k++)
                    cout<<"["<<k<<"] "<<overlord.getMissions()[k]<<endl;
                cin>>m;
                end = overlord.sendOnMission(i, overlord.getMissions()[m], humans);
                break;
            case 5: overlord.nextDay(); break;
            case 6: end = true; break;
            case 7: overlord.adoptCat(); break;
            case 8:
                for (int k=0;k<(int)overlord.getMissions().size();k++)
                    cout<<"["<<k<<"] "<<overlord.getMissions()[k]<<endl;
                break;
            default:
                cout<<"Invalid input!\n";
                break;
        }
        if (humans.isGameOver()) { cout<<"Humans discovered cats! GAME OVER\n"; break; }
    }
    return 0;
}
