#include <GL/glut.h>
#include <math.h>
//para escribir en la consola
#include <iostream>
using namespace std;

//DIBUJO DE PERSONAJE

float camaraX = -20;
float camaraY = 10;
float camaraZ = 30;


float angulo = 2.5;
//para orbitar la camara / mover
float radio = 30;
float centroY = 10;


void iniciarVentana(int ancho, int alto){
    glViewport(0,0,ancho, alto);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, (float)ancho/(float)alto,1,200);
}

void inicializarLuces(){
    //valores es la intensidad
    // sombra reflejo opacidad
    GLfloat luz_ambiente[] = { 0.4,0.4,0.4,1 };
	GLfloat luz_difusa[] = { 0.5,0.5,0.5,1 };
	GLfloat luz_especular[] = { 0.3,0.3,0.3,1 };
	float posicionLuz0[] = { 0,70,60,1 };

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);


	glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicionLuz0);

}

void piso(){
    glPushMatrix();
        glColor3ub(230, 230, 225);
        glTranslated(0,-1,0);
        glScaled(100,1,100); //eje x, y,z
        glutSolidCube(1);
    glPopMatrix();

}

void dibujarEjes(){
    glPushMatrix();
        glLineWidth(2);
        glBegin(GL_LINES);
    //EJE X rojo
            glColor3ub(255,0,0);
            glVertex3d(0,0,0);
            glVertex3d(50,0,0);
    //EJE Y verde
            glColor3ub(0,255,0);
            glVertex3d(0,0,0);
            glVertex3d(0,50,0);

    //EJE z azul
            glColor3ub(0,0,255);
            glVertex3d(0,0,0);
            glVertex3d(0,0,50);
        glEnd();
    glPopMatrix();

}

void pies(float posX){
    glPushMatrix();
        glTranslated(posX,2,0);
        glScaled(1.5, 1.5,1.5); //MARAMODIFICAR ESEFERA
        glutSolidSphere(1.5, 50,50);
        //glutSolidSphere();


    glPopMatrix();
}

void pierna(float posX){
     glPushMatrix();
        glTranslated(posX,2,0);
        glRotated(-90,1,0,0);
        //glScaled(3, 0.6,3); //MARAMODIFICAR ESEFERA
        gluCylinder(gluNewQuadric(),2.2,2.2,5,50,50);
        //glutSolidSphere();
    glPopMatrix();
}

void cuerpo(){
    glPushMatrix();
        glTranslated(0,7,0);
        glScaled(1, 0.7,1);
        glRotated(-90,1,0,0);
        gluCylinder(gluNewQuadric(),8,6,10,50,50);
    glPopMatrix();
}

void brazo(float posX, float rotX){
    glPushMatrix();
         glTranslated(posX,13 ,0);
         glRotated(90,0,7,0); //ejey
         glRotated(rotX,7,0,0); //ejeX
        gluCylinder(gluNewQuadric(),1.5,1.5,6.7,50,50);
    glPopMatrix();
}

void mano(float posX){
    glPushMatrix();
        glTranslated(posX,7.8 ,0);
        glScaled(0.9, 0.9, 0.9);
        glutSolidSphere(1.5,50,50);
    glPopMatrix();
}

void cuerpolinea(){
    glPushMatrix();
        glTranslated(0,6.8 ,6.6);
        glRotated(-16,1,0, 0); //toma forma del cuerpo
        glScaled(0.5 , 7, 1);
        glutSolidCube(1);
    glPopMatrix();

}
void cuello(){
    glPushMatrix();
        glTranslated(0, 10.5 ,0 );
        glRotated(-90, 1, 0,0);
        glScaled(0.6,0.6, 0.6);
        glutSolidTorus(1,10,50, 50);
    glPopMatrix();

}

void cabeza(){
    glPushMatrix();
        glTranslated(0, 20,0 );
        glScaled(0.6,0.6, 0.6);
        glutSolidSphere(9, 50,50);
    glPopMatrix();

}

void gorra(){
    glPushMatrix();
        glTranslated(0, 16.8 ,0 );
        glutSolidSphere(7.8, 50,50);
    glPopMatrix();
}

void gorraAro(){
    glPushMatrix();
        glTranslated(0, 20,0 );
        glRotated(90, 1, 0,0);
        glutSolidTorus(1, 7.2 , 50, 50);
    glPopMatrix();

}
void gorrabola(){
    glPushMatrix();
        glTranslated(0, 24,0 );
        glutSolidSphere(2,50,50 );
    glPopMatrix();

}
void ojo( float posX, float rot){
	glPushMatrix();
	glTranslated(posX,15.1 ,6.9);
	glRotated(rot ,0,0, 1);
        glScaled(0.7, 0.7, 0.7);
        glutSolidSphere(2.8 ,50,50);
	glPopMatrix();

}

void pupila( float posX){
	glPushMatrix();
        glTranslated(posX,15 ,8.5);
        glutSolidSphere(0.7  ,50,50);
	glPopMatrix();

}

void ceja(float posX, float rot){
    glPushMatrix();
        glTranslated(posX,18 ,8);
        glRotated(-90,0,1,0);
        glRotated(rot,1,0,0);
        glScaled(1, 1,1);
        gluCylinder(gluNewQuadric(), 0.2, 0.2, 3, 50 ,50);
	glPopMatrix();
}
void boca(){
    glPushMatrix();
        glTranslated(0, 12.5, 7.18);
        glRotated(15,1,0,0);
        glScaled(1, 0.8, 0.2);
        glutSolidSphere(1.5  ,20,20);
	glPopMatrix();
}

void diente(float posX){
    glPushMatrix();
        glTranslated(posX, 12.5, 7.7);
        glutSolidCube(0.35);
    glPopMatrix();
}


void globo(float posX, float rot){
    glPushMatrix();
    glTranslated(posX, 16, 0);
    glRotated(rot, 0, 0, 1);
    glScaled(0.8, 0.8, 0.8);

    glutSolidSphere(4, 50, 50);

    glPushMatrix();
        glTranslated(0, -4.5, 0);
        glScaled(0.5, 0.5, 0.5);
        glutSolidSphere(1, 20, 20);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.5, 0.35, 0.05);
        glBegin(GL_LINES);
            glVertex3f(0, -5, 0);
            glVertex3f(0, -22, 0);
        glEnd();
    glPopMatrix();

	glPopMatrix();
}


void lentes(float posX, float rot){

    glPushMatrix();
        glTranslated(posX,15 ,9);
        glRotated(rot ,0,0, 1);
        glScaled(0.45, 0.45, 0.45);
        glutSolidTorus(0.5, 5 , 70, 70);
	glPopMatrix();

}



void dibujar(){
  inicializarLuces();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(radio*cos(angulo) , camaraY, radio * sin(angulo) ,0,centroY,0,0,1,0);

    //COLOR DE FONDO
    glClearColor(255/255.0, 214/255.0, 174/255.0,1);
    piso();
    dibujarEjes();
  

    glColor3ub(252, 223, 194);
    mano(9.2);
    mano(-9.2);
    cabeza();

    glColor3ub(182, 8, 8);
    cuerpo();
    brazo(5, 50 );
    brazo(-5, 130 );

    glColor3ub(0,0,0);
    pies(3);
    pies(-3);
    pierna(3);
    pierna(-3);



    glutSwapBuffers();
}

void teclado_especial(int tecla, int x, int y){
    //para reccribir en la consola con la libreria iostream
   // cout<<tecla<<endl;
   switch(tecla)
   {
        case 101:
            camaraY +=0.5;
            break;
        case 103:
            camaraY -=0.5;
            break;
        case 100:
            angulo += 0.05;
            break;
        case 102:
          angulo -= 0.05;
            break;
        case 105:
            radio += 1;
            break;
        case 104:
            radio -= 1;
            break;

   }
}

void timer(int t){
    glutPostRedisplay();
    glutTimerFunc(20,timer,0);
}


int main(int argc, char* argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(850,700);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Ventana de dibujo");
    glutReshapeFunc(iniciarVentana);
    glutDisplayFunc(dibujar);

    //para manejar el teclado
    glutSpecialFunc(teclado_especial);
    glutTimerFunc(0,timer,0);
    glutMainLoop();
    return 0;
}

