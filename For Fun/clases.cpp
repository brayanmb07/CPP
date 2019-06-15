#include <iostream>

using namespace std;

class Persona
{
private:
    char nombre[40];
    int edad;

public:
    void inicializar();
    void imprimir();
    void esMayorEdad();
};

void Persona::inicializar()
{
    cout << "Ingrese nombre:";
    cin.getline(nombre, 40);
    cout<< endl;
    cout << "Ingrese edad:";
    cin >> edad;
    cout << endl;
}

void Persona::imprimir()
{
    cout << "Nombre:" << nombre << endl;


    cout << "Edad:" << edad << endl;


}

void Persona::esMayorEdad()
{
    if (edad >= 18)
    {
        cout << "Es mayor de edad." << endl;
    }
    else
    {
        cout << "No es mayor de edad." << endl;
    }
    cin.get();
    cin.get();
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        Persona persona[i];
        persona[i].inicializar();
        persona[i].imprimir();
        persona[i].esMayorEdad();
    }

    return 0;
}