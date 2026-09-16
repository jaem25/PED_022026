#include <iostream>
#include <random>

struct Accion
{
    std::string simbolo; //AMZN
    std::string nombre_empresa;
    float precio_compra;
    float precio_venta;
    float ultimo_precio;
};
Accion accion;
float CalcularMargenGanancia(float precio_compra, float precio_venta);
//sobrecarga
void CalcularFluctuacionAccion(Accion &accion); //accion
void CalcularFluctuacionAccion(Accion *accion); //&accion

int main()
{
    struct Accion accion;
    CalcularFluctuacionAccion(accion);


    return 0;
}

float CalcularMargenGanancia(float precio_compra, float precio_venta)
{
    //precio venta - precio compra
    return 0;
}

void CalcularFluctuacionAccion(Accion &accion)
{
    //Generar un valor aleatorio entre 10.0 - 500.0
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> disprecio(10.0, 500.0);
    
    
    //accion.compra dist gen
    
    return dist(gen);
}

void CalcularFluctuacionAccion(Accion *accion)
{
     //Generar un valor aleatorio entre 10.0 - 500.0
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> disprecio(10.0, 500.0);
    
    //accion.precio_compra dist(gen)

    return dist(gen); 
}