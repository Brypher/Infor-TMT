#pragma once
#include "Pared.h"
#include "Vector2D.h"
#include "Enemigo.h"
#include "Plataforma.h"
#define N 50

class Nivel
{
	friend class Interaccion;
public: 
	//ATRIBUTOS
	//Suelo del nivel
	Pared suelo[N];
	Pared techo[N];
	Pared p_izq[N];
	Pared p_dcha[N];
	//Plataformas
	Plataforma plataforma[N];
	//Resto del nivel
	Pared tapa[N];
	Pared tapaPlat[N];
	Pared fondo;
	
	EnemigoCorredor Perro;
	EnemigoVolador Murcielago;
	EnemigoDisparador Mago;
	Andromalius Medusa;

public:
	//METODOS
	Nivel();
	virtual ~Nivel();
	void dibuja();
	void inicializa();


};

