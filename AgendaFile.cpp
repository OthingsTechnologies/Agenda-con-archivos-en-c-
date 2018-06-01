//
// Created by emmanuel on 24/05/18.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "AgendaFile.h"

using namespace std;



AgendaFile::AgendaFile() {

    this->list = NULL;

}
void AgendaFile::readFile() {

    char path[] ="/home/emmanuel/CLionProjects/MetodosDeOrdenamiento/agenda.csv";
    FILE * file = fopen(path,"r");
    rewind(file);

    if( file != NULL){

        cout<<"Cargando archivo << agenda.csv >>"<<endl;

        char buffer [1024];
        int x = 0;
        while( fscanf(file," %[^\n]",buffer) != EOF ){

            char *data = strtok(buffer, ",");
            int i = 0;
            string nombre;
            string numero;
            while (data != NULL)
            {
                switch (i){

                    case 0:{
                        nombre = data;
                        break;
                    }
                    case 1:{
                        numero = data;
                        break;
                    }

                }
                data = strtok (NULL, ",");
                i++;
            }

                addContact(new Contact(nombre,numero));
        x++;
        }

        cout<<x<<" contactos cargados <<>> "<<endl;
        fclose(file);

    }
    else{

        FILE *file = fopen(path,"w");
        if(file == NULL){
            cout<<"No se pudo crear el archivo de bases de datos"<<endl<<endl;
        }
        else{
            cout<<"Se creo el archivo de bases de datos correctamente"<<endl<<endl;
        }

        fclose(file);
    }

}
void AgendaFile::addContact(Contact *contact) {

    if( isEmpty() ){

        list = contact;

    }
    else{

        contact->nextContact = list;
        list->previousContact = contact;
        list = contact;

    }

}
bool AgendaFile::isEmpty() {

    return (list == NULL);

}
Contact* AgendaFile::getContacts() {
    return list;
}
void AgendaFile::saveInformation(Contact *list) {

    char path[] ="/home/emmanuel/CLionProjects/MetodosDeOrdenamiento/agenda.csv";
    FILE *file = fopen(path,"w");

    Contact* save = list;
    while (save != NULL){

        string data = save->getName()+","+save->getPhoneNumber()+"\n";
        fprintf(file,data.c_str());
        save = save->nextContact;

    }

    fclose(file);
    cout<<endl<<"Se han guardado los cambios con exito <<>>"<<endl;

}
