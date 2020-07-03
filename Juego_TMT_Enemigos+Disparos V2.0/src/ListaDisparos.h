#pragma once
#define MAX_DISPAROS 5
#include "Disparo.h"

class ListaDisparos
{
private:
	//ATRIBUTOS
	Disparo* lista[MAX_DISPAROS];
	int numero;
public:
	//METODOS
	ListaDisparos();
	virtual ~ListaDisparos();

	int getNumero() { return numero; }
	void mueve(float t);
	void dibuja();
	bool agregar(Disparo* d);
	void eliminar(int pos);
	void eliminar(Disparo* d);

	Disparo* operator [](int i);
};

