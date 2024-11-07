/*
 * AUTHOR : Jawad Khadra
 * STUDENT ID : 1312092 (IVC)
 * LAB #
 * CLASS : CS1B
 * SECTION : MW: 7:30p - 9:50p
 * DUE DATE : November 6, 2024
 */

#include "myHeader.h"

using namespace std;

/*
 * Lab 10 - Creating an Ordered List
 *
 * This lab is to create an ordered list of nodes. The list will be created using a linked list.
 */

// main
int main() {

    MenuOption option;         // INPUT - the user's choice (as an enum)
    int optionInt;             // INPUT - the user's choice
    Person* head = nullptr;    // OUTPUT - the head of the list
    Person* person = nullptr;  // OUTPUT - the person to be added to the list

    printHeader();

    do {
        cout
        << "\n\n"
        << "LIST MENU:" << endl
        << "1 - Create List" << endl
        << "2 - Display List" << endl
        << "3 - Is the list empty?" << endl
        << "4 - Search by Name" << endl
        << "5 - Remove Node" << endl
        << "6 - Clear List" << endl
        << "0 - to Exit" << endl
        << "Enter a command (0 to exit): ";
        cin >> optionInt;
        ;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "**** Please input a NUMBER between 0 and 6 ****" << endl;
        } else if (optionInt < 0 || optionInt > 6) {
            cin.clear();
            cin.ignore();
            cout << "**** The number " << optionInt << " is an invalid entry     ****" << endl;
            cout << "**** Please input a number between 0 and 6 ****" << endl;
        }

        option = static_cast<MenuOption>(optionInt);
        switch (optionInt) {
            case CREATE_LIST:
                createList();
                break;
            case DISPLAY_LIST:
                displayList(createList());
                break;
            case CHECK_EMPTY:
                if (isEmpty(createList())) {
                    cout << "**** The list is empty ****" << endl;
                } else {
                    cout << "**** The list is not empty ****" << endl;
                }
                break;
            case SEARCH_BY_NAME:
                cout << "Enter the name to search for: ";
                string name;
                cin >> name;
                Person* person = searchByName(createList(), name);
                if (person == nullptr) {
                    cout << "**** The name " << name << " was not found ****" << endl;
                } else {
                    cout << "**** The name " << name << " was found ****" << endl;
                    cout << "**** The person's name is " << person->name << " ****" << endl;
                    cout << "**** The person's gender is " << person->gender << " ****" << endl;
                    cout << "**** The person's age is " << person->age << " ****" << endl;
                }
                break;
            case REMOVE_NODE:
                cout << "Enter the name of the person to remove: ";
                string nameToRemove;
                cin >> nameToRemove;
                removeNode(createList(), nameToRemove);
                break;
            case CLEAR_LIST:
                clearList(createList());
                break;
            case EXIT:
                cout << "**** Exiting the program ****" << endl;
                break;
        }
    } while (option != EXIT);

    return 0;
}
