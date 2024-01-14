//
// Created by memop on 08/01/2024.
//
#ifndef PROGRAMACION1_PROYECTOPARCIAL4_LOGIN_H
#define PROGRAMACION1_PROYECTOPARCIAL4_LOGIN_H

#include <iostream>
#include <string>
#include <vector>

#include <sstream>

//Libreria con funciones extra de verificacion y otras funciones extra.
#include "FuncionesVerificacionesExtra.h"

//Funcion principal login.
std::string Login() {
    //Ingreso de usuario y contraseña
    std::string Usuario, Contrasena, Puesto;
    std::cout << "BIENVENIDO AL SISTEMA, INGRESA TU NOMBRE DE USUARIO Y CONTRASENA PARA CONTINUAR" << std::endl
              << "USUARIO:" << std::endl;
    std::cin >> Usuario;
    std::cout << "CONTRASENA:" << std::endl;
    std::cin >> Contrasena;

    std::string nombreArchivo = "BaseDeDatos.csv";
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada) {
        std::cout << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return "";
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

        // Comprobación si el nombre de usuario y contraseña coinciden
        if (campos.size() > 1 && campos[10] == Usuario && campos[11] == Contrasena && campos[4] == Puesto) {
            encontrado = true;
            break;
        }
    }

    archivoEntrada.close();
}

    if (encontrado){
        std::cout << "Acceso concedido." << std::endl;
        std::string decea;

        if (Puesto == "Gerente") {
            std::cout << "bienvenido gerente" << std::endl;
            std::cout << "que decea hacer?" << std::endl;
            std::cout << "1. Crear usuario" << std::endl;
            std::cout << "2. Eliminar usuario" << std::endl;
            std::cout << "3. Editar usuario" << std::endl;
            std::cin >> decea;

            switch (std::stoi(decea)) {
                case 1:
                    std::cout << "1. Crear usuario" << std::endl;
                    // Agrega la lógica para crear usuario aquí.
                    break;
                case 2:
                    std::cout << "2. Eliminar usuario" << std::endl;
                    // Agrega la lógica para eliminar usuario aquí.
                    break;
                case 3:
                    std::cout << "3. Editar usuario" << std::endl;
                    // Agrega la lógica para editar usuario aquí.
                    break;
                default:
                    std::cout << "Opción no válida." << std::endl;
                    break;
            }
        }
        if (Puesto == "Empleado") {
            std::cout << "bienvenido empleado" << std::endl;
            std::cout << "que decea hacer?" << std::endl;
            std::cout << "1. horario del empleado" << std::endl
            std::cout << "2. dias de descanso" << std::endl;
            std::cout << "3. salario del empleado " << std::endl;
            std::cin >> decea;

            switch (std::stoi(decea)) {
                case 1:
                    std::cout << "1. horario del empleado" << std::endl;
                    // Agrega la lógica para mostrar horario del empleado aquí.
                    break;
                case 2:
                    std::cout << "2. dias de descanso" << std::endl;
                    // Agrega la lógica para mostrar días de descanso aquí.
                    break;
                case 3:
                    std::cout << "3. salario del empleado " << std::endl;
                    // Agrega la lógica para mostrar salario del empleado aquí.
                    break;
                default:
                    std::cout << "Opción no válida." << std::endl;
                    break;
            }
        }
        if (Puesto == "GerenteRecursosHumanos") {
            std::cout << "bienvenido gerente de recursos humanos" << std::endl;
            std::cout << "que decea hacer?" << std::endl;
            std::cout << "1. cambiar de ubicación de empleado" << std::endl;
            std::cout << "2. modificar el horario de un empleado" << std::endl;
            std::cout << "3. modificar el salario del empleado" << std::endl;
            std::cin >> decea;

            switch (std::stoi(decea)) {
                case 1:
                    std::cout << "1. cambiar de ubicación de empleado" << std::endl;
                    // Agrega la lógica para cambiar ubicación de empleado aquí.
                    break;
                case 2:
                    std::cout << "2. modificar el horario de un empleado" << std::endl;
                    // Agrega la lógica para modificar horario de un empleado aquí.
                    break;
                case 3:
                    std::cout << "3. modificar el salario del empleado" << std::endl;
                    // Agrega la lógica para modificar salario de un empleado aquí.
                    break;
                default:
                    std::cout << "Opción no válida." << std::endl;
                    break;
            }
        }

        return Usuario;
    } else {
        std::cout << "USUARIO O CONTRASENA INCORRECTOS." << std::endl;
        return "";
    }
#endif //PROGRAMACION1_PROYECTOPARCIAL4_LOGIN_H