#include "Disparo.h"
#include "glut.h"
#include <cmath>

#define DERECHA false
#define IZQUIERDA true

Disparo::Disparo():animacion("imagenes/animacion_fuego.png",2)
{
	radio = 0.25f;
	velocidad.x = 8.0f;
}


Disparo::~Disparo()
{

}
void Disparo::dibuja()
{
	glColor3ub(255, 255, 0);

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	//Animacion del sprite
	if (orientacion == IZQUIERDA)
		animacion.flip(false, false);
	if (orientacion == DERECHA)
		animacion.flip(true, false);
	animacion.draw();

	
	glPopMatrix();

}
//void Disparo::dibuja()
//{
//	glColor3ub(255, 255, 0);
//
//	/*glDisable(GL_LIGHTING);
//	glBegin(GL_LINES);
//	glVertex3f(origen.x, origen.y, 0);
//	glVertex3f(posicion.x, posicion.y, 0);
//	glEnd();
//	glEnable(GL_LIGHTING);*/
//
//	glPushMatrix();
//	glTranslatef(posicion.x, posicion.y, 0);
//	glutSolidSphere(radio, 20, 20);
//	glPopMatrix();
//
//}

void Disparo::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	animacion.loop();
	if(abs(origen.x-posicion.x>=distancia_maxima))
		this->~Disparo();
}

void Disparo::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
	origen = posicion;
}

void Disparo::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

float Disparo::getRadio()
{
	return radio;
}

Vector2D Disparo::getPos()
{
	return posicion;
}