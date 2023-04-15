#include "Comercial.h"
#include <iostream>

using namespace std;

Comercial::Comercial(char *nombre, Plantilla plantilla, int cantImagenes, vector<Imagen> imagenes,
                     int cantItems, vector<Item> items, double precio)
    : SitioWeb(nombre, plantilla, cantImagenes, imagenes, cantItems, items), precio(precio) {}

Comercial::Comercial() : SitioWeb(nullptr, Plantilla(), 0, vector<Imagen>(), 0, vector<Item>()), precio(0.0) {}

void Comercial::pintar()
{
  cout << "Tipo de sitio web - Comercial" << endl;
  cout << "Nombre del sitio web - " << this->nombre << endl;
  cout << "(" << this->plantilla.getNombre() << ")" << endl;

  for (int i = 0; i < this->cantItems; i++)
  {
    if (i % 2 == 0)
    {
      cout << this->items[i].getNombre() << "\t\t";
    }
    else
    {
      cout << this->items[i].getNombre() << endl;
    }
  }
  if (this->cantItems % 2 != 0)
  {
    cout << endl;
  }

  cout << "Precio: $" << this->precio << endl;
}
