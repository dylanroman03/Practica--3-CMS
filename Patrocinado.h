#ifndef PATROCINADO_H
#define PATROCINADO_H

#include "SitioWeb.h"

class Patrocinado : public SitioWeb
{
private:
  char* dependencia;

public:
  Patrocinado(char* nombre, Plantilla plantilla, int cantImagenes, std::vector<Imagen> imagenes,
               int cantItems, std::vector<Item> items, char* dependencia);
  void pintar() override;
};

#endif // PATROCINADO_H