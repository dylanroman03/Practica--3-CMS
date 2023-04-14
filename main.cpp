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

void decoderData(char *elementos[], int cantElementos)
{
  // Decodificar la data
  char *name = elementos[0];
  // char *info = elementos[1];

  cout << name << endl;
  // cout << info << endl;

  int num = atoi(elementos[1]);

  cout << num << endl;

  int precio = (num >> 10) & 0xFFFFF; // desplazamos 10 bits a la derecha y aplicamos una máscara de 20 bits

  // Id de la plantilla del bit 6 al bit 10 (5 bits)
  int id = (num >> 5) & 0x1F; // desplazamos 5 bits a la derecha y aplicamos una máscara de 5 bits

  // Localización de Menú (bit 4, 5 y 6) 000=Horizontal superior 001=Horizontal inferior 010=Vertical derecha 011=Vertical izquierda 100=Mixto.
  int localizacion = num & 0x7; // aplicamos una máscara de 3 bits

  // Ahora podemos imprimir los valores decodificados
  std::cout << "Precio: " << precio << std::endl;
  std::cout << "Id: " << id << std::endl;
  std::cout << "Localización: ";

  switch (localizacion)
  {
  case 0:
    std::cout << "Horizontal superior";
    break;
  case 1:
    std::cout << "Horizontal inferior";
    break;
  case 2:
    std::cout << "Vertical derecha";
    break;
  case 3:
    std::cout << "Vertical izquierda";
    break;
  case 4:
    std::cout << "Mixto";
    break;
  default:
    std::cout << "Valor inválido";
  }
}

void getPlantillas()
{
  int cantPlantillas = datos.getCantPlantillas();

  for (int i = 0; i < cantPlantillas; i++)
  {
    char *plantilla = datos.getPlantilla(i);

    int plantilla_len = strlen(plantilla);
    char *plantilla_copia = new char[plantilla_len + 1];
    strcpy(plantilla_copia, plantilla);

    char *elemento;
    char *elementos[4];
    int j = 0;
    elemento = strtok(plantilla_copia, "-");

    while (elemento != NULL)
    {
      elementos[j] = new char[strlen(elemento) + 1];
      strcpy(elementos[j], elemento);
      elemento = strtok(NULL, "-");
      j++;
    }

    // Llamar a la función que decodifica la data
    decoderData(elementos, j);
  }
}

void getWebSites()
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


void mostrarInformacionImagenes(char *Elementos[], int CanidadElementos)
{


  for(int k = 0; k < CanidadElementos; k++){

        std::cout << Elementos[k]<< std::endl;

  }

  cout << endl;

    

}


void getImagenes()
{

  int CantImagenes = datos.getCantImagenesMenu();

  for(int i = 0; i < CantImagenes; i++)
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
  // printf("Hello World!");

  //getPlantillas();
  //getWebSites();
  getImagenes();
  return 0;
}
