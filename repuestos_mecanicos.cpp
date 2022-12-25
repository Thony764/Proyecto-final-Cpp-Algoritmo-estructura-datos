#include <iostream>
#include <string.h>

using namespace std;

struct info_direccion
{
    string calle;
    int numero;
    string urbanizacion;
};

struct cliente
{
    string nombre;
    struct info_direccion direccion;
    int edad;
    int dni;
} clientes[50];

void menu()
{   cout << "BIENVENIDO A NUeSTRO TALLER";
    cout << "\n====MENU DE OPCIONES=======";
    cout << "\n1) REGISTRAR CLIENTE";
    cout << "\n2) VER CLIENTES REGISTRADOS";
    cout << "\n3) TRABAJO MECANICO";
    cout << "\n4) CALIFICANOS";
    cout << "\n0) SALIR\n";
}

// registrar clientes
int n_registrados;
int total_registrados = 1;

// menu
int op, op2;

// reseña
float estrellas;

// trabajo mecanico.
int trabajo;
int respuesta;
bool opc = false;

// Buscar clientes
int t = 1, j = 0, encontrado = 0;
string dato;
string flag = "F";

// prototipos de funciones
void registro_clientes();
void mostrar_clientes();
void buscar_cliente();
void trabajo_mecanico();
int desicion_salida();

int main()
{

    // cliente precargado
    clientes[0].nombre = "Thony";
    clientes[0].edad = 18;
    clientes[0].dni = 7654321;
    clientes[0].direccion.calle = "San Jose";
    clientes[0].direccion.numero = 764;
    clientes[0].direccion.urbanizacion = "La pradera";

    do
    {
        menu();
        cin >> op;
        cout << endl;
        switch (op)
        {
        case 1:
            cout << "cuentos clientes desea registrar: ";
            cin >> n_registrados;
            if (n_registrados < 0)
            {
                cout << "dato invalido" << endl;
            }

            total_registrados += n_registrados;
            registro_clientes();

            do // repetir en caso de que esten fuera de rango
            {
                desicion_salida();
            } while (op2 > 2 || op2 < 0);
            break;
        case 2:
            cout << "**eleiga**\n1) Mostrar todo\n2) Buscar por nombre\n";
            cin >> op;
            cout << endl;
            switch (op)
            {
            case 1:
                mostrar_clientes();
                break;
            case 2:
                buscar_cliente();
                break;
            default:
                cout << "opcion incorrecta";
            }
            do // repetir en caso de que esten fuera de rango
            {
                desicion_salida();
            } while (op2 > 2 || op2 < 0);
            break;
        case 3:
            trabajo_mecanico();
            do // repetir en caso de que esten fuera de rango
            {
                desicion_salida();
            } while (op2 > 2 || op2 < 0);
            break;
        case 4:
            do
            {
                cout << "califica nuestro cervicio hasta 5 estrellas\n";
                cin >> estrellas;
                if (estrellas < 1 || estrellas > 4)
                {
                    cout << "Calificacion invalida intentelo de nuevo\n";
                }
                else
                {
                    cout << "\n***Grcias por su opinion***\n" << endl;
                }

            } while (estrellas < 1 || estrellas > 5);

            do // repetir en caso de que esten fuera de rango
            {
                desicion_salida();
            } while (op2 > 2 || op2 < 0);
            break;
        case 0:
            cout << "\nSeguro que desea salir? 1 NO, cualquier otro numero SI\n ";
            cin >> op2;
            break;

        default:
            cout << "Opcion incorrecta ingrese de nuevo\n";
            op2 = 1;
            break;
        }

    } while (op2 == 1);
    return 0;
}

int desicion_salida()
{
    cout << "\nescriba 1 para volver al menu,0 para salir: " << endl;
    cin >> op2;
    if (op2 > 2 || op2 < 0)
    {
        cout << "\nOpcion incorrecta" << endl;
    }
}

void registro_clientes()
{
    // un cliente precargado
    for (int i = 1; i <= n_registrados; i++) // registrando mas clientes
    {
        fflush(stdin); // vaciar el buffer
        cout << "cliente #" << t + 1 << endl;
        cout << " digita su nombre: ";
        getline(cin, clientes[t].nombre);

        do // comprobar edades  negativas
        {
            cout << " digita su edad: ";
            cin >> clientes[t].edad;
            if (clientes[t].edad < 0)
            {
                cout << "\nedad invalida digite de nuevo\n" << endl;
            }
        } while (clientes[t].edad < 0);

        cout << " digita su DNI: ";
        cin >> clientes[t].dni;
        cout << " digita su calle: ";
        fflush(stdin);
        getline(cin, clientes[t].direccion.calle);
        cout << " digita su numero de calle: ";
        cin >> clientes[t].direccion.numero;
        fflush(stdin);

        cout << " digita su urbanizacion: ";
        getline(cin, clientes[t].direccion.urbanizacion);
        t++;
        cout << "\n";
    }
}

void mostrar_clientes()
{

    for (int i = 1; i <= total_registrados; i++)
    {
        int s = i;
        cout << "cliente #: " << s << endl;
        cout << "Nombre: " << clientes[s - 1].nombre << endl;
        cout << "edad: " << clientes[s - 1].edad << endl;
        cout << "DNI: " << clientes[s - 1].dni << endl;
        cout << "Calle: " << clientes[s - 1].direccion.calle << endl;
        cout << "numero: " << clientes[s - 1].direccion.numero << endl;
        cout << "urbanizacion: " << clientes[s - 1].direccion.urbanizacion << endl;
        cout << "\n";
        s++;
    }
}

void buscar_cliente()
{
    fflush(stdin);
    cout << "\ningresa el nombre: ";
    getline(cin, dato);

    // buscando cliente
    while ((flag == "F") && (j < 50))
    { // busqueda secuencial
        if (clientes[j].nombre == dato)
        {
            flag = "V";
        }
        j++;
    } // searching
    encontrado = j;

    if (flag == "F")
    {
        cout << "no se encontro registros" << endl;
    }

    else if (flag == "V")
    {
        cout << "\ncliente encontrado\n";
        j = j - 1;
        cout << "edad: " << clientes[j].edad << endl;
        cout << "DNI: " << clientes[j].dni << endl;
        cout << "Calle: " << clientes[j].direccion.calle << endl;
        cout << "numero: " << clientes[j].direccion.numero << endl;
        cout << "urbanizacion: " << clientes[j].direccion.urbanizacion << endl;
        cout << "\n";
    }
    j = 0; // reiniciando variable
    encontrado = 0;
    flag = "F";
}

void trabajo_mecanico()
{

    opc = false;
    while (opc == false) // opc false
    {
        do
        {
            cout << "PRECIO DEL TRABAJO MECANICO" << endl;
            cout << " 1. cambio de aceite        = s/60   " << endl;
            cout << " 2. reparacion de Motor     = s/3000 " << endl;
            cout << " 3. reparacion de CjasDC    = s/400  " << endl;
            cout << " 4. mantenimiento de Ruedas = s/350  " << endl << endl;
            cin >> trabajo;

            if (trabajo < 1 || trabajo > 4) // comprobar opcciones fuera de rango
            {
                cout << "\nOpcion incorrecta\ndigite de nuevo\n" << endl;
            }
            else // trabajo guardado
            {
                cout << "\n\ntrabajo guardado con exito!\n\n";
                // trabajo = -1;//actulizar variable
            }

        } while (trabajo < 1 || trabajo > 4); // al actulizar trabajo termina while

        if (trabajo != 0) // en caso de que dese registrar  otro trabajo
        {
            do // comprobar rango de opcciones
            {
                do // en caso que la opcion este fuera de rango
                {
                    cout << "\ndesea registrar otro trabajo?\n1: SI\n0: NO" << endl;
                    cin >> respuesta;
                    if (respuesta > 2 || respuesta < 0)
                    {
                        cout << "opcion incorrecta";
                    }

                } while (respuesta > 2 || respuesta < 0);

            } while (respuesta < 0 && respuesta > 1);
        }
        if (respuesta == 0) // si es 0 es porque ya no registrara masa opc = true
        {
            opc = true;
        }
    }
}