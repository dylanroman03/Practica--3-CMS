#ifndef PLANTILLA_H
#define PLANTILLA_H

#include <string>

using namespace std;

enum class PosicionMenu
{
  HORIZONTAL_SUPERIOR,
  HORIZONTAL_INFERIOR,
  VERTICAL_IZQUIERDA,
  VERTICAL_DERECHA,
  MIXTO
};

class Plantilla
{
  int id;
  char* nombre;
  PosicionMenu posicion_menu;
  float precio;

public:
  Plantilla(int id, char* nombre, PosicionMenu posicion_menu, float precio)
      : id(id), nombre(nombre), posicion_menu(posicion_menu), precio(precio) {}
  Plantilla() {}

  int getId() const { return id; }
  string getNombre() const { return nombre; }

  PosicionMenu getPosicionMenu() const { return posicion_menu; }
  float getPrecio() const { return precio; }
};

#endif