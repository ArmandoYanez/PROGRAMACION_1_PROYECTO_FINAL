// Created by Armando Yañez on 14/12/2023.
#include <iostream>
#include <string>

//Libreria para comprobar tipo de dato.
#include <type_traits>

//Libreria para comprobar si dentro de un string se ponen numeros.
#include <cctype>

// Función para verificar si una variable es entera.
template<typename T>
bool EsEntero(const T& var) {
    return std::is_integral<T>::value;
}

// Función para verificar si se pone un numero dentro de un string.
bool ContieneSoloLetras(const std::string& texto) {
    for (char caracter : texto) {
        if (!std::isalpha(caracter)) {
            return false; // Si se encuentra un carácter que no es una letra, devuelve falso.
        }
    }
    return true; // Si todos los caracteres son letras, devuelve verdadero.
}

// Verificacion de 2 digitos en un entero.
bool TieneDosDigitos(int numero) {
    // Se verifica si el número está en el rango de dos dígitos (10 a 31) esto para verificar dia de nacimiento.
    return (numero >= 01  && numero <= 31);
}

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
    }

    //Constructor explicito.
    Empleado(T Nombre, T2 Dia, T2 Mes, T2 Anio, T Cargo, T Direccion, T RFC, T2 NumeroDeCuenta,
             T2 NumeroDeSeguroSocial) {
        this->Nombre = Nombre;
        this->Dia = Dia;
        this->Mes = Mes;
        this->Anio = Anio;
        this->Cargo = Cargo;
        this->Direccion = Direccion;
        this->RFC = RFC;
        this->NumeroDeCuenta = NumeroDeCuenta;
        this->NumeroDeSeguroSocial = NumeroDeSeguroSocial;
    }

    void SetNombre(){
        std::cout<<"NOMBRE DEL EMPLEADO:"<<std::endl;
        std::cin>>Nombre;
        if(!ContieneSoloLetras(Nombre)){
            std::cout<<"ERROR AL INGRESAR EL NOMBRE"<<std::endl;
            SetNombre(); //Usamos la recursividad para ingresar el nombre nuevamente
        }
    }

    void SetDia(){
        std::cout<<"INGRESA DIA DE NACIMIENTO CON 2 DIGITOS:"<<std::endl;
        std::cin>>Dia;
        if(!TieneDosDigitos(Dia)){
            std::cout<<"ERROR AL INGRESAR EL DIA, EJEMPLO:(02)"<<std::endl;
            SetDia(); //Usamos la recursividad para ingresar el dia nuevamente
        }
    }

private:
    T Nombre;
    T2 Dia, Mes, Anio;
    T Cargo, Direccion, RFC;
    T2 NumeroDeCuenta, NumeroDeSeguroSocial;
};

int main(){

    Empleado<std::string,int> EmpleadoUno;
    EmpleadoUno.SetNombre();
    EmpleadoUno.SetDia();
    return 0;
}