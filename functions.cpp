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
    ifstream inFile("InFile.txt");  // INPUT - the file to be read
    string name;                      // INPUT - the name of the person
    char gender;                      // INPUT - the gender of the person
    int age;                          // INPUT - the age of the person

    // Check first.
    if (isEmpty(head)) {
        cout << "\nList already created.\n";
        return;
    }

    while (!inFile.eof()) {
        getline(inFile, name);
        inFile >> gender >> age;

        // 2x to ignore the newline
        inFile.ignore();
        inFile.ignore();

        cout << endl << " Adding : " << name;

        Person* personPtr = new Person;
        personPtr->name = name;
        personPtr->gender = gender;
        personPtr->age = age;
        personPtr->next = head;
        personPtr->prev = nullptr;
        if (head != nullptr) head->prev = personPtr;
        head = personPtr;
    }

    inFile.close();
}

/* displayList
 *
 * prints the list
 */
void displayList(Person* head) {
    int count = 0;         // OUTPUT - the number of nodes in the list
    Person* person = head; // INPUT - the head of the list

    if (isEmpty(head)) cout << "\nCan't display an empty list\n\n";
    else {
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
    }
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


    cout << "Who would you like to search for? ";
    getline(cin, name);

    cout << "Searching for " << name << "...";

    if (head == nullptr) cout << "I'm sorry, \"" << head->name << "\" was not found.";
    else {
        cout
        << "\n\nName: " << head->name
        << "\nGender: " << head->gender
        << "\nAge: " << head->age << endl;
    }

    while (person != nullptr) person = person->next;
}

/* removeNode
 *
 * removes a node from the list
 */
void removeNode(Person* head) {

    string nameInput;         // INPUT - the name of the person to be removed
    Person* person = head;    // INPUT - the head of the list
    Person* prev = nullptr;   // OUTPUT - the previous node

    if (isEmpty(head)) {
        cout << "\nCan't remove a node from an empty list\n\n";
        return;
    }

    cout << "Who would you like to remove? ";
    getline(cin, nameInput);

    cout << "Searching for " << nameInput << "...";

    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "**** Please input a NAME ****" << endl;
    } else if (nameInput.empty()) cout << "**** Please input a NAME ****" << endl;
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
}

/*
 * clearList
 *
 * clears the list
 */
void clearList(Person* head) {
    Person* person = head;    // INPUT - the head of the list

    cout << "CLEARING LIST:" << endl;
    while (person != nullptr) {
        Person* next = person->next;
        cout << "\nRemoving " << person->name << "!";
        delete person;
        person = next;
    }

    cout << "\n\nThe list has been cleared.\n" << endl;
    head = nullptr;
}