//
// Created by Jawad Khadra on 11/6/24.
//

#include "myHeader.h"

using namespace std;

/*
 * createList
 *
 * creates a list of nodes
 */
void createList(Person*& head) {
    ifstream inFile;    // INPUT - the file to be read
    string name;        // INPUT - the name of the person
    char gender;        // INPUT - the gender of the person
    int age;            // INPUT - the age of the person
    bool swapped;       // FLAG - true if the list was swapped

    // Initialize the input file.
    inFile.open("InFile.txt");

    while (!inFile.eof()) {
        getline(inFile, name);
        inFile >> gender >> age;

        // 2x to ignore the newline
        inFile.ignore();
        inFile.ignore();

        cout << endl << " Adding : " << name;

        // Create the objects
        Person* personPtr = new Person;
        personPtr->name = name;
        personPtr->gender = gender;
        personPtr->age = age;
        personPtr->next = head;
        personPtr->prev = nullptr;
        if (head != nullptr) head->prev = personPtr;
        head = personPtr;
    }

    cout << "\n";
    inFile.close();

    // Now to order the list alphabetically. (Currently, it's ordered by when it was last created.)
    do {
        swapped = false;
        Person* current = head;

        while (current->next != nullptr) {
            if (current->name > current->next->name) {
                // Swap the contents of the current node and the next node
                swap(current->name, current->next->name);
                swap(current->gender, current->next->gender);
                swap(current->age, current->next->age);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

/* displayList
 *
 * prints the list
 */
void displayList(Person* head) {
    int count = 1;         // OUTPUT - the number of nodes in the list
    Person* person = head; // INPUT - the head of the list



    cout
    << "\n   #    NAME                       GENDER   AGE "
    << "\n------- ------------------------- -------- -----";

    while (person != nullptr) {
        cout << "\n" << right << setw(4) << count++ << "   "
        << " " << left << setw(25) << person->name
        << " " << right << setw(4) << person->gender << "    "
        << " " << setw(3) << person->age;
        person = person->next;
    }

    cout << "\n";
}

/* isEmpty
 *
 * returns true if the list is empty
 */
bool isEmpty(Person* head) { return head == nullptr; }

/* searchByName
 *
 * searches for a person by name
 */
void searchByName(Person* head) {

    string name;            // INPUT - Name search
    Person* person = head;  // INPUT - person list

    cin.clear(); // Make sure it's clear before getting input
    cin.ignore(); // Also get rid of any newline

    cout << "\nWho would you like to search for? ";
    getline(cin, name);

    cout << "\nSearching for " << name << "...";



    while (person != nullptr) {
        if (person->name == name) {
            cout
            << "\n\nName:   " << person->name
            << "\nGender: " << person->gender
            << "\nAge:    " << person->age << endl;
            break;
        }
        person = person->next;
    }

    if (person == nullptr) cout << "\nI'm sorry, \"" << name << "\" was NOT found!\n";
}

/* removeNode
 *
 * removes a node from the list
 */
void removeNode(Person*& head) {

    string nameInput;         // INPUT - the name of the person to be removed
    Person* person = head;    // INPUT - the head of the list
    Person* prev = nullptr;   // OUTPUT - the previous node

    // Clear the input buffer and ignore any newline
    cin.clear();
    cin.ignore();
    cout << "\nWho would you like to remove? ";
    getline(cin, nameInput);

    cout << "\nSearching for " << nameInput << "...";

    if (cin.fail()) cout << "\n**** Please input a NAME ****\n" << endl;
    else if (nameInput.empty()) cout << "\n**** Please input a NAME ****\n" << endl;
    else {
        while (person != nullptr) {
            if (person->name == nameInput) {
                if (prev == nullptr) head = person->next;
                else prev->next = person->next;
                cout << "\nRemoving " << person->name << "!";
                delete person;
                break;
            }
            prev = person;
            person = person->next;
        }
    }

    if (person == nullptr) cout << "\nI'm sorry, \"" << nameInput << "\" was NOT found!\n";
}

/*
 * clearList
 *
 * clears the list
 */
void clearList(Person*& head) {
    Person* person = head;    // INPUT - the head of the list

    cout << "CLEARING LIST:" << endl;
    while (person != nullptr) {
        Person* next = person->next;
        cout << "\nRemoving " << person->name << "!";
        delete person;
        person = next;
    }

    cout << "\n\nThe list has been cleared!\n" << endl;
    head = nullptr;
}