//
// Created by Asus ROG on 18/12/2023.
//

#ifndef PROYECTO_FUNCIONESVERIFICACIONESEXTRA_H
#define PROYECTO_FUNCIONESVERIFICACIONESEXTRA_H

#include <iostream>
#include <string>

#include <fstream> //Para la creacion de archivos csv.

#include <algorithm> // Se utiliza la función transform.

//Libreria para comprobar si dentro de un string se ponen numeros.
#include <cctype>



// Función para crear archivo csv
void GenerarArchivo(){
    // Crear archivo csv
        std::ifstream file("BaseDeDatos.csv");
        if (!file.good()) { //En caso de que no se pueda leer, el archivo no existe.
            std::ofstream outfile("BaseDeDatos.csv"); //se crea un nuevo archivo.
            outfile.close();
        }
}

//Funcion en caso de que este vacio el archivo csv.
bool VerificarArchivoVacio() {
    std::string nombreArchivo = "BaseDeDatos.csv";
    std::ifstream archivoEntrada(nombreArchivo);
    return archivoEntrada.peek() == std::ifstream::traits_type::eof(); //En caso de que este vacio retorna un valor positivo.
}

// Función para verificar si se pone un numero dentro de un string.
bool ContieneSoloLetras(std::string texto) {
    for (char caracter : texto) {
        if (!std::isalpha(caracter) && !std::isspace(caracter)) {
            return false; // Si se encuentra un carácter que no es una letra, devuelve falso.
        }
    }
    return true; // Si todos los caracteres son letras, devuelve verdadero.
}

// Verificacion de 2 digitos en un entero.
bool TieneDosDigitos(int numero) {
    // Se verifica si el número está en el rango de dos dígitos (10 a 31) esto para verificar dia y mes de nacimiento.
    return (numero >= 01  && numero <= 31);
}

// Verificacion de 4 digitos en un entero.
bool TieneCuatroDigitos(int numero) {
    // Se verifica si el número está en el rango de dos dígitos (1800 a 2024) esto para verificar año de nacimiento.
    return (numero >= 1800  && numero <= 2024);
}

//Verificacion de tamaño de carcateres de un RFC.
bool validarLongitudRFC(std::string rfc) {
    return rfc.length() == 13;
}

//Verificacion de sucursales disponibles.
bool validarSucursal(std::string Sucursal) {
    // Se utiliza el transforma para convertir en minusculas el texto ingresado y comparar
    std::transform(Sucursal.begin(), Sucursal.end(), Sucursal.begin(), ::tolower);
    if (Sucursal == "guadalajara" || Sucursal == "zaragoza" || Sucursal == "cdmx"){
        return true;
    }else{
        return false;
    }
}

//Verificacion de longitud de contraseña y usuario.
bool verificarLongitudContrasenaUsuario(const std::string& cadena) {
    return cadena.length() <= 10;
}

//Conversion a mayusculas de cualquier cadena.
std::string convertirAMayusculas(const std::string& str) {
    std::string resultado;

    for (char c : str) {
        resultado += std::toupper(c);
    }

    return resultado;
}

// Hace 25 saltos de linea.
void LineasEnBlanco() {
    for (int i = 0; i < 25; ++i) {
        std::cout << std::endl;
    }
    // Resto del código
}

bool OpecionDeRetorno(){
    //Pregunta de cambio de flujo, seguir en la sesión o salir.
    int Opcion;
    std::cout<<"DESEA HACER OTRA OPERACION?"<<std::endl<<"1-Si"<<std::endl<<"2-No"<<std::endl;
    std::cin>>Opcion;

    if(Opcion == 1){
        return 1;
    } else{
        return 0;
    }
}

#endif //PROYECTO_FUNCIONESVERIFICACIONESEXTRA_H
