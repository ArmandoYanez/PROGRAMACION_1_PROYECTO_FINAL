//
// Created by memop on 08/01/2024.
//

#ifndef PROGRAMACION1_PROYECTOPARCIAL4_LOGIN_H
#define PROGRAMACION1_PROYECTOPARCIAL4_LOGIN_H

#include <iostream>
#include <string>



const int user_max= 100;

struct User {
    std::string username;
    std::string password;
};

User users[user_max];

int numUsers =0;

void registerUser(){
    if (numUsers < user_max){
        std::cout<< "Ingresa un nombre de usuario: ";
        std::cin >> users[numUsers].username;

        std::cout<< "Ingrese una contraseña: ";
        std::cin >> users[numUsers].password;

        numUsers++;

        std::cout << "Usuario registrado exitosamente "<< std::endl;
    }else {
        std::cout << "Se ha alcansado el numero maximo de usuarios" <<std::endl;
    }
}

bool loginUser(){
    std::string username, password;

    std::cout <<"Ingrese su nombre de susario:" << std::endl;
    std::cin >> username;

    std::cout<< "Ingrese su contraseña:" << std::endl ;
    std::cin>> password;

    for(int i=0; i< numUsers; ++i){
        if (users[i].username == username && users[i].password == password){
            std::cout << "Inicio éxitoso, binvenido, "<< username<< "." << std::endl;
            return true;
        }
    }
    std::cout << "Nombre de usuario o contraseña incorrecta"<< std::endl;
    return false;

}
int main(){
    int opcion;

    do{

        std::cout << "Seleccione una opción\n";
        std::cout << "1. Crear cuenta\n";
        std::cout << "2. Iniciar sesion\n";
        std::cout << "3. Salir\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                std::cout << "Adios"<< std::endl;
                break;
            default:
                std::cout << "Opción no valida"<< std::endl;
        }
    }while (opcion != 3);
    return 0;
}






#endif //PROGRAMACION1_PROYECTOPARCIAL4_LOGIN_H
