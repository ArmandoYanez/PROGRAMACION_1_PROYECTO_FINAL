//
// Created by Asus ROG on 18/01/2024.
//

#ifndef PROYECTO_FUNCIONESPARAEMPLEADOS_H
#define PROYECTO_FUNCIONESPARAEMPLEADOS_H
#include <iostream>


void HorarioGDl(){
std::cout << "LUNES: 8:00 AM - 7:00 PM" << std::endl;
std::cout << "MARTES: 8:OO AM - 7:00 PM" << std::endl;
std::cout << "MIERCOLES 8.00 AM - 6:00 PM" << std::endl;
std::cout << "JUEVES 8:00 AM - 6:O0 PM" << std::endl;
std::cout << "VIERNES 8:OO AM - 6:00 PM" << std::endl;
std::cout << "SABADO 8:00 AM - 2:00 PM" << std::endl;
std::cout << "Domingo DIA LIBRE" << std::endl;
}
void HorarioCDMX(){
    std::cout << "LUNES: 6:00 AM - 5:00 PM" << std::endl;
    std::cout << "MARTES: 6:OO AM - 5:00 PM" << std::endl;
    std::cout << "MIERCOLES 6:00 AM - 4:00 PM" << std::endl;
    std::cout << "JUEVES 6:00 AM - 4:O0 PM" << std::endl;
    std::cout << "VIERNES 6:OO AM - 4:00 PM" << std::endl;
    std::cout << "SABADO 6:00 AM - 12:00 PM" << std::endl;
    std::cout << "Domingo DIA LIBRE" << std::endl;
}
void HorarioGTO(){
    std::cout << "LUNES: 9:00 AM - 5:00 PM" << std::endl;
    std::cout << "MARTES: 9:OO AM - 5:00 PM" << std::endl;
    std::cout << "MIERCOLES 9:00 AM - 4:00 PM" << std::endl;
    std::cout << "JUEVES 9:00 AM - 4:O0 PM" << std::endl;
    std::cout << "VIERNES 9:OO AM - 4:00 PM" << std::endl;
    std::cout << "SABADO 9:00 AM - 12:00 PM" << std::endl;
    std::cout << "Domingo DIA LIBRE" << std::endl;
}

void ComparacionHorario(std::string planta){
    if (planta == "GDL"){
        HorarioGDl();
    }

    if (planta == "CDMX"){
        HorarioCDMX();
    }

    if (planta == "GTO"){
        HorarioGTO();
    }

}

#endif //PROYECTO_FUNCIONESPARAEMPLEADOS_H
