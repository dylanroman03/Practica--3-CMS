#include "CMS.h"
#include "Datos.h"
#include "Comercial.h"
#include "Patrocinado.h"
#include <string.h>

// Constructor por defecto
CMS::CMS()
{
  Datos datos;
  getPlantillas();
}

void CMS::getPlantillas()
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

void mostrarBits(unsigned valor)
{
  unsigned c, mascara = 1 << 31;
  printf("%7u = ", valor);
  for (c = 1; c <= 32; c++)
  {
    putchar(valor & mascara ? '1' : '0');
    valor <<= 1;
    if (c % 8 == 0)
      putchar(' ');
  }
  putchar('\n');
}

void CMS::decoderData(char *elementos[], int cantElementos)
{
  // Decodificar la data
  char *name = elementos[0];

  int num = atoi(elementos[1]);

  // Precio del bit 11 al bit 31 (21 bits)
  int precio = (num >> 10) & 0xFFFFF;

  // Id de la plantilla del bit 6 al bit 10 (5 bits)
  int id = (num >> 6) & 0x1F;

  // Localización de Menú (bit 4, 5 y 6) 000=Horizontal superior 001=Horizontal inferior 010=Vertical derecha 011=Vertical izquierda 100=Mixto.
  int localizacion = num & 0x7;
  PosicionMenu posicionMenu;

  switch (localizacion)
  {
  case 0:
    posicionMenu = PosicionMenu::HORIZONTAL_SUPERIOR;
    break;
  case 1:
    posicionMenu = PosicionMenu::HORIZONTAL_INFERIOR;
    break;
  case 2:
    posicionMenu = PosicionMenu::VERTICAL_DERECHA;
    break;
  case 3:
    posicionMenu = PosicionMenu::VERTICAL_IZQUIERDA;
    break;
  case 4:
    posicionMenu = PosicionMenu::MIXTO;
    break;
  default:
    std::cout << "Valor inválido";
  }

  Plantilla *plantilla = new Plantilla(id, name, posicionMenu, precio);
  plantillas.push_back(plantilla);
}

// Métodos para agregar los sitios web
void CMS::addAllWebsites()
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

    cout << elementos[0] << " " << elementos[1] << endl;

    // Llamar a la función que crea el sitio web pasandole los elementos
    createWebsite(elementos, j);
  }
}

void CMS::createWebsite(char *elementos[], int cantElementos)
{
  char *name = elementos[0];
  char *id = elementos[1];
  char *qtyImages = elementos[2];
  char *qtyItemsMenu = elementos[3];
  Plantilla plantilla;

  // Recorremos las plantillas para obtener la plantilla con el id
  for (auto p : plantillas)
  {
    if (p->getId() == atoi(id))
    {
      plantilla = *p;
    }
  }


  cout << "Name: " << plantilla.getNombre() << "id: " << plantilla.getId() << endl;
  if (cantElementos == 5)
  {
    // Comercial *comercial = new Comercial("", plantilla, atoi(qtyImages), atoi(qtyItemsMenu));
  }
}

// Método para obtener la cantidad de sitios web
int CMS::getQtyWebSites() const
{
  return webSites.size();
}

// Método para obtener un sitio web
SitioWeb *CMS::getWebSite(int index) const
{
  return webSites[index];
}