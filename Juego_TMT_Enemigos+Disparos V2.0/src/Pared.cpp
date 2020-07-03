#include "Pared.h"
#include "glut.h"

Pared::Pared()  //CONSTRUCTOR
{

}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
Pared::~Pared()
{

}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Pared::dibuja() //DIBUJAR PAREDES
{
	glDisable(GL_LIGHTING);
    color.ponColor();
	glBegin(GL_POLYGON);
	    glVertex3d(limite1.x, limite1.y, 5);
	    glVertex3d(limite2.x, limite2.y, 5);
	    glVertex3d(limite2.x, limite2.y, -5);
	    glVertex3d(limite1.x, limite1.y, -5);
	glEnd();
	glEnable(GL_LIGHTING);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Pared::dibujaTapa(const char* texturepath) //DIBUJA TAPAS DEBAJO DE LA SUPERFICIE DEL NIVEL
{
	 glEnable(GL_TEXTURE_2D); 
	 glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(texturepath).id);
	 glDisable(GL_LIGHTING);
	 glBegin(GL_POLYGON); 
	 glColor3f(1, 1, 1);	
	 glTexCoord2d(0, 1);	glVertex3f(limite1.x, limite1.y,5);
	 glTexCoord2d(1, 1);	glVertex3f(limite2.x, limite1.y,5); 
	 glTexCoord2d(1, 0);	glVertex3f(limite2.x, -30, 5); 
	 glTexCoord2d(0, 0);	glVertex3f(limite1.x, -30, 5);  
	 glEnd(); 
	 glEnable(GL_LIGHTING);
	 glDisable(GL_TEXTURE_2D); 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Pared::dibujaTapaPlat() //DIBUJA TAPAS DEBAJO DE LA SUPERFICIE DEL NIVEL
{
	glDisable(GL_LIGHTING);
	glColor3ub(128, 64, 0);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 5);
	glVertex3d(limite2.x, limite1.y, 5);
	glVertex3d(limite2.x, limite1.y-0.5f , 5);
	glVertex3d(limite1.x, limite1.y-0.5f , 5);
	glEnd();
	glEnable(GL_LIGHTING);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void Pared::setPos(float x1, float y1, float x2, float y2) //POSICION DE LAS PAREDES
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Pared::setColor(Byte r, Byte v, Byte a) //ESTABLECER COLOR PAREDES
{
	color.set(r, v, a);
}

float Pared::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector…
		*direccion = dir.unitario();
	return distancia;
}