#ifndef PROYECTO_ALMACEN_H
#define PROYECTO_ALMACEN_H

#include <iostream>
#include <string>

#include <sstream>

//Template para poder usarlo en la clase
template <typename X,typename X2>

//Creacion de la clase para tener un inventario
class Inventario{
public:
    //Constructor Implicito
    Inventario(){
        this -> id = (X("N/A"));
        this -> cantidad = (X("N/A"));
        this -> planta = (X2("N/A"));
        this -> nombre = (X2("N/A"));
    }

    //Constructor Explicito
    Inventario(X Id, X Cantidad, X2 Planta, X2 Nombre){
        this -> Id = Id;
        this -> Cantidad = Cantidad;
        this -> Planta = Planta;
        this -> Nombre = Nombre;
    }

    //Uso de set para poder agregar al inventario
    void SetNombre (){
        std::cout << "QUE DESEA AGREGAR AL INVENTARIO?" << std::endl;

        std::cin >> Nombre;
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


private:
    X Id, Cantidad;
    X2 Planta, Nombre;
};

#endif //PROYECTO_ALMACEN_H
