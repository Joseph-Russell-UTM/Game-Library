/**
 * @file main.cpp
 * @author Joseph Russell
 * @date 2026-03-19
 * @brief Uses the functions created in game.cpp to create a Game library
 * 
 * main.cpp tests game.cpp by creating a menu for the user to interact with the game library.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <list>
#include "game.h"

using namespace std;


int main (){
     
    int choice = 0; //user's menu choice
    string gl; //phonebook file name
    string outFile; //output file name

    string name; //First Name
    string publish; //Last Name
    string genre; //Phone Number
    float hours;
    float price;
    float year;


    List gameLibrary;

    while (choice != 8){
        cout << "Welcome to the Game Library!  You may select one of the following options: " << endl;
        cout << "1 Read a game library from a file" << endl;
        cout << "2 Write the game lirary to a file" << endl;
        cout << "3 Print the game library" << endl;
        cout << "4 Search for a game by genre" << endl;
        cout << "5 Search for a game's name" << endl;
        cout << "6 Add a game" << endl;
        cout << "7 Delete a game" << endl;
        cout << "8 Exit this program" << endl;
        cout << "Please enter your choice now: "; 
        cin >> choice;

        if (choice == 1) {
            cout << "Enter a file name: ";
            cin >> gl;
            gameLibrary.read_from_file(gl);
        }
        if (choice == 2) {
            cout << "Enter the name of the file you want to write to: ";
            cin >> outFile;
            gameLibrary.write_to_file(outFile);
        }
        if (choice == 3) {
            gameLibrary.print();
        }
        if (choice == 4) {
            cout << "Enter the name of the genre you want to look up: ";
            cin >> genre;
            gameLibrary.find_genre(genre);
        }
        if (choice == 5) {
            cout << "Enter the name of the game you want to look up: ";
            getline(cin, name); // to allow for spaces in phone number
            getline(cin, name); // to consume the leftover newline from previous input
            gameLibrary.find_game(name);
        }
        if (choice == 6) {
            // prompt for new contact info and insert in sorted order
            cout << "Enter first name: ";
            getline(cin, name);
            getline(cin, name);
            cout << "Enter the publisher: ";
            getline(cin, publish);
            cout << "Enter the genre: ";
            cin >> genre; // to allow for spaces in phone number

            cout << "Enter the amount of hours played: ";
            cin >> hours;
            cout << "Enter the price: ";
            cin >> price;
            cout << "Enter the release year: ";
            cin >> year; // to allow for spaces in phone number

            gameLibrary.insert_sorted(name, publish, genre, hours, price, year);
        }
        if (choice == 7) {
            cout << "Enter the name of the game you want to delete: ";
            getline(cin, name);
            getline(cin, name);
            gameLibrary.delete_user(name);
        }


    }
}