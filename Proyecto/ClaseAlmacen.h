#ifndef PROYECTO_CLASEALMACEN_H
#define PROYECTO_CLASEALMACEN_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T, typename T2>
class AgregarAInventario {
public:
//Constructor Implicito
    AgregarAInventario(){
        this -> Id = (T2("N/A"));
        this -> Cantidad = (T2("N/A"));
        this -> Planta = (T("N/A"));
        this -> Nombre = (T("N/A"));
        this -> Ciudad = (T("N/A"));
    }

//Constructor Explicito
    AgregarAInventario(T2 Id, T2 Cantidad, T Planta, T Nombre, T Ciudad){
        this -> Id = Id;
        this -> Cantidad = Cantidad;
        this -> Planta = Planta;
        this -> Nombre = Nombre;
        this -> Ciudad = Ciudad;
    }

    //Uso de set para agregar
    void SetNombre() {
        std::cout << "PRODUCTA A AGREGAR AL INVENTARIO: ";
        std::cin >> Nombre;
    }

    void SetCiudad() {
        std::cout << "CIUDAD: ";
        std::cin >> Ciudad;
    }

    void SetCantidad() {
        std::cout << "CANTIDAD DE " << Nombre << ": ";
        std::cin >> Cantidad;
    }

    void SetPlanta() {
        std::cout << "PLANTA(GDL, CDMX, GTO): ";
        std::cin >> Planta;
    }

    AgregarAInventario<T,T2> SetCrearProducto() {
    AgregarAInventario<T,T2> retorno;

    retorno.SetNombre();
    retorno.SetCiudad();
    retorno.SetCantidad();
    retorno.SetPlanta();
    return retorno;
    }

    //Uso de get para retornar
    T2 getId() { return Id; }
    T2 getCantidad() { return Cantidad; }
    T getPlanta() { return Planta; }
    T getNombre() { return Nombre; }
    T getCiudad() { return Ciudad; }

private:
    T2 Id, Cantidad;
    T Planta, Nombre, Ciudad;
    std::vector<AgregarAInventario<T, T2>> inventario;
};


#endif //PROYECTO_CLASEALMACEN_H