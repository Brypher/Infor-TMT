#include "Enemigo.h"
#include <cmath>


///////////////////////////////////////////////
//EnemigoCorredor
EnemigoCorredor::EnemigoCorredor(float x, float y):Enemigo(x, y) , animacion("imagenes/hell-hound-run.png", 5) {
	animacion.setCenter(2,1);
	animacion.setSize(4, 2);
	velocidad.x =-20;
	aceleracion.y = -30.0f;
	vida = 1;
}

void EnemigoCorredor::mueve(float t){
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	animacion.loop();
}


void EnemigoCorredor::dibuja(){
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);

	//Animacion del sprite
	if (velocidad.x > 0)animacion.flip(true, false);
	if (velocidad.x < 0)animacion.flip(false, false);
	animacion.draw();

	glPopMatrix();
}


//////////////////////////////////////////////////////////////////////////////////////////
//EnemigoVolador

EnemigoVolador::EnemigoVolador(float x, float y, float rango) :Enemigo(x, y), animacion("imagenes/bat-orig.png", 4,4) {
	animacion.setCenter(1, 0.75);
	animacion.setSize(2,1.5 );
	animacion.setState(4, false);
	velocidad.x = 10;
	aceleracion.y = 0.0f;
	origen = posicion;
	RangoMovimiento = rango;
	vida = 2;
}

void EnemigoVolador::mueve(float t) {
	animacion.loop();
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	if (abs(posicion.x - origen.x) >= RangoMovimiento)
		velocidad.x = -velocidad.x;
	
}


void EnemigoVolador::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);

	//Animacion del sprite
	if (velocidad.x > 0)animacion.flip(false, false);
	if (velocidad.x < 0)animacion.flip(true, false);
	if (animacion.getState() == 8)
		animacion.setState(4,false);
	animacion.draw();

	glPopMatrix();
}

//////////////////////////////////////////////////////////////
//EnemigoDisparador

EnemigoDisparador::EnemigoDisparador(float x, float y ) :Enemigo(x, y), animacion("imagenes/Magician_Skeleton.png", 5, 2,75) {
	animacion.setCenter(2, 1.5);
	animacion.setSize(3, 3);
	velocidad.y=velocidad.x = 0;
	aceleracion.y =aceleracion.x= 0.0f;
	orientacion = IZQUIERDA;
	vida = 4;
	}

void EnemigoDisparador::mueve(float t) {
	animacion.loop();
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	fuegos.mueve(t);
	

}


void EnemigoDisparador::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y+1.5, 0);

	//Animacion del sprite
	if (orientacion == IZQUIERDA)
		animacion.flip(false,false);
	if (orientacion == DERECHA)
		animacion.flip(true, false);
	animacion.draw();
	////////////////////////////////
	//Gestion Disparos
	if (animacion.getState() == 9) {
		Disparo* aux = new Disparo();
		aux->animacion.setSize(1.5, 0.7);
		aux->animacion.setCenter(1, 0.5);
		aux->radio = 0.7f;
		aux->distancia_maxima = 5.0f;

		// orientacion del disparo
		if (orientacion == IZQUIERDA) {
			aux->orientacion = IZQUIERDA;
			aux->setVel(-8, 0);
			aux->setPos(posicion.x - 1.5, posicion.y + 1.5);
		}
		if (orientacion == DERECHA) {
			aux->setVel(8, 0);
			aux->setPos(posicion.x + 1.5, posicion.y + 1.5);
			aux->orientacion = DERECHA;
		}

		fuegos.agregar(aux);
		animacion.setState(0, false);
	}
	glPopMatrix();
	fuegos.dibuja();
}
//////////////////////////////////////////////////////////////////
Andromalius::Andromalius(float x, float y) :Enemigo(x, y), animacion("imagenes/MedusaVerde.png", 8, 3),acido("imagenes/acid.png",8,3,75) {
	altura = 3.0f;
	animacion.setSize(6,6);
	animacion.setCenter(3, 3);
	acido.setState(23,false);
	acido.setSize(2, 15);
	acido.setCenter(1, 0);
	velocidad.x = velocidad.y = 13;
	aceleracion.x = aceleracion.y = 0;
	orientacion = DERECHA;

	vida = 15;
}


void Andromalius::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);

	//Animacion del sprite
	if (velocidad.x > 0) {
		orientacion = DERECHA;
		animacion.flip(false, false);
	}

	if (velocidad.x < 0) {
		orientacion = IZQUIERDA;
		animacion.flip(true, false);
	}
	if (animacion.getState() == 15)
		animacion.setState(0, false);
	animacion.draw();
	//glutWireSphere(altura, 20, 20);
	glPopMatrix();

	//////////////////////////////////////////////
	//Gestion disparo

	//La pared se va ajustando a la animación del chorro de ácido
	if (acido.getState() == 0) {
		acido.setPos(PosicionDisparo, 0);
		disparo.limite1.x = disparo.limite2.x = PosicionDisparo;
		disparo.limite1.y = 15; disparo.limite2.y = 12; //estado 0
	}else if (acido.getState() == 1){
		disparo.limite1.y = 15; disparo.limite2.y = 10.5f;// estado 1
	}else if(acido.getState() == 2) {
		disparo.limite1.y = 15; disparo.limite2.y = 8.5f;  // estado 2
	}else if (acido.getState() == 3) {
	disparo.limite1.y = 15; disparo.limite2.y = 7.0f; //estado 3
	}else if (acido.getState() == 4) {
	disparo.limite1.y = 15; disparo.limite2.y = 5.0f; //estado 4
	}else if (acido.getState() == 5) {
	disparo.limite1.y = 15; disparo.limite2.y = 3.0f; //estado 5
	}else if (acido.getState() == 6) {
	disparo.limite1.y = 15; disparo.limite2.y = 1.5f; //estado 6
	}else if (acido.getState() >= 7 && acido.getState()<=15) {
	disparo.limite1.y = 15; disparo.limite2.y = 0.0f;// estado 7-15
	}else if (acido.getState() == 16) {
	disparo.limite1.y = 13; disparo.limite2.y = 0.0f;// estado 16
	}else if (acido.getState() == 17) {
	disparo.limite1.y = 11; disparo.limite2.y = 0.0f; //estado 17
	}else if (acido.getState() == 18) {
	disparo.limite1.y = 9.5; disparo.limite2.y = 0.0f; //estado 18
	}else if (acido.getState() == 19) {
	disparo.limite1.y = 7.7f; disparo.limite2.y = 0.0f; //estado 19
	}else if (acido.getState() == 20) {
	disparo.limite1.y = 5.7; disparo.limite2.y = 0.0f; //estado 20
	}else if (acido.getState() == 21) {
	disparo.limite1.y = 4; disparo.limite2.y = 0.0f; //estado 21
	}else if (acido.getState() == 22) {
	disparo.limite1.y = 2; disparo.limite2.y = 0.0f; //estado 22
	}else if (acido.getState() == 23) {
		disparo.limite1.y = 1; disparo.limite2.y = 0.0f;// estado 23
	}
	acido.draw();
	disparo.dibuja();



}
void Andromalius::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	animacion.loop();
	acido.loop();
}