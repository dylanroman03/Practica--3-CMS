#include "Patrocinado.h"
#include <iostream>
#include <cstring>

Patrocinado::Patrocinado(char *nombre, Plantilla plantilla, int cantImagenes, std::vector<Imagen> imagenes,
                         int cantItems, std::vector<Item> items, char *dependencia)
    : SitioWeb(nombre, plantilla, cantImagenes, imagenes, cantItems, items)
{
  this->dependencia = new char[strlen(dependencia) + 1];
  strcpy(this->dependencia, dependencia);
}

Patrocinado::~Patrocinado()
{
  delete[] this->dependencia;
}

void Patrocinado::pintar()
{
}