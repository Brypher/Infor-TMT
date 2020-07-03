#pragma once
#include "Personaje.h"
#include "Nivel.h"
#include "Disparo.h"
#include "Plataforma.h"

class Interaccion
{
public:
	//ATRIBUTOS

public:
	//METODOS
	Interaccion();
	//	static void colision(EnemigoCorredor& e, Nivel n);
	static void colision (Personaje &p, Nivel n);
	static void giro_enemigos(Enemigo& e, Personaje& p);
	static void rebote(Andromalius& m, Pared p);
	static bool rebote_paredes(Personaje& pj, Pared p);
	static bool rebote_suelo(Personaje& pj, Pared s);
	static bool rebote_techo(Personaje& pj, Pared s);
	static void rebote_plataforma(Personaje& pj, Plataforma plat);
};

