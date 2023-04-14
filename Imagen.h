#ifndef IMAGEN_H
#define IMAGEN_H

#include <string>

using namespace std;

class Imagen
{
  int id;
  string ruta;
  int tamano;
  string nombre_archivo;
  int columna;
  int fila;

public:
  Imagen(int _id, string _ruta, int _tamano, string _nombre_archivo, int _columna, int _fila) : id(_id), ruta(_ruta), tamano(_tamano), nombre_archivo(_nombre_archivo), columna(_columna), fila(_fila) {}

  int getId() const { return id; }
  void setId(int _id) { id = _id; }

  string getRuta() const { return ruta; }
  void setRuta(string _ruta) { ruta = _ruta; }

  int getTamano() const { return tamano; }
  void setTamano(int _tamano) { tamano = _tamano; }

  string getNombreArchivo() const { return nombre_archivo; }
  void setNombreArchivo(string _nombre_archivo) { nombre_archivo = _nombre_archivo; }

  int getColumna() const { return columna; }
  void setColumna(int _columna) { columna = _columna; }

  int getFila() const { return fila; }
  void setFila(int _fila) { fila = _fila; }
};

#endif