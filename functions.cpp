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

    while (!inFile.eof()) {
        getline(inFile, name);
        inFile >> gender >> age;
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
}