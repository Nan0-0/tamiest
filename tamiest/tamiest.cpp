// tamiest.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <thread> 
#include <chrono> 
#include <cstdlib>

enum class Mood {
    SAD,
    HAPPY,
    EXCITED,
    UNEASY
};

enum class TimePeriod {
    MORNING,
    AFTERNOON,
    EVENING,
    MIDNIGHT
};

enum class Action {
    FEED,
    PLAY,
    WALK,
    TEACH_TRICKS,
    CLEAN_UP,
    GIVE_MEDICINE,
    ATTEND_TO_ATTENTION,
    GO_TO_SLEEP
};

class Tamagorchi {
private:
    int age;
    int hungerLevel;
    int happinessLevel;
    bool isSick;
    int cleanlinessLevel;
    int cleanUpFailures; 


public:
    bool isAsleep;


    Tamagorchi();
    void wakeUp();
    void performAction(Action action);
    void checkStatus();
    void aging();
    void updateMood(Mood mood);
    void timerFunction();
    void handleRandomEvent();
    void handleRandomPoop();
    void displayDeath();
    void handleSeepingTime(int hour);
    void sleep();
    int getCleanlinessLevel();
};

Tamagorchi::Tamagorchi() : age(0), hungerLevel(0), happinessLevel(0), isSick(false), isAsleep(true), cleanlinessLevel(10) {}

int Tamagorchi::getCleanlinessLevel() {
    return cleanlinessLevel;
}

void Tamagorchi::wakeUp() {
    std::cout << " Tama is waking up.\n";
    isAsleep = false;
    age++;
}
void Tamagorchi::sleep() {
    std::cout << "Tama is going to sleep...\n";
    isAsleep = true;
}

void Tamagorchi::handleSeepingTime(int hour) {
    if ((hour >= 6 && hour < 7) && !isAsleep) {
        std::cout << "It's midnight! Tama must sleep \n";
        displayDeath();
        exit(0);
    }
}

void Tamagorchi::displayDeath() {
    std::cout << "Tama was" << age << "at the time of death \n";
}

void Tamagorchi::checkStatus() {
    std::cout << "Checking tama stats...\n";
    std::cout << "Age: " << age << " Hunger: " << hungerLevel << " Happiness: " << happinessLevel << std::endl;
    if (isSick)
        std::cout << "Tama is sick :^[ \n";
    if (isAsleep)
        std::cout << "Tama is asleep \n";
}

void Tamagorchi::performAction(Action action) {
    switch (action) {
    case Action::FEED:
        std::cout << "Tamagotchi is being fed.";
        hungerLevel--;
        updateMood(Mood::HAPPY);
        break;
    case Action::PLAY:
        std::cout << "Playing game with Tamagotchi.";
        happinessLevel++;
        updateMood(happinessLevel < 3 ? Mood::SAD : Mood::HAPPY);
        break;
    case Action:: WALK:
        std::cout << "Taking tama for a walk.";
        happinessLevel += 2;
        updateMood(happinessLevel < 3 ? Mood::SAD : Mood::HAPPY);
        break;
    case Action:: TEACH_TRICKS:
        std::cout << "Teaching tricks to tama.";
        happinessLevel += 3;
        updateMood(happinessLevel < 3 ? Mood::SAD : Mood::HAPPY);
        break;
    case Action::CLEAN_UP:
        std::cout << "Cleaning up tama enviorment.";
        cleanlinessLevel += 2;
        happinessLevel++;
        updateMood(happinessLevel < 3 ? Mood::SAD : Mood::HAPPY);
        break;
    case Action::GIVE_MEDICINE:
        std::cout << "Medicine given to tama.";
        isSick = false;
        updateMood(Mood::HAPPY);
        break;
    case Action::ATTEND_TO_ATTENTION:
        std::cout << "attention given to tama.";
        happinessLevel++;
        updateMood(happinessLevel < 3 ? Mood::SAD : Mood::HAPPY);
        break;
    case Action::GO_TO_SLEEP: 
        if (!isAsleep) {
            sleep();
        }
        else {
            std::cout << "Tama is already asleep \n";
        }
        break;
    default:
        std::cout << "Invalid action.";
        break;
    }
}

void Tamagorchi::updateMood(Mood mood) {
    switch (mood) {
    case Mood::HAPPY:
        std::cout << "\nHappy Tama \n";
        break;
    case Mood::SAD:
        std::cout << "\nSad Tama \n";
        break;
        // other moods here
    default:
        break;
    }
}

void Tamagorchi::aging() {
    age++;
    if (age % 5 == 0) {
        std::cout << "Tama ages up! \n";
    }
    if (age % 10 == 0) {
        std::cout << "Tama not feeling well! \n";
        isSick = true;
    }
}

void Tamagorchi::timerFunction() {
    if (isAsleep) {
        aging();
    }
    handleRandomEvent();
}

void Tamagorchi::handleRandomEvent() {
    srand(time(0));
    int randomEvent = rand() % 10;

    switch (randomEvent) {
    case 0:
        std::cout << "Unexpected! Tama feels uneasy \n";
        updateMood(Mood::UNEASY);
        break;
    case 1:
        std::cout << "Visitors from another planet! Tama is excited \n";
        updateMood(Mood::EXCITED);
        break;
        // Add 
    default:
        break;
    }
}

void Tamagorchi::handleRandomPoop() {
    srand(time(0));
    int randomEvent = rand() % 10;

    if (randomEvent == 0) {
        std::cout << "oh no! tama poop \n";
        cleanlinessLevel -= 2;

    }
}


int main() {

    Tamagorchi myTamagorchi;
    myTamagorchi.wakeUp();
    myTamagorchi.checkStatus();

    int choice;
    std::cin >> choice;
    int day = 1;
    int hour = 0;

    for (int hour = 0; hour < 24; hour++) {
        if (hour >= 0 && hour < 2) {

            std::cout << "Morning actions available. Choose an action:\n";
            std::cout << "1. Feed\n2. Play\n3. Walk\n4. Teach Tricks\n5. Clean up 6. Give medicine 7. Give attention 8.Go to sleep";
        }
        else if (hour >= 2 && hour < 4) {
            std::cout << "Afternoon actions available. Choose an action:\n";
            std::cout << "1. Feed\n2. Play\n3. Walk\n4. Teach Tricks\n5. Clean up 6. Give medicine 7. Give attention 8.Go to sleep";
        }
        else if (hour >= 4 && hour < 6) {
            std::cout << "Evening actions available. Choose an action:\n";
            std::cout << "1. Feed\n2. Play\n3. Walk\n4. Teach Tricks\n5. Clean up 6. Give medicine 7. Give attention 8.Go to sleep";
        }
        else if (hour >= 6 && hour < 8) {
            std::cout << "Midnight. Choose an action:\n";
            std::cout << "8. Go to Sleep\n";
        }

        myTamagorchi.handleRandomPoop();
        if (myTamagorchi.cleanlinessLevel <= 0) {
            myTamagorchi.displayDeath();
            std::cout << "Tama died due to neglect.\n";
            exit(0);
        }
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            myTamagorchi.performAction(Action::FEED);
            break;
        case 2:
            myTamagorchi.performAction(Action::PLAY);
            break;
        case 3:
            myTamagorchi.performAction(Action::WALK);
            break;
        case 4:
            myTamagorchi.performAction(Action::TEACH_TRICKS);
            break;
        case 5:
            myTamagorchi.performAction(Action::CLEAN_UP);
            break;
        case 6:
            myTamagorchi.performAction(Action::GIVE_MEDICINE);
            break;
        case 7:
            myTamagorchi.performAction(Action::ATTEND_TO_ATTENTION);
            break;
        case 8:
            if (hour >= 6 && hour < 7) {
                myTamagorchi.performAction(Action::GO_TO_SLEEP);
                system("cls || clear");
          
                std::cout << "Starting a new day...\n";
                day++;
                hour = 0;
                std::cout << "Day " << day << " . It's a new day! \n";
                break;
            }
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Tama is upset.\n";
            break;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Hour: " << hour << std::endl;
        myTamagorchi.handleSeepingTime(hour);

    }
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
