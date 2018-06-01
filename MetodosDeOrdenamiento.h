//
// Created by emmanuel on 17/05/18.
//

#ifndef METODOSDEORDENAMIENTO_METODOSDEORDENAMIENTO_H
#define METODOSDEORDENAMIENTO_METODOSDEORDENAMIENTO_H


class MetodosDeOrdenamiento {

public:

     void bubleSort( int n );
     void quickSort( int n );
     void insertion_sort( int n );
     void shell( int n );
     void busquedaBinaria();

private:
    void qs( int array[] , int start , int end );
    int qs_divide( int array[] , int start , int end );
    void in_sort( int t[] , int size);
    void sh_order( int A [] , int n );
    int bus_bin( int arreglo[] , int tamano , int clave);
};


#endif //METODOSDEORDENAMIENTO_METODOSDEORDENAMIENTO_H
