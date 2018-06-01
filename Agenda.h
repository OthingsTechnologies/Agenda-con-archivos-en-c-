//
// Created by emmanuel on 24/05/18.
//

#ifndef METODOSDEORDENAMIENTO_AGENDA_H
#define METODOSDEORDENAMIENTO_AGENDA_H


#include "Contact.h"
#include "AgendaFile.h"

class Agenda {

public:

    Agenda();

    Contact* list;
    AgendaFile *agendaFile;

    void showContacts();
    void addContact( Contact* contact );
    void deleteContact( string phone_number );
    void updateContact(string phone_number, Contact* contact);
    void orderDescendent();
    void orderAscendent();
    int size();



private:

    void chargeContacts();
    bool isEmpty();


};


#endif //METODOSDEORDENAMIENTO_AGENDA_H
