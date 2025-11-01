#include <iostream>
#include "clase.h"
using namespace std;

int main() {
    Cat c1 ("Magu",50,70,20,80);
    c1.feed(10);
    c1.trainEvil(20);
    c1.pet(11);
    c1.rewardLoyalty(33);

    return 0;
}
