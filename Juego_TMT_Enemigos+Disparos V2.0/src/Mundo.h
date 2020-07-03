#include "Personaje.h"
#include "ListaDisparos.h"
#include "Disparo.h"
#include "Nivel.h"
#include "glut.h"
#include "Disparo.h"

class Mundo
{

private:
	//ATRIBUTOS
	float x_ojo;
	float y_ojo;
	float z_ojo;
	//añadir el resto de atributos
	//que son los objetos del escenario.
	Disparo disparo;
	Personaje personaje;
	Nivel nivel;
	ListaDisparos disparos;
	

public: 
	//METODOS
	void Tecla(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();

	

};
