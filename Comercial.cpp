#include "Comercial.h"
#include <iostream>

using namespace std;

Comercial::Comercial(char *nombre, Plantilla plantilla, int cantImagenes, std::vector<Imagen> imagenes,
                     int cantItems, std::vector<Item> items, double precio)
    : SitioWeb(nombre, plantilla, cantImagenes, imagenes, cantItems, items), precio(precio)
{
}

void printMixto(std::vector<Item> items)
{
  int j = 0;
  for (const auto &item : items)
  {
    if (j == 0)
    {
      cout << item.getNombre() << "\t\t";
    }
    else if (j == 1)
    {
      cout << item.getNombre() << endl;
    }
    else if (j == 2)
    {
      cout << " " << item.getNombre() << endl;
      j = -1;
    }

    j++;
  }
}

void Comercial::pintar()
{
  // Implementación de la función pintar para Comercial
  std::vector<Item> items = getItems();

  cout << "---------------------------------------------------" << endl;
  cout << " Comercial"
       << " - " << nombre << endl;
  cout << " (" << plantilla.getNombre() << ")" << endl;

  PosicionMenu posicion = plantilla.getPosicionMenu();
  switch (posicion)
  {
  case PosicionMenu::MIXTO:
    cout << "MIXTO" << endl;
    printMixto(items);
    break;

  case PosicionMenu::HORIZONTAL_INFERIOR:
    cout << "\n\n"
         << endl;
    for (const auto &item : items)
    {
      cout << item.getNombre() << "   ";
    }

    cout << "\n ";
    break;

  case PosicionMenu::HORIZONTAL_SUPERIOR:
    cout << "\n ";
    for (const auto &item : items)
    {
      cout << item.getNombre() << "   ";
    }

    cout << "\n\n"
         << endl;
    break;

  case PosicionMenu::VERTICAL_DERECHA:
    cout << endl;
    for (const auto &item : items)
    {
      cout << " " << item.getNombre() << endl;
    }
    cout << endl;
    break;

  case PosicionMenu::VERTICAL_IZQUIERDA:
    cout << endl;
    for (const auto &item : items)
    {
      cout << "\t\t\t" << item.getNombre() << endl;
    }
    cout << endl;
    break;
  }

  std::cout << std::endl
            << "---------------------------------------------------" << std::endl;
}