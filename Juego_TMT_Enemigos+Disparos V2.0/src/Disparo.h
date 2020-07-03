#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"

using ETSIDI::SpriteSequence;

class Disparo
{
public:
	friend class Interaccion;
	//ATRIBUTOS
	float radio;
	float distancia_maxima;// Distancia a la que desaparece el disparo
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	Vector2D origen;
	bool orientacion;
	SpriteSequence animacion;
public:
	//METODOSww
	Disparo();
	virtual ~Disparo();
	void mueve(float t);
	void dibuja();
	void setPos(float ix, float iy);
	void setVel(float vx, float vy);
	float getRadio();
	Vector2D getPos();
	
};

