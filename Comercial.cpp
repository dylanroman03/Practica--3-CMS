#include "Comercial.h"
#include <iostream>

Comercial::Comercial(char *nombre, Plantilla plantilla, int cantImagenes, std::vector<Imagen> imagenes,
                     int cantItems, std::vector<Item> items, double precio)
    : SitioWeb(nombre, plantilla, cantImagenes, imagenes, cantItems, items)
{
  this->precio = precio;
}

void Comercial::pintar()
{
}
