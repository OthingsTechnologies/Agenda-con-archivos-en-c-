#include <iostream>
#include "MetodosDeOrdenamiento.h"
#include "Agenda.h"

using namespace std;

int menu();
int order_menu();
void order_methods();
int agenda_menu();
void agenda();

int main() {

    bool PROGRAM_GO = true;
    do{

        int option = menu();
        switch (option){

            case 1:{
                agenda();
                break;
            }
            case 2:{
                order_methods();
                break;
            }
            case 3:{
                PROGRAM_GO = false;
                break;
            }

        }

    }while(PROGRAM_GO);


}
void order_methods(){


    bool PROGRAM_GO = true;
    MetodosDeOrdenamiento *metodosDeOrdenamiento = new MetodosDeOrdenamiento();

    do{

        int option = order_menu();

        switch (option){

            case 1:{
                int numbers;
                cout<<"Escribe la cantidad de numeros a generar para bublesort>> ";
                cin>>numbers;
                metodosDeOrdenamiento->bubleSort(numbers);

                break;
            }
            case 2:{
                int numbers;
                cout<<"Escribe la cantidad de numeros a generar para quicksort>> ";
                cin>>numbers;
                metodosDeOrdenamiento->quickSort(numbers);

                break;
            }
            case 3:{
                int numbers;
                cout<<"Escribe la cantidad de numeros a generar para insertionsort>> ";
                cin>>numbers;
                metodosDeOrdenamiento->insertion_sort(numbers);

                break;
            }
            case 4:{
                int numbers;
                cout<<"Escribe la cantidad de numeros a generar para shell>> ";
                cin>>numbers;
                metodosDeOrdenamiento->shell(numbers);

                break;
            }
            case 5:{
                metodosDeOrdenamiento->busquedaBinaria();
                break;
            }


            case 6:{
                PROGRAM_GO = false;
                break;
            }

        }
    }while(PROGRAM_GO);


}
int menu(){

    int option;
    cout<<"Menu"<<endl
        <<"[1] Agenda"<<endl
        <<"[2] Metodos de ordenamiento"<<endl
        <<"[3] Salir"<<endl;

    cin>>option;

    return option;

}
int order_menu(){

    int option;
    cout<<"Metodos de ordenamiento:"<<endl
            <<"[1] ordenamiento BubleSort"<<endl
            <<"[2] ordenamiento QuickSort"<<endl
            <<"[3] ordenamiento InserctionSort"<<endl
            <<"[4] ordenamiento Shell"<<endl
            <<"[5] busqueda binaria"<<endl
            <<"[6] salir del programa"<<endl
            <<">> ";

    cin>>option;

    return option;

}
void agenda(){

    bool PROGRAM_GO = true;
    Agenda *agenda = new Agenda();
    do{

        int option = agenda_menu();
        switch (option){

            case 1:{

                string name;
                string phone_number;

                cout<<"Escribe el nombre del contacto >>";
                cin>>name;
                cout<<"Escribe el numero del contacto >>";
                cin>>phone_number;
                Contact * contact = new Contact(name,phone_number);
                agenda->addContact(contact);
                break;
            }
            case 2:{

                string name;
                string phone_number_s;
                string phone_number;

                cout<<"Escribe el numero de telefono a buscar para actualizar>>";
                cin>>phone_number_s;

                cout<<"Escribe el nombre del contacto >>";
                cin>>name;
                cout<<"Escribe el numero del contacto >>";
                cin>>phone_number;
                Contact * contact = new Contact(name,phone_number);
                agenda->updateContact(phone_number_s,contact);
                break;
            }
            case 3:{
                string name;
                string phone_number_s;
                string phone_number;

                cout<<"Escribe el numero de telefono a buscar para eliminar>>";
                cin>>phone_number_s;
                agenda->deleteContact(phone_number_s);
                break;
            }
            case 4:{
                agenda->showContacts();
                break;
            }
            case 5:{
                agenda->orderDescendent();
                break;
            }
            case 6:{
                agenda->orderAscendent();
                break;
            }
            case 7:{
                PROGRAM_GO =false;
                break;
            }

        }

    }while(PROGRAM_GO);

}
int agenda_menu(){

    int option;
    cout<<"Menu"<<endl
        <<"[1] Agregar persona"<<endl
        <<"[2] Editar persona"<<endl
        <<"[3] Eliminar persona"<<endl
        <<"[4] Ver contactos"<<endl
        <<"[5] Ordenar descendentemente"<<endl
        <<"[6] Ordenar ascendentemente"<<endl
        <<"[7] Salir"<<endl;

    cin>>option;

    return option;

}