//
// Created by emmanuel on 24/05/18.
//

#include <iomanip>
#include "Agenda.h"

Agenda::Agenda() {

    agendaFile = new AgendaFile();
    this->chargeContacts();
    list = agendaFile->getContacts();
}
void Agenda::showContacts() {

    Contact *show = list;
    string header1 = "| NOMBRE        |";

    cout<<"+---------------+--------------+"<<endl;
    cout<<right<<setw(15)<<header1;
    cout<<right<<setw(15)<<"NUMERO       |"<<endl;
    cout<<"+---------------+--------------+"<<endl;
    while( show != NULL ){

        cout<<"|";
        cout<<right<<setw(15)<<show->getName();
        cout<<"|";
        cout<<right<<setw(14)<<show->getPhoneNumber();
        cout<<"|"<<endl;
        cout<<"+---------------+--------------+"<<endl;
        show = show->nextContact;
    }

}
void Agenda::addContact(Contact *contact) {

    if( isEmpty() ){

        list = contact;

    }
    else{

        contact->nextContact = list;
        list->previousContact = contact;
        list = contact;

    }
    agendaFile->saveInformation(list);

}
void Agenda::chargeContacts() {

    agendaFile->readFile();

}
void Agenda::updateContact(string phone_number, Contact *contact) {

    Contact* update = list;
    bool updated =false;

    while(update != NULL){

        if(update->getPhoneNumber() == phone_number){
            updated =true;
            update->setName(contact->getName());
            update->setPhoneNumber(contact->getPhoneNumber());

            break;
        }

        update = update->nextContact;

    }

    if(updated){
        agendaFile->saveInformation(list);
        cout<<endl<<"Se actualizo el contacto con exito <<>>"<<endl;
    }
    else{
        cout<<endl<<"No se encontro el contacto con el numero telefonico especificado <<>>"<<endl;
    }

}
void Agenda::deleteContact(string phone_number) {

    Contact* del = list;
    bool deleted =false;

    while(del != NULL){

        if(del->getPhoneNumber() == phone_number){
            deleted =true;

            if( del->previousContact == NULL ){

                if( del->nextContact != NULL ){

                    list = del->nextContact;
                    delete del;

                }
                else{
                    delete del;
                    list = NULL;
                }

            }
            else if( del->previousContact != NULL && del->nextContact != NULL){

                del->previousContact->nextContact = del->nextContact;
                del->nextContact->previousContact = del->previousContact;
                delete del;

            }
            else if( del->previousContact != NULL && del->nextContact == NULL){

                del->previousContact->nextContact = NULL;
                delete del;

            }


            break;
        }

        del = del->nextContact;

    }

    if(deleted){
        agendaFile->saveInformation(list);
        cout<<endl<<"Se elimino el contacto con exito <<>>"<<endl;
    }
    else{
        cout<<endl<<"No se encontro el contacto con el numero telefonico especificado <<>>"<<endl;
    }


}
bool Agenda::isEmpty() {

    return (list == NULL);

}
void Agenda::orderAscendent() {

    int TAM = size();

    for(int i = 0 ; i < TAM ; i++){

        Contact *contact_b = list;
        for(int j=0; j<TAM-i; j++){


            if( contact_b->nextContact != NULL ){

                if( contact_b->getName()[0] > contact_b->nextContact->getName()[0] ){


                    string tmp_name = "";
                    string tmp_phone = "";
                    tmp_name = contact_b->getName();
                    tmp_phone = contact_b->getPhoneNumber();
                    contact_b->setName(contact_b->nextContact->getName());
                    contact_b->setPhoneNumber(contact_b->nextContact->getPhoneNumber());
                    contact_b->nextContact->setName(tmp_name);
                    contact_b->nextContact->setPhoneNumber(tmp_phone);

                }

            }

            contact_b = contact_b->nextContact;
        }

    }





}
void Agenda::orderDescendent() {

    int TAM = size();

    for(int i = 0 ; i < TAM ; i++){

        Contact *contact_b = list;
        for(int j=0; j<TAM-i; j++){


            if( contact_b->nextContact != NULL ){

                if( contact_b->getName()[0] < contact_b->nextContact->getName()[0] ){


                    string tmp_name = "";
                    string tmp_phone = "";
                    tmp_name = contact_b->getName();
                    tmp_phone = contact_b->getPhoneNumber();
                    contact_b->setName(contact_b->nextContact->getName());
                    contact_b->setPhoneNumber(contact_b->nextContact->getPhoneNumber());
                    contact_b->nextContact->setName(tmp_name);
                    contact_b->nextContact->setPhoneNumber(tmp_phone);

                }

            }

            contact_b = contact_b->nextContact;
        }

    }


}



int Agenda::size() {

    Contact* n = list;
    int i = 0;
    while (n != NULL){
        n = n->nextContact;
        i++;
    }
    return i;
}