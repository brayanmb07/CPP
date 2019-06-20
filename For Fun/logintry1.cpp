#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void
registro ()
{

  //Crear

  fstream archivo ("registro.txt");



  string nick, email, password;

  int op, op2;

  //menu
  do
    {
      cout << "1.- Nuevo registro\n2.- Salir\nIntroduzca la opcion deseada: ";
      cin >> op;
      cin.ignore ();

      if (op == 1)
	{
	  //revisar si el archivo esta abierto
	  if (!archivo.is_open ())
	    {
	      archivo.open("registro.txt",  fstream::app | fstream::out);
	    }

	  cout << "Nombre: ";
	  getline (cin, nick);

	  cout << "Email: ";
	  getline (cin, email);

	  cout << "Contrasena: ";
	  getline (cin, password);

	  cout <<
	    "1.- Guardar en registro\n2.- Regresar\nIntroduzca la opcion deseada: ";
	  cin >> op2;

	  if (op2 == 1)
	    {

	      //Guardar en archivo
	      archivo << "Nombre " << nick << endl;
	      archivo << "Email: " << email << endl;
	      archivo << "Contrasena: " << password << endl;


	      system ("cls");

	      cout << ("Registro guardado con exito..\n");

	      system ("pause");
	      system ("cls");
	    }

	  archivo.close ();
	}

    }
  while (op != 2);

}

int
main ()
{
    int inicio;


      cout << "1.- Registrarse\n2.-Ingresar\n3.-Salir\nIntroduzca la opcion deseada: ";
      cin >> inicio;

      if (inicio == 1)
	{

	  registro ();

	}

      else if (inicio == 2)

	{
	  return 2;
      
	}else if (inicio == 3) {
        return 3;
    }



  return 0;

}
