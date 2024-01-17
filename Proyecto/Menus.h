#ifndef PROYECTO_MENUS_H
#define PROYECTO_MENUS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

//Funcion para comprar el puesto de los empleados.
void Comparacion(std::string puesto) {

    int Eleccion;

    //Funcion para gerentes generales.
    if (puesto == "GERENTE GENERAL") {
        std::cout << "BIENVENIDO GERENTE, ¿QUE DESEA HACER?" << std::endl;
        std::cout << "1. CREAR USUARIO" << std::endl;
        std::cout << "2. ELIMINAR USUARIO" << std::endl;
        std::cout << "3. EDITAR USUARIO" << std::endl;
        std::cin >> Eleccion;

        switch (Eleccion) {
            case 1:
                std::cout << "1. CREAR USUARIO" << std::endl;
                // Agrega la lógica para crear usuario aquí.
                break;
            case 2:
                std::cout << "2. ELIMINAR USUARIO" << std::endl;
                // Agrega la lógica para eliminar usuario aquí.
                break;
            case 3:
                std::cout << "3. EDITAR USUARIO" << std::endl;
                // Agrega la lógica para editar usuario aquí.
                break;
            default:
                std::cout << "OPCION NO VALIDA" << std::endl;
                break;
        }
    }

    //En caso de que sea empleado.
    else if(puesto == "EMPLEADO") {
        std::cout << "BIENVENIDO EMPLEADO" << std::endl;
        std::cout << "QUE DESEAS HACER" << std::endl;
        std::cout << "1. HORARIO DE EMPLEADO" << std::endl;
        std::cout << "2. DIAS DE DESCANSO " << std::endl;
        std::cout << "3. SALARIO DEL EMPLEADO " << std::endl;
        std::cin >> Eleccion;

        switch (Eleccion) {
            case 1:
                std::cout << "1. HORARIO DEL EMPLEADO" << std::endl;
                // Agrega la lógica para mostrar horario del empleado aquí.
                break;
            case 2:
                std::cout << "2. DIAS DE DESCANSO " << std::endl;
                // Agrega la lógica para mostrar días de descanso aquí.
                break;
            case 3:
                std::cout << "3. SALARIO DEL EMPLEADO " << std::endl;
                // Agrega la lógica para mostrar salario del empleado aquí.
                break;
            default:
                std::cout << "OPCION NO VALIDA" << std::endl;
                break;
        }
    }

    else if (puesto == "GERENTE ALMACEN") {
        std::cout << "bienvenido gerente de recursos humanos" << std::endl;
        std::cout << "que decea hacer?" << std::endl;
        std::cout << "1. cambiar de ubicación de empleado" << std::endl;
        std::cout << "2. modificar el horario de un empleado" << std::endl;
        std::cout << "3. modificar el salario del empleado" << std::endl;
        std::cin >> Eleccion;

        switch (Eleccion) {
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
}
#endif //PROYECTO_MENUS_H