#include <iostream>

int main()
{
    //stack
    char nombre[] = {'j','o','h','a','n','n','a'};

    std::cout<<"Accediendo a posicion 2: "<<nombre[2];


    //acceder direccion de memoria
    std::cout<<"\n Dir de memoria "<<&nombre;


    //notacion puntero 
    std::cout<<"\n Accediendo a pos 2: "<< *(nombre + 2);



    return 0;
}