#ifndef COMERCIAL_H
#define COMERCIAL_H

#include "SitioWeb.h"

class Comercial : public SitioWeb
{
private:
  double precio;

public:
  Comercial(char *nombre, Plantilla plantilla, int cantImagenes, std::vector<Imagen> imagenes,
            int cantItems, std::vector<Item> items, double precio);
  void pintar() override;

  // Getters
  double getPrecio() const { return precio; }
};

#endif // COMERCIAL_H