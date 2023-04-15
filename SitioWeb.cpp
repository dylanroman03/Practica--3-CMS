#include "SitioWeb.h"

SitioWeb::SitioWeb(char *nombre, Plantilla plantilla, int cantImagenes, std::vector<Imagen> imagenes,
                   int cantItems, std::vector<Item> items)
    : nombre(nombre), plantilla(plantilla), cantImagenes(cantImagenes), imagenes(imagenes),
      cantItems(cantItems), items(items)
{
}