#include <iostream>

//sobrecarga
//paso de valor(copia)
int IncrementarValor(int x);

//paso por referencia
int IncrementarReferencia(int &x);

//Paso por puntero
int IncrementarPuntero(int *ptr_x);

int main()
{
    int valor = 100;

    //punteros
    int *ptr = &valor;

    //modifcar valor desde puntero
    *ptr = 200;

    
    std::cout<<"Detalle de valor: "<<valor<<"\n";
    std::cout<<"Detalle de valor desde el ptr: "<<*ptr<<"\n";
    std::cout<<"Detalle de valor: "<<valor<<"\n";
    std::cout<<"Dir. de memoria de valor: "<<ptr<<" - "<<&valor<<"\n";
    std::cout<<"Dir. de memoria de ptr: "<<&ptr<<"\n";

    //prueba funcion incremento
    std::cout<<"\n";
    std::cout<<"Paso por valor(copia): "<< IncrementarValor(valor)<<"\n";
    std::cout<<"Detalle de valor: "<<valor<<"\n";
    std::cout<<"Detalle de valor desde el ptr: "<<*ptr<<"\n";

    std::cout<<"Paso por referencia: "<< IncrementarReferencia(valor)<<"\n";
    std::cout<<"Detalle de valor: "<<valor<<"\n";
    std::cout<<"Detalle de valor desde el ptr: "<<*ptr<<"\n";

    std::cout<<"Paso por puntero: "<< IncrementarPuntero(&valor)<<"\n";
    std::cout<<"Paso por puntero: "<< IncrementarPuntero(ptr)<<"\n";
    std::cout<<"Detalle de valor: "<<valor<<"\n";
    std::cout<<"Detalle de valor desde el ptr: "<<*ptr<<"\n";

    std::cout<<"Paso por valor(copia): "<< IncrementarValor(valor)<<"\n";
    std::cout<<"Detalle de valor: "<<valor<<"\n";
    return 0;
}

//paso de valor(copia)
int IncrementarValor(int x)
{
    x += 10;

    return x;
}

int IncrementarReferencia(int &x)
{
    x += 10;

    return x;
}
int IncrementarPuntero(int *x)
{
    *x += 10;

    return *x;
}