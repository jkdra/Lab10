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
    string name;

    printHeader();

    do {
        cout
        << "\n"
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

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "**** Please input a NUMBER between 0 and 6 ****" << endl;
        } else if (optionInt < 0 || optionInt > 6) {
            cin.clear();
            cin.ignore();
            cout << "**** The number " << optionInt << " is an invalid entry     ****" << endl;
            cout << "**** Please input a number between 0 and 6 ****" << endl;
        } else option = static_cast<MenuOption>(optionInt);


        switch (optionInt) {
            case CREATE_LIST:
                if (!isEmpty(head)) cout << "\nList already created.\n";
                else createList(head);
                break;
            case DISPLAY_LIST:
                if (isEmpty(head)) cout << "\nCan't display an empty list\n";
                else displayList(head);
                break;
            case CHECK_EMPTY:
                if (isEmpty(head)) cout << "Yes, the list is empty." << endl;
                else cout << "No, the list is NOT empty." << endl;
                break;
            case SEARCH_BY_NAME:
                if (isEmpty(head)) cout << "Can't search an empty list" << endl;
                else searchByName(head);
                break;
            case REMOVE_NODE:
                if (!isEmpty(head)) removeNode(head);
                else cout << "\nCan't remove from an empty list!\n";
                break;
            case CLEAR_LIST:
                if (isEmpty(head)) cout << "\nThe list has been cleared!\n";
                else clearList(head);
                break;
            case EXIT:
                // Do nothing, program will exit
                break;
        }
    } while (option != EXIT);

    return 0;
}
