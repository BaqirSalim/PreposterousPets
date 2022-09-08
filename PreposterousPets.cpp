// PreposterousPets.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Triceratops.h"
#include "Penguin.h"
#include "Dragon.h"

using namespace std;

int main()
{
    Pet* pet = nullptr;
    Dragon dragon;
    Penguin penguin;
    Triceratops triceratops;

    int continuation = 1;
    string petName;
    int option = 0;

    cout << "____________________________________________________________" << endl;
    cout << "Welcome to Preposterous Pets!" << endl;
    cout << "In this game you'll take care of a pet that you'd never imagine owning!" << endl;
    cout << "Please select from the following options:" << endl;
    cout << "1. Create a new pet \n2. Load a previous pet \n3. exit" << endl;
    cout << "------------------------------------------------------------" << endl;
    cin >> option;
    if (option == 1) {
        //show pet options
        cout << "Please choose what kind of pet you'd like to care for:" << endl;
        cout << "1. Penguin \n2. Triceratops \n3. Dragon" << endl;
        cout << "\nPenguin - great all rounder pet, has a high happiness stat and loves to play" << endl;
        cout << "Triceratops - requires a bit more work, gets very hungry and sleepy" << endl;
        cout << "Dragon - most demanding pet, also the biggest diva (they get bored very quickly)" << endl;
        cout << "------------------------------------------------------------" << endl;
        cin >> option;
        cin.ignore();
        cin.clear();
        if (option == 1) {
            cout << "What would you like to name your penguin?" << endl;
            getline(cin, petName);
            pet = &penguin;
            pet->setName(petName);
            cout << "\nSay hello to " << petName << ", your new baby penguin!" << endl;
            continuation = 1;
            pet->printStatus();
        }
        else if (option == 2) {
            cout << "What would you like to name your triceratops?" << endl;
            getline(cin, petName);
            pet = &triceratops;
            pet->setName(petName);
            cout << "Say hello to " << petName << ", your new baby triceratops!" << endl;
            continuation = 1;
            pet->printStatus();
        }
        else if (option == 3) {
            cout << "What would you like to name your dragon?" << endl;
            getline(cin, petName);
            pet = &dragon;
            pet->setName(petName);
            cout << "Say hello to " << petName << ", your new baby dragon!" << endl;
            continuation = 1;
            pet->printStatus();
        }
        else {
            continuation = 0;
            cout << "You did not enter a valid input. Goodbye" << endl;
        }
    }
    else if (option == 2) {
        //load old pet
        string fileName;
        cout << "Please select which type of pet you had previously: " << endl;
        cout << "1. Penguin \n2. Triceratops \n3. Dragon" << endl;
        cout << "------------------------------------------------------------" << endl;
        cin >> option;
        cout << "Please enter the file name for the saved pet: " << endl;
        cin.ignore();
        getline(cin, fileName);
        if (option == 1) {
            while (!(penguin.load(fileName))) {
                cout << "File not found. Please try entering a file name again: " << endl;
                getline(cin, fileName);
            }
            pet = &penguin;
            cout << "Welcome back " << pet->getName() << "!" << endl;
            pet->printStatus();
        }
        else if (option == 2) {
            while (!(triceratops.load(fileName))) {
                cout << "File not found. Please try entering a file name again: " << endl;
                getline(cin, fileName);
            }
            pet = &triceratops;
            cout << "Welcome back " << pet->getName() << "!" << endl;
            pet->printStatus();
        }
        else if (option == 3) {
            while (!(dragon.load(fileName))) {
                cout << "File not found. Please try entering a file name again: " << endl;
                getline(cin, fileName);
            }
            pet = &dragon;
            cout << "\nWelcome back " << pet->getName() << "!" << endl;
            pet->printStatus();
        }
        else {
            continuation = 0;
            cout << "You did not enter a valid input. Goodbye" << endl;
        }
    }
    else if (option == 3) {
        continuation = 0;
    }
    else {
        continuation = 0;
        cout << "You did not enter a valid input. Goodbye" << endl;
    }
    //game loop for interacting with pet
    while (continuation == 1) {
        cout << "------------------------------------------------------------" << endl;
        cout << "Please select an interaction from one of these options: " << endl;
        cout << "1. play \n2. feed \n3. sleep \n4. walk \n5. save and exit \n6. exit" << endl;
        cout << "------------------------------------------------------------" << endl;
        cin >> option;
        if (option == 1) {
            pet->play();
            continuation = 1;
            pet->nextHour();
        }
        else if (option == 2) {
            pet->feed();
            continuation = 1;
            pet->nextHour();
        }
        else if (option == 3) {
            pet->sleep();
            continuation = 1;
            pet->nextHour();
        }
        else if (option == 4) {
            pet->walk();
            continuation = 1;
            pet->nextHour();
        }
        else if (option == 5) {
            string fileName;
            cout << "Do you have a file to save to? If so please enter it. If not, please enter \"NA\"" << endl;
            cin.ignore();
            getline(cin, fileName);
            while (!(pet->save(fileName))) {
                cout << "File not found. Please try entering a file name again (If you do not have one, please enter \"NA\"): " << endl;
                getline(cin, fileName);
            }
            continuation = 0;
        }
        else if (option == 6) {
            cout << "Goodbye! See you next time!" << endl;
            cout << "____________________________________________________________" << endl;
            cout << "" << endl;
            continuation = 0;
        }
    }
    //pet is equal to nullptr so there is no need to delete it
}
