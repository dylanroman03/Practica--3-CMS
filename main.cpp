#include <iostream>
#include <string.h>
#include "Datos.h"
#include "Plantilla.h"
#include "CMS.h"

using namespace std;

Datos datos;

int main(int argc, char const *argv[])
{
  // printf("Hello World!");
  CMS cms;
  cms.addAllWebsites();
  return 0;
}
