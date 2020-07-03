#include "ListaDisparos.h"
//---------------------------------------------------------------------------------------------------------------------------------------------------------------

ListaDisparos::ListaDisparos()
{

}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
ListaDisparos::~ListaDisparos()
{

}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void ListaDisparos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void ListaDisparos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
	for (int i = 0; i < numero;i++)
		if (abs(lista[i]->posicion.x - lista[i]->origen.x) >= lista[i]->distancia_maxima)
			eliminar(i);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
/*void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];

	numero = 0;
}*/
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
bool ListaDisparos::agregar(Disparo* d)
{
	for (int i = 0; i < numero; i++) // Para evitar que se añada una esfera ya existente
		if (lista[i] == d)
			return false;

	if (numero < MAX_DISPAROS)
		lista[numero++] = d;
	else
		return false;
	return true;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void ListaDisparos::eliminar(int pos)
{
	if ((pos < 0) || (pos >= numero))
		return;
	delete lista[pos];

	numero--;
	for (int i = pos;i < numero;i++)
		lista[i] = lista[i + 1];


}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void ListaDisparos::eliminar(Disparo* d)
{
	for (int i = 0;i < numero;i++)

		if (lista[i] == d)
		{
			eliminar(i);
			return;
		}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
Disparo* ListaDisparos::operator [](int i) {
	if (i >= numero) //Si el numero es mayor al tamaño de Lista, devuelve el últiimo elemento
		i = numero - 1;
	if (i < 0) //Si el numero es negativo devuelve el primer elemento
		i = 0;
	return lista[i];
}
