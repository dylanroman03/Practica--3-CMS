#include "CMS.h"
#include "Datos.h"
#include "Comercial.h"
#include "Patrocinado.h"
#include "Item.h"
#include <string.h>

// Constructor por defecto
CMS::CMS()
{
  Datos datos;
  getPlantillas();
  getImages();
}

void CMS::mostrarInformacionImagenes(char *Elementos[], int CanidadElementos, int ControlItemsImagenes)
{

  if (ControlItemsImagenes == 1)
  {
    int horientacion = CanidadElementos > 2 ? atoi(Elementos[2]) : 0;
    Item *item = new Item(atoi(Elementos[0]), Elementos[1], horientacion);
    itemsArray.push_back(item);
  }
  else
  {
    int id = atoi(Elementos[0]);
    char *ruta = Elementos[1];
    int size = atoi(Elementos[2]);
    char *name = Elementos[3];
    int column = atoi(Elementos[4]);
    int row = atoi(Elementos[5]);
    Imagen *imagen = new Imagen(id, ruta, size, name, column, row);
    imagenes.push_back(imagen);
  }
}

void CMS::getImages()
{
  int CantImagenes = datos.getCantImagenesMenu();
  int iteradorDeItems = 0;
  int item = 0;
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

    if (Imagen_Len < 20)
    {

      item = 1;
    }
    else
    {

      item = 0;
    }

    while (Elemento != NULL)
    {
      Elementos[j] = new char[strlen(Elemento) + 1];
      strcpy(Elementos[j], Elemento);
      Elemento = strtok(NULL, "#");
      j++;
    }

    mostrarInformacionImagenes(Elementos, j, item);
  }
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
  int localizacion = (num >> 3) & 0x7;
  PosicionMenu posicionMenu;

  // cout << "Localizacion: " << localizacion << endl;

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
  int imgPosition = 0;
  int itemPosition = 0;

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
    createWebsite(elementos, j, imgPosition, itemPosition);
    imgPosition += atoi(elementos[2]);
    itemPosition += atoi(elementos[3]);
  }
}

void CMS::createWebsite(char *elementos[], int cantElementos, int imgPosition, int itemPosition)
{
  char *name = elementos[0];
  char *id = elementos[1];
  int cantImagenes = atoi(elementos[2]);
  int cantItemsMenu = atoi(elementos[3]);
  double price = 0;

  Plantilla plantilla;

  // Recorremos las plantillas para obtener la plantilla con el id
  for (auto p : plantillas)
  {
    if (p->getId() == atoi(id))
    {
      plantilla = *p;
    }
  }

  std::vector<Imagen> imagenesWS;

  for (int i = imgPosition; i < imgPosition + cantImagenes; i++)
  {
    imagenesWS.push_back(*imagenes[i]);
  }

  std::vector<Item> itemsWS;

  for (int i = itemPosition; i < itemPosition + cantItemsMenu; i++)
  {
    itemsWS.push_back(*itemsArray[i]);
  }

  if (cantElementos == 5)
  {
    price = (cantImagenes * 30) + (cantItemsMenu * 50) + plantilla.getPrecio();
    Comercial *comercial = new Comercial(name, plantilla, cantImagenes, imagenesWS, cantItemsMenu, itemsWS, price);
    webSites.push_back(comercial);
  }
  else
  {
    Patrocinado *patrocinado = new Patrocinado(name, plantilla, cantImagenes, imagenesWS, cantItemsMenu, itemsWS, elementos[5]);
    webSites.push_back(patrocinado);
  }
}

void CMS::printCommersial()
{
  double precioTotal = 0.0;
  std::cout << "Listado de sitios web comerciales" << std::endl;
  std::cout << "Nombre del sitio web\tPrecio" << std::endl;
  std::cout << "---------------------\t-------" << std::endl;

  for (const auto &sitioWeb : webSites)
  {
    if (dynamic_cast<Comercial *>(sitioWeb))
    {
      Comercial *sitioWebComercial = dynamic_cast<Comercial *>(sitioWeb);
      std::cout << sitioWebComercial->getNombre() << "\t\t$" << sitioWebComercial->getPrecio() << std::endl;
      precioTotal += sitioWebComercial->getPrecio();
    }
  }

  std::cout << "---------------------\t-------" << std::endl;
  std::cout << "Total\t\t\t$" << precioTotal << std::endl;
}

void CMS::bestPlantilla()
{
  int idPlantilla = 0;
  int cantSitios = 0;

  for (const auto &plantilla : plantillas)
  {
    int cantSitiosPlantilla = 0;
    for (const auto &sitioWeb : webSites)
    {
      if (plantilla->getId() == sitioWeb->getPlantilla().getId())
      {
        cantSitiosPlantilla++;
      }
    }

    if (cantSitiosPlantilla > cantSitios)
    {
      cantSitios = cantSitiosPlantilla;
      idPlantilla = plantilla->getId();
    }
  }

  cout << "La plantilla con más sitios web es:" << endl;

  for (auto p : plantillas)
  {
    if (p->getId() == idPlantilla)
    {
      cout << "ID: " << p->getId() << " Nombre: " << p->getNombre() << endl;
    }
  }
}

void CMS::pintarWebsites()
{
  for (const auto &sitioWeb : webSites)
  {
    sitioWeb->pintar();
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
