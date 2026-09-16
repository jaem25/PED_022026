#include <iostream>

int main(void)
{
    int *p = new int; //o = nullptr

    if (p == nullptr)
    {
        std::cout<<"Error de asignacion de dir. de memoria";  //imprime esto al ejecutar
        exit(1);
    }
    
    else{
        std::cout<<"Direccion de memoria asignada " << p ;
    }

// Liberando memoria 
    delete p; 

    p = nullptr;

    if (p != nullptr)
    {
        std::cout<<"Direccion de memoria vacia";
    }

    return 0;
    }