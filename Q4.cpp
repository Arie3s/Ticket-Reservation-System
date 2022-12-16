/*
Write a simple airline ticket reservation program.
The program should display a menu with the following options:
1.reserve a ticket
2.cancel a reservation
3.check whether a ticket is reserved for a particular person
4.display the passengers.
The information is maintained on an alphabetized linked list of names.
In a simpler version of the program,assume that tickets are reserved for only one flight.
In a fuller version,
place no limit on the number of flights.
Create a linked list of flights with each node including a pointer to a linked list of passengers
 */

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node *nextNode;

    Node(string d) {
        data = d;
        nextNode = nullptr;
    }
};


class list {
private:
    Node *Head;
    Node *temp;
    Node *Tail;
    int index = 0, size = 1;
public:

    list() {
        Head = nullptr;
        Tail = Head;
    }

    void getTail() {
        temp = Head;
        while ( temp->nextNode != nullptr ) {
            temp = temp->nextNode;
        }
        Tail = temp;
    }

    void addFirst(string d) {
        Node *temp = new Node(d);
        temp->nextNode = Head;
        Head = temp;
        getTail();
    }

    void addLast(string d) {
        getTail();
        temp = new Node(d);
        Tail->nextNode = temp;
        Tail = temp;
    }

    void deleteFirst() {
        temp = Head;
        Head = Head->nextNode;
        delete temp;
        temp = nullptr;
        getTail();
    }

    void deleteLast() {
        getTail();
        temp = Head;
        while ( temp->nextNode->nextNode != nullptr ) {
            temp = temp->nextNode;
        }
        temp->nextNode = nullptr;
        Tail = temp;
    }

    //gets the size of the list
    void getsize() {
        temp = Head;
        while ( temp->nextNode != nullptr ) {
            temp = temp->nextNode;
            size++;
        }
    }

    //delete by data
    void DeleteVal(string val) {
        temp = Head;
        Node *temp1;
        bool deleted = false;
        if ( Head->data == val ) {
            deleteFirst();
            return;
        } else {
            while ( temp->nextNode->data != val ) {
                temp = temp->nextNode;
            }
            if ( val == temp->nextNode->data ) {
                temp1 = temp->nextNode;
                temp->nextNode = temp1->nextNode;
                delete temp1;
                temp1 = nullptr;
                return;
            }
        }
        if ( !deleted ) {
            cout << "no reservation found";
        }
    }

    bool search(string d) {
        temp = Head;
        while ( temp != nullptr ) {
            if ( temp->data == d ) {
                return true;
            }
            temp = temp->nextNode;
        }
        return false;
    }

    Node *getIndex(int pos) {
        Node *temp = Head;
        while ( temp->nextNode != nullptr && pos != 0 ) {
            temp = temp->nextNode;
            pos--;
        }
        return temp;
    }

    void sort() {
        Node *i, *j;
        for ( i = Head; i->nextNode != NULL; i = i->nextNode ) {
            for ( j = i->nextNode; j != NULL; j = j->nextNode )
                if ( i->data > j->data ) {
                    string temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
        }
    }

    void view() {
        temp = Head;
        index = 1;
        sort();
        cout << "Passenger List" << endl;
        while ( temp != nullptr ) {
            cout << index << "." << temp->data << endl;
            temp = temp->nextNode;
            index++;
        }
    }

};

class Flight {
    string Destination;
    string origin;
    list passengers;
public:
    Flight() {
        Destination = "";
        origin = "";
    }

    Flight(string O, string D) {
        Destination = D;
        origin = O;
    }

    Flight(string O, string D, list names) {
        Destination = D;
        origin = O;
        passengers = names;
    }

    void Reserve(string name) {
        passengers.addFirst(name);
        cout << "Seat Reserved for " << name << endl;
    }

    void cancelReservation(string name) {
        passengers.DeleteVal(name);
    }

    void Search(string name) {
        if ( passengers.search(name)) {
            cout << "Flight Reservation found" << endl;
            return;
        }
        cout << "No Reservation found";
    }

    void viewPassengers() {
        passengers.view();
    }
};


namespace flightData {
    Flight boeing777("Karachi", "London");
}

int menuMain() {
    int select;
    cout << "1.Reserve Seat" << endl << "2.Cancel Reservation" << endl << "3.Check Reservation" << endl
         << "4.Display Passenger List";
    cout << endl << "selection :";
    cin >> select;
    return select;
}

int MainProgram() {
    string name;
    int select = menuMain();
    system("cls");
    switch ( select ) {
        case 0:
            return 0;
        case 1:
            cout << "Enter your  name: ";
            cin >> name;
            flightData::boeing777.Reserve(name);
            break;
        case 2:
            cout << "Enter your  name: ";
            cin >> name;
            flightData::boeing777.cancelReservation(name);
            break;
        case 3:
            cout << "Enter your  name: ";
            cin >> name;
            flightData::boeing777.Search(name);
            break;
        case 4:
            flightData::boeing777.viewPassengers();
            break;
        default:
            cout << "Invalid Input";
            break;
    }
}

int main() {
    while ( MainProgram() != 0 ) {
    }
    return 0;
}
