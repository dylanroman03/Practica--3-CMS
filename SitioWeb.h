#ifndef SITIOWEB_H
#define SITIOWEB_H

#include <string>
#include <vector>
#include "Plantilla.h"
#include "Imagen.h"
#include "Item.h"

class SitioWeb
{
protected:
  char *nombre;
  Plantilla plantilla;
  int cantImagenes;
  std::vector<Imagen> imagenes;
  int cantItems;
  std::vector<Item> items;

public:
  SitioWeb(char *nombre, Plantilla plantilla, int cantImagenes, std::vector<Imagen> imagenes,
           int cantItems, std::vector<Item> items);
  virtual void pintar() = 0;

  int getCantImagenes() const { return cantImagenes; }
};

#endif // SITIOWEB_H
