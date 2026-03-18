/**
 * @file game.cpp
 * @author Joseph Russell
 * @date 2026-03-19
 * @brief The implementation of game.h
 * 
 * Defines the functions made in game.h.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <list>
#include "game.h"


using namespace std;

 
List::List() {
    head = NULL;
}

void List::push_front(string fname, string lname, string phone) {
    Node *insert = new Node;
    insert -> next = NULL;
    insert -> fname = fname;
    insert -> lname = lname;
    insert -> phoneNum = phone;

    insert -> next = head;
    head = insert;
   
}

void List::push_back(string fname, string lname, string phone) {
    Node *newGuy = new Node;
    newGuy -> next = NULL;
    newGuy -> fname = fname;
    newGuy -> lname = lname;
    newGuy -> phoneNum = phone;
    newGuy -> name = fname + " " + lname;

    //Case 1 list is empty
    if (head == NULL) {
        head = newGuy;
        return;
    }
    //Case 2 list is !empty
    else {
        Node *tail = head;
        while (tail -> next != NULL) {
            tail = tail -> next;
        }
        tail -> next = newGuy;
    }
}

void List::print(){
    Node *printGuy;
    printGuy = head;

    while (printGuy != NULL) { //print until the end of the list
        cout << printGuy -> fname << " " << printGuy -> lname << " (" << printGuy -> phoneNum << "), ";
        printGuy = printGuy -> next;
    }
    cout << endl;
}



void List::delete_user(string fname, string lname) {
    Node *temp, *eraser;
    
    //Case 1: empty list
    if (head == NULL) {
        return; //nothing to do
    }
    //Case 2: value is at head of the list
    else if (head -> fname == fname && head -> lname == lname) {
        eraser = head;
        head = head -> next;
        delete eraser;
    }
    //Case 3: need to search and destroy
    else {
        temp = head;

        while (temp -> next != NULL && temp -> next -> fname != fname && temp -> next -> lname != lname) {
            temp = temp -> next;
        }

        //if no such value
        if (temp -> next == NULL) {
            return; //nothing to do
        }
        eraser = temp -> next;
        temp -> next = eraser -> next;
        delete eraser;
    }

}

List::~List() {
    cout << "Destroying the list" << endl;
    
    //Not efficent
    while (head != NULL) {
        cout << "Removing list member: " << head -> fname << endl;
        delete_user(head -> fname, head -> lname);
    }
}

void List::read_from_file(string filename) {
    ifstream inFile;
    string fullName;
    string phoneNum;
    string fname, lname;

    inFile.open(filename);

    if (!inFile) {
        cout << "Unable to open file: " << filename << endl;
        exit(1);
    }
    
    // Read pairs: full name line, then phone line
    while (getline(inFile, fullName)) {
        if (getline(inFile, phoneNum)) {
            // Separates full name into first and last name
            size_t spacePos = fullName.find(' ');
            if (spacePos != string::npos) {
                fname = fullName.substr(0, spacePos);
                lname = fullName.substr(spacePos + 1);
                
            } else {
                fname = fullName;
                lname = "";
            }
            
            insert_sorted(fname, lname, phoneNum, hours, price, name);
        }
    }

    inFile.close();
}

void List::write_to_file(string filename) {

    string phoneNum;
    string fname, lname;

    ofstream outFile;
    outFile.open(filename);

    if (!outFile) {
        cout << "Unable to open file: " << filename << endl;
        exit(1);
    }
    Node *current = head;
    while (current != NULL) {
        outFile << current -> fname << " " << current -> lname << endl;
        outFile << current -> phoneNum << endl;
        current = current -> next;
    }

    outFile.close();
}

// sorted insertion by last name then first name; phone provided by user
void List::insert_sorted(string fname, string lname, string phone, 
                         float hours, float price, float year) {
    Node *newGuy = new Node;
    newGuy->next = NULL;
    newGuy->fname = fname;
    newGuy->lname = lname;
    newGuy->phoneNum = phone;
    newGuy->name = fname + " " + lname;

    // empty list or new node sorts before head
    if (head == NULL || lname < head->lname || 
        (lname == head->lname && fname < head->fname)) {
        newGuy->next = head;
        head = newGuy;
        return;
    }

    Node *cur = head;
    while (cur->next != NULL &&
           (cur->next->lname < lname ||
            (cur->next->lname == lname && cur->next->fname < fname))) {
        cur = cur->next;
    }

    newGuy->next = cur->next;
    cur->next = newGuy;
}

void List::find_genre(string genre) {
   Node *cur = head;
   while (cur != NULL) {
       if (cur->fname == fname && cur->lname == lname) {
           cout << "The phone number for " << fname << " " << lname << " is: " << cur->phoneNum << endl;
           return;
       }
       cur = cur->next;
   }
   cout << "Contact not found: " << fname << " " << lname << endl;

}

void List::find_game(string name) {
    Node *cur = head;
    while (cur != NULL) {
        if (cur->phoneNum == phone) {
            cout << "The contact with the phone number " << phone << ": " << cur->fname << " " << cur->lname << endl;
            return;
        }
        cur = cur->next;
    }
    cout << "Contact not found with that phone number: " << phone << endl;
}