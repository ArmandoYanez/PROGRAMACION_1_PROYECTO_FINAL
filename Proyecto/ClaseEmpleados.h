//
// Created by Asus ROG on 18/12/2023.
//

#ifndef PROYECTO_CLASEEMPLEADOS_H
#define PROYECTO_CLASEEMPLEADOS_H

#include <iostream>
#include <string>

#include <sstream>

//Libreria con funciones extra de verificacion y otras funciones extra.
#include "FuncionesVerificacionesExtra.h"

#include "ClaseAlmacen.h"

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
        int eleccion;
        std::cout<<"INGRESE EL CARGO DEL EMPLEADO"<<std::endl<<"1- GERENTE ALMACEN"<<std::endl<<"2- EMPLEADO"<<std::endl;
        std::cin>>eleccion;

        switch (eleccion) {
            case 1:
                Cargo = "ENCARGADO ALMACEN";
                break;
            case 2:
                Cargo = "EMPLEADO";
                break;
            default:
                std::cout<<"PUESTO NO DISPONIBLE"<<std::endl;
                SetCargo(); //Usamos la recursividad para ingresar el cargo nuevamente.
                break;
        }
    }

    //Setter para ingresar el cargo del predeterminado a los gerentes.
    void SetCargoGerenteGeneral(){
        Cargo = "GERENTE GENERAL";
    }

    //Setter para ingresar el cargo del predeterminado del jefe.
    void SetCargoJefe(){
        Cargo = "JEFE";
    }

    //Setter para ingresar la direccion del empleado.
    void SetDireccion(){
        std::cout<<"INGRESE LA DIRECCION DEL EMPLEADO"<<std::endl;
        std::getline(std::cin >> std::ws, Direccion); //Se utiliza getline para extraer toda la infromacion de la linea y ws para limpiar buffer.
    }

    //Setter para ingresar la sucursal del empleado si el jefe lo quiere contratar.
    void SetSucursal(){
        int eleccion;
        std::cout<<"INGRESE LA SUCURSAL DEL EMPLEADO"<<std::endl<<"1- GUADALAJARA"<<std::endl<<"2- GUANAJUATO"<<std::endl<<"3- CDMX"<<std::endl;
        std::cin>>eleccion;
        //Segun el numero elegido se va iguala una cadena de texto a la variable.
        switch (eleccion) {
            case 1:
                Sucursal = "GDL";
                break;
            case 2:
                Sucursal = "GTO";
                break;
            case 3:
                Sucursal = "CDMX";
                break;
            default:
                std::cout<<"SUCURSAL NO DISPONIBLE, SELECCIONA UNA NUEVAMENTE"<<std::endl;
                SetSucursal(); //Usamos la recursividad para ingresar la sucursal correctamente.
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

    //Setter conjunto para creacion de empleado.
    void SetCrearGerente(){
        SetNombre();
        SetDia();
        SetMes();
        SetAnio();
        SetDireccion();
        SetSucursal();
        SetRFC();
        SetNumeroDeCuenta();
        SetNumeroDeSeguroSocial();
        SetCargoGerenteGeneral();
        SetSueldo();
        SetUsuario();
        SetContrasena();
        CargarDatosBaseDeDatos();
    }

    //Setter conjunto para creacion de empleado.
    void SetCrearEmpleadoParaJefe(){
        SetNombre();
        SetDia();
        SetMes();
        SetAnio();
        SetDireccion();
        SetSucursal();
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

//Creacion de la clase Gerente.
class GerenteGeneral : public EmpleadoGDL<std::string, int> {
public:
    // Constructor implicito
    GerenteGeneral() : EmpleadoGDL<std::string, int>() {

    }

    // Constructor explicito
    GerenteGeneral(T Nombre, T2 Dia, T2 Mes, T2 Anio, T Cargo, T Direccion, T RFC, T2 NumeroDeCuenta,
                   T2 NumeroDeSeguroSocial,
                   float Sueldo, T EstadoDePago, T Sucursal) :
            EmpleadoGDL<std::string, int>(Nombre, Dia, Mes, Anio, Cargo, Direccion, RFC, NumeroDeCuenta,
                                          NumeroDeSeguroSocial, Sueldo, EstadoDePago, Sucursal) {
    }

    // Se creo el metodo de creacion para la creacion de empleados comunes sin acceso a la plataforma.
    EmpleadoGDL<std::string, int> CreacionEmpleado(T suscursal) {
        EmpleadoGDL<std::string, int> EmpleadoNuevo;
        std::cout << "BIENVENIDO GERENTE, PARA CREAR UN EMPLEADO COMPLETE LA SIGUIENTE INFORMACION:" << std::endl;

        //Funcion para crear un nuevo usuario.
        EmpleadoNuevo.SetCrear(suscursal); //Se le agrega la sucursal del gerente ya que sera registrado en esa misma sucursal.
        std::cout << "USUARIO REGISTRADO EXITOSAMENTE." << std::endl;

        return EmpleadoNuevo;
    }

    // Se crea metodo para busqueda y edicion de empleados.
    void EditarDatos() {
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

            // Comprobación si el nombre de usuario está en la columna.
            if (campos.size() > 10 && campos[10] == Usuario) {
                int seleccion;
                std::cout<<"QUE DESEAS EDITAR DEL USUARIO: "<<Usuario<<"."<<std::endl<<"1- EDITAR NOMBRE DE USUARIO."<<std::endl<<"2- EDITAR CONTRASENA."<<std::endl<<"3- EDITAR DIRECCION."
                        <<std::endl<<"4- EDITAR NUMERO DE CUENTA."<<std::endl<<"5- EDITAR SUELDO."<<std::endl;
                std::cin>>seleccion;

                // Realizar aquí las modificaciones en los datos según sea necesario.
                switch (seleccion) {
                    case 1:
                        std::cout << "INGRESA EL NUEVO NOMBRE DE USUSARIO:" << std::endl;
                        std::cin >> campos[10];
                        break;

                    case 2:
                        std::cout << "INGRESA LA NUEVA CONTRASENA DEL USUSARIO:" << std::endl;
                        std::cin >> campos[11];
                        break;

                    case 3:
                        std::cout << "INGRESA LA NUEVA DIRECCION DEL USUARIO:" << std::endl;
                        std::cin >> campos[4];
                        break;

                    case 4:
                        std::cout << "INGRESA EL NUEVO NUMERO DE CUENTA DEL USUARIO:" << std::endl;
                        std::cin >> campos[7];
                        break;

                    case 5:
                        std::cout << "INGRESA EL NUEVO NOMBRE DE SUELDO:" << std::endl;
                        std::cin >> campos[9];
                        break;

                    default:
                        std::cout << "OPCION NO DISPONIBLE" << std::endl;
                        EditarDatos();
                        break;
                }

                // Reconstruye la línea con los campos modificados.
                std::stringstream nuevaLinea;
                for (const auto &campo : campos) {
                    nuevaLinea << campo << ",";
                }
                std::string nuevaLineaStr = nuevaLinea.str();
                nuevaLineaStr.pop_back(); // Eliminar la última coma.

                lineasArchivo.push_back(nuevaLineaStr);
            } else {
                lineasArchivo.push_back(linea);
            }
        }
        archivoEntrada.close();

        // Ahora, escribe las líneas modificadas de nuevo al archivo.
        std::ofstream archivoSalida(nombreArchivo);
        if (!archivoSalida) {
            std::cout << "No se pudo abrir el archivo de salida: " << nombreArchivo << std::endl;
            return;
        }

        for (const auto &linea : lineasArchivo) {
            archivoSalida << linea << std::endl;
        }
        archivoSalida.close();

        std::cout << "DATOS EDITADOS EXITOSAMENTE." << std::endl;
    }

    void BorrarEmpleado() {
        // Se crea cadena para guardar el nombre que el usuario quiera borrar.
        std::string Usuario;
        std::cout << "INGRESE EL USUARIO DEL EMPLEADO A BORRAR:" << std::endl;
        std::cin >> Usuario;

        std::string nombreArchivo = "BaseDeDatos.csv";
        std::ifstream archivoEntrada(nombreArchivo);
        if (!archivoEntrada) {
            std::cout << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
            return;
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

            // Comprobación si el nombre de usuario está en la columna correspondiente (por ejemplo, en la posición 10)
            if (campos.size() > 10 && campos[10] == Usuario) {
                std::cout << "El usuario eliminado correctamente." << std::endl;
                continue;  // Salta esta línea, no la agregues al vector lineasArchivo
            } else {
                lineasArchivo.push_back(linea);
            }
        }
        archivoEntrada.close();

        // Ahora, escribe las líneas restantes de nuevo al archivo
        std::ofstream archivoSalida(nombreArchivo);
        if (!archivoSalida) {
            std::cout << "No se pudo abrir el archivo de salida: " << nombreArchivo << std::endl;
            return;
        }

        for (const auto &linea: lineasArchivo) {
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

template<typename T, typename T2>
//Creacion de la clase jefe
class Jefe : public EmpleadoGDL<std::string, int> {
public:
    // Constructor implicito
    Jefe() : EmpleadoGDL<std::string, int>() {

    }

    // Constructor explicito
    Jefe(T Nombre, T2 Dia, T2 Mes, T2 Anio, T Cargo, T Direccion, T RFC, T2 NumeroDeCuenta, T2 NumeroDeSeguroSocial,
         float Sueldo, T EstadoDePago, T Sucursal):
            EmpleadoGDL<std::string, int>(Nombre, Dia, Mes, Anio, Cargo, Direccion, RFC, NumeroDeCuenta, NumeroDeSeguroSocial, Sueldo, EstadoDePago, Sucursal) {
    }


    //Creacion de un jefe en caso de encontrar el archivo vacio.
    void SetCrearJefe(){
        std::cout<<"NO HAY USUSARIOS REGISTRADOS, COMIENZA CON EL REGISTRO DEL JEFE:"<<std::endl;
        SetNombre();
        SetDia();
        SetMes();
        SetAnio();
        SetDireccion();
        SetRFC();
        SetNumeroDeCuenta();
        SetNumeroDeSeguroSocial();
        SetCargoJefe();
        SetSueldo();
        SetUsuario();
        SetContrasena();
        CargarDatosBaseDeDatos();
    }

    //Setter conjunto para creacion de empleado.
    GerenteGeneral<std::string, int> CreacionGerente() {
        GerenteGeneral<std::string, int> EmpleadoNuevo;
        std::cout << "BIENVENIDO JEFE, PARA CREAR UN GERENTE COMPLETE LA SIGUIENTE INFORMACION:" << std::endl;

        //Funcion para crear un nuevo usuario.
        EmpleadoNuevo.SetCrearGerente(); //Se le agrega la sucursal del gerente ya que sera registrado en esa misma sucursal.
        std::cout << "GERENTE REGISTRADO EXITOSAMENTE." << std::endl;

        return EmpleadoNuevo;
    }

    // Se creo el metodo de creacion para la creacion de empleados comunes siendo el jefe.
    EmpleadoGDL<std::string, int> CreacionEmpleadoJefe() {
        EmpleadoGDL<std::string, int> EmpleadoNuevo;
        std::cout << "BIENVENIDO JEFE, PARA CREAR UN EMPLEADO COMPLETE LA SIGUIENTE INFORMACION:" << std::endl;

        //Funcion para crear un nuevo usuario.
        EmpleadoNuevo.SetCrearEmpleadoParaJefe(); // Se usa metodo especial donde pide sucursal y no da puesto predeterminado.
        std::cout << "USUARIO REGISTRADO EXITOSAMENTE." << std::endl;

        return EmpleadoNuevo;
    }




private:
    T Nombre, EstadoDePago, Usuario, Contrasena;
    T2 Dia, Mes, Anio;
    T Cargo, Direccion, RFC, NumeroDeCuenta, Sucursal;
    T2 NumeroDeSeguroSocial;
    float Sueldo;
};


template<typename T, typename T2>
//Clase Gerente Almacen.

class GerenteAlmacen : public EmpleadoGDL<std::string, int> {
public:
    //Constructor implicito
    GerenteAlmacen() : EmpleadoGDL<std::string, int>() {

    }
    //Constructor explicito
    GerenteAlmacen(T Nombre, T2 Dia, T2 Mes, T2 Anio, T Cargo, T Direccion, T RFC, T2 NumeroDeCuenta,
                   T2 NumeroDeSeguroSocial,
                   float Sueldo, T EstadoDePago, T Sucursal) :
            EmpleadoGDL<std::string, int>(Nombre, Dia, Mes, Anio, Cargo, Direccion, RFC, NumeroDeCuenta,
                                          NumeroDeSeguroSocial, Sueldo, EstadoDePago, Sucursal) {
    }

    AgregarAInventario<T,T2> SetCrearProducto() {
        AgregarAInventario<T,T2> retorno;

        retorno.SetNombre();
        retorno.SetCiudad();
        retorno.SetCantidad();
        retorno.SetPlanta();
        return retorno;
    }

    void Mostrar(std::vector<AgregarAInventario<T, T2>> inventarioFuncion) {
        for (size_t i = 0; i < inventarioFuncion.size(); ++i) {
            std::cout << "PRODUCTO NUMERO " << i + 1 << std::endl;  // Incrementa el número de producto
            std::cout << "NOMBRE: " << inventarioFuncion[i].getNombre() << std::endl;
            std::cout << "CIUDAD: " << inventarioFuncion[i].getCiudad() << std::endl;
            std::cout << "PLANTA: " << inventarioFuncion[i].getPlanta() << std::endl;
            std::cout << "CANTIDAD: " << inventarioFuncion[i].getCantidad() << std::endl << std::endl;
        }
    }
};


#endif //PROYECTO_CLASEEMPLEADOS_H
