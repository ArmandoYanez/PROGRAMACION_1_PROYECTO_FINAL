//
// Created by Asus ROG on 18/12/2023.
//

#ifndef PROYECTO_EMPLEADOSGUADALAJARA_H
#define PROYECTO_EMPLEADOSGUADALAJARA_H

#include <iostream>
#include <string>

#include <sstream>

//Libreria con funciones extra de verificacion y otras funciones extra.
#include "FuncionesVerificacionesExtra.h"

//Creacion de 2 templates para su uso dentro de la clase.
template <typename T, typename T2>

//Creamos Clase Empleado -> Esta es la clase principal de creación.
class EmpleadoGDL {
public:
    //Constructor implicito.
    EmpleadoGDL() {
        this->Nombre = (T("N/A"));
        this->Dia = (T2(0));
        this->Mes = (T2(0));
        this->Anio = (T2(0));
        this->Cargo = (T("N/A"));
        this->Direccion = (T("N/A"));
        this->RFC = (T("N/A"));
        this->NumeroDeCuenta = (T("N/A"));
        this->NumeroDeSeguroSocial = (T2(0));
        this->Sueldo = (0);
        this->EstadoDePago = (T("El pago aún no ha sido efectuado."));
        this->Usuario = (T("N/A"));
        this->Contrasena = (T("N/A"));
        this->Sucursal = (T("N/A"));
    }

    //Constructor explicito.
    EmpleadoGDL(T Nombre, T2 Dia, T2 Mes, T2 Anio, T Cargo, T Direccion, T RFC, T2 NumeroDeCuenta,
                T2 NumeroDeSeguroSocial, float Sueldo, T EstadoDePago, T Sucursal) {
        this->Nombre = Nombre;
        this->Dia = Dia;
        this->Mes = Mes;
        this->Anio = Anio;
        this->Cargo = Cargo;
        this->Direccion = Direccion;
        this->RFC = RFC;
        this->NumeroDeCuenta = NumeroDeCuenta;
        this->NumeroDeSeguroSocial = NumeroDeSeguroSocial;
        this->Sueldo = Sueldo;
        this->EstadoDePago = ("El pago aún no ha sido efectuado.");
        this->Usuario = Usuario;
        this->Contrasena = Contrasena;
        this->Sucursal = Sucursal;
    }

    //Setter para ingresar datos del nombre.
    void SetNombre(){
        std::cout<<"NOMBRE DEL EMPLEADO:"<<std::endl;
        std::getline(std::cin >> std::ws, Nombre); //Se utiliza getline para extraer toda la infromacion de la linea y ws para limpiar buffer.
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
        std::getline(std::cin >> std::ws, Cargo); //Se utiliza getline para extraer toda la infromacion de la linea y ws para limpiar buffer.
        if(!ContieneSoloLetras(Cargo)){
            std::cout<<"ERROR AL INGRESAR EL CARGO"<<std::endl;
            SetCargo(); //Usamos la recursividad para ingresar el cargo nuevamente.
        }
    }

    //Setter para ingresar la direccion del empleado.
    void SetDireccion(){
        std::cout<<"INGRESE LA DIRECCION DEL EMPLEADO"<<std::endl;
        std::getline(std::cin >> std::ws, Direccion); //Se utiliza getline para extraer toda la infromacion de la linea y ws para limpiar buffer.
    }

    //Setter para ingresar la sucursal del empleado si el jefe lo quiere contratar.
    void SetSucursal(){
        std::cout<<"INGRESE LA SUCURSAL DEL EMPLEADO"<<std::endl<<"GUADALAJARA"<<std::endl<<"GUANAJUATO"<<std::endl<<"CDMX"<<std::endl;
        std::cin>>Sucursal;
        if(!validarSucursal(Sucursal)){
            std::cout<<"SUCURSAL NO EXISTENTE, INGRESA NUEVAMENTE:"<<std::endl;
            SetSucursal();//Usamos la recursividad para ingresar la sucursal correctamente.
        }
    }

    //Setter para ingresar sucursal en caso de que un gerente quiera crear.
    void SetSucursalGerente(T SucursalIngreso){
        Sucursal = SucursalIngreso;
    }

    //Setter para ingresar el RFC del empleado.
    void SetRFC(){
        std::cout<<"INGRESE EL RFC DEL EMPLEADO"<<std::endl;
        std::cin>>RFC;
        if(!validarLongitudRFC(RFC)){
            std::cout<<"ERROR AL INGRESAR EL RFC"<<std::endl;
            SetRFC(); //Usamos la recursividad para ingresar el cargo RFC.
        }
    }

    //Setter para ingresar el numero de cuenta.
    void SetNumeroDeCuenta(){
        std::cout<<"INGRESE EL NUMERO DE CUENTA DEL EMPLEADO" << std::endl;
        std::cin >> NumeroDeCuenta;
    }

    //Setter para ingresar el numero de seguro social.
    void SetNumeroDeSeguroSocial(){
        std::cout<<"INGRESE EL NUMERO DE SEGURO SOCIAL DEL EMPLEADO"<<std::endl;
        std::cin>>NumeroDeSeguroSocial;
    }

    //Setter para ingrsar el sueldo del empleado.
    void SetSueldo(){
        std::cout<<"INGRESE EL SUELDO DEL EMPLEADO" << std::endl;
        std::cin>>Sueldo;
    }

    //Setter para ingrsar el usuario del empleado.
    void SetUsuario(){
        std::cout<<"INGRESE EL USUARIO DEL EMPLEADO, MAXIMO 10 CARCTERES" << std::endl;
        std::cin>>Usuario;
        if(!verificarLongitudContrasenaUsuario(Usuario)){
            std::cout<<"NOMBRE DE USUARIO NO DISPONIBLE"<<std::endl;
            SetUsuario();
        }
    }

    //Setter para ingrsar la contraseña del empleado.
    void SetContrasena(){
        std::cout<<"INGRESE LA CONTRASENA DEL EMPLEADO, MAXIMO 10 CARCTERES" << std::endl;
        std::cin>>Contrasena;
        if(!verificarLongitudContrasenaUsuario(Contrasena)){
            std::cout<<"CONTRASENA NO DISPONIBLE"<<std::endl;
            SetUsuario();
        }
    }

    //Getters para retornar Nombre.
    T getNombre(){
        return this -> Nombre;
    }

    //Getters para retornar Dia.
    T2 getDia(){
        return this -> Dia;
    }

    //Getters para retornar Mes.
    T2 getMes(){
        return this -> Mes;
    }

    //Getters para retornar Anio.
    T2 getAnio(){
        return this -> Anio;
    }

    //Getters para retornar Cargo.
    T getCargo(){
        return this -> Cargo;
    }

    //Getters para retornar Dirrecion.
    T getDirreccion(){
        return this -> Direccion;
    }

    //Getters para retornar RFC.
    T getRFC(){
        return this -> RFC;
    }

    //Getters para retornar NUMERO DE CUENTA.
    T getNumeroDeCuneta(){
        return this -> NumeroDeCuenta;
    }

    //Getters para retornar Numero de seguro social.
    T2 getNumeroDeSeguroSocial(){
        return this -> NumeroDeSeguroSocial;
    }

    //Getters para retornar Sueldo.
    float getSueldo(){
        return this -> Sueldo;
    }

    //Getters para retornar Usuario.
    T getUsuario(){
        return this -> Usuario;
    }

    //Getters para retornar Contrasena.
    T getContrasena(){
        return this -> Contrasena;
    }

    //Getters para retornar sucursal.
    T getSucursal(){
        return this -> Sucursal;
    }

    //Metodo para obtener ordenadamente todos los datos listos para ser guardados
    T getDatosListos(){
        std::stringstream DatosListos; // Crear un stringstream

        // Construir la cadena de texto en el stringstream
        DatosListos << getNombre() << "," << getDia() << "," << getMes() << "," << getAnio() << "," << getCargo() << "," << getDirreccion() << "," << getRFC() << "," << getNumeroDeCuneta() << "," << getNumeroDeSeguroSocial() << "," << getSueldo() << "," << getUsuario() << "," << getContrasena() << "," << getSucursal() << "\n";

        return DatosListos.str(); // Obtener la cadena de texto del stringstream
    }

    //Funcion para guardar datos a bd.
     void CargarDatosBaseDeDatos(){
        std::ofstream outfile("BaseDeDatos.csv", std::ios::app); // Modo de apertura para agregar datos al final del archivo

        if (outfile.is_open()) {
            outfile << getDatosListos();
            outfile.close();
        } else {
            std::cout << "No se pudo abrir el archivo BaseDeDatos.csv" << std::endl;
        }
    }

    //Setter conjunto para creacion de empleado.
    void SetCrear(T SucursalRegistro){
        SetNombre();
        SetDia();
        SetMes();
        SetAnio();
        SetDireccion();
        SetSucursalGerente(SucursalRegistro);
        SetRFC();
        SetNumeroDeCuenta();
        SetNumeroDeSeguroSocial();
        SetCargo();
        SetSueldo();
        SetUsuario();
        SetContrasena();
        CargarDatosBaseDeDatos();
    }



private:
    T Nombre, EstadoDePago, Usuario, Contrasena;
    T2 Dia, Mes, Anio;
    T Cargo, Direccion, RFC, NumeroDeCuenta, Sucursal;
    T2 NumeroDeSeguroSocial;
    float Sueldo;
};

//Creacion de 2 templates para su uso dentro de la clase.
template <typename T, typename T2>

//Creacion de la clase Jefe.
class GerenteRecursosHumanos : public EmpleadoGDL<std::string, int> {
public:
    // Constructor implicito
    GerenteRecursosHumanos() : EmpleadoGDL<std::string, int>() {

    }

    // Constructor explicito
    GerenteRecursosHumanos(T Nombre, T2 Dia, T2 Mes, T2 Anio, T Cargo, T Direccion, T RFC, T2 NumeroDeCuenta, T2 NumeroDeSeguroSocial,
         float Sueldo, T EstadoDePago, T Sucursal):
         EmpleadoGDL<std::string, int>(Nombre, Dia,Mes, Anio, Cargo, Direccion,RFC, NumeroDeCuenta, NumeroDeSeguroSocial, Sueldo, EstadoDePago, Sucursal) {
    }

    // Se creo el metodo de creacion para la creacion de empleados comunes sin acceso a la plataforma.
    EmpleadoGDL<std::string, int> CreacionEmpleadoGDL(){
        EmpleadoGDL<std::string, int> EmpleadoNuevo;
        std::cout<<"BIENVENIDO GERENTE, PARA CREAR UN EMPLEADO COMPLETE LA SIGUIENTE INFORMACION:"<<std::endl;

        //Funcion para crear un nuevo usuario.
        EmpleadoNuevo.SetCrear(Sucursal); //Se le agrega la sucursal del gerente ya que sera registrado en esa misma sucursal.
        std::cout<<"USUARIO REGISTRADO EXITOSAMENTE."<<std::endl;

        return EmpleadoNuevo;
    }

    // Se crea metodo para busqueda y edicion de empleados.
    void EditarDatos(){
        // Se crea cadena para guardar el nombre que el usuario quiera ingresar.
        std::string Usuario;
        std::cout << "INGRESE EL USUARIO DEL EMPLEADO A EDITAR:" << std::endl;
        std::cin >> Usuario;

        std::string nombreArchivo = "BaseDeDatos.csv";
        std::ifstream archivoEntrada(nombreArchivo);
        if (!archivoEntrada) {
            std::cout << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
            return; // Salir de la función si no se pudo abrir el archivo
        }

        std::vector<std::string> lineasArchivo;
        std::string linea;
        while (std::getline(archivoEntrada, linea)) {
            std::stringstream ss(linea);
            std::string campo;
            std::vector<std::string> campos;

            while (std::getline(ss, campo, ',')) {
                campos.push_back(campo);
            }

            // Comprobación si el nombre de usuario está en la columna correspondiente (por ejemplo, en la posición 1)
            if (campos.size() > 1 && campos[10] == Usuario) {
                std::cout << "El usuario se encuentra en la linea: " << linea << std::endl;
                // Realizar aquí las modificaciones en los datos según sea necesario

                // Por ejemplo, puedes modificar el nombre del usuario en la línea actual:
                // campos[1] = nuevoNombreUsuario;

                // Luego, reconstruye la línea con los campos modificados
                std::stringstream nuevaLinea;
                for (const auto& campo : campos) {
                    nuevaLinea << campo << ",";
                }
                std::string nuevaLineaStr = nuevaLinea.str();
                nuevaLineaStr.pop_back(); // Eliminar la última coma

                lineasArchivo.push_back(nuevaLineaStr);
            } else {
                lineasArchivo.push_back(linea);
            }
        }
        archivoEntrada.close();

        // Ahora, escribe las líneas modificadas de nuevo al archivo
        std::ofstream archivoSalida(nombreArchivo);
        if (!archivoSalida) {
            std::cout << "No se pudo abrir el archivo de salida: " << nombreArchivo << std::endl;
            return;
        }

        for (const auto& linea : lineasArchivo) {
            archivoSalida << linea << std::endl;
        }
        archivoSalida.close();
    }

private:
    T Nombre, EstadoDePago, Usuario, Contrasena;
    T2 Dia, Mes, Anio;
    T Cargo, Direccion, RFC, NumeroDeCuenta, Sucursal;
    T2 NumeroDeSeguroSocial;
    float Sueldo;
};

#endif //PROYECTO_EMPLEADOSGUADALAJARA_H
