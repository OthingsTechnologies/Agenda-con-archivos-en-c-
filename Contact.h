//
// Created by emmanuel on 24/05/18.
//

#ifndef METODOSDEORDENAMIENTO_CONTACT_H
#define METODOSDEORDENAMIENTO_CONTACT_H

#include <iostream>
using namespace std;

class Contact {

public:

    Contact();
    Contact(string name , string phone_number);

    Contact *nextContact;
    Contact *previousContact;

    string getName();
    string getPhoneNumber();
    void setName(string name);
    void setPhoneNumber(string phone_number);
    int getId();
private:
    int id;
    string name;
    string phone_number;
};


#endif //METODOSDEORDENAMIENTO_CONTACT_H
