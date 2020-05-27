#include <GL/glut.h>

float RSun, RMercury, RVenus, REarth, RMars, RJupiter, RSaturn, RUranus, RNeptune = 0;
float lx = 0, ly = 0, lz = 5, ux = 0, uy = 0, uz = 0, fx = 0, fy = 1, fz = 0;
int orbit = 0;
int rotation = 1;
void _movimentacoesTeclado(unsigned char key, int x, int y);
void idle(void);

/*Sequencia do mais proximo ao sol e seu diametro equatorial
Mercury - 4.880km (0.03)
Venus - 12.104Km (0.06)
Earth - 12.756Km (0.07)
Mars - 6.794Km (0.04)
Jupiter - 143.000Km (0.18)
Saturn - 120.000Km (0.15)
Uranus - 51.000Km (0.11)
Neptune - 49.500Km (0.09)

c ou C para visão de cima
l ou L para visão de lado
f ou F para visão de frente
o para mostrar órbitas
O para ocultar órbitas
r para ativar a rotação e translação
R para parar os movimentos*/

void Reshape(int w, int h){
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(lx,ly,lz,ux,uy,uz,fx,fy,fz);
}

void Draw_Orbit(void){
	glColor3f(255, 255, 255);
	
	glPushMatrix();
		glRotatef((GLfloat) 90, 1.0, 0.0, 0.0);
		glutWireTorus(0.002,0.30,100,100);		
	glPopMatrix();
	
	glPushMatrix();
		glRotatef((GLfloat) 90, 1.0, 0.0, 0.0);
		glutWireTorus(0.002,0.50,100,100);		
	glPopMatrix();
	
	glPushMatrix();
		glRotatef((GLfloat) 90, 1.0, 0.0, 0.0);
		glutWireTorus(0.002,0.70,100,100);		
	glPopMatrix();
	
	glPushMatrix();
		glRotatef((GLfloat) 90, 1.0, 0.0, 0.0);
		glutWireTorus(0.002,1,100,100);		
	glPopMatrix();
	
	glPushMatrix();
		glRotatef((GLfloat) 90, 1.0, 0.0, 0.0);
		glutWireTorus(0.002,1.40,100,100);		
	glPopMatrix();
	
	glPushMatrix();
		glRotatef((GLfloat) 90, 1.0, 0.0, 0.0);
		glutWireTorus(0.002,1.80,100,100);		
	glPopMatrix();
	
	glPushMatrix();
		glRotatef((GLfloat) 90, 1.0, 0.0, 0.0);
		glutWireTorus(0.002,2.20,100,100);		
	glPopMatrix();
	
	glPushMatrix();
		glRotatef((GLfloat) 90, 1.0, 0.0, 0.0);
		glutWireTorus(0.002,2.60,100,100);		
	glPopMatrix();
}

void Draw_Planets(void){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glEnable( GL_DEPTH_TEST );
	
	if(orbit == 1){
		Draw_Orbit();
	}
	
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
		if(rotation == 1){
			glRotatef(RSun, 0, 1, 0);
		}
		glutWireSphere(0.25, 10, 10);
	glPopMatrix();
	
	glColor3f(0.84, 0.84, 0.84);
	glPushMatrix();
		if(rotation == 1){
			glRotatef(RMercury, 0, 1, 0);
		}
		glTranslatef(0.3, 0, 0);
		glutWireSphere(0.03, 10, 10);
	glPopMatrix();

	glColor3f(0.88, 0.68, 0.50);
	glPushMatrix();
		if(rotation == 1){
			glRotatef(RVenus, 0, 1, 0);
		}
		glTranslatef(0.5, 0, 0);
		glutWireSphere(0.06, 10, 10);
	glPopMatrix();

	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
		if(rotation == 1){
			glRotatef(REarth, 0, 1, 0);
		}
		glTranslatef(0.7, 0, 0);
		glutWireSphere(0.07, 10, 10);
	glPopMatrix();

	glColor3f(0.50, 0.35, 0.2);
	glPushMatrix();
		if(rotation == 1){
			glRotatef(RMars, 0, 1, 0);
		}
		glTranslatef(1.0, 0, 0);
		glutWireSphere(0.04, 10, 10);
	glPopMatrix();
	
	glColor3f(0.60, 0.80, 0.91);
	glPushMatrix();
		if(rotation == 1){
			glRotatef(RJupiter, 0, 1, 0);
		}
		glTranslatef(1.4, 0, 0);
		glutWireSphere(0.18, 10, 10);
	glPopMatrix();

	glColor3f(1, 0.60, 0);
	glPushMatrix();
		if(rotation == 1){
			glRotatef(RSaturn, 0, 1, 0);
		}
		glTranslatef(1.8, 0, 0);
		glutWireSphere(0.13, 10, 10);
        glRotated(90, 1.0, 0.0, 0.0);
		glutWireTorus(0.03, 0.2, 10, 10);
	glPopMatrix();

	glColor3f(0.70, 1, 1);
	glPushMatrix();
		if(rotation == 1){
			glRotatef(RUranus, 0, 1, 0);
		}
		glTranslatef(2.2, 0, 0);
		glutWireSphere(0.11, 10, 10);
	glPopMatrix();

	glColor3f(0.3, 0.15, 0.50);
	glPushMatrix();
		if(rotation == 1){
			glRotatef(RNeptune, 0, 1, 0);
		}
		glTranslatef(2.6, 0, 0);
		glutWireSphere(0.09, 10, 10);
	glPopMatrix();
	
	glutSwapBuffers();
}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("SOLAR SYSTEM - PARTE 01");
	glutKeyboardFunc(_movimentacoesTeclado);
	glutDisplayFunc(Draw_Planets);
	glutReshapeFunc(Reshape);
	glutIdleFunc(idle);
	glutMainLoop();
	
	return 0;
}

void idle(void)
{
	Draw_Planets();
	
	RSun += 1; 
	RMercury += 1;
	RVenus += 0.33; 
	REarth += 1.6; 
	RMars += 1.8;
	RJupiter += 2.7;
	RSaturn += 2.8;
	RUranus += 2.15;
	RNeptune += 2.35;
}

void _movimentacoesTeclado(unsigned char key,int x, int y){
	switch(key){
		case 'c':
			lx = 0; ly = 5; lz = 0.002; ux = 0;	uy = 0;	uz = 0;	fx = 0;	fy = 1;	fz = 0;
			Reshape(600,600);
			glutPostRedisplay();
			break;
		case 'C':
			lx = 0;	ly = 5; lz = 0.002;	ux = 0;	uy = 0;	uz = 0;	fx = 0;	fy = 1;	fz = 0;
			Reshape(600,600);
			glutPostRedisplay();
			break;
		case 'f':
			lx = 0; ly = 0; lz = 5; ux = 0; uy = 0; uz = 0; fx = 0; fy = 1; fz = 0;
			Reshape(600,600);
			glutPostRedisplay();
			break;
		case 'F':
			lx = 0; ly = 0; lz = 5; ux = 0; uy = 0; uz = 0; fx = 0; fy = 1; fz = 0;
			Reshape(600,600);
			glutPostRedisplay();
			break;
		case 'l':
			lx = 0; ly = 0; lz = 5; ux = 0; uy = 0; uz = 0; fx = 5; fy = 0; fz = 0;
			Reshape(600,600);
			glutPostRedisplay();
			break;
		case 'L':
			lx = 0; ly = 0; lz = 5; ux = 0; uy = 0; uz = 0; fx = 5; fy = 0; fz = 0;
			Reshape(600,600);
			glutPostRedisplay();
			break;
		case 'o':
			orbit = 1;
			glutPostRedisplay();
		break;
		case 'O':
			orbit = 0;
			glutPostRedisplay();
		break;
		case 'r':
			rotation = 1;
			glutPostRedisplay();
		break;
		case 'R':
			rotation = 0;
			glutPostRedisplay();
		break;
	}
}
