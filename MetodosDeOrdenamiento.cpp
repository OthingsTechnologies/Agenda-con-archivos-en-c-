//
// Created by emmanuel on 17/05/18.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "MetodosDeOrdenamiento.h"
using namespace std;
void MetodosDeOrdenamiento::bubleSort(int n) {

    int numbers [n];
    srand(time(NULL));


    cout<<endl<<endl<<"[NUMEROS NO ORDENADOS]"<<endl<<endl;
    for(int i = 0 ; i < n ; i ++){
        numbers[i] = 1+rand()%(101-1);

        cout<<numbers[i]<<"\t";
        if((i+1) % 10 == 0 ){
            cout<<endl;
        }
    }

    cout<<endl;

    cout<<"[NUMEROS ORDENADOS]"<<endl<<endl;

    for( int i = 0 ; i < n ; i ++){

        for( int j = 0 ; j < n ; j ++){

            if(numbers[j] < numbers[i]){

                int temp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = numbers[j];
                numbers[i] = temp;

            }

        }
    }

    for(int i = 0 ; i < n ; i ++){

        cout<<numbers[i]<<"\t";
        if((i+1) % 10 == 0 ){
            cout<<endl;
        }
    }



}

void MetodosDeOrdenamiento::quickSort(int n) {

    int numbers [n];
    srand(time(NULL));


    cout<<endl<<endl<<"[NUMEROS NO ORDENADOS]"<<endl<<endl;
    for(int i = 0 ; i < n ; i ++){
        numbers[i] = 1+rand()%(101-1);

        cout<<numbers[i]<<"\t";
        if((i+1) % 10 == 0 ){
            cout<<endl;
        }
    }


    this->qs(numbers,0,n-1);

    cout<<endl;

    cout<<"[NUMEROS ORDENADOS]"<<endl<<endl;

    for(int i = 0 ; i < n ; i ++){

        cout<<numbers[i]<<"\t";
        if((i+1) % 10 == 0 ){
            cout<<endl;
        }
    }


}
void MetodosDeOrdenamiento::qs(int *array, int start, int end) {

    int pivot;

    if (start < end) {
        pivot = this->qs_divide(array, start, end);

        // Ordeno la lista de los menores
        qs(array, start, pivot - 1);

        // Ordeno la lista de los mayores
        qs(array, pivot + 1, end);
    }


}

int MetodosDeOrdenamiento::qs_divide(int *array, int start, int end) {

    int left;
    int right;
    int pivot;
    int temp;

    pivot = array[start];
    left = start;
    right = end;

    // Mientras no se cruzen los índices
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }

        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }

        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }

    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;

    // La nueva posición del pivot
    return right;

}
void MetodosDeOrdenamiento::insertion_sort(int n) {

    int numbers [n];
    srand(time(NULL));


    cout<<endl<<endl<<"[NUMEROS NO ORDENADOS]"<<endl<<endl;
    for(int i = 0 ; i < n ; i ++){
        numbers[i] = 1+rand()%(101-1);

        cout<<numbers[i]<<"\t";
        if((i+1) % 10 == 0 ){
            cout<<endl;
        }
    }
    cout<<endl;

    cout<<"[NUMEROS ORDENADOS]"<<endl<<endl;
    this->in_sort(numbers,n);
 for(int i = 0 ; i < n ; i ++){

        cout<<numbers[i]<<"\t";
        if((i+1) % 10 == 0 ){
            cout<<endl;
        }
    }


}
void MetodosDeOrdenamiento::in_sort(int *numbers , int array_size) {

    int i, a, index;
    for (i=1; i < array_size; i++) {
        index = numbers[i];
        a = i-1;
        while (a >= 0 && numbers[a] > index) {
            numbers[a + 1] = numbers[a];
            a--;
        }
        numbers[a+1] = index;
    }

}
void MetodosDeOrdenamiento::shell(int n) {

    int numbers [n];
    srand(time(NULL));


    cout<<endl<<endl<<"[NUMEROS NO ORDENADOS]"<<endl<<endl;
    for(int i = 0 ; i < n ; i ++){
        numbers[i] = 1+rand()%(101-1);

        cout<<numbers[i]<<"\t";
        if((i+1) % 10 == 0 ){
            cout<<endl;
        }
    }
    cout<<endl;

    cout<<"[NUMEROS ORDENADOS]"<<endl<<endl;
    this->sh_order(numbers,n);

    for(int i = 0 ; i < n ; i ++){

        cout<<numbers[i]<<"\t";
        if((i+1) % 10 == 0 ){
            cout<<endl;
        }
    }



}

void MetodosDeOrdenamiento::sh_order(int *A, int n) {

    int i, j, inc, temp;

    for(inc = 1 ; inc<n;inc=inc*3+1);

    while (inc > 0)
    {
        for (i=inc; i < n; i++)
        {
            j = i;
            temp = A[i];
            while ((j >= inc) && (A[j-inc] > temp))
            {
                A[j] = A[j - inc];
                j = j - inc;
            }

            A[j] = temp;
        }

        inc/= 2;
    }


}

void MetodosDeOrdenamiento::busquedaBinaria() {

    int n;
    cout<<"¿Cuantos numeros desea generar? "<<endl<<">> ";
    cin>>n;
    int numbers [n];
    srand(time(NULL));


    cout<<endl<<endl<<"[NUMEROS GENERADOS]"<<endl<<endl;
    for(int i = 0 ; i < n ; i ++){
        numbers[i] = 1+rand()%(101-1);

        cout<<numbers[i]<<"\t";
        if((i+1) % 10 == 0 ){
            cout<<endl;
        }
    }
    cout<<endl;
    this->qs(numbers,0,n);
    cout<<"[NUMEROS ORDENADOS]"<<endl<<endl;

    for(int i = 0 ; i < n ; i ++){

        cout<<numbers[i]<<"\t";
        if((i+1) % 10 == 0 ){
            cout<<endl;
        }
    }
    cout<<endl<<endl;

    int b_n;
    cout<<"¿Que numero desea buscar? >>";
    cin>>b_n;
    cout<<endl<<endl<<"EL INDICE DEL NUMERO BUSCADO ES: "<<this->bus_bin(numbers,n,b_n)<<endl<<endl;



}

int MetodosDeOrdenamiento::bus_bin(int *arreglo, int tamano, int clave) {

    int Iarriba = tamano-1;
    int Iabajo = 0;
    int Icentro;
    while (Iabajo <= Iarriba)
    {
        Icentro = (Iarriba + Iabajo)/2;
        if (arreglo[Icentro] == clave)
            return Icentro;
        else
        if (clave < arreglo[Icentro])
            Iarriba=Icentro-1;
        else
            Iabajo=Icentro+1;
    }
    return -1;

}