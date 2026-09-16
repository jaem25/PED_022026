#include <iostream>
#include <string>

//variable global para el promedio general
float promedio_general = 0.0;

struct Consumo
{
    std::string nombre_mes;
    //kilovatios consumidos
    float kWh;
};

//funciones
void SolicitarDatos(Consumo *ptr);
void MostrarInformacion(Consumo *ptr);
float CalcularPromedio(Consumo *ptr, int cant_meses);



int main()
{
    //solicitar cantidad de meses
    int cant_meses;

    std::cout<<"Ingresar la cantidad de meses a registrar: "<<std::endl;
    std::cin>>cant_meses;

    //reserva de memoria para el arreglo
    Consumo *ptr_consumo = new Consumo[cant_meses];

    for (int i = 0; i < cant_meses; i++)
    {
        SolicitarDatos(ptr_consumo + i);
    }
    
    for (int i = 0; i < cant_meses; i++)
    {
        MostrarInformacion(ptr_consumo + i);
    }

    promedio_general = CalcularPromedio(ptr_consumo, cant_meses);
    std::cout << "Promedio general de consumo (kWh): " << promedio_general << std::endl;

    //liberacion de memoria
    delete ptr_consumo;

    //inicializar a nulo el puntero
    ptr_consumo = nullptr;

    return 0;
}

void SolicitarDatos(Consumo *ptr)
{
    std::cout<<"Ingresar el nombre del mes: "<<std::endl;
    std::cin>>ptr->nombre_mes;
    std::cout<<"Ingresar le cant. de kWh consumidos: "<<std::endl;
    std::cin>>ptr->kWh;
    std::cout<<"\n";

}
void MostrarInformacion(Consumo *ptr)
{
    std::cout<<"Nombre del mes: "<<ptr->nombre_mes<<std::endl;
    std::cout<<"Dir. mes: "<<&ptr->nombre_mes<<std::endl;
    std::cout<<"Consumo electrico almacenado (kWh): "<<ptr->kWh<<std::endl;
    std::cout<<"Dir. kWh: "<<&ptr->kWh<<std::endl;

    //direccion de cada posicion del puntero
    std::cout<<"Direccion de memoria: "<<ptr<<std::endl<<std::endl;


    
}
//funcion de tarea juju
float CalcularPromedio(Consumo *ptr, int cant_meses)
{
    float suma = 0.0;

    for (int i = 0; i < cant_meses; i++)
    {
        suma += (ptr + i)->kWh;
    }

    return suma / cant_meses;
}