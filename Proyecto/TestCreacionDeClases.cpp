// Created by Armando Yañez on 14/12/2023.
#include <iostream>
#include <string>
#include <vector>

//Libreria con funciones extra de verificacion y otras funciones extra.
#include "FuncionesVerificacionesExtra.h"

//Creacion de 2 templates para su uso dentro de la clase.
template <typename T, typename T2>

//Creamos Clase Empleado -> Esta es la clase principal de creación.
class Empleado {
public:
    //Constructor implicito.
    Empleado() {
        this->Nombre = (T("N/A"));
        this->Dia = (T2(0));
        this->Mes = (T2(0));
        this->Anio = (T2(0));
        this->Cargo = (T("N/A"));
        this->Direccion = (T("N/A"));
        this->RFC = (T("N/A"));
        this->NumeroDeCuenta = (T2(0));
        this->NumeroDeSeguroSocial = (T2(0));
        this->Sucursal = (T("N/A"));
        this->Sueldo = (0);
        this->EstadoDePago = (T("El pago aún no ha sido efectuado."));
    }

    //Constructor explicito.
    Empleado(T Nombre, T2 Dia, T2 Mes, T2 Anio, T Cargo, T Direccion, T RFC, T2 NumeroDeCuenta,
             T2 NumeroDeSeguroSocial, T Sucursal, float Sueldo, T EstadoDePago) {
        this->Nombre = Nombre;
        this->Dia = Dia;
        this->Mes = Mes;
        this->Anio = Anio;
        this->Cargo = Cargo;
        this->Direccion = Direccion;
        this->RFC = RFC;
        this->NumeroDeCuenta = NumeroDeCuenta;
        this->NumeroDeSeguroSocial = NumeroDeSeguroSocial;
        this->Sucursal = Sucursal;
        this-> Sueldo = Sueldo;
        this->EstadoDePago = ("El pago aún no ha sido efectuado.");
    }

    //Setter para ingresar datos del nombre.
    void SetNombre(){
        std::cout<<"NOMBRE DEL EMPLEADO:"<<std::endl;
        std::cin>>Nombre;
        if(!ContieneSoloLetras(Nombre)){
            std::cout<<"ERROR AL INGRESAR EL NOMBRE"<<std::endl;
            SetNombre(); //Usamos la recursividad para ingresar el nombre nuevamente.
        }
    }

    //Setter para ingresar datos del dia de nacimiento.
    void SetDia(){
        std::cout<<"INGRESA DIA DE NACIMIENTO CON DOS DIGITOS:"<<std::endl;
        std::cin>>Dia;
        if(!TieneDosDigitos(Dia)){
            std::cout<<"ERROR AL INGRESAR EL DIA, EJEMPLO:(02)"<<std::endl;
            SetDia(); //Usamos la recursividad para ingresar el dia nuevamente.
        }
    }

    //Setter para ingresar datos del mes de nacimiento.
    void SetMes(){
        std::cout<<"INGRESA EL MES DE NACIMIENTO CON DOS DIGITOS:"<<std::endl;
        std::cin>>Mes;
        if(!TieneDosDigitos(Mes)){
            std::cout<<"ERROR AL INGRESAR EL MES, EJEMPLO:(09)"<<std::endl;
            SetMes(); //Usamos la recursividad para ingresar el mes nuevamente.
        }

    }

    //Setter para ingresar datos del año de nacimiento.
    void SetAnio(){
        std::cout<<"INGRESA EL ANIO DE NACIMIENTO CON CUATRO DIGITOS:"<<std::endl;
        std::cin>>Anio;
        if(!TieneCuatroDigitos(Anio)){
            std::cout<<"ERROR AL INGRESAR EL ANIO, EJEMPLO:(1982)"<<std::endl;
            SetAnio(); //Usamos la recursividad para ingresar el año nuevamente.
        }
    }

    //Setter para ingresar el cargo del empleado.
    void SetCargo(){
        std::cout<<"INGRESE EL CARGO DEL EMPLEADO"<<std::endl;
        std::cin>>Cargo;
        if(!ContieneSoloLetras(Cargo)){
            std::cout<<"ERROR AL INGRESAR EL CARGO"<<std::endl;
            SetCargo(); //Usamos la recursividad para ingresar el cargo nuevamente.
        }
    }

    //Setter para ingresar la direccion del empleado.
    void SetDireccion(){
        std::cout<<"INGRESE LA DIRECCION DEL EMPLEADO"<<std::endl;
        std::cin>>Direccion;
    }

    //Setter para ingresar el RFC del empleado.
    void SetRFC(){
        std::cout<<"INGRESE EL RFC DEL EMPLEADO"<<std::endl;
        std::cin>>RFC;
        if(!validarLongitudRFC(RFC)){
            std::cout<<"ERROR AL INGRESAR EL RFC"<<std::endl;
            SetRFC(); //Usamos la recursividad para ingresar el cargo RFC
        }
    }

    //Setter para ingresar el numero de cuenta.
    void SetNumeroDeCuenta() {
        std::cout<<"INGRESE EL NUMERO DE CUENTA DEL EMPLEADO" << std::endl;
        std::cin >> NumeroDeCuenta;
    }

    //Setter para ingresar el numero de seguro social.
    void SetNumeroDeSeguroSocial(){
        std::cout<<"INGRESE EL NUMERO DE SEGURO SOCIAL DEL EMPLEADO"<<std::endl;
        std::cin>>NumeroDeSeguroSocial;
    }

    //Setter para ingresar la scurusal del empleado.
    void SetSucursal(){
        std::cout<<"TECLEE LA SUCURSAL DEL EMPLEADO:"<<std::endl<<"* GUADALAJARA"<<std::endl<<"* ZARAGOZA"<<std::endl<<"* CDMX"<<std::endl;
        std::cin>>Sucursal;
        if(!validarSucursal(Sucursal)){
            std::cout<<"SUCURSAL NO DISPONIBLE"<<std::endl;
            SetSucursal();
        }
    }

    //Setter para ingrsar el sueldo del empleado.
    void SetSueldo(){
        std::cout<<"INGRESE EL SUELDO DEL EMPLEADO" << std::endl;
        std::cin>>Sueldo;
    }

private:
    T Nombre, Sucursal, EstadoDePago;
    T2 Dia, Mes, Anio;
    T Cargo, Direccion, RFC;
    T2 NumeroDeCuenta, NumeroDeSeguroSocial;
    float Sueldo;
};


//Creacion de 2 templates para su uso dentro de la clase.
template <typename T, typename T2>

class Jefe : public Empleado<T, T2>{
public:
    //Constructor implicito.
    Jefe(){
        this->Cargo = "Jefe";
    }

    //Constructor explicito.
    Jefe(T Nombre, T2 Dia, T2 Mes, T2 Anio, T Cargo, T Direccion, T RFC, T2 NumeroDeCuenta,
            T2 NumeroDeSeguroSocial, T Sucursal, float Sueldo) : Empleado<T, T2>(Nombre, Dia, Mes, Anio, Cargo, Direccion, RFC, NumeroDeCuenta,
             NumeroDeSeguroSocial, Sucursal, Sueldo){
        this->Cargo = "Jefe";
    }
};

int main(){

    Empleado<std::string,int> EmpleadoUno;
    EmpleadoUno.SetNombre();
    EmpleadoUno.SetDia();
    EmpleadoUno.SetMes();
    EmpleadoUno.SetAnio();
    EmpleadoUno.SetSucursal();
    return 0;
}
