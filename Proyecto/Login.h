//
// Created by memop on 08/01/2024.
//
#ifndef PROGRAMACION1_PROYECTOPARCIAL4_LOGIN_H
#define PROGRAMACION1_PROYECTOPARCIAL4_LOGIN_H

#include <iostream>
#include <string>
#include <vector>

#include <sstream>

//libreria con los menus
#include "Menus.h"

//Libreria con funciones extra de verificacion y otras funciones extra.
#include "FuncionesVerificacionesExtra.h"

//Funcion principal login.
void Login() {
    //Ingreso de usuario y contraseña
    std::string Usuario, Contrasena, Puesto;
    std::cout << "BIENVENIDO AL SISTEMA, INGRESA TU NOMBRE DE USUARIO Y CONTRASENA PARA CONTINUAR" << std::endl << "USUARIO:";
    std::cin >> Usuario;
    std::cout << "CONTRASENA:";
    std::cin >> Contrasena;
    LineasEnBlanco();

    std::string nombreArchivo = "BaseDeDatos.csv";
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada) {
        std::cout << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    std::string linea;
    bool encontrado = false;
    while (std::getline(archivoEntrada, linea)) {
        std::stringstream ss(linea);
        std::string campo;
        std::vector<std::string> campos;

        while (std::getline(ss, campo, ',')) {
            campos.push_back(campo);
        }

        // Comprobación si el nombre de usuario y contraseña coinciden.
        if (campos.size() > 1 && campos[10] == Usuario && campos[11] == Contrasena) {
            Comparacion(campos[4], campos[12], campos[9]);
            LineasEnBlanco();
            Login();
            encontrado = true;
            break;
        }
    }
    archivoEntrada.close();

    if (!encontrado) {
        std::cout << "Nombre de usuario o contraseña incorrectos. Inténtalo de nuevo." << std::endl;
        Login();
    }

}
#endif //PROGRAMACION1_PROYECTOPARCIAL4_LOGIN_H