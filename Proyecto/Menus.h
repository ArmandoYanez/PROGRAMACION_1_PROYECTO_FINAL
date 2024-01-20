#ifndef PROYECTO_MENUS_H
#define PROYECTO_MENUS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "FuncionesParaEmpleados.h"

#include <cstdlib>  // Necesario para system()

//Funcion para comprar el puesto de los empleados.
void Comparacion(std::string puesto, std::string planta, std::string salario) {

    int Eleccion;
    GerenteRecursosHumanos<std::string ,int> GerenteRecursosHumanos;

    //Funcion para gerentes generales.
    if (puesto == "GERENTE GENERAL") {
        std::cout << "BIENVENIDO GERENTE, QUE DESEA HACER?" << std::endl;
        std::cout << "1. CREAR USUARIO" << std::endl;
        std::cout << "2. ELIMINAR USUARIO" << std::endl;
        std::cout << "3. EDITAR USUARIO" << std::endl;
        std::cout << "4. SALIR" << std::endl;
        std::cin >> Eleccion;
        LineasEnBlanco();

        switch (Eleccion) {
            case 1:
                // Agrega la lógica para crear usuario aquí.
                GerenteRecursosHumanos.CreacionEmpleado();
                LineasEnBlanco();
                break;
            case 2:
                // Agrega la lógica para eliminar usuario aquí.
                GerenteRecursosHumanos.BorrarEmpleado();
                LineasEnBlanco();
                break;
            case 3:
                std::cout << "3. EDITAR USUARIO" << std::endl;
                // Agrega la lógica para editar usuario aquí.
                break;
            case 4:
                std::cout << "SESION CERRADA" << std::endl;
                return;
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
        std::cout << "2. SALARIO DEL EMPLEADO " << std::endl;
        std::cout << "3. SALIR" << std::endl;
        std::cin >> Eleccion;
        LineasEnBlanco();

        switch (Eleccion) {
            case 1:
                // Funcion para mostrar horario del empleado aquí.
                if((ComparacionHorario(planta)) == 1){
                    LineasEnBlanco(); //Salto de linea para que se vea mas limpio.
                    Comparacion(puesto, planta, salario);
                }else{
                    return;
                }
                break;

            case 2:
                if((MostrarSalario(salario)) == 1){
                    LineasEnBlanco(); //Salto de linea para que se vea mas limpio.
                    Comparacion(puesto, planta, salario);
                }else{
                    return;
                }
                break;

            case 3:
                std::cout << "SESION CERRADA" << std::endl;
                return;
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
        std::cout <<"4. SALIR" << std::endl;
        std::cin >> Eleccion;
        LineasEnBlanco();

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