#include <iostream>
#include <string.h>
#include "Datos.h"
#include "Plantilla.h"
#include "CMS.h"

using namespace std;

Datos datos;

int main(int argc, char const *argv[])
{
  cout << "Bienvenido al CMS, Cargando Data..." << endl;
  CMS cms;
  cms.addAllWebsites();

  // cms.printCommersial();
  // cms.bestPlantilla();
  // cms.pintarWebsites();
  // cms.memoryImages();

 int opcion = 0;
    do {
        std::cout << "Menu de opciones:" << std::endl;
        std::cout << "1. Imprimir sitios web comerciales" << std::endl;
        std::cout << "2. Imprimir plantilla mas utilizada" << std::endl;
        std::cout << "3. Pintar sitios web" << std::endl;
        std::cout << "4. Mostrar cantidad de memoria requerida para almacenar imagenes" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese la opcion deseada: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                cms.printCommersial();
                break;
            case 2:
                cms.bestPlantilla();
                break;
            case 3:
                cms.pintarWebsites();
                break;
            case 4:
                cms.memoryImages();
                break;
            case 5:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo." << std::endl;
                break;
        }
    } while (opcion != 5);
  return 0;
}
