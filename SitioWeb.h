#ifndef SITIOWEB_H
#define SITIOWEB_H

#include <string>
#include <vector>
#include "Plantilla.h"
#include "Imagen.h"
#include "Item.h"

enum class TipoSitioWeb
{
  COMERCIAL,
  PATROCINADO
};

class SitioWeb
{
protected:
  std::string nombre;
  Plantilla plantilla;
  int cantImagenes;
  std::vector<Imagen> imagenes;
  int cantItems;
  std::vector<Item> items;
  TipoSitioWeb tipo;

public:
  SitioWeb(std::string nombre, Plantilla plantilla, int cantImagenes, std::vector<Imagen> imagenes,
           int cantItems, std::vector<Item> items, TipoSitioWeb tipo);
  virtual void pintar() = 0;
};

#endif // SITIOWEB_H
