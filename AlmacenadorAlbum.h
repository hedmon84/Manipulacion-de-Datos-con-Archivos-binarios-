#pragma once

#include <fstream>
#include <iostream>


using namespace std;

struct cancion
{
	char nombre[50]; //
	char interprete[30]; //minutos
	float duracion; //4
	char genero[20];
	char album[20];
	int no_cancion; // 4 track

	//sizeof 128
};

struct Node
{
	char *name;
	Node *next;
	

};


class AlmacenadorAlbum
{
public:
	
	static void ingresarAlbum_Reproduccion();
	static void TotalCanciones();
	static void TiempoDuracion();
	static void Imprimir_X_Genero();
	static void Imprimir_X_Album();
	static void Ordenador_Canciones(Node *&);






};

