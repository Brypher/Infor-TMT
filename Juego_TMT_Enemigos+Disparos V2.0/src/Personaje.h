#pragma once
#include "Vector2D.h"
#include "Personaje.h"

class Personaje
{
	friend class Interaccion;
public:
	//ATRIBUTOS
	float altura; //equicalente a radio de la esfera que lo simula
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	int cadencia; // numero de ciclos que tienen que pasar para que el personaje vuelva a disparar (si es 0 significa que puede hacerlo)
public:
	//METODOS
	Personaje(); //Constructor
	virtual ~Personaje(); 

	void dibuja();
	void setVel(float vx, float vy);
	void mueve(float t);
	float getAltura() { return altura; }
	Vector2D getPos() { return posicion; }
};

