#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include "ColorRGB.h"


class Pared
{
	friend class Interaccion;
public:
	//ATRIBUTOS
	Vector2D limite1;
	Vector2D limite2;
	ColorRGB color;
public:
	//METODOS
	Pared();
	virtual ~Pared();
	void dibuja();
	void dibujaTapa(const char* texturepath);
	void dibujaTapaPlat();
	void setPos(float x1,float y1, float x2, float y2);
	void setColor(Byte r, Byte v, Byte a);
	float distancia(Vector2D punto, Vector2D* direccion);

};

