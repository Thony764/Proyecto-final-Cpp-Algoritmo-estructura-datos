#include <iostream>
#include <string>

using namespace std;

struct platillo
{
    string nombre;
    float precio;
    int numero;

} platillos[50]; // se puede registra 50 platillos

void menu()
{
    cout << "\nBIENVENIDOS A NUESTRO RESTAURANTE" << endl;
    cout << "\n====MENU DE OPCIONES=======";
    cout << "\n1) Mostrar Platillos";
    cout << "\n2) Ordenar platillo";
    cout << "\n3) Calificar Servicio";
    cout << "\n0) Salir\n\n";
}

// Ordenar platillo
int total_platillos;
int numero_pedidos;
int pedido;
float dinero;

// menu
int op;
int op2;
int op3;

// reseña
float estrellas;

// prototipos de funciones
void mostrar_platillo_todo();
void ordenar_platillo();
void desicion_salida();
int buscar_numero_pedido(int pedido);

//busqueda secuencial
int j = 0;
int encontrado = 0;
int dato;
string flag = "F";

int main()
{
    // platillos registrados

    platillos[0].numero = 1;
    platillos[0].nombre = "\nPapa a la huancaina";
    platillos[0].precio = 20;
    
    platillos[1].numero = 2;
    platillos[1].nombre = "\nPizza";
    platillos[1].precio = 10;
    
    platillos[2].numero = 3;
    platillos[2].nombre = "\nMole";
    platillos[2].precio = 7.5;
    
    platillos[3].numero = 4;
    platillos[3].nombre = "\nHamburguesa";
    platillos[3].precio = 5.2;

    platillos[4].numero = 5;
    platillos[4].nombre = "\nestofado de pavo";
    platillos[4].precio = 15;

    // Para colocar mas cambie el indice numero

    total_platillos = 5; // actualizar si se ponen o quitan mas

    do
    {
        menu();
        cin >> op;cout << endl;

        switch (op)
        {
        case 1:
            mostrar_platillo_todo();
            do // repetir en caso de que esten fuera de rango
            {
                desicion_salida();
            } while (op2 > 2 || op2 < 0);
        break;

        case 2:
            do // si desea ver el menu antes de ordenar
            {   
                cout << "Mostrar menu de platillos\n";
                cout << "1) SI\n";
                cout << "0) Saltar\n";
                cin >> op3;

                if (op3 < 0 || op3 > 1)
                {
                    cout << "\nOpcion incorrecta\n";
                }

            } while (op3 < 0 || op3 > 1);
            
            if (op3 == 1)
            {
                mostrar_platillo_todo();
            }
            ordenar_platillo();

            do // repetir en caso de que esten fuera de rango
            {
                desicion_salida();
            } while (op2 > 2 || op2 < 0);
            break;
        
        case 3:

            do// calificar servicio 
            {
                cout << "califica nuestro cervicio hasta 5 estrellas\n";
                cin >> estrellas;
                if (estrellas < 1 || estrellas > 5)
                {
                    cout << "Calificacion invalida intentelo de nuevo\n";
                }
                else
                {
                    cout << "\n***Grcias por su opinion***\n"<< endl;
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
        }

    } while (op2 == 1); 
    return 0;
}

void mostrar_platillo_todo()// mostrar todos los platillos 
{
    for (int i = 0; i < total_platillos; i++)
    {
        cout << "Platillo #: " << i+1 << endl;
        cout << "Nombre: " << platillos[i].nombre << endl;
        cout << "Precio: S/ " << platillos[i].precio << endl << endl;
    }
}

void ordenar_platillo() // pedir un platillo 
{
    void mostrar_platillo_todo();
    do
    {
        cout << "cuantos pedidos desea\n";
        cin >> numero_pedidos;
        if (numero_pedidos < 0)
        {
            cout << "\nOpcion incorrecta digite denuevo\n";
        }
        
    } while (numero_pedidos < 0);
    
    for (int i = 0; i < numero_pedidos; i++) // proceso de compra
    {
        cout << "\ningrese el numero del platillo / "  << "Pedido #"<<i+1 << endl;
        cin >> pedido;
        buscar_numero_pedido(pedido);
        
    }
}

void desicion_salida() // desicion despues de cada case
{
    cout << "\nescriba 1 para volver al menu,0 para salir: " << endl;
    cin >> op2;
    if (op2 > 2 || op2 < 0)
    {
        cout << "\nOpcion incorrecta" << endl;
    }
}

int buscar_numero_pedido(int pedido)
{
    // busqueda secuencial
    while ((flag == "F") && (j < 50))
    { 
        if (platillos[j].numero == pedido)
        {
            flag = "V";
        }
        j++;
    } 
    encontrado = j;

    if (flag == "F")// si no hay coincidencias
    {
        cout << "\nEse platillo no esta en el menu" << endl;
    }

    else if (flag == "V") // si se encontro
    {   //precess de compra
        cout << platillos[pedido-1].nombre << endl;
        cout << "S/ " << platillos[pedido-1].precio << endl;
        cout << "\ningrese su dinero\n";
        cin >> dinero;
        
        if (dinero < platillos[pedido - 1].precio)
        {
            cout << "No cuenta con el dinero suficiente para este platillo\n";
        }
        if (dinero == platillos[pedido - 1].precio)
        {
            cout << "Comprado con exito\n";
        }
        if (dinero > platillos[pedido - 1].precio)
        {
            cout << "Comprado con exito" << endl;
            cout << "Su cambio: S/ " << (dinero - (platillos[pedido - 1].precio)) << endl;
        }
        j = j - 1;
    }
    j = 0; // reiniciando variables
    encontrado = 0;
    flag = "F";
}
