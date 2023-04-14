#include <iostream>
#include <string.h>
#include "Datos.h"
#include "Plantilla.h"
#include "CMS.h"

using namespace std;

Datos datos;

void mostrarInformacionImagenes(char *Elementos[], int CanidadElementos)
{

  for (int k = 0; k < CanidadElementos; k++)
  {
    std::cout << Elementos[k] << std::endl;
  }

  cout << endl;
}

void getImagenes()
{

  int CantImagenes = datos.getCantImagenesMenu();

  for (int i = 0; i < CantImagenes; i++)
  {

    char *Imagen = datos.getImagenesMenu(i);
    int Imagen_Len = strlen(Imagen);
    char *Imagen_Copia = new char[Imagen_Len + 1];
    strcpy(Imagen_Copia, Imagen);

    char *Elemento;
    char *Elementos[6];
    int j = 0;
    Elemento = strtok(Imagen_Copia, "#");

    while (Elemento != NULL)
    {
      Elementos[j] = new char[strlen(Elemento) + 1];
      strcpy(Elementos[j], Elemento);
      Elemento = strtok(NULL, "#");
      j++;
    }

    mostrarInformacionImagenes(Elementos, j);
  }
}

int main(int argc, char const *argv[])
{
  CMS cms;
  cms.addAllWebsites();
  getImagenes();
  return 0;
}
