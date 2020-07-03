#include "Interaccion.h"
#include "stdio.h"

#define DERECHA false
#define IZQUIERDA true

Interaccion::Interaccion(void)
{
	
}
//---------------------------------------------------------------------------------------------------------------------------------------------
bool Interaccion::rebote_paredes(Personaje& pj, Pared p) { //Rebote entre la esfera y la pared
	Vector2D dir;
	float dif = p.distancia(pj.posicion, &dir) - pj.altura;
	if (dif <= 0.0f)
	{

		pj.posicion = pj.posicion - dir * dif;
		return true;
	}
	return false;
}
bool Interaccion::rebote_suelo(Personaje& pj, Pared s) { //Rebote entre la esfera y la pared

	// se ordenan los límites para que no haya problema con la forma de creacion de la pared
	float aux;
	if (s.limite2.x < s.limite1.x) {
		aux = s.limite1.x;
		s.limite1.x = s.limite2.x;
		s.limite2.x = aux;
	}
	if (s.limite2.y < s.limite1.y) {
		aux = s.limite1.y;
		s.limite1.y = s.limite2.y;
		s.limite2.y = aux;
	}
	float y_suelo = s.limite1.y;

	if (abs(y_suelo - pj.posicion.y) < 1)
		if ((pj.posicion.x >= s.limite1.x) && (pj.posicion.x <= s.limite2.x)) {
			pj.velocidad.y = 0;
			pj.posicion.y = y_suelo + 1;
			return true;
		}
	return false;
}
bool Interaccion::rebote_techo(Personaje& pj, Pared t) { //Rebote entre la esfera y la pared
	
	// se ordenan los límites para que no haya problema con la forma de creacion de la pared
	float aux;
	if (t.limite2.x < t.limite1.x) {
		aux = t.limite1.x;
		t.limite1.x = t.limite2.x;
		t.limite2.x = aux;
	}
	if (t.limite2.y < t.limite1.y) {
		aux = t.limite1.y;
		t.limite1.y = t.limite2.y;
		t.limite2.y = aux;
	}
	float y_techo = t.limite1.y;

	if (abs(y_techo - pj.posicion.y) < 1)
		if ((pj.posicion.x >= t.limite1.x) && (pj.posicion.x <= t.limite2.x)) {
			pj.velocidad.y = 0;
			pj.posicion.y = y_techo -1;
			return true;
		}
	return false;

}
//---------------------------------------------------------------------------------------------------------------------------------------------
void Interaccion::rebote_plataforma(Personaje& pj, Plataforma plat) {
	rebote_techo(pj, plat.techo);
	rebote_suelo(pj, plat.suelo);
	rebote_paredes(pj, plat.p_dcha);
	rebote_paredes(pj, plat.p_izq);
}
//---------------------------------------------------------------------------------------------------------------------------------------------
void Interaccion::colision (Personaje &pj, Nivel n)
{

	for (int i = 0;i < N;i++) {
		rebote_paredes(pj, n.p_dcha[i]);
		rebote_paredes(pj, n.p_izq[i]);
		rebote_suelo(pj, n.suelo[i]);
		rebote_techo(pj, n.techo[i]);
		rebote_plataforma(pj, n.plataforma[i]);
	}

//////////////////////////////////////////////////////////////////////////////////////

}

//void Interaccion::colision(EnemigoCorredor& e, Nivel n)
//{
//
//	float PosX = e.posicion.x;
//	float PosY = e.posicion.y;
//	int nParedD = 0;
//	int nParedI = 0;
//	float Ymin = 0;
//	float Ymax = 40;
//	bool HayPlataforma = false;
//	float Yplataforma = 0;
//	float Ysuelo = 0;
//
//	//Interaccion enemigo-pared derecha
//	
//	if ((n.p_dcha[16].limite1.x - e.posicion.x) <= 0)
//		if ((e.posicion.y - n.p_dcha[16].limite2.y) < 1) {
//			e.velocidad.x = -e.velocidad.x;
//		}
//	//////////////////////////////////////////////////////////////////////////////
//		//Interaccion enemigo-pared izquierda
//
//	if ((e.posicion.x - n.p_izq[0].limite1.x) <= 0)
//		if ((e.posicion.y - n.p_izq[0].limite1.y) < 1)
//			//e.posicion.x = n.p_izq[nParedI].limite1.x + 1;
//			e.velocidad.x = -e.velocidad.x;
//	//Interaccion enemigo-suelo
//	for (int i = 0; i < N; i++)
//	{
//		if ((PosX < n.suelo[i].limite2.x) && (PosX > n.suelo[i].limite1.x))
//		{
//			Ymin = n.suelo[i].limite1.y;
//
//			for (int i = 0; i < N; i++)
//			{
//				if ((PosX < n.plataforma[i].limite2.x) && (PosX > n.plataforma[i].limite1.x) && (PosY > n.plataforma[i].limite1.y))
//				{
//					//HayPlataforma = true;
//					Ymin = n.plataforma[i].limite1.y;
//
//				}
//			}
//		}
//	}
//	if (e.posicion.y - 1 < Ymin) {
//		e.posicion.y = Ymin+1 ;
//		e.velocidad.y = 0;
//	}
//	////////////////////////////////////////////////////////////////////////////////////
//
//}

void Interaccion::giro_enemigos(Enemigo& e, Personaje& p) {
	if (p.posicion.x < e.posicion.x) e.orientacion = IZQUIERDA;
	else e.orientacion = DERECHA;
}

void Interaccion::rebote(Andromalius& m, Pared p) { //Rebote entre la esfera y la pared
	Vector2D dir;
	float dif = p.distancia(m.posicion, &dir) - m.altura;
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = m.velocidad;
		m.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
		m.posicion = m.posicion - dir * dif;
		
	}

}