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

  // Getters
  char* getNombre() const { return nombre; }
  Plantilla getPlantilla() const { return plantilla; }
  int getCantItems() const { return cantItems; }
  std::vector<Imagen> getImagenes() const { return imagenes; }
  std::vector<Item> getItems() const { return items; }
};

#endif // SITIOWEB_H
