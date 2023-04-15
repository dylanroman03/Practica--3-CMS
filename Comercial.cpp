#include "Comercial.h"
#include <iostream>

using namespace std;

Comercial::Comercial(char *nombre, Plantilla plantilla, int cantImagenes, std::vector<Imagen> imagenes,
                     int cantItems, std::vector<Item> items, double precio)
    : SitioWeb(nombre, plantilla, cantImagenes, imagenes, cantItems, items), precio(precio)
{
}

void Comercial::pintar()
{
  // Implementación de la función pintar para Comercial
  cout << nombre << endl;
}