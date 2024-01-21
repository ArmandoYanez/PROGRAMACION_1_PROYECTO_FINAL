#ifndef PROYECTO_MENUS_H
#define PROYECTO_MENUS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "FuncionesParaEmpleados.h"


//Funcion para comprar el puesto de los empleados.
void Comparacion(std::string puesto, std::string planta, std::string salario) {

    int Eleccion;
    GerenteGeneral<std::string ,int> GerenteGeneral; //Objeto gerente general.
    Jefe<std::string ,int> Jefe; //Objeto Jefe.
    GerenteAlmacen<std::string, int> GerenteAlmacen;

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
                // Opcion para crear un empleado siendo gerente.
                GerenteGeneral.CreacionEmpleado(planta);
                if(OpecionDeRetorno() == 1){
                    LineasEnBlanco(); //Funcion para saltar lineas.
                    Comparacion(puesto, planta, salario);
                }
                LineasEnBlanco();
                break;

            case 2:
                // Opcion para eliminar usuario siendo gerente.
                GerenteGeneral.BorrarEmpleado();
                if(OpecionDeRetorno() == 1){
                    LineasEnBlanco(); //Funcion para saltar lineas.
                    Comparacion(puesto, planta, salario);
                }
                LineasEnBlanco();
                break;

            case 3:
                // Opcion para eliminar usuario siendo gerente.
                GerenteGeneral.EditarDatos();
                if(OpecionDeRetorno() == 1){
                    LineasEnBlanco(); //Funcion para saltar lineas.
                    Comparacion(puesto, planta, salario);
                }
                LineasEnBlanco();
                break;

            case 4:
                //Se cierra la sesion y vuelve al login.
                std::cout << "SESION CERRADA" << std::endl;
                return;
                break;

            default:
                std::cout << "OPCION NO VALIDA" << std::endl;
                Comparacion(puesto, planta, salario);
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
                // Funcion para mostrar horario del empleado + pregunta de volver a hacer algo.
                if((ComparacionHorario(planta)) == 1){
                    LineasEnBlanco(); //Salto de linea para que se vea mas limpio.
                    Comparacion(puesto, planta, salario);
                }else{
                    return;
                }
                break;

            case 2:
                //Sistema para mostrar salario del empleado + pregunta de volver a hacer algo.
                if((MostrarSalario(salario)) == 1){
                    LineasEnBlanco(); //Salto de linea para que se vea mas limpio.
                    Comparacion(puesto, planta, salario);
                }else{
                    return;
                }
                break;

            case 3:
                //Se cierra la sesion y vuelve al login.
                std::cout << "SESION CERRADA" << std::endl;
                return;
                break;

            default:
                std::cout << "OPCION NO VALIDA" << std::endl;
                Comparacion(puesto, planta, salario);
                break;
        }
    }

    else if (puesto == "GERENTE ALMACEN") {
        std::cout << "BIENVENIDO GERENTE DE ALMACEN, QUE DESEA HACER?" << std::endl;
        std::cout << "1. AGREGAR PRODUCTO" << std::endl; //Hacer un vector que agrege la info de el objeto producto.
        std::cout << "2. BORRAR PRODUCTO" << std::endl; //Buscar por id, y eleminar vector.
        std::cout << "3. MOVER PRODUCTO" << std::endl; //Buscar y cambiar el dato de "ciudad o planta"
        std::cout << "4. SALIR" << std::endl;
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
                // Opcion para eliminar usuario siendo gerente.

                break;

            case 4:
                //Se cierra la sesion y vuelve al login.
                std::cout << "SESION CERRADA" << std::endl;
                return;
                break;

            default:
                std::cout << "OPCION NO VALIDA" << std::endl;
                Comparacion(puesto, planta, salario);
                break;
        }
}
    else if (puesto == "JEFE") {
        std::cout << "BIENVENIDO JEFE, QUE DESEA HACER?" << std::endl;
        std::cout << "1. CREAR GERENTE" << std::endl;
        std::cout << "2. CREAR EMPLEADO" << std::endl;
        std::cout << "3. DESPEDIR PERSONAL" << std::endl;
        std::cout << "4. MODIFICAR DATOS DE UN EMPLEADO" << std::endl;
        std::cout << "5. SALIR" << std::endl;
        std::cin >> Eleccion;
        LineasEnBlanco();

        switch (Eleccion) {
            case 1:
                //Funcion para crear gerente.
                Jefe.CreacionGerente();
                if(OpecionDeRetorno() == 1){
                    LineasEnBlanco(); //Funcion para saltar lineas.
                    Comparacion(puesto, planta, salario);
                }
                LineasEnBlanco();
                break;

            case 2:
                //Funcion para crear empleado común sinedo jefe.
                Jefe.CreacionEmpleadoJefe();
                if(OpecionDeRetorno() == 1){
                    LineasEnBlanco(); //Funcion para saltar lineas.
                    Comparacion(puesto, planta, salario);
                }
                LineasEnBlanco();
                break;

            case 3:
                //Se utiliza la funcion del gerente para borrar datos.
                GerenteGeneral.BorrarEmpleado();
                if (OpecionDeRetorno() == 1) {
                    LineasEnBlanco(); //Funcion para saltar lineas.
                    Comparacion(puesto, planta, salario);
                }
                LineasEnBlanco();
                break;

            case 4:
                //Se utiliza la funcion del gerente para editar datos.
                GerenteGeneral.EditarDatos();
                if (OpecionDeRetorno() == 1) {
                    LineasEnBlanco(); //Funcion para saltar lineas.
                    Comparacion(puesto, planta, salario);
                }
                LineasEnBlanco();
                break;

            case 5:
                //Se cierra la sesion y vuelve al login.
                std::cout<<"SECION CERRADA"<<std::endl;
                break;

            default:
                std::cout << "OPCION NO VALIDA" << std::endl;
                Comparacion(puesto, planta, salario);
                break;
        }
    }
}
#endif //PROYECTO_MENUS_H