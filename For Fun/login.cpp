#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void registro ();
void ingresar ();
void leerdatos ();
void page ();

int main()
{

  int op;

  cout << "1.- Nuevo registro" << endl;
  cout << "2.- Ingresar" << endl;
  cout << "3.- Leer datos" << endl;
  cout << "Introduzca la opcion deseada: ";

  cin >> op;
  cin.ignore ();
  cout << endl;


  if (op == 1){

      registro ();

    }
  else if (op == 2){

      ingresar ();

    }
  else if (op == 3){

      leerdatos ();

    }

  return 0;
}



void registro()
{

  ofstream archivo;

  string usuario, email, password;

  archivo.open ("registro.txt", ios::app | ios::out);

  if (archivo.fail ())
    {
      cout << "No se ha abierto el archivo.";
      exit (1);
    }
   
   //leer input
    cout << "Nombre: ";
    getline (cin, usuario);

    cout << "Email: ";
    getline (cin, email);

    cout << "Contrasena: ";
    getline (cin, password);

  //Guardar en archivo
  archivo << "Nombre: " << usuario << endl;
  archivo << "Email: " << email << endl;
  archivo << "Contrasena: " << password << endl << endl;

  archivo.close ();

   cout<<"Te haz registrado correctamente!"<< endl << endl;

   cin.get();

   system ("cls");
   system ("clear");

   main ();

}


void ingresar()
{

  ifstream archivo;

  string usuario, texto, linea, linea2, linea3, password, passregistrada;

  int matchusuario = 0;

  cout << "Introduzca el usuario: ";
  cin >> usuario;
  cout << endl;

  usuario = "Nombre: "+usuario;

  //Confirmar renombre del usuario
  //cout<<"Actualmente usuario = " << usuario<<endl;

  if (!archivo.is_open ())
  {

    archivo.open ("registro.txt", ios::in);

  }
    
  while (getline (archivo, linea))
  {

   // cout << "Linea 1 = " << linea <<endl ;

      if (usuario == linea)
      {

         if (linea.find (usuario) != string::npos)
         {

            //Esto es el Email = linea 2
            getline (archivo, linea);
            //out <<  "Linea 1 = " <<  linea << endl;

            //Esto es la contrasena == linea 3
            getline (archivo, linea2);
            //cout <<  "Linea 2 = " <<  linea2 << endl;
            passregistrada = linea2;


   
            cout<<"Introduzca contrasena: ";
            cin>> password;
            password = "Contrasena: "+password;
            cout<<endl;

            //confirmal renombre de la contrasena
            //cout<<password;

            //cout<<passregistrada;

            if(passregistrada == password)
            {
               page ();

            }else{

               int op;
               

               do{

                  cout<<"La contrasena introducida es incorrecta." << endl;
                  cout <<"¿Quiere reintentarlo?"<<endl;
                  cout<<"1.- Si"<<endl;
                  cout<<"2.- Volver al menu principal" << endl;
                  cout<<"3.- Salir"<<endl;
                  cout<<"Introduzca la opcion deseada: ";
                  cin >> op;
                  cout << endl;

                  if (op == 1)
                  {
                     system("cls");
                     system("clear");
                     ingresar ();

                  }else if (op == 2)
                  {
                     system("cls");
                     system("clear");
                     main ();

                  }else if (op == 3)
                  {
                     exit(1);
                  }

               }while(op != 1 || op != 2 || op != 3);

            }  

            matchusuario = 1;

         }

      }

  }


  if (matchusuario == 0)
  {
      int op;

      cout << "Usuario no registrado." << endl;
      cout <<"¿Quiere registrarse?"<<endl;
      cout<<"1.- Si"<<endl;
      cout<<"2.- Salir"<<endl;
      cout<<"Introduzca la opcion deseada: ";
      cin >> op;
      cout << endl;

      if (op == 1)
      {
         //Ir al menu principal
         cin.ignore();
         registro ();

      }else if (op == 2)
      {

	     exit (1);

      }

   }


  archivo.close ();

  exit (1);

}


void leerdatos ()
{

  ifstream archivo;
  string texto;

  if (!archivo.is_open ())
  {

      archivo.open ("registro.txt", ios::in);

  }

  while (getline (archivo, texto))
  {

     	cout << texto << endl;
     	getline (archivo, texto);
      cout << texto << endl;
      getline (archivo, texto);
      cout << texto << endl;

   }

  archivo.close ();

  main ();

  exit (1);

}

void page()
{
   cout << "Haz entrado a la pagina!!";
}
