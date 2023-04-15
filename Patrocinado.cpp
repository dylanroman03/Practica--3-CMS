#include "Patrocinado.h"
#include <iostream>
#include <cstring>

Patrocinado::Patrocinado(char *nombre, Plantilla plantilla, int cantImagenes, std::vector<Imagen> imagenes,
                         int cantItems, std::vector<Item> items, char *dependencia)
    : SitioWeb(nombre, plantilla, cantImagenes, imagenes, cantItems, items)
{
  this->dependencia = new char[strlen(dependencia) + 1];
  strcpy(this->dependencia, dependencia);
}

Patrocinado::~Patrocinado()
{
  delete[] this->dependencia;
}

void Patrocinado::pintar()
{
  // Imprimir tipo de sitio web y nombre
  cout << "Patrocinado" <<  " - " << nombre << endl;

  // Imprimir nombre de la plantilla
  cout << "(" << plantilla.getNombre() << ")" << endl;

  // Imprimir menús
  // switch (plantilla.getPosicionMenu())
  // {
  // case PosicionMenu::HORIZONTAL_SUPERIOR:
  //   cout << menu1 << "\t" << menu2 << endl;
  //   cout << menu3 << "\t\t\t" << menu4 << endl;
  //   cout << menu5 << endl;
  //   break;
  // case PosicionMenu::HORIZONTAL_INFERIOR:
  //   cout << menu1 << "\t" << menu2 << endl;
  //   cout << menu3 << "\t\t\t" << menu4 << endl;
  //   cout << menu5 << endl;
  //   cout << endl
  //        << menu6 << endl;
  //   break;
  // case PosicionMenu::VERTICAL_IZQUIERDA:
  //   cout << menu1 << endl;
  //   cout << menu2 << endl;
  //   cout << menu3 << endl;
  //   cout << menu4 << endl;
  //   cout << menu5 << endl;
  //   break;
  // case PosicionMenu::VERTICAL_DERECHA:
  //   cout << "\t\t\t\t" << menu1 << endl;
  //   cout << "\t\t\t\t" << menu2 << endl;
  //   cout << "\t\t\t\t" << menu3 << endl;
  //   cout << "\t\t\t\t" << menu4 << endl;
  //   cout << "\t\t\t\t" << menu5 << endl;
  //   break;
  // case PosicionMenu::MIXTO:
  //   cout << menu1 << "\t" << menu2 << endl;
  //   cout << menu3 << "\t\t\t" << menu4 << endl;
  //   cout << menu5 << endl;
  //   cout << endl
  //        << menu6 << endl;
  //   break;
  // default:
  //   cout << "Error en la plantilla" << endl;
  //   break;
  // }
}