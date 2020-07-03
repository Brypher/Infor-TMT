#pragma once

#include "Vector2D.h"
#include "ETSIDI.h"
#include "ListaDisparos.h"
#include "Pared.h"
#include "glut.h"

#define DERECHA false
#define IZQUIERDA true

using ETSIDI::SpriteSequence;

class Enemigo {
public:
	//ATRIBUTOS
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	int vida;
	bool orientacion; // true=mira izquierda,  false=mira derecha
	float altura;
public:
	//METODOS
	Enemigo(float x, float y) { posicion.x = x; posicion.y = y; }
	virtual ~Enemigo() {}
	virtual void dibuja() = 0;
	virtual void mueve(float t) = 0;
};
/////////////////////////////
//Enemigos normales
class EnemigoCorredor :public Enemigo {
private:
	SpriteSequence animacion;
public:
	EnemigoCorredor(float x, float y);
	virtual ~EnemigoCorredor() {}
	void dibuja();
	void mueve(float t) ;

};

class EnemigoVolador :public Enemigo {
private:
	SpriteSequence animacion;
	Vector2D origen;
	float RangoMovimiento;//Distancia maxima que se aleja el Muercielago antes de dar media vuelta
public:
	EnemigoVolador(float x, float y,float RangoMovimiento);
	virtual ~EnemigoVolador() {}
	void dibuja();
	void mueve(float t);

};


class EnemigoDisparador : public Enemigo {
	SpriteSequence animacion;
	ListaDisparos fuegos;
public:
	EnemigoDisparador(float x, float y);
	virtual ~EnemigoDisparador() {}
	void dibuja();
	void mueve(float t);
};
/////////////////////////////////////////
//Jefes finales

class Andromalius : public Enemigo {
	SpriteSequence animacion; //animacion del jefe
	SpriteSequence acido; // animacion del acido(disparo)
	Pared disparo; // Pared que va a servir para la interacción del chorro de ácido con el personaje
public:
	float PosicionDisparo; //Posicion del suelo de la que sale el ácido
public:
	Andromalius(float x, float y);
	virtual ~Andromalius() {}
	void dibuja();
	void mueve(float t);
};