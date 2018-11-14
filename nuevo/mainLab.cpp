//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "Camera.h"
#include "figuras.h"
#include "FigPropias.h"


//	Prototipos de funciones
void fachada();
void silla();
void arbol(const GLuint &text);
void sillon_uno();
void mesa_comedor();
void sillon_dos();
void lampara();
void paloma();
void tele();
void mesa_sala();


/*int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;*/

static GLuint ciudad_display_list;	//Display List for the Monito


									//NEW// Keyframes
float posX = 4, posY = 0, posZ = -4, rotRodIzq = 0, rotRodDer = 0.0, rotBrazoIzq = 0.0, rotBrazoDer = 0.0;
float movBrazoIzq = 0.0;
float giroMonito = 0;
float movBrazoDer = 0.0;
float movCuerpo = 0.0;

// variables para fantasma
float movfantX = 0;
float movfantY = 0;
bool animac = true;
bool animac2 = false;
float grados = 0;

#define MAX_FRAMES 200		//cuantos cuadros clave se van a utilizar (keyframes)
int i_max_steps = 90;
int i_curr_steps = 0;
typedef struct _frame
{

	float mov_pelotaX;
	float mov_pelotaY;
	float mov_pelotaZ;
	float rot_pelotaX;
	float rot_pelotaY;
	float rot_pelotaZ;

	float IncX;
	float IncZ;
	float IncY;
	float IncRotX;
	float IncRotY;
	float IncRotZ;

	float giroPuerta;
	float giroPuertaInc;
	float giroVentana;
	float giroVentanaInc;

	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ

	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	/*
	//Variables para GUARDAR Key Frames

	float rotRodIzq;
	float rotRodDer;

	float rotRodIzqInc;
	float rotRodDerInc;

	float giroMonito;
	float giroMonitoInc;
	
	float movBrazoDer;
	float movBrazoDerInc;
	
	float movBrazoIzq;
	float movBrazoIzqInc;
	
	float rotBrazoIzq;
	float rotBrazoDer;
	float rotBrazoDerInc;
	float rotBrazoIzqInc;
	
	float rotInc;

	float movCuerpo;
	float movCuerpoInc;
	*/

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 7;			//introducir datos
bool play = false;
int playIndex = 0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, time2, timebase = 0;
char s[30];


// Variables para keyframe
float mov_pelotaX = 0.0;
float mov_pelotaY = 0.0;
float mov_pelotaZ = 0.0;
float rot_pelotaX = 0.0;
float rot_pelotaY = 0.0;
float rot_pelotaZ = 0.0;

float IncX = 0.0;
float IncZ = 0.0;
float IncY = 0.0;
float IncRotX = 0.0;
float IncRotY = 0.0;
float IncRotZ = 0.0;

// variables para giros
float giroPuerta = 0;
float giroVentana = 0;


//	Objeto para dibujar figuras
Figures figures;

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

//Variables de apoyo para colocar figuras
float xx=0.0, yy = 0.0, zz = 0.0;
float tamx = 1.0, tamy = 1.0, tamz = 1.0;

//	Variables para animar a la paloma
GLfloat pos_paloma_x = 0.f;
GLfloat pos_paloma_y = 15.f;
GLfloat pos_paloma_z = -13.f;
GLfloat rot_paloma = 0.f;
GLfloat ant_pos_paloma_z = 0.f;

//	Variables para animar la pelota
GLfloat pos_ball_x = 0.f;
GLfloat pos_ball_y = 23.0f;
GLfloat pos_ball_z = -5.6f;
GLfloat rot_ball_x = 0.f;
GLfloat par_pos_ball_x_ini = 0.f;
GLfloat par_pos_ball_y_ini = 23.0f;
GLfloat par_pos_ball_z_ini = -5.6f;
GLfloat v_ini_ball = 10;
GLfloat angle_ball = 3.141592 / 10;
GLfloat ball_t = 0;
const GLfloat gravity = 9.81;
int estadoPelota = 1;

// Variable inicial de la paloma
int estadopaloma = 1;

//	Variables para animar la textura
GLdouble estadoTelevision = 1.0;

// Objeto de figuras.cpp
CFiguras fig7;

//	Texturas
CTexture window_texture;
CTexture cuarzo;
CTexture metal_cromo;
CTexture pared_interior;
CTexture puertaFrente;
CTexture garage;

CTexture pisoRojo;
CTexture pisoPatioT;

CTexture cielo_lateral;
CTexture cielo_frontal;
CTexture cielo_superior;
CTexture pasto;
CTexture lamp;
CTexture tocador;
CTexture t1;
CTexture t2;
CTexture t3;
CTexture t4;
CTexture t5;
CTexture t6;
CTexture t7;
CTexture t8;
CTexture t9;
CTexture t10;
CTexture t11;
CTexture t12;
CTexture t13;
CTexture t14;
CTexture sillon;
CTexture vitrina;
CTexture chimenea;
CTexture madera;
CTexture muebleBanio;
CTexture muebleBanio2;
CTexture negroMate;
CTexture almohada;
CTexture cabecera;
CTexture cobija;
CTexture tree_tex;
CTexture ball;
CTexture estante;
CTexture fondo_lad;
CTexture centro_mesa;
CTexture plata;
CTexture ball_basq;
CTexture skyboxparedes;
CTexture piedra;
CTexture puertacuartos;
CTexture ventanacuartos;
CTexture puerta3;
CTexture puerta4;
CTexture foto;
CTexture picado1;
CTexture frank;
CTexture pielfrank;
CTexture bosque2;
CTexture pisomadera;
CTexture calabaza;
CTexture fantasma;
CTexture picado2;
CTexture cempa;
CTexture panmuerto;

//CTexture tree;

const double PI = 3.1415926535897;



void saveFrame ( void )
{
	
	printf("frameindex %d\n",FrameIndex);			

	KeyFrame[FrameIndex].mov_pelotaX = mov_pelotaX;
	KeyFrame[FrameIndex].mov_pelotaY = mov_pelotaY;
	KeyFrame[FrameIndex].mov_pelotaZ = mov_pelotaZ;
	KeyFrame[FrameIndex].rot_pelotaX = rot_pelotaX;
	KeyFrame[FrameIndex].rot_pelotaY = rot_pelotaY;
	KeyFrame[FrameIndex].rot_pelotaZ = rot_pelotaZ;
	KeyFrame[FrameIndex].giroVentana = giroVentana;
	KeyFrame[FrameIndex].giroPuerta = giroPuerta;
	KeyFrame[FrameIndex].posX = posX;
	KeyFrame[FrameIndex].posY = posY;
	KeyFrame[FrameIndex].posZ = posZ;
		
	printf("KeyFrame[%i].giroVentana = %f \n", FrameIndex, giroVentana);
	printf("KeyFrame[%i].giroPuerta = %f \n", FrameIndex, giroPuerta);
	printf("KeyFrame[%i].posX = %f \n", FrameIndex, posX);
	printf("KeyFrame[%i].posY = %f \n", FrameIndex, posY);
	printf("KeyFrame[%i].posZ = %f \n", FrameIndex, posZ);

	FrameIndex++;

}

void resetElements( void )
{
	mov_pelotaX = KeyFrame[0].mov_pelotaX;
	mov_pelotaY = KeyFrame[0].mov_pelotaY;
	mov_pelotaZ = KeyFrame[0].mov_pelotaZ;
	rot_pelotaX = KeyFrame[0].rot_pelotaX;
	rot_pelotaY = KeyFrame[0].rot_pelotaY;
	rot_pelotaZ = KeyFrame[0].rot_pelotaZ;
	posX = KeyFrame[0].posX;
	posY = KeyFrame[0].posY;
	posZ = KeyFrame[0].posZ;
	giroPuerta = KeyFrame[0].giroPuerta;
	giroVentana = KeyFrame[0].giroVentana;

}

void interpolation ( void )
{
	KeyFrame[playIndex].IncX = (KeyFrame[playIndex + 1].mov_pelotaX - KeyFrame[playIndex].mov_pelotaX) / i_max_steps;
	KeyFrame[playIndex].IncY = (KeyFrame[playIndex + 1].mov_pelotaY - KeyFrame[playIndex].mov_pelotaY) / i_max_steps;
	KeyFrame[playIndex].IncZ = (KeyFrame[playIndex + 1].mov_pelotaZ - KeyFrame[playIndex].mov_pelotaZ) / i_max_steps;	
	KeyFrame[playIndex].IncRotX = (KeyFrame[playIndex + 1].rot_pelotaX - KeyFrame[playIndex].rot_pelotaX) / i_max_steps;
	KeyFrame[playIndex].IncRotY = (KeyFrame[playIndex + 1].rot_pelotaY - KeyFrame[playIndex].rot_pelotaY) / i_max_steps;
	KeyFrame[playIndex].IncRotZ = (KeyFrame[playIndex + 1].rot_pelotaZ - KeyFrame[playIndex].rot_pelotaZ) / i_max_steps;
	KeyFrame[playIndex].giroVentanaInc = (KeyFrame[playIndex + 1].giroVentana - KeyFrame[playIndex].giroVentana) / i_max_steps;		//100 frames
	KeyFrame[playIndex].giroPuertaInc = (KeyFrame[playIndex + 1].giroPuerta - KeyFrame[playIndex].giroPuerta) / i_max_steps;		//100 frames
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//100 frames				

}



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.3f);


	//	Texturas
	cuarzo.LoadTGA("textures/paredExt.tga");
	cuarzo.BuildGLTexture();
	cuarzo.ReleaseImage();

	metal_cromo.LoadTGA("textures/metal_cromo.tga");
	metal_cromo.BuildGLTexture();
	metal_cromo.ReleaseImage();

	tocador.LoadTGA("textures/tocador.tga");
	tocador.BuildGLTexture();
	tocador.ReleaseImage();

	pared_interior.LoadTGA("textures/pared.tga");
	pared_interior.BuildGLTexture();
	pared_interior.ReleaseImage();

	puertaFrente.LoadTGA("textures/puerta.tga");
	puertaFrente.BuildGLTexture();
	puertaFrente.ReleaseImage();

	garage.LoadTGA("textures/garage.tga");
	garage.BuildGLTexture();
	garage.ReleaseImage();

	estante.LoadTGA("textures/estante.tga");
	estante.BuildGLTexture();
	estante.ReleaseImage();

	fondo_lad.LoadTGA("textures/ladrillo_fachada.tga");
	fondo_lad.BuildGLTexture();
	fondo_lad.ReleaseImage();

	centro_mesa.LoadTGA("textures/centro_mesa.tga");
	centro_mesa.BuildGLTexture();
	centro_mesa.ReleaseImage();

	t1.LoadTGA("textures/t1.tga");
	t1.BuildGLTexture();
	t1.ReleaseImage();

	t2.LoadTGA("textures/t2.tga");
	t2.BuildGLTexture();
	t2.ReleaseImage();

	t3.LoadTGA("textures/t3.tga");
	t3.BuildGLTexture();
	t3.ReleaseImage();

	t4.LoadTGA("textures/t4.tga");
	t4.BuildGLTexture();
	t4.ReleaseImage();

	t5.LoadTGA("textures/t5.tga");
	t5.BuildGLTexture();
	t5.ReleaseImage();

	t6.LoadTGA("textures/t6.tga");
	t6.BuildGLTexture();
	t6.ReleaseImage();

	t7.LoadTGA("textures/t7.tga");
	t7.BuildGLTexture();
	t7.ReleaseImage();

	t8.LoadTGA("textures/t8.tga");
	t8.BuildGLTexture();
	t8.ReleaseImage();

	t9.LoadTGA("textures/t9.tga");
	t9.BuildGLTexture();
	t9.ReleaseImage();

	t10.LoadTGA("textures/t10.tga");
	t10.BuildGLTexture();
	t10.ReleaseImage();

	t11.LoadTGA("textures/t11.tga");
	t11.BuildGLTexture();
	t11.ReleaseImage();

	t12.LoadTGA("textures/t12.tga");
	t12.BuildGLTexture();
	t12.ReleaseImage();

	t13.LoadTGA("textures/t13.tga");
	t13.BuildGLTexture();
	t13.ReleaseImage();

	t14.LoadTGA("textures/t14.tga");
	t14.BuildGLTexture();
	t14.ReleaseImage();

	pisoRojo.LoadTGA("textures/piso_entrada.tga");
	pisoRojo.BuildGLTexture();
	pisoRojo.ReleaseImage();

	chimenea.LoadTGA("textures/chimenea.tga");
	chimenea.BuildGLTexture();
	chimenea.ReleaseImage();

	lamp.LoadTGA("textures/lampara.tga");
	lamp.BuildGLTexture();
	lamp.ReleaseImage();

	pisoPatioT.LoadTGA("textures/ladrillo.tga");
	pisoPatioT.BuildGLTexture();
	pisoPatioT.ReleaseImage();

	plata.LoadTGA("textures/plata.tga");
	plata.BuildGLTexture();
	plata.ReleaseImage();

	sillon.LoadTGA("textures/sillon.tga");
	sillon.BuildGLTexture();
	sillon.ReleaseImage();

	cielo_frontal.LoadTGA("textures/cielo_2.tga");
	cielo_frontal.BuildGLTexture();
	cielo_frontal.ReleaseImage();	

	cielo_lateral.LoadTGA("textures/cielo_3.tga");
	cielo_lateral.BuildGLTexture();
	cielo_lateral.ReleaseImage();

	cielo_superior.LoadTGA("textures/cielo.tga");
	cielo_superior.BuildGLTexture();
	cielo_superior.ReleaseImage();

	pasto.LoadTGA("textures/pasto.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	madera.LoadTGA("textures/madera_clara.tga");
	madera.BuildGLTexture();
	madera.ReleaseImage();

	negroMate.LoadTGA("textures/negroMate.tga");
	negroMate.BuildGLTexture();
	negroMate.ReleaseImage();

	almohada.LoadTGA("textures/almohada.tga");
	almohada.BuildGLTexture();
	almohada.ReleaseImage();

	cabecera.LoadTGA("textures/cabecera.tga");
	cabecera.BuildGLTexture();
	cabecera.ReleaseImage();

	cobija.LoadTGA("textures/cobija.tga");
	cobija.BuildGLTexture();
	cobija.ReleaseImage();

	tree_tex.LoadTGA("textures/arbol.tga");
	tree_tex.BuildGLTexture();
	tree_tex.ReleaseImage();

	window_texture.LoadTGA("textures/window.tga");
	window_texture.BuildGLTexture();
	window_texture.ReleaseImage();

	ball.LoadTGA("textures/ball.tga");
	ball.BuildGLTexture();
	ball.ReleaseImage();

	ball_basq.LoadTGA("textures/balon_basq.tga");
	ball_basq.BuildGLTexture();
	ball_basq.ReleaseImage();

	skyboxparedes.LoadTGA("textures/bosque1.tga");
	skyboxparedes.BuildGLTexture();
	skyboxparedes.ReleaseImage();

	piedra.LoadTGA("textures/piedra.tga");
	piedra.BuildGLTexture();
	piedra.ReleaseImage();

	puertacuartos.LoadTGA("textures/puerta2.tga");
	puertacuartos.BuildGLTexture();
	puertacuartos.ReleaseImage();

	ventanacuartos.LoadTGA("textures/ventana2.tga");
	ventanacuartos.BuildGLTexture();
	ventanacuartos.ReleaseImage();

	puerta3.LoadTGA("textures/puerta3.tga");
	puerta3.BuildGLTexture();
	puerta3.ReleaseImage();

	puerta4.LoadTGA("textures/puerta4.tga");
	puerta4.BuildGLTexture();
	puerta4.ReleaseImage();

	picado1.LoadTGA("textures/picadoTransparente.tga");
	picado1.BuildGLTexture();
	picado1.ReleaseImage();

	foto.LoadTGA("textures/epn.tga");
	foto.BuildGLTexture();
	foto.ReleaseImage();

	for(int i=0; i<MAX_FRAMES; i++)
	frank.LoadTGA("textures/frank.tga");
	frank.BuildGLTexture();
	frank.ReleaseImage();

	pielfrank.LoadTGA("textures/piel.tga");
	pielfrank.BuildGLTexture();
	pielfrank.ReleaseImage();

	bosque2.LoadTGA("textures/bosque2.tga");
	bosque2.BuildGLTexture();
	bosque2.ReleaseImage();

	pisomadera.LoadTGA("textures/pisomadera.tga");
	pisomadera.BuildGLTexture();
	pisomadera.ReleaseImage();

	calabaza.LoadTGA("textures/calabaza.tga");
	calabaza.BuildGLTexture();
	calabaza.ReleaseImage();

	fantasma.LoadTGA("textures/fantasma.tga");
	fantasma.BuildGLTexture();
	fantasma.ReleaseImage();

	picado2.LoadTGA("textures/picado2.tga");
	picado2.BuildGLTexture();
	picado2.ReleaseImage();

	cempa.LoadTGA("textures/cempa.tga");
	cempa.BuildGLTexture();
	cempa.ReleaseImage();

	panmuerto.LoadTGA("textures/panmuerto.tga");
	panmuerto.BuildGLTexture();
	panmuerto.ReleaseImage();

	/*for(int i=0; i<MAX_FRAMES; i++)
>>>>>>> 1ad99b980d6a1573e4d938aa7c9d270acde0291e
	{
		KeyFrame[i].mov_pelotaX = 0;
		KeyFrame[i].mov_pelotaY = 0;
		KeyFrame[i].mov_pelotaZ = 0;
		KeyFrame[i].rot_pelotaX = 0;
		KeyFrame[i].rot_pelotaY = 0;
		KeyFrame[i].rot_pelotaZ = 0;
		KeyFrame[i].IncX = 0;
		KeyFrame[i].IncY = 0;
		KeyFrame[i].IncZ = 0;
		KeyFrame[i].IncRotX = 0;
		KeyFrame[i].IncRotY = 0;
		KeyFrame[i].IncRotZ = 0;
	}*/
	/*
	KeyFrame[0].giroVentana = 0.000000; 
	KeyFrame[0].giroPuerta = 0.000000;

	KeyFrame[1].giroVentana = 78.000000;	
	KeyFrame[1].giroPuerta = 0.000000;

	KeyFrame[2].giroVentana = 78.000000; 
	KeyFrame[2].giroPuerta = -74.000000;

	KeyFrame[3].giroVentana = 78.000000; 
	KeyFrame[3].giroPuerta = 74.000000;

	KeyFrame[4].giroVentana = 78.000000; 
	KeyFrame[4].giroPuerta = 0.000000;

	KeyFrame[5].giroVentana = 78.000000; 
	KeyFrame[5].giroPuerta = -59.000000;

	KeyFrame[6].giroVentana = 78.000000; 
	KeyFrame[6].giroPuerta = 0.000000;

	KeyFrame[7].giroVentana = 4.000000; 
	KeyFrame[7].giroPuerta = 0.000000; 

	KeyFrame[8].giroVentana = -75.000000; 
	KeyFrame[8].giroPuerta = 0.000000; 

	KeyFrame[9].giroVentana = 53.000000; 
	KeyFrame[9].giroPuerta = 0.000000;

	KeyFrame[10].giroVentana = 0.000000; 
	KeyFrame[10].giroPuerta = 0.000000;
	*/

	//frameindex 0
	//KeyFrame[0].giroVentana = 0.000000; 
	KeyFrame[0].giroPuerta = 0.000000; 
	KeyFrame[0].posX = 4.000000; 
	KeyFrame[0].posY = 0.000000; 
	KeyFrame[0].posZ = -4.000000; 
	//frameindex 1
	//KeyFrame[1].giroVentana = 0.000000; 
	KeyFrame[1].giroPuerta = -93.000000; 
	KeyFrame[1].posX = 4.000000; 
	KeyFrame[1].posY = 0.000000; 
	KeyFrame[1].posZ = -4.000000; 
	//frameindex 2
	//KeyFrame[2].giroVentana = 0.000000; 
	KeyFrame[2].giroPuerta = -93.000000; 
	KeyFrame[2].posX = -0.200001; 
	KeyFrame[2].posY = 0.000000; 
	KeyFrame[2].posZ = -4.000000; 
	//frameindex 3
	//KeyFrame[3].giroVentana = 0.000000; 
	KeyFrame[3].giroPuerta = -93.000000; 
	KeyFrame[3].posX = -0.200001; 
	KeyFrame[3].posY = 0.000000; 
	KeyFrame[3].posZ = 3.400001; 
	//frameindex 4
	//KeyFrame[4].giroVentana = 0.000000; 
	KeyFrame[4].giroPuerta = -93.000000; 
	KeyFrame[4].posX = -0.200001; 
	KeyFrame[4].posY = 0.000000; 
	KeyFrame[4].posZ = -4.000000; 
	//frameindex 5
	//KeyFrame[5].giroVentana = 0.000000; 
	KeyFrame[5].giroPuerta = -93.000000; 
	KeyFrame[5].posX = 5.199999; 
	KeyFrame[5].posY = 0.000000; 
	KeyFrame[5].posZ = -4.000000; 
	//frameindex 6
	//KeyFrame[6].giroVentana = 0.000000; 
	KeyFrame[6].giroPuerta = 0.000000; 
	KeyFrame[6].posX = 4.000000; 
	KeyFrame[6].posY = 0.000000; 
	KeyFrame[6].posZ = -4.000000; 

	//	posicion     (0, 2.5, 3)
	//	hacia donde  (0, 2.5, 0)
	//	inclinación  (0, 1, 0)
	objCamera.Position_Camera(9.5, 2.5f, 40, 9.5, 2.5f, 37, 0, 1, 0);

	//	Reproducir música si se está en Windows
	#if _WIN32
	PlaySound(TEXT("halo_channel.wav"), NULL, SND_LOOP | SND_ASYNC);
	#endif

}

void puertas(void){

	//Puerta frontal
	glPushMatrix();
		glTranslatef(-2.5, 6, 18.005);
		glScalef(5, 12, 1);
		glBindTexture(GL_TEXTURE_2D, puerta4.GLindex);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 0); glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0, 1); glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0.5);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.5, 6, 18.005);
		glScalef(5, 12, 1);
		glBindTexture(GL_TEXTURE_2D, puerta3.GLindex);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 0); glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0, 1); glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0.5);
		glEnd();
	glPopMatrix();

}

void monito()
{
	glPushMatrix();

	glTranslatef(posX,posY,posZ);
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho

	glTranslatef(0.0, movCuerpo, 0.0);
	glScalef(0.5, 0.5, 0.5);
	fig7.prisma(2.0, 2.0, 1, pielfrank.GLindex);

	glPushMatrix();//Cuello
	glTranslatef(0, 1.0, 0.0);
	fig7.cilindro(0.25, 0.25, 15, pielfrank.GLindex);
	glPushMatrix();//Cabeza
	glTranslatef(0, 1.0, 0);
	glRotatef(90,0,1,0);
	fig7.esfera(0.75, 15, 15, frank.GLindex);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo derecho-->
	glTranslatef(1.25, 0.65, 0);
	glRotatef(rotBrazoDer, 0.0, 1.0, 0.0);
	glRotatef(movBrazoDer, 0.0, 0.0, 1.0);
	fig7.esfera(0.5, 12, 12, pielfrank.GLindex);
	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glRotatef(-25, 0, 0, 1);
	glRotatef(-25, 1, 0, 0);
	glTranslatef(0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, pielfrank.GLindex);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo izquierdo <--
	glTranslatef(-1.25, 0.65, 0);
	glRotatef(rotBrazoIzq, 0, 1, 0);
	glRotatef(movBrazoIzq, 0.0, 0.0, 1.0);

	fig7.esfera(0.5, 12, 12, pielfrank.GLindex);
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);
	glRotatef(25, 0, 0, 1);
	glRotatef(25, 1, 0, 0);
	glTranslatef(-0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, pielfrank.GLindex);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Cintura
	glColor3f(.349, .2078, .1215);
	glTranslatef(0, -1.5, 0);
	fig7.prisma(1, 2, 1, pielfrank.GLindex);

	//glTranslatef(0.0, movCuerpo+1.5, 0.0);


	glPushMatrix(); //Pie Derecho -->
	glTranslatef(0.75, -0.5, 0);
	//glRotatef(-15, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, pielfrank.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	//glRotatef(15 + rotRodDer, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, pielfrank.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	//glRotatef(15 - rotRodDer, 1, 0, 0);
	fig7.prisma(0.2, 1.2, 1.5, pielfrank.GLindex);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //Pie Izquierdo -->
	glTranslatef(-0.75, -0.5, 0);
	//glRotatef(-5, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, pielfrank.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	//glRotatef(15 + rotRodIzq, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, pielfrank.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	//glRotatef(15 - rotRodIzq, 1, 0, 0);
	fig7.prisma(0.2, 1.2, 1.5, pielfrank.GLindex);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();

	glPopMatrix();
}

void crearFantasma(){
	glPushMatrix();
		glTranslatef(0,13,-17);
		glTranslatef(movfantX,movfantY,0);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		int num=rand()%100;
		if (num < 51)
		{
			fig7.prisma(7, 7, 0, fantasma.GLindex); //fantasma
		}
		glDisable(GL_ALPHA_TEST);
		glDisable(GL_BLEND);
	glPopMatrix();

}


void cama(void){


	glPushMatrix();

	glTranslatef(10, 0, 15);
	glRotatef(-90, 0, 1, 0);

		glPushMatrix(); //pata 1 derecha
		glTranslatef(1.3+0.4,-0.75+0.1,0.40+0.8);
		
		//glColor3f(0,0,0);
		figures.u_cilindro(0.1,1,5,madera.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata 2 
		glTranslatef(1.3+0.4,-0.75+0.1,-0.40-0.8);
		//glColor3f(0,0,0);
		figures.u_cilindro(0.1,1,5,madera.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata 3 izquierda
		glTranslatef(-1.3-0.6,-0.75+0.1,0.40+0.8);
		//glColor3f(0,0,0);
		figures.u_cilindro(0.1,1,5,madera.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata 4
		glTranslatef(-1.3-0.6,-0.75+0.1,-0.40-0.8);
		//glColor3f(0,0,0);
		figures.u_cilindro(0.1,1,5,madera.GLindex);
		glPopMatrix();

		glPushMatrix(); //almohadas
			glTranslatef(1.2, 1, -0.8);
			glScalef(1, 0.4, 1);
			figures.u_prisma(almohada.GLindex);
		glPopMatrix(); 
			
		glPushMatrix();
			glTranslatef(1.2, 1, 0.8);
			glScalef(1, 0.4, 1);
			figures.u_prisma(almohada.GLindex);
		glPopMatrix(); //almohadas


		glPushMatrix();
		glTranslatef(0,0.5,0);

		glPushMatrix(); //cobija
			//glTranslatef(0,0.3,0);
			glTranslatef(-1, 0.21, 0);
			glScalef(1.4, 0.1, 3);
			glScalef(3-1.2,1+1.2,1+0.02);
			figures.u_prisma(cobija.GLindex);
		glPopMatrix(); //cobija

		glPushMatrix(); //Cabecera
			glTranslatef(2.4, 0, 0);
			glScalef(0.6, 3.2, 3.6);
			figures.u_prisma(cabecera.GLindex);
		glPopMatrix(); //Cabecera

		glScalef(1.4, 0.6, 3);
		glScalef(3,1,1);
		glColor3f(1,1,1);
		figures.u_prisma(0);
		glPopMatrix();
		//glColor3f(1,1,1);

	glPopMatrix();

}

void ofrenda(void) {

	
	//base
	glPushMatrix();
		glScalef(0.49, 0.3, 0.4);
		glPushMatrix(); 
			glRotatef(270, 0, 1, 0);
			glTranslatef(25, 0, -20);
			glPushMatrix(); //mediano
				glTranslatef(0, 7, -0.5);
				glPushMatrix();//base3
					glTranslatef(0, 5, -1);
					glPushMatrix();//fotografia
						glTranslatef(0.0, 9, -0.2);
						glScalef(5, 12.5, 0.1);
						glRotatef(90, 1, 0, 0);
						figures.u_prisma(foto.GLindex);///cambiar t_foto
					glPopMatrix();//fin fotografia
					glPushMatrix();//panes y cosas de la base 3 de arriba
						glTranslatef(-1.7, 0.8, 0.0);
						//glRotatef(-90, 0, 0, 1);
						//glScalef(4, 5, 0.0);
						glTranslatef(8.0, -1.5, 3.0);//(-y, x, z)
						glPushMatrix();
							glTranslatef(-13.0, 0, 0);//(-y, x, z)
							glAlphaFunc(GL_GREATER, 0.1);
							glEnable(GL_BLEND);
							glEnable(GL_ALPHA_TEST);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							fig7.prisma(4,7,0,cempa.GLindex); // flor de cempasuchil 2 
							glDisable(GL_BLEND);
							glDisable(GL_ALPHA_TEST);
						glPopMatrix();
						glPushMatrix();
							glTranslatef(-4.0, 0, 0);//(-y, x, z)
							//glRotatef(-90,1,0,0);
							glAlphaFunc(GL_GREATER, 0.1);
							glEnable(GL_BLEND);
							glEnable(GL_ALPHA_TEST);
							glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
							//figures.u_media_esfera(2,20,20,panmuerto.GLindex);
							fig7.prisma(3,3,0,panmuerto.GLindex); // pan de muerto 
							glTranslatef(-4.0, 0, 0);
							fig7.prisma(3,3,0,panmuerto.GLindex); // pan de muerto 
							glDisable(GL_BLEND);
							glDisable(GL_ALPHA_TEST);
						glPopMatrix();
						//glRotatef(90,0,0,1);
						glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
						glEnable(GL_ALPHA_TEST);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						fig7.prisma(4,7,0,cempa.GLindex); // flor de cempasuchil 1
						glDisable(GL_BLEND);
						glDisable(GL_ALPHA_TEST);
					glPopMatrix();//fin de panes y cosas de la base 3

						glScalef(10, 5, 5); //t3
						glRotatef(90, 1, 0, 0);
						figures.u_prisma(madera.GLindex);
					glPopMatrix();//fin base3
					//panes y cosas de la base 2 de enmedio
					glPushMatrix();
						glTranslatef(-2.7, 0.7, 1.35);
						glRotatef(-90, 0, 0, 1);
						glEnable(GL_ALPHA_TEST);
						glAlphaFunc(GL_GREATER, 0.1);
						glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						glScalef(4, 4, 0.0);//(y.x.z) t2
						glTranslatef(0.0, 4.0, 0.0);//(-y, x, z)
						glTranslatef(0.0, -2.0, 0.0);//(-y, x, z)
						glDisable(GL_BLEND);
						glDisable(GL_ALPHA_TEST);
					glPopMatrix();

					glPushMatrix();
	glTranslatef(-2.9, 0.8, -1.3);
	glRotatef(-90, 0, 0, 1);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glScalef(0.7, 1.5, 0.0);//(y.x.z)
	glTranslatef(0.0, 4.0, 0.0);//(-y, x, z)
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.5, 0.8, 0.7);
	glRotatef(-90, 0, 0, 1);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glScalef(0.7, 1.2, 0.0);//(y.x.z)
	glTranslatef(0.0, 4.0, 0.0);//(-y, x, z)
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//fin de panes y cosas de la base 2



	glScalef(15, 5, 5);
	glRotatef(90, 1, 0, 0);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();//fin base2

	glPushMatrix();//panes y cosas de la base 1 de hasta abajo
	glTranslatef(-4.3, 0.8, 1.5);
	glRotatef(-90, 0, 0, 1);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glScalef(0.7, 2.0, 0.0);//(y.x.z)
	glTranslatef(0.0, 4.3, 0.0);//(-y, x, z)
	glTranslatef(0.0, -2.3, 0.0);//(-y, x, z)
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-4.3, 1.0, 0.5);
	glRotatef(-90, 0, 0, 1);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glScalef(0.7, 2.2, 0.0);//(y.x.z)
	glTranslatef(0.0, 4.0, 0.0);//(-y, x, z)
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//fin de panes y cosas de la base1

	glScalef(23, 7, 7); //te uno
	glRotatef(90, 1, 0, 0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	figures.prisma(madera.GLindex, picado1.GLindex);
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();//fin base1

	glPopMatrix();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	srand(time(NULL));

	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,29.98,0);
				glScalef(150, 60, 200);
				figures.skybox(skyboxparedes.GLindex,skyboxparedes.GLindex , cielo_superior.GLindex, pasto.GLindex); //skybox
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //	Ejes de referencia
				glBegin(GL_LINES);
				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(100.0, 0.0, 0.0);

				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(0.0, 100.0, 0.0);

				glVertex3f(0.0, 0.0, 0.0);
				glVertex3f(0.0, 0.0, 100.0);
				glEnd();
			glPopMatrix();

			glPushMatrix(); //fachada
				fachada();
				glPushMatrix();
					glTranslatef(0,11,0);
					glPushMatrix();
						glTranslatef(-12.95,0,-9);
						glRotatef(90, 0, 1, 0);
						fig7.prisma(22,18,0,bosque2.GLindex); //sustos - izquierda
						glTranslatef(0,0,25.85);
						fig7.prisma(22,18,0,bosque2.GLindex); //sustos - derecha
					glPopMatrix();
					glTranslatef(0,0,-17.95);
					fig7.prisma(22,26,0,bosque2.GLindex); //sustos - fondo
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-12.8,15,9);
					glRotatef(90, 0, 1, 0);
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER,0.1);
					glEnable(GL_BLEND);
					glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					fig7.prisma(15,18,0,picado2.GLindex); //ofrenda - fondo
					glDisable(GL_BLEND);
					glDisable(GL_ALPHA_TEST);
				glPopMatrix();
				glTranslatef(0,.2,-9);
				glRotatef(90, 1, 0, 0);
				fig7.prisma(18,26,0,pisomadera.GLindex); //sustos - piso

			glPopMatrix();

			glPushMatrix(); //frank
				glTranslatef(0,4.8,0);
				glScalef(1,2,1);
				monito();
			glPopMatrix();

			glPushMatrix();
				crearFantasma();
			glPopMatrix();

			glPushMatrix(); //puerta entrada y garage
				puertas();
			glPopMatrix();

			glPushMatrix(); //fachada
				ofrenda();
			glPopMatrix();			

			glPushMatrix(); //pelota
			glEnable(GL_LIGHTING);
			glTranslatef(pos_ball_x, pos_ball_y, pos_ball_z);
			glRotatef(rot_ball_x, 1, 0, 0);
			figures.u_esfera(1, 20, 20, ball.GLindex);
			glDisable(GL_LIGHTING);
			glPopMatrix();			

			glPushMatrix();
				paloma();
			glPopMatrix();

			glPushMatrix();
				
				glTranslatef(-10, 2.7, -14);
				glRotatef(rot_pelotaX, 1, 0, 0);
				glRotatef(rot_pelotaY, 0, 1, 0);
				glRotatef(rot_pelotaZ, 0, 0, 1);
				glEnable(GL_LIGHTING);
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER,0.1);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
				glRotatef(90, 0, 1, 0);
				fig7.esfera(2, 20, 20, calabaza.GLindex);
				glDisable(GL_BLEND);
				glDisable(GL_ALPHA_TEST);
				glDisable(GL_LIGHTING);
			glPopMatrix();		

		glPopMatrix(); 

	glPopMatrix();

	glutSwapBuffers();
}

void animacion()
{


	if(animac) {
		movfantX += 0.02;
		grados++;
		movfantY = 6*(sin((grados*PI)/180));
		if (movfantX > 9) {
			animac = false;
			animac2 = true;
		}
	}
	if (animac2) {
		movfantX -= 0.02;
		grados++;
		movfantY = 6*(sin((grados*PI)/180));
		if (movfantX < -9) {
			animac2 = false;
			animac = true;
		}
	}

	//Animación paloma
	switch (estadopaloma)
	{
		case 1:
			giroVentana -= 1;
			//pos_paloma_z += 0.1;
			if(giroVentana <= -90)
			{
				estadopaloma = 2;
				//ant_pos_paloma_z = pos_paloma_z;
			}
			break;
		case 2:
			pos_paloma_z += 0.1;
			//pos_paloma_x += 0.1;
			//rot_paloma = 90;
			if(pos_paloma_z >= 7)
			{
				estadopaloma = 3;
				//ant_pos_paloma_z = pos_paloma_z;
			}
			break;
		case 3:
			rot_paloma += 2;
			//pos_paloma_z -= 0.1;
			if(rot_paloma >= 180)
			{
				estadopaloma = 4;
			}
			break;
		case 4:
			pos_paloma_z -= 0.1;
			//pos_paloma_x -= 0.1;
			//rot_paloma += 3;
			if(pos_paloma_z <= -7)
			{
				//rot_paloma = 0;
				estadopaloma = 5;
			}
			break;
		case 5:
			rot_paloma -= 2;
			//pos_paloma_x -= 0.1;
			//rot_paloma += 3;
			if(rot_paloma <= 0)
			{
				estadopaloma = 6;
			}
			break;
		case 6:
			giroVentana += 2;
			//pos_paloma_x -= 0.1;
			//rot_paloma += 3;
			if(giroVentana >= 0)
			{
				estadopaloma = 0;
			}
			break;
	}


	//Movimiento de la pelota
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
				interpolation();
			}
		}
		else
		{	//Draw information


			mov_pelotaX += KeyFrame[playIndex].IncX;
			mov_pelotaY += KeyFrame[playIndex].IncY;
			mov_pelotaZ += KeyFrame[playIndex].IncZ;
			rot_pelotaX += KeyFrame[playIndex].IncRotX;
			rot_pelotaY += KeyFrame[playIndex].IncRotY;
			rot_pelotaZ += KeyFrame[playIndex].IncRotZ;
			giroVentana += KeyFrame[playIndex].giroVentanaInc;
			giroPuerta += KeyFrame[playIndex].giroPuertaInc;

			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;

			/*
			
			movCuerpo += KeyFrame[playIndex].movCuerpoInc;

			rotRodIzq += KeyFrame[playIndex].rotInc;
			rotRodDer += KeyFrame[playIndex].rotRodDerInc;
			giroMonito += KeyFrame[playIndex].giroMonitoInc;
			movBrazoDer += KeyFrame[playIndex].movBrazoDerInc;

			movBrazoIzq += KeyFrame[playIndex].movBrazoIzqInc;
			rotBrazoDer += KeyFrame[playIndex].rotBrazoDerInc;
			rotBrazoIzq += KeyFrame[playIndex].rotBrazoIzqInc;*/
			

			i_curr_steps++;
		}

	}

	/*frame++;
	time2 = glutGet(GLUT_ELAPSED_TIME);
	if (time2 - timebase > 1000) {
		sprintf(s, "FPS:%4.2f", frame*1000.0 / (time2 - timebase));
		timebase = time2;
		frame = 0;
	}*/

	//	Movimiento de la pelota
	switch(estadoPelota){
		case 1:
			pos_ball_z += 0.2;
			rot_ball_x -= 1;
			if (pos_ball_z >= 20.5) {
				estadoPelota = 2;
			}
			break;
		case 2:
			pos_ball_z = 21.0 + (v_ini_ball * ball_t);
			pos_ball_y = par_pos_ball_y_ini + (v_ini_ball * sin(angle_ball) * ball_t 
				- 0.5 * gravity * ball_t * ball_t);
			ball_t += 0.01;

			if (pos_ball_y <= 1)
			{
				estadoPelota = 3;
				xx = pos_ball_z;
				printf("%f\n", xx);
			}
			break;
		case 3:
			pos_ball_z += 0.2;
			if (pos_ball_z >= 48 )
			{
				estadoPelota = 4;
			}
			break;
	}
	


	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case '<':
			pos_ball_x = par_pos_ball_x_ini;
			pos_ball_y = par_pos_ball_y_ini;
			pos_ball_z = par_pos_ball_z_ini;
			rot_ball_x = 0.f;
			ball_t = 0.f;
			estadoPelota = 1;
			break;

		//Movimientos de camara
		case 'w':   
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'q':
		case 'Q':
			objCamera.UpDown_Camera(CAMERASPEED+0.2);
			break;

		case 'z':
		case 'Z':
			objCamera.UpDown_Camera(-(CAMERASPEED+0.2));
			break;

		//Tecla para colocar la camara al frente de la casa
		case 'f':
		case 'F':
			objCamera.Position_Camera(9.5, 2.5f, 40, 9.5, 2.5f, 38, 0, 1, 0);
			break;

		//Tecla para colocar la camara en la cama
		case 'c':
		case 'C':
			objCamera.Position_Camera(10, 3, 16, 10, 3, 12, 0, 1, 0);
			break;

		//Tecla para colocar la camara en la esquina para ver el interior de la casa
		case 'p':
		case 'P':
			//objCamera.Position_Camera(22.13, 6.69f, -38.55, -48.94, 2.5f, -69.66, 0, 1, 0);
			objCamera.Position_Camera(-12.4, 3, 17.5, 12.4, 3, -10.5, 0, 1, 0);
			break;

		//Tecla para colocar la camara en una vista isometrica de la casa
		case 'i':
		case 'I':
			objCamera.Position_Camera(-23.94, 58.5f, 16.99, -5, 2.5f, -12.39, 0, 1, 0);
			break;

		case 'u':
			mov_pelotaX += 0.1;
			break;
		case 'U':
			mov_pelotaX -= 0.1;
			//zz -= 0.2;
			break;

		case 'j':
			mov_pelotaY += 0.1;
			break;
		case 'J':
			mov_pelotaY -= 0.1;
			//zz += 0.2;
			break;

		case 'h':
			mov_pelotaZ += 0.1;
			break;
		case 'H':
			mov_pelotaZ -= 0.1;
			//xx -= 0.2;
			break;

		case 'y':
			rot_pelotaY += 10;
			break;
		case 'Y':
			rot_pelotaY -= 10;
			//yy += 0.2;
			break;

		case '1':
			posX += 0.2;
			break;
		case '2':
			posX -= 0.2;
			break;

		case '3':
			posY += 0.2;
			break;

		case '4':
			posY -= 0.2;
			break;

		case '5':
			posZ += 0.2;
			break;

		case '6':
			posZ -= 0.2;
			break;

		case 'l':
		case 'L':
			if(play==false && (FrameIndex>1))
			{

				resetElements();
				//First Interpolation				
				interpolation();
				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;

		case 'k':		//
		case 'K':
			if(FrameIndex<MAX_FRAMES)
				{
					saveFrame();
				}
			break;
/*
	case 'e':
	case 'E':
		if (play == false && (FrameIndex>1))
		{

			posX = KeyFrame[0].posX;
			posY = KeyFrame[0].posY;
			posZ = KeyFrame[0].posZ;
			rotRodIzq = KeyFrame[0].rotRodIzq;
			rotRodDer = KeyFrame[0].rotRodDer;
			giroMonito = KeyFrame[0].giroMonito;
			movBrazoDer = KeyFrame[0].movBrazoDer;
			movBrazoIzq = KeyFrame[0].movBrazoIzq;
			rotBrazoDer = KeyFrame[0].rotBrazoDer;
			rotBrazoIzq = KeyFrame[0].rotBrazoIzq;
			movCuerpo = KeyFrame[0].movCuerpo;

			//First Interpolation
			KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
			KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//100 frames
			KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;		//100 frames
			KeyFrame[playIndex].rotRodDerInc = (KeyFrame[playIndex + 1].rotRodDer - KeyFrame[playIndex].rotRodDer) / i_max_steps;		//100 frames
			KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;		//100 frames
			KeyFrame[playIndex].movBrazoDerInc = (KeyFrame[playIndex + 1].movBrazoDer - KeyFrame[playIndex].movBrazoDer) / i_max_steps;		//100 frames
			KeyFrame[playIndex].movBrazoIzqInc = (KeyFrame[playIndex + 1].movBrazoIzq - KeyFrame[playIndex].movBrazoIzq) / i_max_steps;		//100 frames
			KeyFrame[playIndex].rotBrazoDerInc = (KeyFrame[playIndex + 1].rotBrazoDer - KeyFrame[playIndex].rotBrazoDer) / i_max_steps;		//100 frames
			KeyFrame[playIndex].rotBrazoIzqInc = (KeyFrame[playIndex + 1].rotBrazoIzq - KeyFrame[playIndex].rotBrazoIzq) / i_max_steps;		//100 frames
			KeyFrame[playIndex].movCuerpoInc = (KeyFrame[playIndex + 1].movCuerpo - KeyFrame[playIndex].movCuerpo) / i_max_steps;

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;*/

		case 'x':
		rotRodIzq++;
		//printf("%f \n", rotRodIzq);
		break;

	case 'X':
		rotRodIzq--;
		//printf("%f \n", rotRodIzq);
		break;

	

	case 'g':
		rotBrazoDer++;
		//printf("%f \n", rotRodIzq);
		break;

	case 'G':
		rotBrazoDer--;
		//printf("%f \n", rotRodIzq);
		break;

	case '7':
		movBrazoDer++;
		//printf("%f \n", rotRodIzq);
		break;

	case '8':
		movBrazoDer--;
		//printf("%f \n", rotRodIzq);
		break;

	case '9':
		movCuerpo += 0.2;
		//printf("%f \n", rotRodIzq);
		break;

	case '0':
		movCuerpo -= 0.2;
		//printf("%f \n", rotRodIzq);
		break;

	case 't':
		giroMonito++;
		//printf("%f \n", giroMonito);
		break;

	case 'T':
		giroMonito--;
		//printf("%f \n", giroMonito);
		break;
	case 'v':
	case 'V':
		giroVentana++;
		//printf("giroVentana: %f \n", giroVentana);
		break;
	case 'b':
	case 'B':
		giroVentana--;
		//printf("giroVentana: %f \n", giroVentana);
		break;
	case 'n':
	case 'N':
		giroPuerta++;
		//printf("giroPuerta: %f \n", giroPuerta);
		break;
	case 'm':
	case 'M':
		giroPuerta--;
		//printf("giroPuerta: %f \n", giroPuerta);
		break;
	case 'o':
		animac^=true;
		//printf("%f \n", posX);
		break;
	case 'O':
		estadopaloma=1;
		rot_paloma=0;
		pos_paloma_z=-13;
		giroVentana=0;
		//printf("%f \n", posX);
		break;
	case 27:        // Cuando Esc es presionado...
		exit ( 0 );   // Salimos del programa
		break;        
	default:        // Cualquier otra
		break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:   // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (2000, 2000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}




void silla()
{

	//RESPALDO
	glPushMatrix();
	glTranslatef(0,0.50,-0.22);
	glPushMatrix();
	glTranslatef(0,0.375,0.031);
	glRotatef(-90,1,0,0);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_medio_cilindro(0.25,0.0625,30,madera.GLindex);
	glPopMatrix();
	glScalef(0.5,0.75,0.0625);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	glColor3f(1,1,0);
	//PATA 1
	glPushMatrix();
	glTranslatef(0.1875,-0.5,0.1875);
	glScalef(0.125,0.75,0.125);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	//PATA  2
	glPushMatrix();
	glTranslatef(0.1875,-0.5,-0.1875);
	glScalef(0.125,0.75,0.125);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	//PATA 3
	glPushMatrix();
	glTranslatef(-0.1875,-0.5,-0.1875);
	glScalef(0.125,0.75,0.125);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	//PATA 4
	glPushMatrix();
	glTranslatef(-0.1875,-0.5,0.1875);
	glScalef(0.125,0.75,0.125);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
	glScalef(0.5,0.25,0.5);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glColor3f(1,1,1);
}

void arbol(const GLuint &text)
{

	glPushMatrix();
		//glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);

		glBindTexture(GL_TEXTURE_2D, text);
		for(int i = 0; i < 12; i++)
		{
			glPushMatrix();
				glRotatef(30 / 2.0 * i, 0, 1, 0);
				glNormal3f(0, 0, 1);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0, 10.0, 0.0);
					glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0, 10.0, 0.0);
				glEnd();
			glPopMatrix();

		}
		//glEnable(GL_LIGHTING);
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();
}

void sillon_uno()
{
	glPushMatrix(); //PUSH DE PRISMA PRINCIPAL
	/*glPushMatrix();
	glTranslatef(0,0.75,0.0);
	glScalef(2.5,0.5,1.5);
	glColor3f(0,0,1);
	figures.u_prisma(0);
	glPopMatrix();*/
	glPushMatrix(); //DESCANSO BRAZP DER
	glTranslatef(1.20,0.5,0.5);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.30,0.75,30,sillon.GLindex);
	glPopMatrix();

	glPushMatrix(); //DESCANSO BRAZO IZQ
	glTranslatef(-1.20,0.5,0.5);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.30,0.75,30,sillon.GLindex);
	glPopMatrix();

	glPushMatrix(); //RESPALDO
	glTranslatef(0,1.10,-0.375);

	glPushMatrix();
	glTranslatef(1.2,-0.3,0);

	glPushMatrix(); 
	glTranslatef(-0.3,0.3,0.125);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_cuarto_cilindro(0.6,0.25,30,sillon.GLindex);
	glPopMatrix();

	glScalef(0.6,0.6,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.2,-0.3,0);

	glPushMatrix(); 
	glTranslatef(0.3,0.3,-0.125);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	glRotatef(180,0,0,1);
	figures.u_cuarto_cilindro(0.6,0.25,30,sillon.GLindex);
	glPopMatrix();

	glScalef(0.6,0.6,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glScalef(1.8,1.20,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix(); //pata del sillon 1 derecha
	glTranslatef(1.3,-0.75,0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 2 
	glTranslatef(1.3,-0.75,-0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 3 izquierda
	glTranslatef(-1.3,-0.75,0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 4
	glTranslatef(-1.3,-0.75,-0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glScalef(3,1,1);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
}

void sillon_dos()
{
	glPushMatrix(); //PUSH DE PRISMA PRINCIPAL
	/*glPushMatrix();
	glTranslatef(0,0.75,0.0);
	glScalef(2.5,0.5,1.5);
	glColor3f(0,0,1);
	figures.u_prisma(0);
	glPopMatrix();*/
	

	glPushMatrix();
	glTranslatef(0.6,0.65,0.12);
	glPushMatrix(); //DESCANSO BRAZP DER
	glTranslatef(0,0.15,0.375);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.15,0.75,30,sillon.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
	glScalef(0.3,0.3,0.75);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6,0.65,0.12);
	glPushMatrix(); //DESCANSO BRAZP DER
	glTranslatef(0,0.15,0.375);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_medio_cilindro(0.15,0.75,30,sillon.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
	glScalef(0.3,0.3,0.75);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix(); //RESPALDO
	glTranslatef(0,0.90,-0.375);

	glPushMatrix();
	glTranslatef(0.6,-0.1,0);

	glPushMatrix(); 
	glTranslatef(-0.15,0.3,0.125);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	figures.u_cuarto_cilindro(0.3,0.25,30,sillon.GLindex);
	glPopMatrix();

	glScalef(0.3,0.6,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6,-0.1,0);

	glPushMatrix(); 
	glTranslatef(0.15,0.3,-0.125);
	glColor3f(1,1,1);
	glRotatef(-90,1,0,0);
	glRotatef(180,0,0,1);
	figures.u_cuarto_cilindro(0.3,0.25,30,sillon.GLindex);
	glPopMatrix();

	glScalef(0.3,0.6,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glScalef(0.9,1.0,0.25);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();

	glPushMatrix(); //pata del sillon 1 derecha
	glTranslatef(0.65,-0.75,0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 2 
	glTranslatef(0.65,-0.75,-0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 3 izquierda
	glTranslatef(-0.65,-0.75,0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glPushMatrix(); //pata del sillon 4
	glTranslatef(-0.65,-0.75,-0.40);
	glColor3f(0,0,0);
	figures.u_cilindro(0.1,0.25,5,madera.GLindex);
	glPopMatrix();
	glScalef(1.5,1,1);
	glColor3f(1,1,1);
	figures.u_prisma(sillon.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
}

void tele()
{
	glPushMatrix();
	glTranslatef(0,2.5,-0.35);
			glColor3f(1,1,1);
			glRotatef(-90,1,0,0);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t14.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t13.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t12.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t11.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t10.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t9.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t8.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t7.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t6.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t5.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t4.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t3.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t2.GLindex);
			figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t1.GLindex);
			glPopMatrix();
}
void lampara()
{
	glPushMatrix();
	glTranslatef(0,1,0.0);

	glPushMatrix();
	glTranslatef(0,0.0625,0);
	glPushMatrix();
	glTranslatef(0,2,0);
	//glColor3f(1,1,1);
	figures.u_cono(0.3,1,10,lamp.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
	figures.u_cilindro(0.01,2,5,0);
	glPopMatrix();

	glColor3f(0,0,0);
	figures.u_cilindro(0.25,0.0625,30,0);
	glPopMatrix();
	glColor3f(1,1,1);
}

void mesa_comedor()
{
	glPushMatrix();
	glTranslatef(0,1.05,0);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0,1.5,0);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_cilindro(1.5,0.1,20,madera.GLindex);
	glPopMatrix();
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_cilindro(0.125,1.5,15,madera.GLindex);
	glPopMatrix();
	glScalef(1.5,0.05,1.5);
	glColor3f(0.3529,0.1764,0.0862);
	figures.u_prisma(madera.GLindex);
	glPopMatrix();
}

void paloma()
{
	glPushMatrix();

	glTranslatef(pos_paloma_x, pos_paloma_y, pos_paloma_z);
	glRotatef(rot_paloma, 0, 1, 0);

	glPushMatrix();//Ala derecha
	glTranslatef(0.25,0.1,0);
	glScalef(0.1,0.75,0.325);
	glColor3f(0.4431,0.4901,0.4941);
	figures.u_prisma(0);
	glPopMatrix();	

	glPushMatrix();//Ala derecha
	glTranslatef(-0.25,0.1,0);
	glScalef(0.1,0.75,0.325);
	glColor3f(0.4431,0.4901,0.4941);
	figures.u_prisma(0);
	glPopMatrix();

	//PATAS
	glPushMatrix();//IZQUIERDA
	glTranslatef(-0.15,-0.75,0);
	glPushMatrix();
	glTranslatef(0,-0.25,0.1);
	glScalef(0.15,0.1,0.15);
	glColor3f(0.8627,0.4627,0.2);
	figures.u_prisma(0);
	glPopMatrix();
	glScalef(0.05,0.5,0.075);
	glColor3f(0.8627,0.4627,0.2);
	figures.u_prisma(0);
	glPopMatrix();

	glPushMatrix();//DERECHA
	glTranslatef(0.15,-0.75,0);
	glPushMatrix();
	glTranslatef(0,-0.25,0.1);
	glScalef(0.15,0.1,0.15);
	glColor3f(0.8627,0.4627,0.2);
	figures.u_prisma(0);
	glPopMatrix();
	glScalef(0.05,0.5,0.075);
	glColor3f(0.8627,0.4627,0.2);
	figures.u_prisma(0);
	glPopMatrix();

	//CABEZA
	glPushMatrix();
	glTranslatef(0,0.65,0.25);
	glPushMatrix();//PUSH DE LA BOCA
	glTranslatef(0,0,0.07);

	glPushMatrix();//PUSH DE OJO IZQ
	glTranslatef(-0.095,0.15,0);
	glScalef(0.025,0.05,0.05);
	glColor3f(0,0,0);
	figures.u_prisma(0);
	glPopMatrix();

	glPushMatrix();//PUSH DE OJO DER
	glTranslatef(0.095,0.15,0);
	glScalef(0.025,0.05,0.05);
	glColor3f(0,0,0);
	figures.u_prisma(0);
	glPopMatrix();

	glScalef(0.25,0.25,0.05);
	glColor3f(0.9568,0.8156,0.2470);
	figures.u_prisma(0);
	glPopMatrix();
	glScalef(0.25,0.75,0.1);
	glColor3f(0.6666,0.7176,0.7215);
	figures.u_prisma(0);
	glPopMatrix();

	glScalef(0.5,1,0.5);
	glColor3f(0.4745,0.4901,0.4980);
	figures.u_prisma(0);
	glPopMatrix();
}




void fachada()
{
	glPushMatrix();

	glTranslatef(0, 11, 0);
	
	//	Figura A (central)
	
	glPushMatrix();
		glScalef(26, 22, 36);
		figures.u_prisma_no_derecha(piedra.GLindex);	
	glPopMatrix();


	glEnable(GL_LIGHTING);
	glPushMatrix();
		glScalef(25.995, 21.995, 35.995);
		figures.l_prisma_no_derecha(piedra.GLindex, metal_cromo.GLindex);	
	glPopMatrix();
	glDisable(GL_LIGHTING);

	glPushMatrix(); // Pared de enmedio 
		//fig7.prisma(22,26,1,piedra.GLindex);
		glTranslatef(-7.5,0,0);
		fig7.prisma(22,11,1,piedra.GLindex);
		glPushMatrix();
			glTranslatef(7.5,0.5,0);
			fig7.prisma(3,4,1,piedra.GLindex);
			glPushMatrix();
				glTranslatef(-2,4.5,0);
				glRotatef(giroVentana,0,1,0);
				glPushMatrix();
					glTranslatef(2,0,0);
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER,0.1);
					glEnable(GL_BLEND);
					glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					fig7.prisma(6,4,0,ventanacuartos.GLindex); //ventana entre cuartos
					glDisable(GL_ALPHA_TEST);
					glDisable(GL_BLEND);
				glPopMatrix();	
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0,9,0);
				fig7.prisma(3,4,1,piedra.GLindex);	
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-2,-6.5,0);
				glRotatef(giroPuerta,0,1,0);
				glTranslatef(2,0,0);
				fig7.prisma(10,4,0,puertacuartos.GLindex); //puerta entre cuartos
			glPopMatrix();
				glTranslatef(7.5,-0.5,0);
				fig7.prisma(22,11,1,piedra.GLindex); 
			glPushMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	

	glColor3f(1, 1, 1);

	glPopMatrix();
}

void mesa_sala()
{
	glPushMatrix(); // stack de primer prisma medio - frente
			glPushMatrix(); // stack de segundo prisma medio - medio
			glTranslatef(0.0, 0.0, -2.5);
				glPushMatrix(); // stack de tercer prisma medio - atrás
				glTranslatef(0.0, 0.0, -2.5);
					glPushMatrix(); //stack de cuarto prisma derecha - atrás
					glTranslatef(1.25, -1.5, 0.0);
						glPushMatrix(); //stack de quinto prisma derecha - medio
						glTranslatef(0.0, 1.5, 2.5);
							glPushMatrix(); //stack de sexto prisma derecha - frente
							glTranslatef(0.0, -1.5, 2.5);
								//glColor3f(1.0, 1.0, 1.0);
								glScalef(0.5, 4.0, 1.0);
								figures.prisma(madera.GLindex, madera.GLindex);
							glPopMatrix();
							//glColor3f(1.0, 1.0, 1.0);
							glScalef(0.5, 1.0, 4.0);
							figures.prisma(madera.GLindex, madera.GLindex);
						glPopMatrix();
						//glColor3f(1.0, 1.0, 1.0);
						glScalef(0.5, 4.0, 1.0);
						figures.prisma(madera.GLindex, madera.GLindex);
					glPopMatrix();
					glPushMatrix(); //stack de séptimo prisma izquierda - atrás
					glTranslatef(-1.25, -1.5, 0.0);
						glPushMatrix(); //stack de octavo prisma izquierda - medio
						glTranslatef(0.0, 1.5, 2.5);
							glPushMatrix(); //stack de noveno prisma izquierda - medio
							glTranslatef(0.0, -1.5, 2.5);
								//glColor3f(1.0, 1.0, 1.0);
								glScalef(0.5, 4.0, 1.0);
								figures.prisma(madera.GLindex, madera.GLindex);
							glPopMatrix();
							//glColor3f(1.0, 1.0, 1.0);
							glScalef(0.5, 1.0, 4.0);
							figures.prisma(madera.GLindex,madera.GLindex);
						glPopMatrix();
						//glColor3f(1.0, 1.0, 1.0);
						glScalef(0.5, 4.0,1.0);
						figures.prisma(madera.GLindex, madera.GLindex);
					glPopMatrix();
					//glColor3f(1.0, 1.0, 1.0);
					glScalef(2.0, 1.0, 1.0);
					figures.prisma(madera.GLindex, madera.GLindex);
				glPopMatrix();
				//glColor3f(1.0, 1.0, 1.0);
				glScalef(2.0, 1.0, 4.0);
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
				figures.prisma(centro_mesa.GLindex, centro_mesa.GLindex);
				glDisable(GL_ALPHA_TEST);
			glPopMatrix();
			//glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0,1.0,1.0);  
			figures.prisma(madera.GLindex, madera.GLindex);	
		glPopMatrix();
}