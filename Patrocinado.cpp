#include "Patrocinado.h"
#include <iostream>
#include <cstring>

Patrocinado::Patrocinado(char *nombre, Plantilla plantilla, int cantImagenes, std::vector<Imagen> imagenes,
                         int cantItems, std::vector<Item> items, char *dependencia)
    : SitioWeb(nombre, plantilla, cantImagenes, imagenes, cantItems, items), dependencia(dependencia)
{
}

void Patrocinado::pintar()
{
  // Imprimir tipo de sitio web y nombre
  cout << "Patrocinado" <<  " - " << nombre << endl;
}