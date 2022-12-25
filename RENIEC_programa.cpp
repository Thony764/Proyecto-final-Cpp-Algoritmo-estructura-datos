/*Escribí un programa para la RENIEC, donde debe realizar las siguientes operaciones:

a) REGISTRAR UNA PERSONA

B) BUSCAR A UNA PERSONA POR DNI

C) BUSCAR A UNA PERSONA POR APELLIDOS

D) LISTAR A LAS PERSONAS EN ORDEN POR DNI

C) LISTAR A LAS PERSONAS EN ORDEN POR EDAD

Debe utilizar funciones y vectores.*/

#include <iostream>
#include <vector>

using namespace std;

struct Cliente
{
    string nombre;
    string apellido;
    int dni;
    float venta;
};

// Funcion para registrar las ventas del dia
void registrarVentas(vector<Cliente> &clientes)
{
    Cliente c;
    cout << "Ingresar datos del cliente:" << endl;
    cout << "Nombre: ";
    cin >> c.nombre;
    cout << "Apellido: ";
    cin >> c.apellido;
    cout << "DNI: ";
    cin >> c.dni;
    cout << "Venta total de cliente: ";
    cin >> c.venta;
    clientes.push_back(c);
}

// Funcion para buscar al cliente por DNI
void buscarPersonaPorDni(vector<Cliente> &clientes)
{
    int dni;
    cout << "Ingrese el DNI a buscar: ";
    cin >> dni;
    for (int i = 0; i < clientes.size(); i++)
    {
        if (clientes[i].dni == dni)
        {
            cout << "Nombre: " << clientes[i].nombre << endl;
            cout << "Apellidos: " << clientes[i].apellido << endl;
            cout << "DNI: " << clientes[i].dni << endl;
            cout << " Venta total realizada al ciente" << clientes[i].venta << endl;
            return;
        }
    }
    cout << "No se encontro ninguna persona con el DNI ingresado." << endl;
}

// Funcion para buscar al cliente por apellidos
void buscarPersonaPorApellido(vector<Cliente> &clientes)
{
    string apellido;
    cout << "Ingrese el apellido a buscar: ";
    cin >> apellido;
    for (int i = 0; i < clientes.size(); i++)
    {
        if (clientes[i].apellido == apellido)
        {
            cout << "Nombre: " << clientes[i].nombre << endl;
            cout << "Apellidos: " << clientes[i].apellido << endl;
            cout << "DNI: " << clientes[i].dni << endl;
            cout << "Venta total realizada al ciente" << clientes[i].venta << endl;
            return;
        }
    }
    cout << "No se encontro ninguna persona con el apellido ingresado." << endl;
}
// Funcion para listar al cliente en orden por DNI
void listarClientesDni(vector<Cliente> clientes)
{

    for (int i = 0; i < clientes.size() - 1; i++)
    {
        for (int j = i + 1; j < clientes.size(); j++)
        {
            if (clientes[i].dni > clientes[j].dni)
            {
                Cliente temp = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = temp;
            }
        }
    }
    // Mostrar los datos de los clientes en orden
    for (int i = 0; i < clientes.size(); i++)
    {
        cout << "Nombre: " << clientes[i].nombre << endl;
        cout << "Apellido: " << clientes[i].apellido << endl;
        cout << "DNI: " << clientes[i].dni << endl;
        cout << "Venta total de cliente: " << clientes[i].venta << endl;
        cout << endl;
    }
}

void listarVentasVenta(vector<Cliente> clientes)
{

    for (int i = 0; i < clientes.size() - 1; i++)
    {
        for (int j = i + 1; j < clientes.size(); j++)
        {
            if (clientes[i].venta < clientes[j].venta)
            {
                Cliente temp = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = temp;
            }
        }
    }
    // Mostrar los datos de los clientes en orden
    for (int i = 0; i < clientes.size(); i++)
    {
        cout << "Nombre: " << clientes[i].nombre << endl;
        cout << "Apellido: " << clientes[i].apellido << endl;
        cout << "DNI: " << clientes[i].dni << endl;
        cout << "Venta total de cliente: " << clientes[i].venta << endl;
        cout << endl;
    }
}

float mostrarTotalVentas(vector<Cliente> clientes)
{
    float total = 0;
    for (int i = 0; i < clientes.size(); i++)
    {
        total += clientes[i].venta;
    }
    cout << "Total de ventas del dia: " << total << endl;
    return total;
}

void mostrarMayorVenta(vector<Cliente> clientes)
{
    float mayorVenta = 0;
    Cliente mayorCliente;
    for (int i = 0; i < clientes.size(); i++)
    {
        if (clientes[i].venta > mayorVenta)
        {
            mayorVenta = clientes[i].venta;
            mayorCliente = clientes[i];
        }
    }
    cout << "Mayor venta del dia: " << mayorVenta << endl;
    cout << "Nombre : " << mayorCliente.nombre << endl;
    cout << "Apellido del cliente: " << mayorCliente.apellido << endl;
    cout << "DNI: " << mayorCliente.dni << endl;
}

int main()
{
    vector<Cliente> clientes;

    int opcion;
    do
    {
        cout << "Elija una opcion:" << endl;
        cout << "1. Registrar ventas del dia" << endl;
        cout << "2. Buscar al cliente por DNI" << endl;
        cout << "3. Buscar al cliente por apellido" << endl;
        cout << "4. Listar al cliente en orden por DNI" << endl;
        cout << "5. Listar las ventas en orden de total de venta" << endl;
        cout << "6. Mostrar el total de ventas del dia" << endl;
        cout << "7. Mostrar la mayor venta" << endl;
        cout << "8. Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            registrarVentas(clientes);
            break;
        case 2:
            buscarPersonaPorDni(clientes);
            break;
        case 3:
            buscarPersonaPorApellido(clientes);
            break;
        case 4:
            listarClientesDni(clientes);
            break;
        case 5:
            listarVentasVenta(clientes);
            break;
        case 6:
            mostrarTotalVentas(clientes);
            break;
        case 7:
            mostrarMayorVenta(clientes);
            break;
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (opcion != 8);

    return 0;
}
