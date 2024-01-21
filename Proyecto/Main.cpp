// Created by Armando Yañez on 14/12/2023.

#include "FuncionesVerificacionesExtra.h" //Libreria con berificaciones extra.
#include "Login.h" //Libreria para la ejecuccion del login.

int main(){
    std::vector<AgregarAInventario<std::string, int>> inventario;//Vector para guardar productos.

    GenerarArchivo();
    Login(inventario);

    return 0;
}
