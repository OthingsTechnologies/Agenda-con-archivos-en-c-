//
// Created by emmanuel on 24/05/18.
//

#include "Contact.h"

Contact::Contact() {

    this->nextContact = NULL;
    this->previousContact = NULL;

}

Contact::Contact(string name, string phone_number) {

    this->name = name;
    this->phone_number = phone_number;

}

int Contact::getId() {
    return this->id;
}

string Contact::getName() {

    return this->name;

}

void Contact::setName(string name) {
    this->name = name;
}

void Contact::setPhoneNumber(string phone_number) {
    this->phone_number = phone_number;
}

string Contact::getPhoneNumber() {

    return this->phone_number;

}