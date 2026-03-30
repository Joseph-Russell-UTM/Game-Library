/**
 * @file game.h
 * @author Joseph Russell, Zachery Pickell
 * @date 2026-03-19
 * @brief Creates prototypes of game functions
 * 
 * Creates the prototypes used in the code used in game.cpp.
 */

#ifndef GAME_H
#define GAME_H

#include <string>
#include <list>
using namespace std;

struct Game {
    string title;
    string publisher;
    string genre;
    float hours;
    float price;
    int year;
};

class Library {
private:
    list<Game> games;

public:
    //Adds a new game and sorts the list
    void insert_sorted(const Game& newGame);

    //Reads a file to a list
    void read_from_file(string filename);

    //Writes the list into a file
    void write_to_file(string filename);

    //Prints the list
    void print_all() const;

    //Finds all games based on the genre
    void find_genre(string genre) const;

    //Gives information on a game based off the name given bu the user,.
    void find_game(string keyword) const;

    //Removes a game from the list.
    void remove_game(string title, int year);
};

#endif