//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Sotres Cataño Mario**************//
//*************				Máquina 10					******//
//*************			Visual Studio 2015				******//
//************************************************************//
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -30; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position

CTexture t_madera;
CTexture t_madera2;
CTexture t_piedra;
CTexture t_ventana;
CTexture t_puerta;
CTexture t_puerta2;
CTexture t_techo;
CTexture t_arbol;
CTexture t_bosque1;
CTexture t_bosque2;
CTexture t_cielo;
CTexture t_pino;
CTexture t_piso;
CTexture t_tierra;
CTexture t_tumba1;
CTexture t_tumba2;
CTexture t_tumba3;
CTexture t_negro;


int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f,0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);  //Habilitamos las texturas

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_madera.LoadTGA("madera.tga"); //cargamos la textura
	t_madera.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_madera.ReleaseImage();

	t_madera2.LoadTGA("madera2.tga"); //cargamos la textura
	t_madera2.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_madera2.ReleaseImage();

	t_piedra.LoadTGA("piedra.tga"); //cargamos la textura
	t_piedra.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_piedra.ReleaseImage();

	t_puerta.LoadTGA("puerta.tga"); //cargamos la textura
	t_puerta.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_puerta.ReleaseImage();

	t_puerta2.LoadTGA("puerta2.tga"); //cargamos la textura
	t_puerta2.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_puerta2.ReleaseImage();

	t_techo.LoadTGA("techo.tga"); //cargamos la textura
	t_techo.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_techo.ReleaseImage();

	t_ventana.LoadTGA("ventana.tga"); //cargamos la textura
	t_ventana.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_ventana.ReleaseImage();

	t_arbol.LoadTGA("arbol.tga"); //cargamos la textura
	t_arbol.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_arbol.ReleaseImage();

	t_bosque1.LoadTGA("bosque1.tga"); //cargamos la textura
	t_bosque1.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_bosque1.ReleaseImage();

	t_bosque2.LoadTGA("bosque2.tga"); //cargamos la textura
	t_bosque2.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_bosque2.ReleaseImage();

	t_pino.LoadTGA("pino.tga"); //cargamos la textura
	t_pino.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_pino.ReleaseImage();

	t_tierra.LoadTGA("tierra.tga"); //cargamos la textura
	t_tierra.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_tierra.ReleaseImage();

	t_piso.LoadTGA("piso.tga"); //cargamos la textura
	t_piso.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_piso.ReleaseImage();

	t_tumba1.LoadTGA("tumba1.tga"); //cargamos la textura
	t_tumba1.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_tumba1.ReleaseImage();

	t_tumba2.LoadTGA("tumba2.tga"); //cargamos la textura
	t_tumba2.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_tumba2.ReleaseImage();

	t_tumba3.LoadTGA("tumba3.tga"); //cargamos la textura
	t_tumba3.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_tumba3.ReleaseImage();

	t_negro.LoadTGA("negro.tga"); //cargamos la textura
	t_negro.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_negro.ReleaseImage();

	t_cielo.LoadTGA("cielo.tga"); //cargamos la textura
	t_cielo.BuildGLTexture();  //generamos la textura y para poder ocuparla
	t_cielo.ReleaseImage();

}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void prisma (GLuint textura1, GLuint textura2,float a, float b, float c,float d)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		
		glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,1.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]); //Se ponen los vértices donde está la textura. La primer coordenada de la
			glTexCoord2f(a, 0.0f); glVertex3fv(vertice[0]); //textura pertenece al primer vértice 0
			glTexCoord2f(a, d); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f, d); glVertex3fv(vertice[7]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(a, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(a, d); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, d); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(-a, 0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(-a, d); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, d); glVertex3fv(vertice[5]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(a, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(a, d); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, d); glVertex3fv(vertice[6]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(a, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(a, d); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0, d); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(b, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(b, c); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0, c); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();

}



void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();
		glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);
	

		//***** TERRENO  ********		//centro (25,0,25)
		glPushMatrix(); 
			glColor3f(1.0, 1.0, 1.0);
			glScalef(50.0,0.0,50.0);  
			prisma(t_tierra.GLindex, t_tierra.GLindex, 1.0, 15.0, 15.0, 1.0); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PISO  ********
		glPushMatrix();
			glTranslatef(0.0f, 0.5f, -10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(30.0, 1.0, 30.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 6.0, 3.0, 10.0, 0.15); //Estamos asignando la textura ladrillo
		glPopMatrix();


/***************************** PARED FRONTAL ***********************************************************/

		//***** PARED FRONTAL  abajo izq********
		glPushMatrix();
			glTranslatef(-9.0f, 4.0f, 4.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(12.0, 6.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 15.0, 10.0, 1.0); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED FRONTAL  abajo der********
		glPushMatrix();
			glTranslatef(9.0f, 4.0f, 4.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(12.0, 6.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 15.0, 10.0, 1.0); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED FRONTAL en medio abajo izq********
		glPushMatrix();
			glTranslatef(-13.0f, 8.5f, 4.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED FRONTAL en medio abajo der********
		glPushMatrix();
			glTranslatef(13.0f, 8.5f, 4.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED FRONTAL en medio abajo ********
		glPushMatrix();
			glTranslatef(0.0f, 8.5f, 4.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(14.0, 3.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED FRONTAL en medio ********
		glPushMatrix();
			glTranslatef(0.0f, 13.0f, 4.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(30.0, 6.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 3.0, 15.0, 10.0, 1.0); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED FRONTAL en medio arriba izq********
		glPushMatrix();
			glTranslatef(-13.0f, 17.5f, 4.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED FRONTAL en medio arriba der********
		glPushMatrix();
		glTranslatef(13.0f, 17.5f, 4.75f);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(4.0, 3.0, 0.5);
		prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED FRONTAL en medio arriba ********
		glPushMatrix();
			glTranslatef(0.0f, 17.5f, 4.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(14.0, 3.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED FRONTAL arriba ********
		glPushMatrix();
			glTranslatef(0.0f, 20.5f, 4.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(30.0, 3.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 3.0, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

/******************************************** FIN PARED FRONTAL ************************************************/

/********************************************* PARED TRASERA ****************************************************/

		//***** PARED TRASERA abajo ********
		glPushMatrix();
			glTranslatef(0.0f, 4.0f, -24.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(30.0, 6.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 3.0, 15.0, 10.0, 1.0); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED TRASERA en medio abajo izq********
		glPushMatrix();
			glTranslatef(-13.0f, 8.5f, -24.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED TRASERA en medio abajo der********
		glPushMatrix();
			glTranslatef(13.0f, 8.5f, -24.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED TRASERA en medio abajo ********
		glPushMatrix();
			glTranslatef(0.0f, 8.5f, -24.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(14.0, 3.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED TRASERA en medio ********
		glPushMatrix();
			glTranslatef(0.0f, 13.0f, -24.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(30.0, 6.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 3.0, 15.0, 10.0, 1.0); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED TRASERA en medio arriba izq********
		glPushMatrix();
			glTranslatef(-13.0f, 17.5f, -24.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED TRASERA en medio arriba der********
		glPushMatrix();
			glTranslatef(13.0f, 17.5f, -24.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED TRASERA en medio arriba ********
		glPushMatrix();
			glTranslatef(0.0f, 17.5f, -24.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(14.0, 3.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED TRASERA arriba ********
		glPushMatrix();
			glTranslatef(0.0f, 20.5f, -24.75f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(30.0, 3.0, 0.5);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 3.0, 15.0, 10.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

/*********************************************FIN PARED TRASERA ***********************************************/


/***********************************************PARED LATERAL DERECHA ****************************************/
		//***** PARED LATERAL DER abajo ********
		glPushMatrix();
			glTranslatef(14.75f, 5.5f, -10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 9.0, 30.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 3.0, 1.0, 1.0, 1.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED LATERAL DER en medio más izq ********
		glPushMatrix();
			glTranslatef(14.75f, 11.5f, 2.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 3.0, 4.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 1.0, 1.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED LATERAL DER en medio izq ********
		glPushMatrix();
			glTranslatef(14.75f, 11.5f, -5.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 3.0, 4.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 1.0, 1.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED LATERAL DER en medio der ********
		glPushMatrix();
			glTranslatef(14.75f, 11.5f, -14.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 3.0, 4.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 1.0, 1.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED LATERAL DER en medio más der ********
		glPushMatrix();
			glTranslatef(14.75f, 11.5f, -22.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 3.0, 4.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 1.0, 1.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED LATERAL DER arriba ********
		glPushMatrix();
			glTranslatef(14.75f, 17.5f, -10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 9.0, 30.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 3.0, 1.0, 1.0, 1.5); //Estamos asignando la textura ladrillo
		glPopMatrix();
/**********************************************FIN PARED LATERAL DERECHA ***********************************/

/********************************************** PARED LATERAL IZQUIERDA ************************************/

		//***** PARED LATERAL IZQ abajo ********
		glPushMatrix();
			glTranslatef(-14.75f, 5.5f, -10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 9.0, 30.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 3.0, 1.0, 1.0, 1.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED LATERAL IZQ en medio más izq ********
		glPushMatrix();
			glTranslatef(-14.75f, 11.5f, 2.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 3.0, 4.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 1.0, 1.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED LATERAL IZQ en medio izq ********
		glPushMatrix();
			glTranslatef(-14.75f, 11.5f, -5.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 3.0, 4.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 1.0, 1.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED LATERAL IZQ en medio der ********
		glPushMatrix();
			glTranslatef(-14.75f, 11.5f, -14.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 3.0, 4.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 1.0, 1.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED LATERAL IZQ en medio más der ********
		glPushMatrix();
			glTranslatef(-14.75f, 11.5f, -22.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.5, 3.0, 4.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 0.7, 1.0, 1.0, 0.5); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//***** PARED LATERAL DER arriba ********
		glPushMatrix();
		glTranslatef(-14.75f, 17.5f, -10.0f);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 9.0, 30.0);
		prisma(t_piedra.GLindex, t_piedra.GLindex, 3.0, 1.0, 1.0, 1.5); //Estamos asignando la textura ladrillo
		glPopMatrix();



/********************************************** FIN PARED LATERAL IZQUIERDA ********************************/

		//***** TECHO  ********
		glPushMatrix();
			glTranslatef(0.0f, 21.5f, -10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(30.0, 1.0, 30.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 3.0, 3.0, 10.0, 10.0); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//********Ventana 1************		
		glPushMatrix();
			glTranslatef(-9.0f, 8.5f, 4.90f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.1);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 2************		
		glPushMatrix();
			glTranslatef(9.0f, 8.5f, 4.90f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.1);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 3************		
		glPushMatrix();
			glTranslatef(9.0f, 17.5f, 4.90f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.1);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 4************		
		glPushMatrix();
			glTranslatef(-9.0f, 17.5f, 4.90f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.1);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 5************		
		glPushMatrix();
			glTranslatef(-9.0f, 17.5f, -24.90f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.1);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 6************		
		glPushMatrix();
			glTranslatef(9.0f, 17.5f, -24.90f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.1);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 7************		
		glPushMatrix();
			glTranslatef(9.0f, 8.5f, -24.90f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.1);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 8************		
		glPushMatrix();
			glTranslatef(-9.0f, 8.5f, -24.90f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(4.0, 3.0, 0.1);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 9************		
		glPushMatrix();
			glTranslatef(14.90f, 11.5f, -1.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.1, 3.0, 4.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 10************		
		glPushMatrix();
			glTranslatef(14.90f, 11.5f, -10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.1, 3.0, 5.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 11************		
		glPushMatrix();
			glTranslatef(14.90f, 11.5f, -18.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.1, 3.0, 4.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 12************		
		glPushMatrix();
			glTranslatef(-14.90f, 11.5f, -1.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.1, 3.0, 4.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 13************		
		glPushMatrix();
			glTranslatef(-14.90f, 11.5f, -10.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.1, 3.0, 5.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Ventana 14************		
		glPushMatrix();
			glTranslatef(-14.90f, 11.5f, -18.5f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.1, 3.0, 4.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_ventana.GLindex, t_ventana.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
			glDisable(GL_ALPHA_TEST);		//desactivamos la transparencia
		glPopMatrix();

		//********Puerta 1************		
		glPushMatrix();
			glTranslatef(1.5f, 4.0f, 4.90f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(3.0, 6.0, 0.1);
			prisma(t_puerta.GLindex, t_puerta.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//********Puerta 2************		
		glPushMatrix();
			glTranslatef(-1.5f, 4.0f, 4.90f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(3.0, 6.0, 0.1);
			prisma(t_puerta2.GLindex, t_puerta2.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
		glPopMatrix();

		//************** torre 1 *****************************
		glPushMatrix();
			glTranslatef(19.0f, 14.0f, 1.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(8.0, 28.0, 8.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 4.0); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(16.5f, 29.0f, 4.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(16.5f, 29.0f, -2.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(21.5f, 29.0f, 4.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(21.5f, 29.0f, -2.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();

		//************** torre 2 ************************************
		glPushMatrix();
			glTranslatef(-19.0f, 14.0f, 1.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(8.0, 28.0, 8.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 4.0); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-16.5f, 29.0f, 4.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-16.5f, 29.0f, -2.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-21.5f, 29.0f, 4.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-21.5f, 29.0f, -2.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();


		/*******************************  torre 3 ******************************************/

		glPushMatrix();
			glTranslatef(-19.0f, 14.0f, -21.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(8.0, 28.0, 8.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 4.0); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-16.5f, 29.0f, -24.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-16.5f, 29.0f, -18.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-21.5f, 29.0f, -24.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-21.5f, 29.0f, -18.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();


	/*************************** torre 4 *******************************/
		glPushMatrix();
			glTranslatef(19.0f, 14.0f, -21.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(8.0, 28.0, 8.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 4.0); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(16.5f, 29.0f, -24.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(16.5f, 29.0f, -18.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(21.5f, 29.0f, -24.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();

		glPushMatrix();
			glTranslatef(21.5f, 29.0f, -18.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(2.0, 2.0, 2.0);
			prisma(t_piedra.GLindex, t_piedra.GLindex, 1.2, 3.0, 3.0, 1.1); //Estamos asignando la textura ladrillo
		glPopMatrix();


	/************** escalón ************/
	glPushMatrix();
		glTranslatef(0.0f, 0.5f, 5.5f);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(6.0, 1.0, 1.0);
		prisma(t_piedra.GLindex, t_madera.GLindex, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura madera
	glPopMatrix();



/*****************************  Paisaje ****************************************/

	glPushMatrix();
		glTranslatef(0.0f, 25.0f, 25.0f);
		glColor3f(1.0, 1.0, 1.0);
		glRotatef(180, 0.0, 1.0, 0.0);
		glScalef(50.0, 50.0, 0.1);
		prisma(t_bosque1.GLindex, t_bosque1.GLindex, 1.0, 1.0, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(25.0f, 25.0f, 0.0f);
		glRotatef(90, 0.0, 1.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(50.0, 50.0, 0.1);
		prisma(t_bosque1.GLindex, t_bosque1.GLindex, 3.0, 1.0, 1.0, 1.0); 
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, 25.0f, -25.0f);
		//glRotatef(90, 0.0, 1.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(50.0, 50.0, 0.1);
		prisma(t_bosque1.GLindex, t_bosque1.GLindex, 3.0, 1.0, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-25.0f, 25.0f, 0.0f);
		glRotatef(-90, 0.0, 1.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(50.0, 50.0, 0.1);
		prisma(t_bosque1.GLindex, t_bosque1.GLindex, 3.0, 1.0, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, 50.0f, 0.0f);
		glRotatef(-90, 1.0, 0.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(50.0, 50.0, 0.1);
		prisma(t_cielo.GLindex, t_cielo.GLindex, 3.0, 1.0, 1.0, 1.0);
	glPopMatrix();




/******************************** fin paisaje ************************************/




		//*****arbol 1********
		glPushMatrix();
			glTranslatef(-13.0f, 20.0f, 15.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(8.0, 40.0, 0.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_pino.GLindex, 0, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura ladrillo
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-13.5f, 20.0f, 14.5f);
			glRotatef(90, 0.0, 1.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(8.0, 40.0, 0.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_pino.GLindex, 0, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura ladrillo
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		//*****arbol 2********
		glPushMatrix();
			glTranslatef(13.0f, 20.0f, 14.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(8.0, 40.0, 0.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_pino.GLindex, 0, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura ladrillo
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(12.5f, 20.0f, 13.5f);
			glRotatef(90, 0.0, 1.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(8.0, 40.0, 0.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_pino.GLindex, 0, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura ladrillo
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		//*****arbol 3********
		glPushMatrix();
			glTranslatef(12.0f, 20.0f, 20.0f);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(8.0, 40.0, 0.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_arbol.GLindex, 0, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura ladrillo
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(12.3f, 20.0f, 20.2f);
			glRotatef(90, 0.0, 1.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(8.0, 40.0, 0.0);
			glEnable(GL_ALPHA_TEST);			//**********Activamos el alpha (activamos la transparencia)
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_arbol.GLindex, 0, 1.0, 1.0, 1.0, 1.0); //Estamos asignando la textura ladrillo
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 8");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Texturas");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
			break;

		case 'u':
		case 'U':
			pos_camY += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'i':
		case 'I':
			pos_camY -= 0.5f;
			//eye_camX += 0.5f;
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
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
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
  glutInitWindowSize  (5000, 5000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 8"); // Nombre de la Ventana
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