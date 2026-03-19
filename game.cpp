/**
 * @file game.cpp
 * @author Joseph Russell, Zachery Pickell
 * @date 2026-03-19
 * @brief The implementation of game.h
 * 
 * Defines the functions made in game.h.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "game.h"

using namespace std;

// Insert game in sorted order by title
void Library::insert_sorted(const Game& newGame) {
    auto it = games.begin();

    while (it != games.end() && it->title < newGame.title) {
        ++it;
    }

    games.insert(it, newGame);
}

// Read games from file
void Library::read_from_file(string filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Unable to open file\n";
        return;
    }

    Game g;
    string line;

    while (getline(inFile, g.title)) {
        getline(inFile, g.publisher);

        // Read entire line with genre + numbers
        getline(inFile, line);

        // Parse it
        stringstream os(line);
        os >> g.genre >> g.hours >> g.price >> g.year;

        insert_sorted(g);
    }

    inFile.close();
}


// Write games to file
void Library::write_to_file(string filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cout << "Unable to open file\n";
        return;
    }

    for (const auto& g : games) {
        outFile << g.title << endl;
        outFile << g.publisher << endl;
        outFile << g.genre << " "
                << g.hours << " "
                << g.price << " "
                << g.year << endl;
    }

    outFile.close();
}

// Print all games
void Library::print_all() const {
    for (const auto& g : games) {
        cout << "Title: " << g.title << endl;
        cout << "Publisher: " << g.publisher << endl;
        cout << "Genre: " << g.genre << endl;
        cout << "Hours Played: " << g.hours << endl;
        cout << "Price: $" << fixed << setprecision(2) << g.price << endl;
        cout << "Year: " << g.year << endl;
        cout << "-----------------------------" << endl;
    }
}

// Find all games of a specific genre
void Library::find_genre(string genre) const {
    bool found = false;

    for (const auto& g : games) {
        if (g.genre == genre) {
            cout << g.title << " (" << g.year << ")" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No games found for genre: " << genre << endl;
    }
}

// Find games containing keyword in title
void Library::find_game(string keyword) const {
    bool found = false;

    for (const auto& g : games) {
        if (g.title.find(keyword) != string::npos) {
            cout << "Title: " << g.title << endl;
            cout << "Publisher: " << g.publisher << endl;
            cout << "Year: " << g.year << endl;
            cout << "-----------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No games found containing: " << keyword << endl;
    }
}

// Remove a game by title and year
void Library::remove_game(string title, int year) {
    for (auto it = games.begin(); it != games.end(); ++it) {
        if (it->title == title && it->year == year) {
            games.erase(it);
            cout << "Game removed successfully." << endl;
            return;
        }
    }

    cout << "Game not found." << endl;
}