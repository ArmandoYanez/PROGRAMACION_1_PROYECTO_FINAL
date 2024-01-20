# BITACORA DE RAMSES 

## PROYECTO PARCIAL 4 | LOGIN

<span style="color:#d41089">ENCARGADO DE CREACION DE LOGIN</span>

Día: 18/12/2023: creación de login
Dia 18/01/2024: Creacion de las funciones de horarios.

```#include <iostream>
#include <string>

using namespace std;

const int user_max= 100;

struct User {
string username;
string password;
};

User users[user_max];

int numUsers =0;

void registerUser(){
if (numUsers < user_max){
cout<< "Ingresa un nombre de usuario: ";
cin >> users[numUsers].username;

cout<< "Ingrese una contraseña: ";
cin >> users[numUsers].password;

numUsers++;

cout << "Usuario registrado exitosamente "<< endl;
}else {
cout << "Se ha alcansado el numero maximo de usuarios" <<endl;
}
}

bool loginUser(){
string username, password;

cout <<"Ingrese su nombre de susario:" << endl;
cin >> username;

cout<< "Ingrese su contraseña:" << endl ;
cin>> password;

for(int i=0; i< numUsers; ++i){
if (users[i].username == username && users[i].password == password){
cout << "Inicio éxitoso, binvenido, "<< username<< "." << endl;
return true;
}
}
cout << "Nombre de usuario o contraseña incorrecta"<< endl;
return false;

}
int main(){
int opcion;

do{
cout << "Seleccione una opción\n";
cout << "1. Crear cuenta\n";
cout << "2. Iniciar sesion\n";
cout << "3. Salir\n";
cin >> opcion;

switch (opcion) {
case 1:
registerUser();
break;
case 2:
loginUser();
break;
case 3:
cout << "Adios"<< endl;
break;
default:
cout << "Opción no valida"<< endl;
}
}while (opcion != 3);
return 0;
}