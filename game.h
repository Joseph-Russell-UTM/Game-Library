/**
 * @file game.h
 * @author Joseph Russell
 * @date 2026-03-19
 * @brief Creates prototypes of game functions
 * 
 * Creates the prototypes used in the code used in game.cpp.
 */

#ifndef LIST_H
#define LIST_H

#include <string>

struct Node{
    Node *next;

    std::string name;
    std::string fname;
    std::string lname;
    std::string phoneNum;
 };

class List {
    private:
        Node *head;
    public:
        //constructor
        List();

        //destructor
        ~List();

        //Pushes new node to the front of the list
        void push_front(std::string fname, std::string lname, std::string phone);
        
        //Pushes new node to the back of the list
        void push_back(std::string fname, std::string lname, std::string phone);

        //Prints the list
        void print();

        //Removes the user with the given name from the list
        void delete_user(std::string name);
        
        // Reads contacts from a file and adds them to the list
        void read_from_file(std::string filename);

        // Writes the contacts in the list to a file
        void write_to_file(std::string filename);

        // insert a new contact in alphabetical order by last name
        void insert_sorted(std::string name, std::string publish, std::string genre,
                            float hours, float price, float year);

        // looks up a contact by name and prints their phone number
        void find_genre(std::string genre);

        // looks up a contact by phone number and prints their name
        void find_game(std::string name);


};

#endif