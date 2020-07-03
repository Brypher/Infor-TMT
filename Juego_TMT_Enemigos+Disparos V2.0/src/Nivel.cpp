#include "Nivel.h"
#include "Vector2D.h"
#include "ColorRGB.h"
#include "glut.h"
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
Nivel::Nivel():Perro(12,5),Murcielago(3,5,3),Mago(5,3),Medusa(5,5)
{
	
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
Nivel::~Nivel()
{

}
void Nivel::inicializa()
{
	//COLORES DE LAS DIFERENTES PAREDES QUE FORMAN EL NIVEL
	for (int i = 0; i < N; i++)
		suelo[i].setColor(0, 100, 0); //VERDE 1
	for (int i = 0; i < N; i++)
		p_izq[i].setColor(0, 150, 0); //VERDE 2
	for (int i = 0; i < N; i++)
		p_dcha[i].setColor(0, 150, 0); //VERDE 1
	for (int i = 0; i < N; i++)
		techo[i].setColor(0, 100, 0); //VERDE 2
	for (int i = 0; i < N; i++)
		tapaPlat[i].setColor(128, 64, 0); //Marron
	for (int i = 0; i < N; i++)
		tapa[i].setColor(128, 64, 0); //Marron

		//IMPORTANTE, PARA LA PARED DERECHA, LIM1Y ES LA MAS BAJA Y LIM2Y LA MAS ALTA  //EJEMPLO p_dcha[1].setPos(6,0,6,1);
		//IMPORTANTE, PARA LA PARED IZQUIERDA, LIM1Y ES LA MAS ALTA Y LIM2Y LA MAS BAJA  //EJEMPLO p_izq[1].setPos(10, 1, 10, 0);

	//SUPERFICIE DEL NIVEL

	p_izq[0].setPos(0, 40, 0, 15);
	suelo[0].setPos(0, 15, 6, 15);
	p_izq[1].setPos(6, 15, 6, 12);
	suelo[1].setPos(6, 12, 10, 12);
	p_izq[2].setPos(10, 12, 10, 9);
	suelo[2].setPos(10, 9, 25, 9);
	p_dcha[0].setPos(25, 9, 25, 15);
	suelo[3].setPos(25, 15, 42, 15);
	p_dcha[1].setPos(42, 15, 42, 21);
	suelo[4].setPos(42, 21, 48, 21);
	p_dcha[2].setPos(48, 21, 48, 25);
	techo[0].setPos(48, 25, 42, 25);
	p_dcha[3].setPos(42, 25, 42, 30);
	suelo[5].setPos(42, 30, 50, 30);
	p_izq[3].setPos(50, 30, 50, 5);
	suelo[6].setPos(50, 5, 70, 5);
	p_dcha[4].setPos(70, 5, 70, 8);
	suelo[7].setPos(70, 8, 77, 8);
	p_dcha[5].setPos(77, 8, 77, 11);
	suelo[8].setPos(77, 11, 87, 11);
	p_dcha[6].setPos(87, 11, 87, 13);
	suelo[9].setPos(87, 13, 90, 13);
	p_izq[4].setPos(90, 13, 90, 11);
	suelo[10].setPos(90, 11, 100, 11);
	p_dcha[7].setPos(100, 11, 100, 40);

	//Nivel Jefes
		//p_izq[0].setPos(0, 30, 0, 0);
		//suelo[0].setPos(0, 0, 40, 0);
		//p_dcha[0].setPos(40, 0, 40, 30);
		//techo[0].setPos(0, 30, 40, 30);

			//Plataformas

	plataforma[0].setPos(6, 20, 10, 20);
	plataforma[1].setPos(6, 25, 10, 25);
	//Plataformas Jefes
		//plataforma[0].setPos(10, 6, 17, 6);
		//plataforma[1].setPos(23, 6, 30, 6);
		//plataforma[2].setPos(13.5, 12, 26.5, 12);




		//TAPA SUELO
	for (int i = 0; i < N; i++)
		tapa[i].setPos(suelo[i].limite1.x, suelo[i].limite1.y, suelo[i].limite2.x, -30);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Nivel::dibuja()
{
	Medusa.dibuja();
	Mago.dibuja();
	Murcielago.dibuja();
	Perro.dibuja();
	//Pinta todos los suelos
	for (int i = 0; i < N; i++)
	    suelo[i].dibuja();
	//Pinta todas las paredes que van a quedar a la izq del jugador
    for (int i = 0; i < N; i++)
		p_izq[i].dibuja();
    //Pinta todas las paredes que van a quedar a la dcha del jugador
    for (int i = 0; i < N; i++)
	    p_dcha[i].dibuja();
    //Pinta todos los techos
    for (int i = 0; i < N; i++)
	    techo[i].dibuja();
	//Pinta todas las plataformas
	for (int i = 0; i < N; i++)
	{
    plataforma[i].dibuja();
	}
    //Superficie lateral suelo
    for (int i = 0; i < N; i++)
	    tapa[i].dibujaTapa("imagenes/ladrillos.png");
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------