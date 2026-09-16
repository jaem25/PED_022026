#include <iostream>
// #include <cstdlib>
// #include <ctime>
#include <random>

// Desde C++20 activa funcionalidades de calendario
#include <chrono>

// Lib de arreglo de tamaño variable
#include <vector>
#include <utility> //para usar pair

struct DatosAlquiler
{
    const double kPrecioAlquiler = 3;
    double costo_alquiler;
    int cod_alquiler;

    std::vector<std::pair<std::string, double>> dias_horas;
};

// Struct Principal
struct Cliente
{
    std::string nombre;
    int edad;
    int anio_nac;
    std::string num_telefono;
    // Variable que anida
    struct DatosAlquiler datos_alquiler;

} cliente; // Variable de ámbito global

// Declaracion de un vector
std::vector<struct Cliente> vector_clientes;

// Declaracion de funciones
void SolicitarDatos();
double CalcularCostoAlquiler(std::vector<std::pair<std::string, double>> horas_dias, double precio_alquier);
int GenerarCodigoCupon();
void DeterminarDescuento(int cod_alquiler);
void Imprimir();
void ReiniciarCliente();

int main()
{
    std::cout << " Tamano del struct cliente " << sizeof(cliente) << "\n";

    char continuar_cliente;

    do
    {
        ReiniciarCliente();

        SolicitarDatos();

        cliente.datos_alquiler.costo_alquiler =
            CalcularCostoAlquiler(cliente.datos_alquiler.dias_horas, cliente.datos_alquiler.kPrecioAlquiler);

        cliente.datos_alquiler.cod_alquiler = GenerarCodigoCupon();

        // Almacenando en el vector
        vector_clientes.push_back(cliente);

        std::cout << "\nDesea ingresar otro cliente? (s/n): ";
        std::cin >> continuar_cliente;

    } while (continuar_cliente == 's' || continuar_cliente == 'S');

    Imprimir();

    return 0;
}

void ReiniciarCliente()
{
    // DatosAlquiler tiene un miembro const (kPrecioAlquiler), por lo que
    // el struct NO se puede reasignar completo (el operator= queda eliminado
    // por el compilador). Por eso limpiamos los campos uno por uno para
    // poder reutilizar la variable global "cliente" en cada vuelta del
    // do-while sin arrastrar datos del cliente anterior.
    cliente.nombre.clear();
    cliente.edad = 0;
    cliente.anio_nac = 0;
    cliente.num_telefono.clear();

    cliente.datos_alquiler.dias_horas.clear();
    cliente.datos_alquiler.costo_alquiler = 0;
    cliente.datos_alquiler.cod_alquiler = 0;
}

void SolicitarDatos()
{
    std::string dias;
    double horas;
    char continuar_dia;

    std::cout << "Ingresar el nombre: ";
    std::cin >> cliente.nombre;

    std::cout << "Detalles del alquiler\n";

    do
    {
        std::cout << "Ingresa el dia: ";
        std::cin >> dias;
        std::cout << "Ingresa las horas: ";
        std::cin >> horas;

        cliente.datos_alquiler.dias_horas.push_back({dias, horas});

        std::cout << "Desea ingresar otro dia para este cliente? (s/n): ";
        std::cin >> continuar_dia;

    } while (continuar_dia == 's' || continuar_dia == 'S');
}

double CalcularCostoAlquiler(std::vector<std::pair<std::string, double>> horas_dias, double precio_alquier)
{
    double cantidad_horas = 0;

    for (size_t i = 0; i < horas_dias.size(); i++)
    {
        cantidad_horas += horas_dias[i].second;
    }

    return cantidad_horas * precio_alquier;
}

int GenerarCodigoCupon()
{
    /*  srand(time(NULL));
      // rango 1000 - 9999
    return rand() %  9999 - 1000 + 1;
  */

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1000, 9999);

    return dist(gen);
}

void DeterminarDescuento(int cod_alquiler)
{
    // Operador ternario
    (cod_alquiler % 2 == 0) ? std::cout << "Descuento del 10% \n"
                             : std::cout << "No tiene descuento \n";
}

void Imprimir()
{
    std::cout << "\n............Imprimiendo datos................. \n";

    for (size_t i = 0; i < vector_clientes.size(); i++)
    {
        std::cout << "Nombre cliente: " << vector_clientes[i].nombre << "\n";
        std::cout << "Precio alquiler por hora $" << vector_clientes[i].datos_alquiler.kPrecioAlquiler << "\n";
        std::cout << "Detalle de horas de alquiler \n";

        for (size_t j = 0; j < vector_clientes[i].datos_alquiler.dias_horas.size(); j++)
        {
            std::cout << " - Dia: " << vector_clientes[i].datos_alquiler.dias_horas[j].first << "\n";
            std::cout << " - Cantidad de horas: " << vector_clientes[i].datos_alquiler.dias_horas[j].second << "\n";
        }

        std::cout << "Costo de alquiler: $" << vector_clientes[i].datos_alquiler.costo_alquiler << "\n";
        std::cout << "Codigo de alquiler: " << vector_clientes[i].datos_alquiler.cod_alquiler << "\n";
        DeterminarDescuento(vector_clientes[i].datos_alquiler.cod_alquiler);
        std::cout << "\n";
    }
}