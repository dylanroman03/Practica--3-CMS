#ifndef CMS_H
#define CMS_H

#include <vector>
#include "SitioWeb.h"
#include "Plantilla.h"
#include "Imagen.h"
#include "Item.h"
#include "Datos.h"

class CMS
{
public:
  // Constructor por defecto
  CMS();

  // Métodos para agregar y eliminar sitios web
  void addAllWebsites();
  void getPlantillas();
  void getImages();
  void getItems();
  void decoderData(char *elementos[], int cantElementos);
  void createWebsite(char *elementos[], int cantElementos, int imgPosition, int itemPosition);
  void mostrarInformacionImagenes(char *Elementos[], int CanidadElementos, int ControlItemsImagenes);

  // Métodos para Imprimir
  void printCommersial();
  void bestPlantilla();
  void pintarWebsites();
  void memoryImages();

  // Método para obtener la cantidad de sitios web
  int getQtyWebSites() const;

  // Método para obtener un sitio web
  SitioWeb *getWebSite(int index) const;

private:
  std::vector<SitioWeb *> webSites;
  std::vector<Plantilla *> plantillas;
  std::vector<Imagen *> imagenes;
  std::vector<Item *> itemsArray;
  Datos datos;
};

#endif
