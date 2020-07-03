#include "Plataforma.h"


Plataforma::Plataforma() {
	suelo.setColor(0, 100, 0);
	techo.setColor(0, 100, 0);
	p_dcha.setColor(0, 150, 0);
	p_izq.setColor(0, 150, 0);
}

void Plataforma::dibuja() {
	suelo.dibuja();
	suelo.dibujaTapaPlat();
	techo.dibuja();
	p_dcha.dibuja();
	p_izq.dibuja();
}

void Plataforma::setPos(float x1, float y1, float x2, float y2) {
	suelo.setPos(x1, y1, x2, y2);
	techo.setPos(x1, y1 - 0.5f, x2, y2 - 0.5f);
	p_dcha.setPos(x2, y1, x2, y1 - 0.5f);
	p_izq.setPos(x1, y1, x1, y1 - 0.5f);
}