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
        this -> Id = (T("N/A"));
        this -> Cantidad = (T("N/A"));
        this -> Planta = (T2("N/A"));
        this -> Nombre = (T2("N/A"));
        this -> Ciudad = (T2("N/A"));
    }

//Constructor Explicito
    AgregarAInventario(T Id, T Cantidad, T2 Planta, T2 Nombre, T2 Ciudad){
        this -> Id = Id;
        this -> Cantidad = Cantidad;
        this -> Planta = Planta;
        this -> Nombre = Nombre;
        this -> Ciudad = Ciudad;
    }

    //Uso de set para agregar
    void SetNombre() {
        std::cout << "¿Qué desea agregar al inventario?" << std::endl;
        std::cin >> Nombre;
    }

    void SetCiudad() {
        std::cout << "¿En qué ciudad desea agregar el producto?" << std::endl;
        std::cin >> Ciudad;
    }

    void SetCantidad() {
        std::cout << "¿Qué cantidad de " << Nombre << " desea agregar?" << std::endl;
        std::cin >> Cantidad;
    }

    void SetPlanta() {
        std::cout << "¿En qué planta desea agregarlos?(GDL, CDMX, GTO)" << std::endl;
        std::cin >> Planta;
    }

    void SetId() {
        std::cout << "El ID del producto es " << Id << std::endl;
        for (T i = 0; i < Cantidad; ++i) {
            i = Id;
            std::cout << "El ID de su producto es " << Id << std::endl;
        }
    }

    //Metodo para eliminar por ID
    void EliminarPorId(T id) {
        inventario.erase(
                std::remove_if(inventario.begin(), inventario.end(),
                               [id](const AgregarAInventario<T, T2>& elemento) {
                                   return elemento.getId() == id;
                               }),
                inventario.end());
    }

    //Metodo para Modificar por ID
    void ModificarCiudadPlantaPorId(T id, T2 nuevaCiudad, T2 nuevaPlanta) {
        auto it = std::find_if(inventario.begin(), inventario.end(),
                               [id](const AgregarAInventario<T, T2>& elemento) {
                                   return elemento.getId() == id;
                               });

        if (it != inventario.end()) {
            // Se encontró el elemento con el ID, ahora se modifican ciudad y planta
            it->Ciudad = nuevaCiudad;
            it->Planta = nuevaPlanta;
        } else {
            std::cout << "Elemento con ID " << id << " no encontrado." << std::endl;
        }
    }

    //Uso de get para retornar
    T getId() { return Id; }
    T getCantidad() { return Cantidad; }
    T2 getPlanta() { return Planta; }
    T2 getNombre() { return Nombre; }
    T2 getCiudad() { return Ciudad; }

private:
    T Id, Cantidad;
    T2 Planta, Nombre, Ciudad;
    std::vector<AgregarAInventario<T, T2>> inventario;
};


#endif //PROYECTO_CLASEALMACEN_H