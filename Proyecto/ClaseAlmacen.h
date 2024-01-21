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
        this -> Id = (T2(0));
        this -> Cantidad = (T2(0));
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

    //Uso de set para nombre
    void SetNombre() {
        std::cout << "PRODUCTA A AGREGAR AL INVENTARIO: ";
        std::cin >> Nombre;
    }
    //Uso de set para ciudad
    void SetCiudad() {
        std::cout << "CIUDAD: ";
        std::cin >> Ciudad;
    }
    //Uso de set para cantidad
    void SetCantidad() {
        std::cout << "CANTIDAD DE " << Nombre << ": ";
        std::cin >> Cantidad;
    }
    //Uso de set para planta
    void SetPlanta() {
        std::cout << "PLANTA(GDL, CDMX, GTO): ";
        std::cin >> Planta;
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
};


#endif //PROYECTO_CLASEALMACEN_H