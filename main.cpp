/**
 * @file main.cpp
 * @author Joseph Russell
 * @date 2026-03-19
 * @brief Menu-driven program for managing a game library
 */

#include <iostream>
#include <string>
#include "game.h"

using namespace std;

int main() {

    int choice = 0; // menu choice
    string filename; // for file input

    Library gameLibrary;

    while (choice != 8) {
        cout << "\n=== Game Library Menu ===" << endl;
        cout << "1. Read a game library from a file" << endl;
        cout << "2. Write the game library to a file" << endl;
        cout << "3. Print the game library" << endl;
        cout << "4. Search for games by genre" << endl;
        cout << "5. Search for a game by title" << endl;
        cout << "6. Add a game" << endl;
        cout << "7. Delete a game" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline

        if (choice == 1) {
            cout << "Enter filename: ";
            getline(cin, filename);
            gameLibrary.read_from_file(filename);
        }

        else if (choice == 2) {
            cout << "Enter filename: ";
            getline(cin, filename);
            gameLibrary.write_to_file(filename);
        }

        else if (choice == 3) {
            gameLibrary.print_all();
        }

        else if (choice == 4) {
            string genre;
            cout << "Enter genre: ";
            getline(cin, genre);
            gameLibrary.find_genre(genre);
        }

        else if (choice == 5) {
            string keyword;
            cout << "Enter part of the game title: ";
            getline(cin, keyword);
            gameLibrary.find_game(keyword);
        }

        else if (choice == 6) {
            Game g;

            cout << "Enter title: ";
            getline(cin, g.title);

            cout << "Enter publisher: ";
            getline(cin, g.publisher);

            cout << "Enter genre: ";
            getline(cin, g.genre);

            cout << "Enter hours played: ";
            cin >> g.hours;

            cout << "Enter price: ";
            cin >> g.price;

            cout << "Enter release year: ";
            cin >> g.year;
            cin.ignore(); // clear newline

            gameLibrary.insert_sorted(g);
        }

        else if (choice == 7) {
            string title;
            int year;

            cout << "Enter title of game to delete: ";
            getline(cin, title);

            cout << "Enter release year: ";
            cin >> year;
            cin.ignore();

            gameLibrary.remove_game(title, year);
        }

        else if (choice == 8) {
            cout << "Exiting program..." << endl;
        }

        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}