#pragma once
#include "Pared.h"

class Plataforma {
public:
	Pared suelo;
	Pared techo;
	Pared p_dcha;
	Pared p_izq;
public:
	Plataforma();
	virtual ~Plataforma() {}
	void setPos(float x1, float y1, float x2, float y2);
	void dibuja();
};