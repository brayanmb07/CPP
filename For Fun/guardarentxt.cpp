#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{   
    fstream archivo("registro.txt");

    string nombre, apellido, direccion;

    int telefono, op, op2;

    do{
        cout <<" 1.- Nuevo registro\n2.- Salir";
        cin >> op;
        cin.ignore();

        if(op == 1){
            if(!archivo.is_open()){

                archivo.open("registro.txt", ios::out);
            }
            cout<<"Nombre: ";
            getline(cin, nombre);

            cout<<"Apellido: ";
            getline(cin, apellido);

            cout<<"Direccion: ";
            getline(cin,direccion);

            cout<<"Telefono";
            cin>> telefono;

            cout<<"1,- guardar registro\n2.- regresar\n";
            cin >> op2;

            if(op2 == 1){

            archivo<<"nombreL "<< nombre << endl;
            archivo<<"apellido: "<< apellido << endl;
            archivo<<"direccion: "<< direccion << endl;
            archivo<<"telefono: "<< telefono << endl;

            system("cls");

            cout<<"registro guardado con exito..\n";

            system("pause");
            system("cls");
            
            }
            archivo.close();
        } 

    }while(op != 2);

    return 0;

}
