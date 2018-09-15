#include "AlmacenadorAlbum.h"


void AlmacenadorAlbum::ingresarAlbum_Reproduccion()
{

	ofstream AlbumIn("Album_Reproduccion.dat", ios::out | ios::app | ios::binary);

	if (!AlbumIn) {
		cout << "Error al Abrir archivo Empleados";
	}

	cancion nueva;

	int opc = 0;

	
	do {

		

		cout << "\nAlbum de Reproduccion \n" ;

		cout << "\n Ingrese Nombre de cancion :  ";
		cin >> nueva.nombre;
		cout << "\n Ingrese Nombre de Interprete :  ";
		cin >> nueva.interprete;
		cout << "\n Tiempo de duracion  :  ";
		cin >> nueva.duracion;
		cout << "\n Ingrese Genero :  ";
		cin >> nueva.genero;
		cout << "\n Ingrese Album :  ";
		cin >> nueva.album;
		cout << "\n Ingrese no_cancion :  ";
		cin >> nueva.no_cancion;

		AlbumIn.seekp(0, ios::end);

		AlbumIn.write(reinterpret_cast<const char*>(&nueva), sizeof(cancion));

		cout << "\n Desea agregar cancion  al album   ? presiona 1  si no    -1 salir:  ";
		cin >> opc;


	} while (opc != -1);

	AlbumIn.close();

	
}

void AlmacenadorAlbum::TotalCanciones()
{

	ifstream AlbumIn("Album_Reproduccion.dat", ios::in | ios::binary);

	if (!AlbumIn) {
		cout << "Error al abrir  Archivo Album_Reproduccion.dat ";
		return;
	}

	AlbumIn.seekg(0, ios::end);
	int tamano = AlbumIn.tellg();
	int cantidad = tamano / sizeof(cancion);

	cout << "Cantidad de canciones en tu PlayList:  " << cantidad << endl;

}

void AlmacenadorAlbum::TiempoDuracion()
{

	ifstream DuracionIn("Album_Reproduccion.dat", ios::in | ios::binary);

	if (!DuracionIn) {
		cout << "Error al abrir  Archivo Album_Reproduccion.dat ";
		return;
	}

	cancion D;

	DuracionIn.seekg(0, ios::beg);

	DuracionIn.read(reinterpret_cast <char*> (&D), sizeof(D));

	float total = 0;

	while (!DuracionIn.eof()) {

		total = total + D.duracion;
		DuracionIn.read(reinterpret_cast <char*> (&D), sizeof(D));

	}

	cout << "Total de minutos :  " << total <<endl;
	DuracionIn.close();
}

void AlmacenadorAlbum::Imprimir_X_Genero()
{

	ifstream AlbumIn("Album_Reproduccion.dat", ios::in | ios::binary);

	if (!AlbumIn) {
		cout << "Error al abrir  Archivo Album_Reproduccion.dat ";
		return;
	}

	cancion temporal;

	AlbumIn.seekg(0, ios::beg);

	AlbumIn.read(reinterpret_cast <char*> (&temporal), sizeof(temporal));



	while (!AlbumIn.eof()) {

		cout << " \n\n*** Album X Genero : " << temporal.genero << " ***\n\n"<<"\nCancion:  " << temporal.nombre << "\n Numero de cancion:  "<< temporal.no_cancion
			<< "\nInterprete:  " << temporal.interprete << "\nDuracion :  " << temporal.duracion << "\nAlbum:  " << temporal.album << "\nCantidad de Canciones:  " << endl;
		AlbumIn.read(reinterpret_cast <char*> (&temporal), sizeof(temporal));

	}

	cout << "-----------------------------\n";
	
	AlmacenadorAlbum::TiempoDuracion();
	AlmacenadorAlbum::TotalCanciones();
	AlbumIn.close();
}

void AlmacenadorAlbum::Imprimir_X_Album()
{

	ifstream AlbumIn("Album_Reproduccion.dat", ios::in | ios::binary);

	if (!AlbumIn) {
		cout << "Error al abrir  Archivo Album_Reproduccion.dat ";
		return;
	}

	cancion temporal;

	AlbumIn.seekg(0, ios::beg);

	AlbumIn.read(reinterpret_cast <char*> (&temporal), sizeof(temporal));



	while (!AlbumIn.eof()) {

		cout << " \n\n--- Album X Album : " << temporal.album << " ***\n\n" << "\nCancion:  " << temporal.nombre << "\n Numero de cancion:  " << temporal.no_cancion
			<< "\nInterprete:  " << temporal.interprete << "\nDuracion :  " << temporal.duracion << "\Genero:  " << temporal.genero << "\nCantidad de Canciones:  " << endl;
		AlbumIn.read(reinterpret_cast <char*> (&temporal), sizeof(temporal));

	}

	cout << "-----------------------------\n";

	AlmacenadorAlbum::TiempoDuracion();
	AlmacenadorAlbum::TotalCanciones();
	AlbumIn.close();
}

void AlmacenadorAlbum::Ordenador_Canciones(Node *&root)
{

	ifstream AlbumIn("Album_Reproduccion.dat", ios::in | ios::binary);

	if (!AlbumIn) {
		cout << "Error al abrir  Archivo Album_Reproduccion.dat ";
		return;
	}

	cancion temporal;

	AlbumIn.seekg(0, ios::beg);

	AlbumIn.read(reinterpret_cast <char*> (&temporal), sizeof(temporal));

	
	while (!AlbumIn.eof()) {
		Node*newNode = new Node();
		newNode->name = _strdup(temporal.nombre);
		newNode->next = 0;

		if ( root == 0) {

			root = newNode;
			return;

		}
		else {


			Node *tmp = root;
			Node *helper = 0;

			while (tmp->next!= 0)
			{
				tmp = tmp->next;
			}

			tmp->next = newNode;
			return;
		}

		
		AlbumIn.read(reinterpret_cast <char*> (&temporal), sizeof(temporal));

	}

	cout << "-----------------------------\n";

	AlbumIn.close();
	
	cout << "\nImprimiendo Lista\n";

	Node *t = root;

	while (t != 0) {

		cout << t->name << " ";

		t = t->next;
	}

	cout << endl;

}


