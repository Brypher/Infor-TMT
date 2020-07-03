#include "Mundo.h"
#include <math.h>
#include "Personaje.h"
#include "Interaccion.h"
#include "glut.h"
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Mundo::RotarOjo()
{
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Mundo::Dibuja()
{

	gluLookAt(personaje.posicion.x, personaje.posicion.y, z_ojo,  // posicion del ojo
			personaje.posicion.x, personaje.posicion.y, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


	//Fondo azul y marron
	glDisable(GL_LIGHTING);
	glColor3ub(0, 0, 240);
	glBegin(GL_POLYGON);
	    glVertex3d(0, -30, -5);
	    glVertex3d(100, -30, -5);
	    glVertex3d(100, 40, -5);
	    glVertex3d(0, 40, -5);
	glEnd();
	glColor3ub(128, 64, 0);
	glBegin(GL_POLYGON);
	    glVertex3d(0, -30, 5);
     	glVertex3d(-40, -30, 5);
	    glVertex3d(-40, 40, 5);
    	glVertex3d(0, 40, 5);
 	glEnd();
	glEnable(GL_LIGHTING);


	//AQUI ES DONDE HAY QUE PONER EL CODIGO DE DIBUJO
	nivel.dibuja();
	personaje.dibuja();
	//disparo.dibuja();
	disparos.dibuja();
	




	//FIN CODIGO DE DIBUJO
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Mundo::Mueve()
{
	if (personaje.cadencia > 0) personaje.cadencia--;
	personaje.mueve(0.025f);
	disparos.mueve(0.025f);
	Interaccion::colision(personaje, nivel);
	nivel.Perro.mueve(0.025f);
	//Interaccion::colision(nivel.Perro, nivel);
	nivel.Murcielago.mueve(0.025f);
	nivel.Mago.mueve(0.025f);
	Interaccion::giro_enemigos(nivel.Mago, personaje);
	nivel.Medusa.mueve(0.025f);
	nivel.Medusa.PosicionDisparo = personaje.posicion.x;
	Interaccion::rebote(nivel.Medusa, nivel.p_dcha[0]);
	Interaccion::rebote(nivel.Medusa, nivel.p_izq[0]);
	Interaccion::rebote(nivel.Medusa, nivel.suelo[0]);
	Interaccion::rebote(nivel.Medusa, nivel.techo[0]);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Mundo::Inicializa()
{
	x_ojo= 10.0f;
	y_ojo= 3.0f;
	z_ojo =20.0f;

	nivel.inicializa();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Mundo::Tecla(unsigned char key)
{
	if (key == 'w')
		personaje.velocidad.y = 10.0f;
	  //personaje.posicion.y += 0.03f;
	if (key == 's')
		personaje.velocidad.x = 0.0f;
	if (key == 'a')
	{
		//personaje.posicion.x -= 0.3f;
		personaje.velocidad.x = -7.0f;

	}
	if (key == 'd')
	{
	//personaje.posicion.x += 0.6f;
	personaje.velocidad.x = 7.0f;

	}

	if (key == ' ')
	{
		if (personaje.cadencia == 0) {
			Disparo* d = new Disparo();
			Vector2D pos = personaje.getPos();
			d->animacion.setSize(2, 2);
			d->animacion.setCenter(1, 1);
			d->distancia_maxima = 20;
			d->setPos(pos.x, pos.y);
			if (personaje.velocidad.x < 0)
				d->setVel(-14.0f, 0);
			if (personaje.velocidad.x > 0)
				d->setVel(+14.0f, 0);
			disparos.agregar(d);
			personaje.cadencia = 5;
		}
		//personaje.setVel(0, 0);
	}
		
	
	//ACERCAR O ALEJAR VISTA
	if (key == '+')
	    z_ojo -= 0.3f;
	if (key == '-')
		z_ojo += 0.3f;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------