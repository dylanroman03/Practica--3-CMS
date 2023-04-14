#include <iostream>
#include <string.h>
#include "Datos.h"

using namespace std;

Datos datos;


void createWebsite(char *elementos[], int cantElementos)
{
  // Crear el sitio web
  for (int e = 0; e < cantElementos; e++)
  {
    printf("%s\n", elementos[e]);
  }
  cout << endl;
}

void readingData()
{
  int cantSitios = datos.getCantSitios();

  for (int i = 0; i < cantSitios; i++)
  {
    char *sitio = datos.getSitio(i);

    int sitio_len = strlen(sitio);
    char *sitio_copia = new char[sitio_len + 1];
    strcpy(sitio_copia, sitio);

    char *elemento;
    char *elementos[6];
    int j = 0;
    elemento = strtok(sitio_copia, ",");

    while (elemento != NULL)
    {
      elementos[j] = new char[strlen(elemento) + 1];
      strcpy(elementos[j], elemento);
      elemento = strtok(NULL, ",");
      j++;
    }

    // Llamar a la función que crea el sitio web pasandole los elementos
    createWebsite(elementos, j);
  }
}

int main(int argc, char const *argv[])
{
  // printf("Hello World!");

  readingData();
  return 0;
}
