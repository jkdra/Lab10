//
// Created by Jawad Khadra on 11/6/24.
//

#ifndef MYHEADER_H
#define MYHEADER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Person {
    string name;
    char gender;
    int age;
    Person* prev;
    Person* next;
};

enum MenuOption {
 EXIT = 0,
 CREATE_LIST = 1,
 DISPLAY_LIST = 2,
 CHECK_EMPTY = 3,
 SEARCH_BY_NAME = 4,
 REMOVE_NODE = 5,
 CLEAR_LIST = 6
};

/*
 * printHeader
 *
 * prints the header of the lab
 */
void printHeader();

/*
 * createList
 *
 * creates a list of nodes
 */
void createList(Person*& head);

/*
 * displayList
 *
 * prints the list
 */
void displayList(Person* head);

/*
 * isEmpty
 *
 * returns true if the list is empty
 */
bool isEmpty(Person* head);

/*
 * searchByName
 *
 * searches for a person by name
 */
Person* searchByName(Person* head, string name);

/*
 * removeNode
 *
 * removes a node from the list
 */
void removeNode(Person* head, string name);

/*
 * clearList
 *
 * clears the list
 */
void clearList(Person* head);

#endif //MYHEADER_H
