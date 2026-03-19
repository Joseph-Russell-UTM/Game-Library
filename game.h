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
    //Adds a new game
    void insert_sorted(const Game& newGame);
    void read_from_file(string filename);
    void write_to_file(string filename);
    void print_all() const;
    void find_genre(string genre) const;
    void find_game(string keyword) const;
    void remove_game(string title, int year);
};

#endif