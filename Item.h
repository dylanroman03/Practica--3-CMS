#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
  int id;
  string nombre;
  int localizacion;

public:
  Item(int id, string nombre, int localizacion) : id(id), nombre(nombre), localizacion(localizacion) {}

  int getId() const { return id; }
  string getNombre() const { return nombre; }
  int getLocalizacion() const { return localizacion; }
};

#endif