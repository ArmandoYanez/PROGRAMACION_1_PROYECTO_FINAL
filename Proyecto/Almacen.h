#ifndef PROYECTO_ALMACEN_H
#define PROYECTO_ALMACEN_H

#include <iostream>
#include <string>
#include <vector>

#include <sstream>

//Template para poder usarlo en la clase
template <typename X,typename X2>

//Creacion de la clase para tener un inventario
class Inventario{
public:
    //Constructor Implicito
    Inventario(){
        this -> Id = (X("N/A"));
        this -> Cantidad = (X("N/A"));
        this -> Planta = (X2("N/A"));
        this -> Nombre = (X2("N/A"));
        this -> Ciudad = (X2("N/A"));
    }

    //Constructor Explicito
    Inventario(X Id, X Cantidad, X2 Planta, X2 Nombre, X2 Ciudad){
        this -> Id = Id;
        this -> Cantidad = Cantidad;
        this -> Planta = Planta;
        this -> Nombre = Nombre;
        this -> Ciudad = Ciudad;
    }

    //Uso de set para poder agregar al inventario
    void SetNombre (){
        std::cout << "QUE DESEA AGREGAR AL INVENTARIO?" << std::endl;

        std::cin >> Nombre;
    }
    void SetCiudad (){
        std::cout << "EN QUE CIUDAD DESEA AGREGAR EL PRODUCTO" << std::endl;

        std::cin >> Ciudad;
    }
    void SetCantidad (){
        std::cout << "QUE CANTIDAD DE " << Nombre << " DESEA AGREGAR" << std::endl;

        std::cin >> Cantidad;
    }
    void SetPlanta (){
        std::cout << "EN QUE PLANTA DESEA AGREGARLOS" << std::endl;

        std::cin >> Planta;
    }
    void SetId (){
        std::cout << "EL ID DEL PRODUCTO/S ES " << Id << std::endl;
        for (X i = 0 ; i = Cantidad ; ++i) {
            i = Id;
            std::cout << "EL ID DE SU PRODUCTO ES " << Id << std::endl;
        }
    }

    //Uso de get para poder rellenar el inventario
    X getId(){
        return this -> Id;
    }
    X getCantidad(){
        return this -> Cantidad;
    }
    X2 getPlanta(){
        return this -> Planta;
    }
    X2 getNombre(){
        return this -> Nombre;
    }
    X2 getCiudad(){
        return this -> Ciudad;
    }


private:
    X Id, Cantidad;
    X2 Planta, Nombre, Ciudad;
};

#endif //PROYECTO_ALMACEN_H
