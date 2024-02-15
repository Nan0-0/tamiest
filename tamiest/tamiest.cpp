// tamiest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


enum class Mood {
    SAD,
    HAPPY,
    EXCITED,
    UNEASY
};
enum class Action {
    FEED,
    PLAY,
    WALK,
    TEACH_TRICKS,
    CLEAN_UP,
    GIVE_MEDICINE,
    ATTEND_TO_ATTENTION,
   
};

class Tamagorchi {
private:
    int age;
    int hungerLevel;
    int happinessLevel;
    bool isSick;
    bool isAsleep;

public:
    Tamagorchi();
    void wakeUp();
    void performAction(Action);
    void checkStatus();
    void aging();
    void updateMood(Mood);
    void timerFunction();
    void handleRandomEvent();

};

Tamagorchi::Tamagorchi() {
    age = 0;
    hungerLevel = 0;
    happinessLevel = 0;
    isSick = false;
    isAsleep = true;
}

void Tamagorchi::wakeUp() {
    std:: cout << " Tama is waking up.";
    isAsleep = false;
}

void Tamagorchi::checkStatus() {
    std::cout << "Checking tama stats...";
    std:: cout << "Age:" << age << " Hunger: " << hungerLevel << " Happiness: " << happinessLevel;
    if (isSick)
        std::cout << "Tama sick :^[";
    if (isAsleep)
        std::cout << "Tama is asleep";

}



int main()
{
    Tamagorchi myTamagorchi;
    myTamagorchi.wakeUp();
    myTamagorchi.checkStatus();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
