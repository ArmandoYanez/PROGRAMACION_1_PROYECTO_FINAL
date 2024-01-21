// Created by Armando Yañez on 14/12/2023.
#include <string>


//Libreria para la creacion de empleados de guadalajara
#include "ClaseEmpleados.h"
#include "FuncionesVerificacionesExtra.h"
#include "Login.h"
int main(){

    GenerarArchivo();
    Login();

    GerenteGeneral<std::string ,int> GerenteRecursosHumanos;
    GerenteRecursosHumanos.EditarDatos();

    return 0;
}
