//
// Created by emmanuel on 24/05/18.
//

#ifndef METODOSDEORDENAMIENTO_AGENDAFILE_H
#define METODOSDEORDENAMIENTO_AGENDAFILE_H

#include <iostream>
#include "Contact.h"

using namespace std;
class AgendaFile {

public:

    AgendaFile();
    Contact *list;

    void readFile();
    void addContact( Contact* contact );
    Contact * searchSpace( Contact* contact );
    Contact *getContacts();
    void saveInformation( Contact* list );
private:

   bool isEmpty();

};


#endif //METODOSDEORDENAMIENTO_AGENDAFILE_H
