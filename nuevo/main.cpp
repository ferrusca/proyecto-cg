//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "Figures.h"

//	Prototipos de funciones
void fachada();
void refrigerador();
void silla();
void arbol(const GLuint &text);
void cocina();
void sillon_uno();
void mesa_centro();
void mesa_comedor();
void mesa_cocina();
void divisiones();
void divisiones_superior();
void sillon_dos();
void mueble_buro();
void mueble_armario();
void mueble_librero();
void lampara();
void pato();
void taza_banio();
void mueble_banio();
void mueble_banio_toallas();
void tele();
/*int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;*/

static GLuint ciudad_display_list;	//Display List for the Monito


									//NEW// Keyframes
float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0, rotRodDer = 0.0, rotBrazoIzq = 0.0, rotBrazoDer = 0.0;
float movBrazoIzq = 0.0;
float giroMonito = 0;
float movBrazoDer = 0.0;
float movCuerpo = 0.0;

#define MAX_FRAMES 200		//cuantos cuadros clave se van a utilizar (keyframes)
int i_max_steps = 50;
int i_curr_steps = 0;
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ

	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ

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


}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 19;			//introducir datos
bool play = false;
int playIndex = 0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, time2, timebase = 0;
char s[30];

//	Objeto para dibujar figuras
//CFiguras figures;
Figures figures;
Figures mov_agua;

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

//Variables de apoyo para colocar figuras
float xx=0.0, yy = 0.0, zz = 0.0;
float tamx = 1.0, tamy = 1.0, tamz = 1.0;

//	Variables para animar al pato
GLfloat pos_pato_x = 0.f;
GLfloat pos_pato_y = 0.f;
GLfloat pos_pato_z = 0.f;
GLfloat rot_pato = 0.f;
GLfloat ant_pos_pato_z = 0.f;

//	Variables para animar la pelota
GLfloat pos_ball_x = 13.f;
GLfloat pos_ball_y = 22.0f;
GLfloat pos_ball_z = -5.6f;
GLfloat rot_ball_x = 0.f;
GLfloat par_pos_ball_x_ini = 13.f;
GLfloat par_pos_ball_y_ini = 22.0f;
GLfloat par_pos_ball_z_ini = -5.6f;
GLfloat v_ini_ball = 10;
GLfloat angle_ball = 3.141592 / 10;
GLfloat ball_t = 0;
const GLfloat gravity = 9.81;
int estadoPelota = 1;

// 1 (Adelante), 2(Atras), 3(Giro)
int estadoPato = 1;

//	Variables para animar la textura
GLdouble estadoTelevision = 1.0;


//CTexture text1;
//CTexture text2;
//CTexture text3;	//Flecha

CFiguras fig7;

//	Texturas para el refrigerador
CTexture window_texture;
CTexture cuarzo;
CTexture cubierta;
CTexture metal_cromo;
CTexture pared_interior;
CTexture puertaFrente;
CTexture garage;
CTexture alacena1;
CTexture alacena2;
CTexture alacena3;
CTexture pisoRojo;
CTexture mosaicoVintage;
CTexture textAlberca;
CTexture pisoPatioT;
CTexture ropero;
CTexture agua;
CTexture porcelana;
CTexture plata;
CTexture cielo_lateral;
CTexture cielo_frontal;
CTexture cielo_superior;
CTexture pasto;
CTexture lamp;
CTexture tocador;
CTexture toallas;
CTexture tele1;
CTexture refri;
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
CTexture librero;
CTexture vitrina;
CTexture chimenea;
CTexture chimeneaExt;
CTexture madera;
CTexture muebleBanio;
CTexture muebleBanio2;
CTexture negroMate;
CTexture muebleBuro;
CTexture almohada;
CTexture cabecera;
CTexture cobija;
CTexture piso;
CTexture estufa;
CTexture estufaCal;
CTexture tree_tex;
CTexture door;
CTexture ball;

//CTexture tree;

//CFiguras sky;
const double PI = 3.1415926535897;
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

	ropero.LoadTGA("textures/roperoo.tga");
	ropero.BuildGLTexture();
	ropero.ReleaseImage();

	toallas.LoadTGA("textures/toallas.tga");
	toallas.BuildGLTexture();
	toallas.ReleaseImage();

	cubierta.LoadTGA("textures/cubierta.tga");
	cubierta.BuildGLTexture();
	cubierta.ReleaseImage();

	tele1.LoadTGA("textures/tele1.tga");
	tele1.BuildGLTexture();
	tele1.ReleaseImage();

	tocador.LoadTGA("textures/tocador.tga");
	tocador.BuildGLTexture();
	tocador.ReleaseImage();

	alacena1.LoadTGA("textures/alacena.tga");
	alacena1.BuildGLTexture();
	alacena1.ReleaseImage();

	alacena2.LoadTGA("textures/alacena1.tga");
	alacena2.BuildGLTexture();
	alacena2.ReleaseImage();

	alacena3.LoadTGA("textures/alacena2.tga");
	alacena3.BuildGLTexture();
	alacena3.ReleaseImage();

	pared_interior.LoadTGA("textures/pared.tga");
	pared_interior.BuildGLTexture();
	pared_interior.ReleaseImage();

	puertaFrente.LoadTGA("textures/puerta.tga");
	puertaFrente.BuildGLTexture();
	puertaFrente.ReleaseImage();

	garage.LoadTGA("textures/garage.tga");
	garage.BuildGLTexture();
	garage.ReleaseImage();

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

	estufa.LoadTGA("textures/estufa.tga");
	estufa.BuildGLTexture();
	estufa.ReleaseImage();

	estufaCal.LoadTGA("textures/estufaCal.tga");
	estufaCal.BuildGLTexture();
	estufaCal.ReleaseImage();

	refri.LoadTGA("textures/metalPulido.tga");
	refri.BuildGLTexture();
	refri.ReleaseImage();

	piso.LoadTGA("textures/piso.tga");
	piso.BuildGLTexture();
	piso.ReleaseImage();

	mosaicoVintage.LoadTGA("textures/mosaico_vintage.tga");
	mosaicoVintage.BuildGLTexture();
	mosaicoVintage.ReleaseImage();

	chimenea.LoadTGA("textures/chimenea.tga");
	chimenea.BuildGLTexture();
	chimenea.ReleaseImage();

	vitrina.LoadTGA("textures/vitrina.tga");
	vitrina.BuildGLTexture();
	vitrina.ReleaseImage();

	muebleBuro.LoadTGA("textures/muebleSala.tga");
	muebleBuro.BuildGLTexture();
	muebleBuro.ReleaseImage();

	lamp.LoadTGA("textures/lampara.tga");
	lamp.BuildGLTexture();
	lamp.ReleaseImage();

	textAlberca.LoadTGA("textures/alberca.tga");
	textAlberca.BuildGLTexture();
	textAlberca.ReleaseImage();

	pisoPatioT.LoadTGA("textures/ladrillo.tga");
	pisoPatioT.BuildGLTexture();
	pisoPatioT.ReleaseImage();

	agua.LoadTGA("textures/water.tga");
	agua.BuildGLTexture();
	agua.ReleaseImage();

	librero.LoadTGA("textures/librero.tga");
	librero.BuildGLTexture();
	librero.ReleaseImage();

	porcelana.LoadTGA("textures/porcelana.tga");
	porcelana.BuildGLTexture();
	porcelana.ReleaseImage();

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

	madera.LoadTGA("textures/maderaa.tga");
	madera.BuildGLTexture();
	madera.ReleaseImage();

	muebleBanio.LoadTGA("textures/muebleBanio.tga");
	muebleBanio.BuildGLTexture();
	muebleBanio.ReleaseImage();

	muebleBanio2.LoadTGA("textures/muebleBanio2.tga");
	muebleBanio2.BuildGLTexture();
	muebleBanio2.ReleaseImage();

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

//<<<<<<< HEAD
	KeyFrame[0].posX = 0;
	KeyFrame[0].posY = 2.4;
	KeyFrame[0].posZ = -3.5;
	KeyFrame[0].rotRodIzq = 0;
	KeyFrame[0].rotRodDer = 0;
	KeyFrame[0].giroMonito = 0;
	KeyFrame[0].movBrazoDer = 0;
	KeyFrame[0].movBrazoIzq = 0;
	KeyFrame[0].movCuerpo = 0;
	KeyFrame[0].rotBrazoDer = 0;
	KeyFrame[0].rotBrazoIzq = 0;

	KeyFrame[1].posX = 0;
	KeyFrame[1].posY = 2.4;
	KeyFrame[1].posZ = -3.5;
	KeyFrame[1].rotRodIzq = 0;
	KeyFrame[1].rotRodDer = 0;
	KeyFrame[1].giroMonito = 77.0;
	KeyFrame[1].movBrazoDer = 0;
	KeyFrame[1].movBrazoIzq = 0;
	KeyFrame[1].movCuerpo = 0;
	KeyFrame[1].rotBrazoDer = -91.0;
	KeyFrame[1].rotBrazoIzq = 83.0;

	KeyFrame[2].posX = 0;
	KeyFrame[2].posY = 2.4;
	KeyFrame[2].posZ = -3.5;
	KeyFrame[2].rotRodIzq = 0;
	KeyFrame[2].rotRodDer = 0;
	KeyFrame[2].giroMonito = 77.0;
	KeyFrame[2].movBrazoDer = 31.0;
	KeyFrame[2].movBrazoIzq = 33.0;
	KeyFrame[2].movCuerpo = 0;
	KeyFrame[2].rotBrazoDer = -91.0;
	KeyFrame[2].rotBrazoIzq = 83.0;

	KeyFrame[3].posX = 0;
	KeyFrame[3].posY = 2.2;
	KeyFrame[3].posZ = -3.5;
	KeyFrame[3].rotRodIzq = 49.0;
	KeyFrame[3].rotRodDer = 44.0;
	KeyFrame[3].giroMonito = 77.0;
	KeyFrame[3].movBrazoDer = -23.0;
	KeyFrame[3].movBrazoIzq = -36.0;
	KeyFrame[3].movCuerpo = 0;
	KeyFrame[3].rotBrazoDer = -91.0;
	KeyFrame[3].rotBrazoIzq = 83.0;

	KeyFrame[4].posX = 0;
	KeyFrame[4].posY = 2.2;
	KeyFrame[4].posZ = -3.5;
	KeyFrame[4].rotRodIzq = 15.0;
	KeyFrame[4].rotRodDer = 17.0;
	KeyFrame[4].giroMonito = 77.0;
	KeyFrame[4].movBrazoDer = 40.0;
	KeyFrame[4].movBrazoIzq = 28.0;
	KeyFrame[4].movCuerpo = 0;
	KeyFrame[4].rotBrazoDer = -91.0;
	KeyFrame[4].rotBrazoIzq = 83.0;

	KeyFrame[5].posX = 0;
	KeyFrame[5].posY = 2.4;
	KeyFrame[5].posZ = -3.5;
	KeyFrame[5].rotRodIzq = 46.0;
	KeyFrame[5].rotRodDer = 51.0;
	KeyFrame[5].giroMonito = 77.0;
	KeyFrame[5].movBrazoDer = -17.0;
	KeyFrame[5].movBrazoIzq = -41.0;
	KeyFrame[5].movCuerpo = 0;
	KeyFrame[5].rotBrazoDer = -91.0;
	KeyFrame[5].rotBrazoIzq = 83.0;

	KeyFrame[6].posX = 0;
	KeyFrame[6].posY = 2.4;
	KeyFrame[6].posZ = -3.5;
	KeyFrame[6].rotRodIzq = 9.0;
	KeyFrame[6].rotRodDer = 23.0;
	KeyFrame[6].giroMonito = 77.0;
	KeyFrame[6].movBrazoDer = 33.0;
	KeyFrame[6].movBrazoIzq = 29.0;
	KeyFrame[6].movCuerpo = 0;
	KeyFrame[6].rotBrazoDer = -91.0;
	KeyFrame[6].rotBrazoIzq = 83.0;

	KeyFrame[7].posX = 0;
	KeyFrame[7].posY = 2.2;
	KeyFrame[7].posZ = -3.5;
	KeyFrame[7].rotRodIzq = 46.0;
	KeyFrame[7].rotRodDer = 43.0;
	KeyFrame[7].giroMonito = 77.0;
	KeyFrame[7].movBrazoDer = -22.0;
	KeyFrame[7].movBrazoIzq = -36.0;
	KeyFrame[7].movCuerpo = 0;
	KeyFrame[7].rotBrazoDer = -91.0;
	KeyFrame[7].rotBrazoIzq = 83.0;

	KeyFrame[8].posX = 0;
	KeyFrame[8].posY = 2.4;
	KeyFrame[8].posZ = -3.5;
	KeyFrame[8].rotRodIzq = 3.0;
	KeyFrame[8].rotRodDer = 8.0;
	KeyFrame[8].giroMonito = 77.0;
	KeyFrame[8].movBrazoDer = 43.0;
	KeyFrame[8].movBrazoIzq = 26.0;
	KeyFrame[8].movCuerpo = 0.0;
	KeyFrame[8].rotBrazoDer = -91.0;
	KeyFrame[8].rotBrazoIzq = 83.0;

	KeyFrame[9].posX = 0;
	KeyFrame[9].posY = 2.2;
	KeyFrame[9].posZ = -3.5;
	KeyFrame[9].rotRodIzq = 43.0;
	KeyFrame[9].rotRodDer = 45.0;
	KeyFrame[9].giroMonito = 77.0;
	KeyFrame[9].movBrazoDer = -31.0;
	KeyFrame[9].movBrazoIzq = -42.0;
	KeyFrame[9].movCuerpo = 0;
	KeyFrame[9].rotBrazoDer = -91.0;
	KeyFrame[9].rotBrazoIzq = 83.0;

	KeyFrame[10].posX = 0;
	KeyFrame[10].posY = 2.4;
	KeyFrame[10].posZ = -3.5;
	KeyFrame[10].rotRodIzq = 1.0;
	KeyFrame[10].rotRodDer = 11.0;
	KeyFrame[10].giroMonito = 77.0;
	KeyFrame[10].movBrazoDer = 41.0;
	KeyFrame[10].movBrazoIzq = 32.0;
	KeyFrame[10].movCuerpo = 0;
	KeyFrame[10].rotBrazoDer = -91.0;
	KeyFrame[10].rotBrazoIzq = 83.0;

	KeyFrame[11].posX = 0;
	KeyFrame[11].posY = 2.2;
	KeyFrame[11].posZ = -3.5;
	KeyFrame[11].rotRodIzq = 43.0;
	KeyFrame[11].rotRodDer = 56.0;
	KeyFrame[11].giroMonito = 77.0;
	KeyFrame[11].movBrazoDer = -23.0;
	KeyFrame[11].movBrazoIzq = -47.0;
	KeyFrame[11].movCuerpo = 0;
	KeyFrame[11].rotBrazoDer = -91.0;
	KeyFrame[11].rotBrazoIzq = 83.0;

	KeyFrame[12].posX = 0;
	KeyFrame[12].posY = 2.4;
	KeyFrame[12].posZ = -3.5;
	KeyFrame[12].rotRodIzq = 6.0;
	KeyFrame[12].rotRodDer = 10.0;
	KeyFrame[12].giroMonito = 77.0;
	KeyFrame[12].movBrazoDer = 34.0;
	KeyFrame[12].movBrazoIzq = 27.0;
	KeyFrame[12].movCuerpo = 0;
	KeyFrame[12].rotBrazoDer = -91.0;
	KeyFrame[12].rotBrazoIzq = 83.0;

	KeyFrame[13].posX = 0;
	KeyFrame[13].posY = 2.2;
	KeyFrame[13].posZ = -3.5;
	KeyFrame[13].rotRodIzq = 6.0;
	KeyFrame[13].rotRodDer = 10.0;
	KeyFrame[13].giroMonito = -1.0;
	KeyFrame[13].movBrazoDer = 12.0;
	KeyFrame[13].movBrazoIzq = 6.0;
	KeyFrame[13].movCuerpo = 0;
	KeyFrame[13].rotBrazoDer = -91.0;
	KeyFrame[13].rotBrazoIzq = 83.0;

	KeyFrame[14].posX = 0;
	KeyFrame[14].posY = 2.4;
	KeyFrame[14].posZ = -3.5;
	KeyFrame[14].rotRodIzq = 6.0;
	KeyFrame[14].rotRodDer = 10.0;
	KeyFrame[14].giroMonito = -82.0;
	KeyFrame[14].movBrazoDer = -20.0;
	KeyFrame[14].movBrazoIzq = -26.0;
	KeyFrame[14].movCuerpo = 0;
	KeyFrame[14].rotBrazoDer = -91.0;
	KeyFrame[14].rotBrazoIzq = 83.0;

	KeyFrame[15].posX = 0;
	KeyFrame[15].posY = 2.2;
	KeyFrame[15].posZ = -3.5;
	KeyFrame[15].rotRodIzq = 42.0;
	KeyFrame[15].rotRodDer = 44.0;
	KeyFrame[15].giroMonito = -82.0;
	KeyFrame[15].movBrazoDer = 37.0;
	KeyFrame[15].movBrazoIzq = 21.0;
	KeyFrame[15].movCuerpo = 0;
	KeyFrame[15].rotBrazoDer = -91.0;
	KeyFrame[15].rotBrazoIzq = 83.0;

	KeyFrame[16].posX = 0;
	KeyFrame[16].posY = 2.4;
	KeyFrame[16].posZ = -3.5;
	KeyFrame[16].rotRodIzq = -15.0;
	KeyFrame[16].rotRodDer = 6.0;
	KeyFrame[16].giroMonito = -82.0;
	KeyFrame[16].movBrazoDer = -25.0;
	KeyFrame[16].movBrazoIzq = -37.0;
	KeyFrame[16].movCuerpo = 0;
	KeyFrame[16].rotBrazoDer = -91.0;
	KeyFrame[16].rotBrazoIzq = 83.0;

	KeyFrame[17].posX = 0;
	KeyFrame[17].posY = 2.2;
	KeyFrame[17].posZ = -3.5;
	KeyFrame[17].rotRodIzq = 9.0;
	KeyFrame[17].rotRodDer = 44.0;
	KeyFrame[17].giroMonito = -82.0;
	KeyFrame[17].movBrazoDer = 35.0;
	KeyFrame[17].movBrazoIzq = 15.0;
	KeyFrame[17].movCuerpo = 0;
	KeyFrame[17].rotBrazoDer = -91.0;
	KeyFrame[17].rotBrazoIzq = 83.0;

	KeyFrame[18].posX = 0;
	KeyFrame[18].posY = 2.4;
	KeyFrame[18].posZ = -3.5;
	KeyFrame[18].rotRodIzq = -1.0;
	KeyFrame[18].rotRodDer = 5.0;
	KeyFrame[18].giroMonito = -82.0;
	KeyFrame[18].movBrazoDer = -23.0;
	KeyFrame[18].movBrazoIzq = -48.0;
	KeyFrame[18].movCuerpo = 0;
	KeyFrame[18].rotBrazoDer = -91.0;
	KeyFrame[18].rotBrazoIzq = 83.0;



//=======
	window_texture.LoadTGA("textures/window.tga");
	window_texture.BuildGLTexture();
	window_texture.ReleaseImage();

	door.LoadTGA("textures/door.tga");
	door.BuildGLTexture();
	door.ReleaseImage();

	ball.LoadTGA("textures/ball.tga");
	ball.BuildGLTexture();
	ball.ReleaseImage();
//>>>>>>> refs/remotes/origin/master

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

	//Puerta Frontal
	glPushMatrix();
		glTranslatef(4.8, 5.0, -0.4);
		glScalef(4, 8, 1);
		glBindTexture(GL_TEXTURE_2D, puertaFrente.GLindex);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 0); glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0, 1); glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0.5);
		glEnd();

	glPopMatrix();

	//Puerta garage
	/*glPushMatrix();
		glTranslatef(-6, 2.4, -6.99);
		glScalef(8, 4.8, 1);
		glBindTexture(GL_TEXTURE_2D, garage.GLindex);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 0); glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0, 0); glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0, 1); glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1, 1); glVertex3f(0.5, 0.5, 0.5);
		glEnd();
	glPopMatrix();*/

}

void monito()
{
	glPushMatrix();

		//glTranslatef(xx,yy,zz);
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho

	glTranslatef(0.0, movCuerpo, 0.0);
	glScalef(0.5, 0.5, 0.5);
	fig7.prisma(2.0, 2.0, 1, plata.GLindex);

	glPushMatrix();//Cuello
	glTranslatef(0, 1.0, 0.0);
	fig7.cilindro(0.25, 0.25, 15, 0);
	glPushMatrix();//Cabeza
	glTranslatef(0, 1.0, 0);
	fig7.esfera(0.75, 15, 15, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo derecho-->
	glTranslatef(1.25, 0.65, 0);
	glRotatef(rotBrazoDer, 0.0, 1.0, 0.0);
	glRotatef(movBrazoDer, 0.0, 0.0, 1.0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glRotatef(-25, 0, 0, 1);
	glRotatef(-25, 1, 0, 0);
	glTranslatef(0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo izquierdo <--
	glTranslatef(-1.25, 0.65, 0);
	glRotatef(rotBrazoIzq, 0, 1, 0);
	glRotatef(movBrazoIzq, 0.0, 0.0, 1.0);

	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);
	glRotatef(25, 0, 0, 1);
	glRotatef(25, 1, 0, 0);
	glTranslatef(-0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Cintura
	glColor3f(0, 0, 1);
	glTranslatef(0, -1.5, 0);
	fig7.prisma(1, 2, 1, plata.GLindex);

	//glTranslatef(0.0, movCuerpo+1.5, 0.0);


	glPushMatrix(); //Pie Derecho -->
	glTranslatef(0.75, -0.5, 0);
	glRotatef(-15, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, plata.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 + rotRodDer, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, plata.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	glRotatef(15 - rotRodDer, 1, 0, 0);
	fig7.prisma(0.2, 1.2, 1.5, plata.GLindex);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //Pie Izquierdo -->
	glTranslatef(-0.75, -0.5, 0);
	glRotatef(-5, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, plata.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 + rotRodIzq, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, plata.GLindex);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	glRotatef(15 - rotRodIzq, 1, 0, 0);
	fig7.prisma(0.2, 1.2, 1.5, plata.GLindex);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();

	glPopMatrix();
}

void cocina(void){

	glPushMatrix();
		glTranslatef(0.45, 2.35, -23);
		glRotatef(90,0,1,0);
		refrigerador();
	//MESA 2
	glPopMatrix();
	//TABLA MESA 2
	glPushMatrix();
	glTranslatef(0.51,1.75,-26);
		glPushMatrix(); //ALACENA 2 ARRIBA
		glTranslatef(0,2.35,0);
		glColor3f(1,1,1);
		glRotatef(90,0,1,0);
		glScalef(1.25,1,0.5);
		figures.u_prisma_mueble(0,alacena1.GLindex);
		glPopMatrix();
	glPushMatrix();
	glTranslatef(0.20,0.8,0.0);
	glRotatef(90,0,1,0);
	glScalef(3.25,0.15,1.15);
	//glColor3f(0.5843,0.4196,0.1843);
	figures.u_prisma(cubierta.GLindex);
	glPopMatrix();

	glRotatef(90,0,1,0);
	glScalef(3,1.5,1);
	//glColor3f(0.8901,0.7803,0.6235);
	figures.u_prisma_mueble(0,alacena2.GLindex);
	glPopMatrix();

	//TABLA MESA 2
	glPushMatrix();
	glTranslatef(0.51,1.75,-32);
		glPushMatrix(); //ALACENA 2 ARRIBA
		glTranslatef(0,2.35,0);
		glColor3f(1,1,1);
		glRotatef(90,0,1,0);
		glScalef(1.25,1,0.5);
		figures.u_prisma_mueble(0,alacena1.GLindex);
		glPopMatrix();
	glPushMatrix();
	glTranslatef(0.20,0.8,0.0);
	glRotatef(90,0,1,0);
	glScalef(3.25,0.15,1.15);
	//glColor3f(0.5843,0.4196,0.1843);
	figures.u_prisma(cubierta.GLindex);
	glPopMatrix();

	glRotatef(90,0,1,0);
	glScalef(3,1.5,1);
	//glColor3f(0.8901,0.7803,0.6235);
	figures.u_prisma_mueble(0,alacena2.GLindex);
	glPopMatrix();


	//ESTUFA 1
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0.51,1.75,-28.5);
	glRotatef(90,0,1,0);
	glScalef(1,1.5,1);
	//glColor3f(0.3254,0.4784,0.4549);
	figures.u_prisma_mueble(negroMate.GLindex,estufa.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.51,2.50,-28.5);
	glRotatef(90,0,1,0);
	glScalef(1,0.02,1);
	//glColor3f(0.5843,0.4196,0.1843);
	figures.u_prisma_mueble(estufaCal.GLindex,negroMate.GLindex);
	glPopMatrix();
	glPopMatrix();

	//ESTUFA 2
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0.51,1.75,-29.5);
	glRotatef(90,0,1,0);
	glScalef(1,1.5,1);
	//glColor3f(0,0.4784,0.4549);
	figures.u_prisma_mueble(negroMate.GLindex,estufa.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.51,2.50,-29.5);
	glRotatef(90,0,1,0);
	glScalef(1,0.02,1);
	//glColor3f(0.5843,0.4196,0.1843);
	figures.u_prisma_mueble(estufaCal.GLindex,negroMate.GLindex);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
			glTranslatef(4.5,1.8,-28);
			mesa_cocina();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4,1.75,-21.5);


	//ALACENA ARRIBA
	glPushMatrix();
	glTranslatef(0,2.75,0.20);
	glColor3f(1,1,1);
	glRotatef(180,0,1,0);
	glScalef(1.25,1,0.5);
	figures.u_prisma_mueble(0,alacena1.GLindex);
	glPopMatrix();

	//ALACENA GRANDE
	glPushMatrix();
	glTranslatef(0,1.25,-14.2);
	glScalef(2,4,0.5);
	glColor3f(1,1,1);
	figures.u_prisma_mueble(0,alacena3.GLindex);
	glPopMatrix();

	//TABLA DE MESA 1
	glPushMatrix();
	glTranslatef(0,0.8,-0.05);
	glScalef(3.25,0.15,1.15);
	//glColor3f(0.5843,0.4196,0.1843);
	figures.u_prisma(cubierta.GLindex);
	glPopMatrix();

	glRotatef(180,0,1,0);
	glScalef(3,1.5,1);
	//glColor3f(0.8901,0.7803,0.6235);
	figures.u_prisma_mueble(0,alacena2.GLindex);
	glPopMatrix();

}

void alberca(void){

	glPushMatrix(); //alberca
		glTranslatef(7.8+5.9, -4-0.2, -62.4-3.8);
		glPushMatrix(); //agua
			glTranslatef(0,4.2,0);
			glScalef(9.99,0.1,19.99);
			mov_agua.l_prisma_agua(agua.GLindex);
		glPopMatrix(); //agua
		glScalef(10,10,20);
		figures.l_prisma_alberca(textAlberca.GLindex);
	glPopMatrix(); //alberca

	/*
	glPushMatrix(); //jacuzzi
		glTranslatef(17, -3.4, -46);
		glPushMatrix(); //alberca parte 1
			glTranslatef(-8.45, -6.2, -4.8);
			figures.u_medio_cilindro_sin_tapa(8,10,10,textAlberca.GLindex);
			glPushMatrix(); //alberca parte 2
				//glTranslatef(-8.45,-6.4,-4.8);
				glRotatef(180,0,1,0);
				glScalef(1,1,2);
				figures.u_medio_cilindro_sin_tapa(8,10,10,textAlberca.GLindex);
			glPopMatrix(); //alberca parte 2
		glPopMatrix(); //alberca parte 1
			
		figures.l_cilindro_sin_tapa(2,5,10,textAlberca.GLindex);
	glPopMatrix(); //jacuzzi

	///Agua en la alberca
	glPushMatrix(); //agua
		glTranslatef(17,0.8,-46);
		glPushMatrix(); //alberca parte 1
			glTranslatef(-8.45, -2.2, -4.8);
			figures.u_medio_cilindro_sin_tapa(7.99,0.1,10,agua.GLindex);
			glPushMatrix(); //alberca parte 2
				//glTranslatef(-8.45,-6.4,-4.8);
				glRotatef(180,0,1,0);
				glScalef(1,1,2);
				figures.u_medio_cilindro_sin_tapa(7.99,0.1,10,agua.GLindex);
			glPopMatrix(); //alberca parte 2
		glPopMatrix(); //alberca parte 1
		figures.l_cilindro_sin_tapa(1.99,0.1,10,agua.GLindex);
	glPopMatrix(); //agua
	*/

}

void patioTrasero(void){

	glPushMatrix();
	glTranslatef(9.2,-1.51,-43.4);

	glPushMatrix();
		glTranslatef(22.2, 1, 6);
		glScalef(25.4, 1, 25.2);
		figures.u_prisma_patio(pisoPatioT.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(16.52+5.6, 0.99-0.4, -16.8-2.4-0.22);
		glScalef(25.8-0.6, 2, 24.4+1+1.25);
		figures.u_prisma_patio(pisoPatioT.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.2, 1, -0.17);
		glScalef(18.8, 1, 25.2);
		figures.u_prisma_patio(pisoPatioT.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-11.81, 1, -19.2);
		glScalef(22.6, 0.8, 27.2);
		figures.u_prisma_patio(pisoPatioT.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-16, 1.2, 5.2);
		glScalef(14.2, 0.4, 21.6);
		figures.u_prisma_patio(pisoPatioT.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-15.4, 0.9, 18.2);
		glScalef(15.4, 0.8, 18.8);
		figures.u_prisma_patio(pisoPatioT.GLindex);
	glPopMatrix();

	glPopMatrix();

}

void taza_banio(void){


	glPushMatrix(); //toilet
		//glTranslatef(0,2, 12.8);
		glTranslatef(15.6, 1.6, -16.6);

		glScalef(0.4,0.4,0.4);

		glPushMatrix(); //base
			glTranslatef(0, -1.4, -0.4);
			figures.u_cono(1,2,10,porcelana.GLindex);
		glPopMatrix(); //base

		glPushMatrix(); //caja
			glTranslatef(0, 2.2, -1);
			glScalef(2, 2.0, 0.6);
			figures.l_prisma(porcelana.GLindex);

			glPushMatrix(); //palanca
				glTranslatef(0.4,0.35,0.6);
				glRotatef(90,1,0,0);
				figures.u_cilindro(0.05,0.1,5,plata.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.45, 0.35, 0.6);
				glScalef(0.15, 0.02, 0.2);
				figures.u_prisma(plata.GLindex);
			glPopMatrix(); //palanca

		glPopMatrix(); //caja

		glScalef(1,1,1.7);
		figures.u_cilindro(1,1,10,porcelana.GLindex);

	glPopMatrix(); //toilet

}

void mueble_banio()
{
	glPushMatrix(); //mueble
		glTranslatef(19.6, 1.6+1, -16.6);

		glPushMatrix(); //lavabo
			glTranslatef(-0.6, 1.85, 0);

			glPushMatrix(); //base llave
				glTranslatef(-0.4, -0.6, -0.4);

				glPushMatrix();
					glTranslatef(0.2, 1.0, 0.2);
					glRotatef(90,0,0,1);
					glRotatef(-45, 1, 0, 0);
					figures.u_cilindro(0.05, 0.4, 5, plata.GLindex);
				glPopMatrix();

				figures.u_cilindro(0.05, 1.2, 10, plata.GLindex);
			glPopMatrix(); //base llave

			glRotatef(90,1,0,0);
			figures.u_media_esfera(0.5, 20,20, plata.GLindex);
		glPopMatrix(); //lavabo

		glScalef(2.5,1.5+1.2,1);
		//glColor3f(1,0,1);
		figures.u_prisma_mueble(negroMate.GLindex,muebleBanio.GLindex);
		glPopMatrix();
		//glColor3f(1,1,1);
	//glPopMatrix(); //mueble
}

void mueble_banio_toallas()
{
	glPushMatrix();
	//glTranslatef(15.35,7.5,-20.200005);
	//glScalef(-0.600000,1.000000,1.000000);
	glTranslatef(15.5,7.799997,-19.600002);
	glRotatef(90,0,1,0);
	glScalef(2.000000,1.600000,1.000000);
	glColor3f(1,1,1);
	figures.u_prisma_mueble(negroMate.GLindex,muebleBanio2.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
}

void cama(void){


	glPushMatrix();

	glTranslatef(-16.75,6,5.65);

		glTranslatef(22, 1.6, -11.6);
		//glScalef(1.4, 0.6, 3);

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

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
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
				figures.skybox(0, 0, cielo_superior.GLindex, pasto.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();


			//	Ejes de referencia
			glPushMatrix();
			glBegin(GL_LINES);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(100.0, 0.0, 0.0);

			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 100.0, 0.0);

			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 100.0);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(11.4,0.4,-63.4);
			pato();
			glPopMatrix();

			cocina();

			glPushMatrix();
			glTranslatef(13.75,2,-34);
			//glRotatef(-90,0,1,0);
			silla();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(13.75,2,-31);
			glRotatef(180,0,1,0);
			silla();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(12,2,-32.5);
			glRotatef(90,0,1,0);
			silla();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(15.5,2,-32.5);
			glRotatef(-90,0,1,0);
			silla();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(13.8,0,-32.5);
			glRotatef(45,0,1,0);
			mesa_comedor();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(20.5,1.8,-14);
			glRotatef(180,0,1,0);
			sillon_uno();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(23,0,-15);
			lampara();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(20.5,0,-9.4);
			mueble_librero();
			glPopMatrix();

			glPushMatrix(); //CHIMENEA Y TELE
			glTranslatef(20.5,2,-23.5);

			glPushMatrix();
			glTranslatef(0,2.5,-0.35);
			glColor3f(1,1,1);
			glRotatef(-90,1,0,0);
			
			if (estadoTelevision >= 1 && estadoTelevision <= 10){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t1.GLindex);
				glutPostRedisplay();
			}
			else if (estadoTelevision >= 11 && estadoTelevision <= 20){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t2.GLindex);
				glutPostRedisplay();
			}	
			else if (estadoTelevision >= 21 && estadoTelevision <= 30){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t3.GLindex);
				glutPostRedisplay();
			}	
			else if (estadoTelevision >= 31 && estadoTelevision <= 40){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t4.GLindex);
				glutPostRedisplay();
			}	
			else if (estadoTelevision >= 41 && estadoTelevision <= 50){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t5.GLindex);
				glutPostRedisplay();
			}	
			else if (estadoTelevision >= 51 && estadoTelevision <= 60){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t6.GLindex);
				glutPostRedisplay();
			}	
			else if (estadoTelevision >= 61 && estadoTelevision <= 70){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t7.GLindex);
				glutPostRedisplay();
			}	
			else if (estadoTelevision >= 71 && estadoTelevision <= 80){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t8.GLindex);
				glutPostRedisplay();
			}	
			else if (estadoTelevision >= 81 && estadoTelevision <= 90){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t9.GLindex);
				glutPostRedisplay();
			}	
			else if (estadoTelevision >= 91 && estadoTelevision <= 100){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t10.GLindex);
				glutPostRedisplay();
			}	
			else if (estadoTelevision >= 101 && estadoTelevision <= 110){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t11.GLindex);
				glutPostRedisplay();
			}	
			else if (estadoTelevision >= 111 && estadoTelevision <= 120){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t12.GLindex);
				glutPostRedisplay();
			}	
			else if (estadoTelevision >= 121 && estadoTelevision <= 130){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t13.GLindex);
				glutPostRedisplay();
			}	
			else if (estadoTelevision >= 131 && estadoTelevision <= 140){
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,t14.GLindex);
				glutPostRedisplay();
			}	
				
			glPopMatrix();

			glScalef(1.5,2,1);
			glColor3f(1,1,1);
			figures.u_prisma_mueble(0,chimenea.GLindex);
			glColor3f(1,1,1);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(11.3,1.8,-17);
			glRotatef(90,0,1,0);
			mueble_buro();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(17.75,2.3,-25.5);
			glRotatef(-90,0,1,0);
			mueble_armario();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(18,1.5,-14);
			mesa_centro();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(16.5,1.8,-15);
			glRotatef(135,0,1,0);
			sillon_dos();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(23,1.8,-18);
			glRotatef(255,0,1,0);
			sillon_dos();
			glPopMatrix();


			glDisable(GL_LIGHTING);
				fachada();
				puertas();
				alberca();
				patioTrasero();

				glPushMatrix();
				glTranslatef(10.6,7.0,-29.4);
				glTranslatef(-5.8, posY, 0.0);
				glRotatef(giroMonito, 0,1,0);
				monito();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(40.6,5.9,-32.5);
				//glTranslatef(xx,yy,zz);
				glRotatef(180,0,1,0);
				taza_banio();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(40.4,5.7,-32.2);
				//glTranslatef(xx,yy,zz);
				glRotatef(180,0,1,0);
				mueble_banio();
				glPopMatrix();

				glPushMatrix();
				mueble_banio_toallas();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(9.999995,0.000000,-24.200020);
				glPushMatrix();
				glTranslatef(5.999999,7.599998,-3.000000);
				mesa_centro();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(2.600000,7.399998,-5.999999);

				glPushMatrix();//CUARTO 1
				glTranslatef(0.000000,0.600000,0.000000);
				glScalef(1.000000,0.200000,3.000000);
				glColor3f(0.6274,0.1529,0.0705);
				figures.u_prisma(almohada.GLindex);
				glColor3f(1,1,1);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-1.800000,0.400000,-3.600001);
				glRotatef(45,0,1,0);
				glPushMatrix();
				glTranslatef(0.000000,-0.3,0.400000);
				glScalef(0.800000,0.800000,1.000000);
				
				glPushMatrix(); //TELE
				glTranslatef(0,2.5,-0.35);
				glColor3f(1,1,1);
				glRotatef(-90,1,0,0);
				figures.u_prisma_tele(0.25,2.5,2.5,negroMate.GLindex,tele1.GLindex);	
				glPopMatrix();

				glPopMatrix();
				glScalef(1.600000,1.400000,0.800000);
				glColor3f(0.3529,0.1764,0.0862);
				figures.u_prisma_mueble(madera.GLindex,tocador.GLindex);
				glColor3f(1,1,1);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-11.399994,0.400000,3.800001);
				glRotatef(90,0,1,0);
				glScalef(1.200000,1.000000,1.000000);
				sillon_uno();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.200000,1.500000,4.700000);
				glRotatef(180,0,1,0);
				glScalef(1.600000,3.800001,1.000000);
				glColor3f(0.3529,0.1764,0.0862);
				figures.u_prisma_mueble(madera.GLindex,ropero.GLindex);
				glColor3f(1,1,1);
				glPopMatrix();

				glScalef(1.000000,1.000000,2.800000);
				figures.u_prisma(madera.GLindex);
				glPopMatrix();

				cama();
				glPopMatrix();

				glPushMatrix();//CUARTO 2
				glTranslatef(19.4,0.000000,2.400000);

				glPushMatrix();
				glTranslatef(3.600001,8.799996,-11.799994);
				glScalef(1.600000,3.800001,1.000000);
				figures.u_prisma_mueble(madera.GLindex,0);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-2.800000,7.699997,-4.600000);
				glPushMatrix();
				glTranslatef(0.400000,-0.000000,-0.000000);
				glRotatef(90,0,1,0);
				glScalef(0.600000,0.600000,1.000000);
				tele();
				glPopMatrix();
				glRotatef(90,0,1,0);
				glScalef(1.200000,1.400000,1.000000);
				figures.u_prisma_mueble(madera.GLindex,0);
				glPopMatrix();

				glScalef(0.800000,1.000000,0.800000);

				glPushMatrix();
				glTranslatef(-23.800018,7.7,-10.999994);
				glPushMatrix();
				glTranslatef(0.400000,-0.000000,-0.000000);
				glRotatef(90,0,1,0);
				glScalef(0.600000,0.600000,1.000000);
				tele();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0.000000,-1.800000,16.599991);

				glPushMatrix();
				glTranslatef(-0.000000,-0.200000,-32.000050);
				glRotatef(-90,0,1,0);
				glScalef(1.000000,1.000000,1.000000);
				mueble_banio();
				glPopMatrix();

				glScalef(1.000000,1.000000,1.000000);
				taza_banio();
				glPopMatrix();

				glRotatef(90,0,1,0);
				//glScalef(1.200000,1.400000,1.000000);
				glScalef(1.400000,1.400000,0.800000);
				figures.u_prisma_mueble(madera.GLindex,0);
				glPopMatrix();
				cama();
				glPopMatrix();


				glPushMatrix();

				cama();
				glPopMatrix();
			glEnable(GL_LIGHTING);
			divisiones();
			divisiones_superior();
			
			for(int i = 0; i < 3; i++){
				glPushMatrix();
					glTranslatef(10 + 10 * i, 0, 5);
					//glScalef(0.3, 0.3, 0.3);
					arbol(tree_tex.GLindex);
				glPopMatrix();

				glPushMatrix();
				glTranslatef(15 + 10 * i, 0, 10);
				//glScalef(0.3, 0.3, 0.3);
				arbol(tree_tex.GLindex);
				glPopMatrix();
			}

			glPushMatrix();
				glTranslatef(21.4, 14.7, -24.6);
				glScalef(3.4, 8.4, 1);
				figures.ventana(window_texture.GLindex, true, false, false, 
				false, false, false);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(25.4, 3.4, -25.2);
				glScalef(3.4, 3, 1);
				figures.ventana(window_texture.GLindex, true, false, false, 
					false, false, false);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(25.2, 12, -6.6);
			glScalef(2, 4.2, 3.2);
			figures.ventana(window_texture.GLindex, false, false, false,
				false, false, true);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(26.8, 3.6, -22.4);
			glScalef(1, 3, 3.2);
			figures.ventana(window_texture.GLindex, false, false, false,
				false, false, true);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0, 1.8, -18);
			glScalef(0.2, 3.605, 2.2);
			figures.puerta(door.GLindex, false, true);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(8.4, 9, -22.6);
			glScalef(1, 3.8, 1.6);
			figures.puerta(door.GLindex, false, true);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(8.6, 9, -22.6);
			glScalef(1, 3.8, 1.6);
			figures.puerta(door.GLindex, false, true);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(pos_ball_x, pos_ball_y, pos_ball_z);
			glRotatef(rot_ball_x, -1, 0, 0);
			figures.u_esfera(1, 20, 20, ball.GLindex);
			glPopMatrix();

		glPopMatrix(); 

	glPopMatrix();

	glutSwapBuffers();
}

void animacion()
{
	//	Movimiento del agua
	mov_agua.t_ini -= 0.001;
	mov_agua.t_fin -= 0.001;

	if (mov_agua.t_ini < -1.0)
	{
		mov_agua.t_ini = 0.0;
	}
	if(mov_agua.t_fin < 0.0)
	{
		mov_agua.t_fin = 1.0;
	}

	++estadoTelevision;
	if(estadoTelevision == 140) estadoTelevision = 1;

	switch (estadoPato)
	{
		case 1:
			pos_pato_z += 0.01;
			if(pos_pato_z >= 6)
			{
				estadoPato = 2;
				ant_pos_pato_z = pos_pato_z;
			}
			break;
		case 2:
			pos_pato_z += 0.01;
			pos_pato_x += 0.05;
			rot_pato += 3;
			if(rot_pato >= 180)
			{
				estadoPato = 3;
				ant_pos_pato_z = pos_pato_z;
			}
			break;
		case 3:
			pos_pato_z -= 0.01;
			if(pos_pato_z <= -10)
			{
				estadoPato = 4;
			}
			break;
		case 4:
			pos_pato_z -= 0.01;
			pos_pato_x -= 0.05;
			rot_pato += 3;
			if(rot_pato >= 360)
			{
				rot_pato = 0;
				estadoPato = 1;
				pos_pato_x = 0;
			}
			break;
	}

//<<<<<<< HEAD
//=======
//<<<<<<< HEAD
	//Movimiento del monito
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
								  //Interpolation
				KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotRodDerInc = (KeyFrame[playIndex + 1].rotRodDer - KeyFrame[playIndex].rotRodDer) / i_max_steps;
				KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movBrazoDerInc = (KeyFrame[playIndex + 1].movBrazoDer - KeyFrame[playIndex].movBrazoDer) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movBrazoIzqInc = (KeyFrame[playIndex + 1].movBrazoIzq - KeyFrame[playIndex].movBrazoIzq) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotBrazoDerInc = (KeyFrame[playIndex + 1].rotBrazoDer - KeyFrame[playIndex].rotBrazoDer) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotBrazoIzqInc = (KeyFrame[playIndex + 1].rotBrazoIzq - KeyFrame[playIndex].rotBrazoIzq) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movCuerpoInc = (KeyFrame[playIndex + 1].movCuerpo - KeyFrame[playIndex].movCuerpo) / i_max_steps;
			}
		}
		else
		{	//Draw information


			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;

			movCuerpo += KeyFrame[playIndex].movCuerpoInc;

			rotRodIzq += KeyFrame[playIndex].rotInc;
			rotRodDer += KeyFrame[playIndex].rotRodDerInc;
			giroMonito += KeyFrame[playIndex].giroMonitoInc;
			movBrazoDer += KeyFrame[playIndex].movBrazoDerInc;

			movBrazoIzq += KeyFrame[playIndex].movBrazoIzqInc;
			rotBrazoDer += KeyFrame[playIndex].rotBrazoDerInc;
			rotBrazoIzq += KeyFrame[playIndex].rotBrazoIzqInc;

			

			i_curr_steps++;
		}

	}

	frame++;
	time2 = glutGet(GLUT_ELAPSED_TIME);
	if (time2 - timebase > 1000) {
		sprintf(s, "FPS:%4.2f", frame*1000.0 / (time2 - timebase));
		timebase = time2;
		frame = 0;
	}

//=======
	//	Movimiento de la pelota
	switch(estadoPelota){
		case 1:
			pos_ball_z -= 0.2;
			rot_ball_x -= 1;
			if (pos_ball_z <= -37.5) {
				estadoPelota = 2;
			}
			break;
		case 2:
			pos_ball_z = -38.0 - (v_ini_ball * ball_t);
			pos_ball_y = par_pos_ball_y_ini + (v_ini_ball * sin(angle_ball) * ball_t 
				- 0.5 * gravity * ball_t * ball_t);
			ball_t += 0.01;

			if (pos_ball_y <= 0)
			{
				estadoPelota = 3;
				xx = pos_ball_z;
			}
			break;
		case 3:
			rot_ball_x += 0.2;
			break;
	}
	
//>>>>>>> refs/remotes/origin/master
//>>>>>>> 24ff8ad8257540ac645e88e7afe1a4ca17ce7eeb


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

		case 'w':   //Movimientos de camara
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

		//Tecla para colocar la camara al interior de un cuarto de la casa
		case 'c':
		case 'C':
			objCamera.Position_Camera(16.27, 9.5f, -9.68, 14, 9.5f, -7, 0, 1, 0);
			break;

		//Tecla para colocar la camara a un lado de la alberca
		case 'p':
		case 'P':
			//objCamera.Position_Camera(22.13, 6.69f, -38.55, -48.94, 2.5f, -69.66, 0, 1, 0);
			objCamera.Position_Camera(22.13, 6.69f, -38.55, 20, 4.0f, -40, 0, 1, 0);
			break;

		//Tecla para colocar la camara en una vista isometrica de la casa
		case 'i':
		case 'I':
			objCamera.Position_Camera(-23.94, 58.5f, 16.99, -5, 2.5f, -12.39, 0, 1, 0);
			break;

		case 'u':
		case 'U':
			zz -= 0.2;
			break;

		case 'j':
		case 'J':
			zz += 0.2;
			break;

		case 'h':
		case 'H':
			xx -= 0.2;
			break;

		case 'k':
		case 'K':
			xx += 0.2;
			break;

		case 'y':
		case 'Y':
			yy += 0.2;
			break;

		case 'n':
		case 'N':
			yy -= 0.2;
			break;

		case '1':
			tamx += 0.2;
			break;
		case '2':
			tamx -= 0.2;
			break;

		case '3':
			tamy += 0.2;
			break;

		case '4':
			tamy -= 0.2;
			break;

		case '5':
			tamz += 0.2;
			break;

		case '6':
			tamz -= 0.2;
			break;

		case 'l':
		case 'L':
			printf("(xx,yy,zz) (%f,%f,%f)\n", xx,yy,zz);
			//printf("(tamx,tamy,tamz) (%f,%f,%f)\n", tamx,tamy,tamz);
			//printf("(mPos) (%f, %f, %f)\n", objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z);
			//printf("(mView) (%f, %f, %f)\n", objCamera.mView.x, objCamera.mView.y, objCamera.mView.z);
			//printf("(mUp) (%f, %f, %f)\n", objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
			
			/*for(int i = 1; i <= FrameIndex; i++){
				//printf("posX: %f\n", posX);
				//printf("posY: %f\n", posY);
				//printf("posZ: %f\n", posZ);
				printf("rotRodIzq: %f\n", KeyFrame[i].rotRodIzq);
				printf("rotRodDer: %f\n", KeyFrame[i].rotRodDer);
				printf("giroMonito: %f\n", KeyFrame[i].giroMonito);
				printf("movBrazoDer: %f\n", KeyFrame[i].movBrazoDer);
				printf("movBrazoIzq: %f\n", KeyFrame[i].movBrazoIzq);
				printf("movCuerpo: %f\n", KeyFrame[i].movCuerpo);
				printf("rotBrazoDer: %f\n", KeyFrame[i].rotBrazoDer);
				printf("rotBrazoIzq: %f\n", KeyFrame[i].rotBrazoIzq);
			}*/

			/*
			KeyFrame[0].posX = 0;
	KeyFrame[0].posY = 2.5;
	KeyFrame[0].posZ = -3.5;
	KeyFrame[0].rotRodIzq = 0;
	KeyFrame[0].rotRodDer = 0;
	KeyFrame[0].giroMonito = 0;
	KeyFrame[0].movBrazoDer = 0;
	KeyFrame[0].movBrazoIzq = 0;
	KeyFrame[0].movCuerpo = 0;
	KeyFrame[0].rotBrazoDer = 0;
	KeyFrame[0].rotBrazoIzq = 0;
			*/

			break;

		case 'o':		//
	case 'O':
		if (FrameIndex<MAX_FRAMES)
		{
			printf("frameindex %d\n", FrameIndex);

			KeyFrame[FrameIndex].posX = posX;
			KeyFrame[FrameIndex].posY = posY;
			KeyFrame[FrameIndex].posZ = posZ;

			KeyFrame[FrameIndex].rotRodIzq = rotRodIzq;
			KeyFrame[FrameIndex].rotRodDer = rotRodDer;
			KeyFrame[FrameIndex].giroMonito = giroMonito;
			KeyFrame[FrameIndex].movBrazoDer = movBrazoDer;
			KeyFrame[FrameIndex].movBrazoIzq = movBrazoIzq;
			KeyFrame[FrameIndex].rotBrazoDer = rotBrazoDer;
			KeyFrame[FrameIndex].rotBrazoIzq = rotBrazoIzq;
			KeyFrame[FrameIndex].movCuerpo = movCuerpo;

			FrameIndex++;
		}

		break;

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
		break;

		case 'x':
		rotRodIzq++;
		//printf("%f \n", rotRodIzq);
		break;

	case 'X':
		rotRodIzq--;
		//printf("%f \n", rotRodIzq);
		break;

	case 'v':
		rotRodDer++;
		//printf("%f \n", rotRodIzq);
		break;

	case 'V':
		rotRodDer--;
		//printf("%f \n", rotRodIzq);
		break;

	case 'b':
		rotBrazoIzq++;
		//printf("%f \n", rotRodIzq);
		break;

	case 'B':
		rotBrazoIzq--;
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

	case 'm':
		movBrazoIzq++;
		//printf("%f \n", rotRodIzq);
		break;

	case 'M':
		movBrazoIzq--;
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

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
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
  glutCreateWindow    ("Jerarquia"); // Nombre de la Ventana
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



void refrigerador()
{
	//glTranslatef(1, 1.25, -0.4);

	//	Principal (trasera)
	glPushMatrix();
		glTranslatef(0,0.5,0);
		glScalef(2, 3.5, 0.8);
		figures.u_prisma(refri.GLindex);
	glPopMatrix();

	//	Delantera (izquierda)
	glPushMatrix();
		glTranslatef(-0.95, -1.3505, 0.55);
		figures.u_cilindro(0.05, 0.1, 6, metal_cromo.GLindex);
	glPopMatrix();

	//	Delantera (derecha)
	glPushMatrix();
		glTranslatef(0.95, -1.3505, 0.55);
		figures.u_cilindro(0.05, 0.1, 6, metal_cromo.GLindex);
	glPopMatrix();

	//	Trasera (izquierda)
	glPushMatrix();
		glTranslatef(-0.95, -1.3505, -0.35);
		figures.u_cilindro(0.05, 0.1, 6, metal_cromo.GLindex);
	glPopMatrix();

	//	Trasera (derecha)
	glPushMatrix();
		glTranslatef(0.95, -1.3505, -0.35);
		figures.u_cilindro(0.05, 0.1, 6, metal_cromo.GLindex);
	glPopMatrix();

	//	Principal (delantera, abajo)
	glPushMatrix();
		glTranslatef(0, 0.2505, 0.505);

		//	Manija (superior)
		glPushMatrix();
			glTranslatef(-0.7, 0.50, 0.130);
			glScalef(0.05, 0.1, 0.05);
			figures.u_prisma(metal_cromo.GLindex);
		glPopMatrix();

		//	Manija (cilindro)
		glPushMatrix();
			glTranslatef(-0.7, -0.15, 0.150);
			figures.u_cilindro(0.025, 0.7, 6, metal_cromo.GLindex);
		glPopMatrix();

		//	Manija (inferior)
		glPushMatrix();
			glTranslatef(-0.7, -0.1, 0.130);
			glScalef(0.05, 0.1, 0.05);
			figures.u_prisma(metal_cromo.GLindex);
		glPopMatrix();

		glScalef(2, 3, 0.2);
		figures.u_prisma(refri.GLindex);
	glPopMatrix();

	//	Principal (delantera, arriba)
	glPushMatrix();
		glTranslatef(0, 1.7505, 0.505);

		//	Manija (superior)
		glPushMatrix();
			glTranslatef(-0.7, -0.25, 0.130);
			glScalef(0.05, 0.1, 0.05);
			figures.u_prisma(metal_cromo.GLindex);
		glPopMatrix();

		//	Manija (cilindro)
		glPushMatrix();
			glTranslatef(-0.7, -0.3, 0.150);
			figures.u_cilindro(0.025, 0.6, 6, metal_cromo.GLindex);
		glPopMatrix();

		//	Manija (inferior)
		glPushMatrix();
			glTranslatef(-0.7, 0.23, 0.130);
			glScalef(0.05, 0.1, 0.05);
			figures.u_prisma(metal_cromo.GLindex);
		glPopMatrix();

		glScalef(2, 1, 0.2);
		figures.u_prisma(refri.GLindex);
	glPopMatrix();
	
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
	//glColor3f(1,1,1);
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

void mueble_buro()
{
	glPushMatrix();
	glTranslatef(0,0.3,0);
	glPushMatrix();//PATA1
	glTranslatef(0.9,-1.1,0.15);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_cilindro(0.05,0.4,5,madera.GLindex);
	glPopMatrix();

	glPushMatrix();//PATA2
	glTranslatef(-0.9,-1.1,0.15);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_cilindro(0.05,0.4,5,madera.GLindex);
	glPopMatrix();

	glPushMatrix();//PATA3
	glTranslatef(-0.9,-1.1,-0.15);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_cilindro(0.05,0.4,5,madera.GLindex);
	glPopMatrix();

	glPushMatrix();//PATA4
	glTranslatef(0.9,-1.1,-0.15);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_cilindro(0.05,0.4,5,madera.GLindex);
	glPopMatrix();

	glPushMatrix();//PATA5
	glTranslatef(0.0,-1.1,0.15);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_cilindro(0.05,0.4,5,madera.GLindex);
	glPopMatrix();

	glPushMatrix();//PATA6
	glTranslatef(0.0,-1.1,-0.15);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_cilindro(0.05,0.4,5,madera.GLindex);
	glPopMatrix();


	glScalef(2,1.5,0.5);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_prisma_mueble(madera.GLindex,muebleBuro.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);

}

void mueble_armario()
{
	glPushMatrix();
	glTranslatef(0,1.0,0);
	glPushMatrix();
	glTranslatef(0,2.25,0);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_prisma_trapecio(0.5,2,0.5,madera.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-2.125,0);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_prisma_trapecio(0.5,2,0.5,madera.GLindex);
	glPopMatrix();
	glScalef(2,4.0,0.5);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_prisma_mueble(madera.GLindex,vitrina.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);
}


void mueble_librero()
{
	glPushMatrix();
	glTranslatef(0,3.0,0);
	glScalef(3,4,0.75);
	glRotatef(180,0,1,0);
	glColor3f(0.2745,0.1882,0.1333);
	figures.u_prisma_mueble(madera.GLindex,librero.GLindex);
	glPopMatrix();
	glColor3f(1,1,1);

}
void mesa_centro()
{

	glPushMatrix();

	for (int i = 0; i < 4; i++)
	{
		glPushMatrix();
		//glColor3f(1,0.25,0.5);
		glTranslatef(0.4*cos(PI/2 * i),-0.5,0.4*sin(PI/2 * i));
		figures.u_cilindro(0.05,1,5,madera.GLindex);
		glPopMatrix();
	}

	//glColor3f(0.75,1,0.25);
	glTranslatef(0,0.5,0);
	figures.u_cilindro(0.5,0.1,30,madera.GLindex);
	
	glPopMatrix();
	//glColor3f(1,1,1);
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

void mesa_cocina()
{
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0,0.80,0);
	glScalef(2.5,0.1,2.5);
	//glColor3f(0.8901,0.7803,0.6235);
	figures.u_prisma(cubierta.GLindex);
	glPopMatrix();
	glScalef(1.5,1.5,2);
	//glColor3f(0.6901,0.4980,0.2196);
	figures.u_prisma(0);
	glPopMatrix();	
}

void pato()
{
	glPushMatrix();

	glTranslatef(pos_pato_x, pos_pato_y, pos_pato_z);
	glRotatef(rot_pato, 0, 1, 0);

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

void divisiones() {

	glPushMatrix();
		//	División entrada (derecha)
		glTranslatef(17, 3, -4.502);
		glScalef(18, 6, 9);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		//	División entrada (derecha sala)
		glTranslatef(9.5, 3, -17);
		glScalef(3, 6, 8);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(10, 3, -12.5);
		glScalef(4, 6, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	División central entrada sala
	glPushMatrix();
		glTranslatef(8.5, 5.5, -10.5);
		glScalef(1, 1, 3);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	División Pasillo Cochera
	glPushMatrix();
	glTranslatef(3, 2, -16.5);
	glScalef(6, 4, 1);
	figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	División Pasillo Cochera
	glPushMatrix();
	glTranslatef(3.5, 2, -20.5);
	glScalef(5, 4, 1);
	figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	División Pasillo Cochera
	glPushMatrix();
	glTranslatef(0.5, 2, -20);
	glScalef(1, 4, 2);
	figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	División Pasillo Cochera
	glPushMatrix();
	glTranslatef(0.5, 3.75, -18);
	glScalef(1, 0.5, 2);
	figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	ESCALERAS	
	glPushMatrix();	// 01
		glColor3f(0.8,0.8,0.8);
		glTranslatef(2, 0.25, -10);
		glScalef(4, 0.5, 2);
		figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
		//glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 02
	glColor3f(1,1,0);
	glTranslatef(1.5, 0.5, -10.5);
	glScalef(3, 1, 1);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 03
	glColor3f(1,1,0);
	glTranslatef(1.5, 0.75, -11.5);
	glScalef(3, 1.5, 1);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 04
	glColor3f(1,1,0);
	glTranslatef(1.5, 1, -12.5);
	glScalef(3, 2, 1);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 05
	glColor3f(1,1,0);
	glTranslatef(1.5, 1.25, -13.5);
	glScalef(3, 2.5, 1);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 06
	glColor3f(1,1,0);
	glTranslatef(1.5, 1.5, -14.5);
	glScalef(3, 3, 1);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 07
	glColor3f(1,1,0);
	glTranslatef(1.5, 1.75, -15.5);
	glScalef(3, 3.5, 1);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	//	Escalera (vuelta)
	glPushMatrix();	// 08-1
	glColor3f(1,1,0);
	glTranslatef(1.5, 3.5, -16.5);
	glScalef(3, 1.01, 1.01);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 08-2
	glColor3f(1,1,0);
	glTranslatef(1.5, 3.75, -18);
	glScalef(3, 0.501, 4.01);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 09
	glColor3f(1,1,0);
	glTranslatef(3.5, 4.25, -18);
	glScalef(1, 0.5, 4);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 10
	glColor3f(1,1,0);
	glTranslatef(4.5, 4.5, -18);
	glScalef(1, 1, 4);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 11
	glColor3f(1,1,0);
	glTranslatef(5.5, 4.75, -18);
	glScalef(1, 1.5, 4);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 12
	glColor3f(1,1,0);
	glTranslatef(6.5, 5, -18);
	glScalef(1, 2, 4);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 13
	glColor3f(1,1,0);
	glTranslatef(7.5, 5.25, -18);
	glScalef(1, 2.5, 4);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();

	glPushMatrix();	// 14
	glColor3f(1,1,0);
	glTranslatef(8.5, 5.5, -18);
	glScalef(1, 3, 4);
	figures.u_prisma_escalera(piso.GLindex,piso.GLindex);
	glColor3f(1,1,1);
	glPopMatrix();	//	Fin escaleras


	//	Modificaciones sala
	glPushMatrix();
		glTranslatef(26.5, 3.5, -11);
		glScalef(1, 5, 4);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(26.5, 3, -11);
		glScalef(1.05, 6, 4.05);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(27.5, 3.5, -16.5);
		glScalef(1, 7, 9);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(27.5, 1, -22.5);
		glScalef(1, 2, 3);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(27.5, 6, -22.5);
		glScalef(1, 2, 3);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(27.5, 3.5, -24.5);
		glScalef(1, 7, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(25.5, 1, -24.5);
		glScalef(3, 2, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(25.5, 6, -24.5);
		glScalef(3, 2, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(21.5, 3.5, -24.5);
		glScalef(5, 7, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	PISO SALA
	glPushMatrix();
		glTranslatef(19, 0.5, -16.5);
		glScalef(16, 1, 15);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	Fin modificaciones sala

	//	División sala-comedor
	glPushMatrix();
		glTranslatef(18.5, 3.5, -30);
		glScalef(1, 7, 11.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(17.495, 3.5, -27.5);
		glScalef(3, 7, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();


	//	División cocina-comedor
	glPushMatrix();
		glTranslatef(9.5, 3.5, -27.5);
		glScalef(3, 7, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(8.5, 3.5, -29);
		glScalef(1, 7, 2);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(8.5, 3.5, -35);
		glScalef(1, 7, 1.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	Pared Escaleras
	glPushMatrix();
		glTranslatef(4.5, 12.49, -20.5);
		glScalef(8.995, 17, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	PISO COCINA/COMEDOR
	glPushMatrix();
		glTranslatef(9.5, 0.5, -28.5);
		glScalef(18.995, 0.995, 14.995);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	Escalones hacia la sala
	glPushMatrix();
		glTranslatef(9.5, 0.25, -10.5);
		glScalef(1, 0.5, 3);
		figures.u_prisma(pared_interior.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(10.5, 0.5, -10.5);
		glScalef(1, 1, 3);
		figures.u_prisma(pared_interior.GLindex);
	glPopMatrix();

	//	Escalones hacia el comedor
	glPushMatrix();
		glTranslatef(7, 0.25, -20.25);
		glScalef(2, 0.5, 0.5);
		figures.u_prisma(pared_interior.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(7, 0.5, -20.75);
		glScalef(2, 1, 0.5);
		figures.u_prisma(pared_interior.GLindex);
	glPopMatrix();

	/*glPushMatrix();
		glTranslatef(5, 5, 5);
		figures.u_cuarto_cilindro(3, 3, 20, pared_interior.GLindex);
	glPopMatrix();*/

	//	Escalones en la entrada
	glPushMatrix();
		glTranslatef(4.8, 0.3, 1.05);
		glScalef(8, 0.5, 2);
		figures.u_prisma(pared_interior.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4.8, 0.6, 0.505);
		glScalef(5, 1, 1);
		figures.u_prisma(pared_interior.GLindex);
	glPopMatrix();



}

void divisiones_superior()
{
	//	PISO SUPERIOR CENTRAL
	glPushMatrix();
		glTranslatef(11, 6.5, -16.5);
		glScalef(5.995, 0.995, 16.995);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(8.5, 14, -22.5);
		glScalef(1, 13.995, 4.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(11, 14, -24.5);
		glScalef(6, 13.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(14.5, 14, -20.5);
		glScalef(1, 13.995, 7);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISION CUARTO TRACEY-BAÑO
	glPushMatrix();
		glTranslatef(21, 14, -14.5);
		glScalef(14, 13.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	PARED EXTERIOR
	glPushMatrix();
		glTranslatef(27.5, 14, -19.5);
		glScalef(1, 13.995, 11);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(21, 20, -24.5);
		glScalef(14, 1.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(21, 9, -24.5);
		glScalef(13.995, 3.995, 0.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(17, 15.995, -24.5);
		glScalef(6, 10, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(25, 15.995, -24.5);
		glScalef(4, 10, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA TECHO TRACEY
	glPushMatrix();
		glTranslatef(14.5, 15.995, -16);
		glScalef(1, 10, 2);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	PISO CUARTO TRACEY
	glPushMatrix();
		glTranslatef(21, 6.5, -19);
		glScalef(13.995, 0.995, 9.995);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	TECHO COCINA/COMEDOR
	glPushMatrix();
		glTranslatef(9.5, 6.505, -28.5);
		glScalef(18.995, 1, 14.995);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	PISO PASILLO BAÑO SUPERIOR CENTRAL
	glPushMatrix();
		glTranslatef(20.5, 6.5, -12.5);
		glScalef(13, 1, 3);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();


	//	PRISMA CUARTO DE MICHAEL
	glPushMatrix();
		glTranslatef(4.5, 13.5, -11.5);
		glScalef(8.995, 14.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	PARTE 1 PUERTA CUARTO DE MICHAEL¡
	glPushMatrix();
		glTranslatef(8.5, 13.5, -10.5);
		glScalef(1, 14.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE MICHAEL¡
	glPushMatrix();
		glTranslatef(11, 13.5, -7.5);
		glScalef(6, 14.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE MICHAEL-BAÑO¡
	glPushMatrix();
		glTranslatef(8.5, 13.5, -6);
		glScalef(0.995, 14.995, 3.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE MICHAEL-BAÑO 2
	glPushMatrix();
		glTranslatef(8.5, 13.5, -1);
		glScalef(0.995, 14.995, 1.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE MICHAEL-BAÑO 3
	glPushMatrix();
		glTranslatef(8.5, 15.5, -3);
		glScalef(0.995, 10.995, 2);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE MICHAEL-BAÑO 4
	glPushMatrix();
		glTranslatef(8.5, 15.5, -9);
		glScalef(0.995, 10.995, 2);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	PISO
	glPushMatrix();
		glTranslatef(4.5, 6.495, -6);
		glScalef(8.995, 1, 11.995);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	PISO 2 (baño)
	glPushMatrix();
		glTranslatef(11, 6.5, -4);
		glScalef(6, 1, 7.995);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();


	//	PISO 3 (CUARTO DE JIMMY)
	glPushMatrix();
		glTranslatef(20, 6.5, -5.505);
		glScalef(11.995, 1, 11);
		figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();

	//	Cerrar superficie principal
	glPushMatrix();
		glTranslatef(19, 0, 0);
		glBindTexture(GL_TEXTURE_2D, cuarzo.GLindex);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
			glTexCoord2f(1.0, 0.0); glVertex3f(7, 0, 0);
			glTexCoord2f(1.0, 1.0); glVertex3f(7, 21, 0);
			glTexCoord2f(0.0, 1.0); glVertex3f(0, 21, 0);
		glEnd();
		glEnable(GL_LIGHTING);

		glTranslatef(0, 0, -0.02);
		glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
			glTexCoord2f(1.0, 0.0); glVertex3f(7, 0, 0);
			glTexCoord2f(1.0, 1.0); glVertex3f(7, 21, 0);
			glTexCoord2f(0.0, 1.0); glVertex3f(0, 21, 0);
		glEnd();
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE JIMMY
	glPushMatrix();
		glTranslatef(15, 13.5, -5.5);
		glScalef(2, 14.995, 10.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN CENTRAL PUERTA CUARTO DE JIMMY
	glPushMatrix();
		glTranslatef(17, 15.5, -10.5);
		glScalef(2, 10.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN PUERTA CUARTO DE JIMMY
	glPushMatrix();
		glTranslatef(22.5, 13.5, -10.5);
		glScalef(9, 14.995, 1);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();


	//	DIVISIÓN FINAL CUARTO 1
	glPushMatrix();
		glTranslatef(26.5, 10.5, -2.5);
		glScalef(1, 21, 5);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN FINAL CUARTO 2
	glPushMatrix();
		glTranslatef(26.5, 5, -6.5);
		glScalef(1, 10, 3);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN FINAL CUARTO 3
	glPushMatrix();
		glTranslatef(26.5, 17.5, -6.5);
		glScalef(1, 7, 3);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN FINAL CUARTO 4
	glPushMatrix();
		glTranslatef(26.5, 10.5, -9.5);
		glScalef(1, 21, 3);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	DIVISIÓN FINAL CUARTO 4
	glPushMatrix();
		glTranslatef(27.5, 10.5, -11.5);
		glScalef(1, 21, 5);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();

	//	Cerrar superficie superior
	glPushMatrix();
		glTranslatef(23, 20.5, -12.5);
		glScalef(8, 1, 25);
		figures.l_prisma(cuarzo.GLindex);
	glPopMatrix();

	glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(23.5, 20.5, -12.5);
		glScalef(9.05, 1.05, 25.05);
		figures.u_prisma(cuarzo.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	//	CIERRE FINAL COMEDOR(SUPERIOR)
	glPushMatrix();
		glTranslatef(18.5, 14, -30);
		glScalef(1, 13.995, 11.995);
		figures.u_prisma(cuarzo.GLindex);
	glPopMatrix();
	
}

void fachada()
{
	glPushMatrix();

	glTranslatef(9.5, 10.5, -18);
	
	//	Figura A (central)
	
	glPushMatrix();
	glScalef(19, 21, -36);
	figures.u_prisma_no_derecha(cuarzo.GLindex);	
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glPushMatrix();
	glScalef(18.995, 20.995, -35.995);
	figures.l_prisma_no_derecha(cuarzo.GLindex, metal_cromo.GLindex);	
	glPopMatrix();
	glDisable(GL_LIGHTING);

	//	Figura B (garage)
	glPushMatrix();
	glTranslatef(-15.501, -7.5, 3.5);
	glScalef(12, 6, 16);
	figures.u_prisma_garage(garage.GLindex, pared_interior.GLindex, metal_cromo.GLindex);
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(-15.501, -7.5, 3.5);
	glScalef(11.995, 5.995, 15.995);
	figures.l_prisma_garage(garage.GLindex, pared_interior.GLindex, metal_cromo.GLindex);
	glPopMatrix();
	glDisable(GL_LIGHTING);

	/*//	Figura C (sala)
	glColor3f(1, 1, 0);
	glPushMatrix();
	glTranslatef(20.501, -6.5, 5.5);
	glScalef(22, 8, 25);
	figures.u_prisma_no_izquierda(metal_cromo.GLindex);
	glPopMatrix();

	//	Cuartos (arriba)
	glColor3f(0, 1, 0);
	glPushMatrix();
	glTranslatef(15.01, 1.01, 5.5);
	glScalef(11, 7, 25);
	figures.u_prisma(metal_cromo.GLindex);
	glPopMatrix();*/

	//	Chimenea
	//glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(-10.501, 1.5, -11.5);
	glScalef(2, 24, 2);
	figures.u_prisma(pisoPatioT.GLindex);
	glPopMatrix();

	glColor3f(1, 1, 1);

	glPopMatrix();
}
