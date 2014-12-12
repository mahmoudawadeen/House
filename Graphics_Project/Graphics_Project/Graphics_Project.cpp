// Graphics_Project.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"

#include "glew.h"

#include "GLAUX.H"

#include "glut.h"

#include<math.h>

#include "MModel_3DS.h"

#pragma comment (lib, "kernel32.lib") //Manually add this library	
#pragma comment (lib, "user32.lib") //Manually add this library
#pragma comment (lib, "gdi32.lib") //Manually add this library
#pragma comment (lib, "advapi32.lib") //Manually add this library
#pragma comment(lib, "glew32.lib")

#pragma comment(lib, "GLAUX.lib")

MModel_3DS tree;
MModel_3DS house;
MModel_3DS grass;
MModel_3DS sofa;
MModel_3DS billiard;
MModel_3DS car;
MModel_3DS desk;
MModel_3DS cone;
MModel_3DS tv;
MModel_3DS bed;
MModel_3DS bird2;
MModel_3DS bird;
MModel_3DS tvtable;
MModel_3DS piano;
MModel_3DS cone2;
MModel_3DS clock;
MModel_3DS wheel;
MModel_3DS bench;
MModel_3DS ball;
MModel_3DS trash;

double birdXTranslate = 0;
double birdRotate = 90;
boolean rightBird = true;
double bird2XTranslate = -2;
double bird2Rotate = 90;
boolean rightBird2 = true;

class Position{

public:

float x, y, z;

};

float

angle = 0.0f;

Position cameraLocation;
double viewAngle=0;

Position lineOfSight;
void ChangeLightColor( float red, float green, float blue)
{
GLfloat mat_diffuse[] = {red, green, blue, 1.0f};
glLightfv(GL_LIGHT0,GL_DIFFUSE, mat_diffuse);
}

void mydisplay(void)

{

glMatrixMode(GL_MODELVIEW);

glLoadIdentity();

gluLookAt(cameraLocation.x, cameraLocation.y+viewAngle, cameraLocation.z,

cameraLocation.x + lineOfSight.x, cameraLocation.y + lineOfSight.y, cameraLocation.z + lineOfSight.z,

0.0, 1.0, 0.0);

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


///trees///
glEnable(GL_LIGHTING);
tree.pos.x = -10;
tree.pos.z = 28;
/*tree.scale = 0.02;*/ 
tree.pos.y=1;
tree.Draw();

tree.pos.x = 25;
tree.pos.z = 28;
tree.scale = 0.02;
tree.pos.y=1;
tree.Draw();

//bench
glEnable(GL_LIGHTING);
ChangeLightColor(1.0f,1.0f,1.0f);
bench.pos.x = -9;
bench.pos.z = 20;
bench.scale = 0.01;
bench.rot.y = 90;
bench.pos.y=1;
bench.Draw();

glEnable(GL_LIGHTING);
ChangeLightColor(1.0f,1.0f,1.0f);
bench.pos.x = -6;
bench.pos.z = 20;
bench.scale = 0.01;
bench.rot.y = 270;
bench.pos.y=1;
bench.Draw();

glEnable(GL_LIGHTING);
ChangeLightColor(1.0f,0.0f,0.0f);
ball.pos.x = 7;
ball.pos.z = 23;
ball.scale = 0.008;
ball.pos.y=1.5;
ball.Draw();

glEnable(GL_LIGHTING);
ChangeLightColor(1.0f,1.0f,1.0f);
trash.pos.x = -8;
trash.pos.z = 28;
trash.scale = 0.003;
trash.pos.y=1;
trash.Draw();

glEnable(GL_LIGHTING);
ChangeLightColor(1.0f,0.35f,0.0f);
cone.pos.x = 15;
cone.pos.z = 28;
cone.scale = 0.05;
cone.pos.y=1;
cone.Draw();

glEnable(GL_LIGHTING);
ChangeLightColor(1.0f,0.35f,0.0f);
cone2.pos.x = 16;
cone2.pos.z = 28;
cone2.scale = 0.05;
cone2.rot.x = 90;
cone2.pos.y=1;
cone2.Draw();

glEnable(GL_LIGHTING);
ChangeLightColor(1.0f,0.35f,0.0f);
bird.rot.y = birdRotate;
if(rightBird){
	birdXTranslate+=0.3;
	bird.pos.x = birdXTranslate;
	if(bird.pos.x >= 15){
		bird.rot.y = -bird.rot.y;
		rightBird = false;
	}
}
if(!rightBird){
	birdXTranslate-=0.3;
	bird.pos.x = birdXTranslate;
	if(bird.pos.x <= -15){
		bird.rot.y = -bird.rot.y;
		rightBird = true;
	}
}
bird.pos.y = 13;
bird.pos.z = 28;
bird.scale = 0.03;
bird.Draw();
//////////bird2
glEnable(GL_LIGHTING);
ChangeLightColor(0.0f,0.0f,0.8f);
bird2.rot.y = bird2Rotate;
if(rightBird2){
	bird2XTranslate+=0.15;
	bird2.pos.x = bird2XTranslate;
	if(bird2.pos.x >= 15){
		bird2.rot.y = -bird2.rot.y;
		rightBird2 = false;
	}
}
if(!rightBird2){
	bird2XTranslate-=0.15;
	bird2.pos.x = bird2XTranslate;
	if(bird2.pos.x <= -15){
		bird2.rot.y = -bird2.rot.y;
		rightBird2 = true;
	}
}
bird2.pos.y = 15;
bird2.pos.z = 22;
bird2.scale = 0.03;
bird2.Draw();




////sofas el gamb el lamp///
glEnable(GL_LIGHTING);
ChangeLightColor(0.0f,0.0f,1.0f);
sofa.pos.x = -1.65;
sofa.pos.z = 2;
sofa.pos.y=1;
sofa.rot.y = 30.0f;
sofa.scale = 0.002;
sofa.Draw();

/// window sofa///
sofa.pos.x = 0.65;
sofa.pos.z = 4;
sofa.pos.y=1;
sofa.rot.y = 120.0f;
sofa.scale = 0.002;
sofa.Draw();


////lamp next to the sofa
//ChangeLightColor(0.0f,0.0f,0.0f);
//lamp.pos.x = -1.65;
//lamp.pos.z = 4;
//lamp.pos.y=1;
//lamp.scale = 0.001;
//lamp.Draw();

ChangeLightColor(0.0f,0.0f,0.0f);
tv.rot.y = -90;
tv.scale = 0.04;
tv.pos.y = 2;
tv.pos.x = -2.5;
tv.pos.z = -5.75;
tv.Draw();

////////////CLOCK////////////
clock.scale = 0.005;
clock.pos.y = 2.5;
clock.pos.x = 2.5;
clock.pos.z = -5.75;
clock.Draw();


tvtable.scale = 0.005;
tvtable.pos.y = 1;
tvtable.pos.x = -2.5;
tvtable.pos.z = -5.75;
tvtable.Draw();


//////////////BED///////
glDisable(GL_LIGHTING);
bed.scale =0.02;
bed.pos.y = 1;
bed.pos.x = 3.45;
bed.pos.z = 4;
bed.Draw();

//CANDLE NEXT TO THE TV////////
//candle.scale = 0.01;
//candle.pos.y = 1;
//candle.pos.x = -3.5;
//candle.pos.z = -4.75;
//candle.Draw();

////////VASE NEXT TO THE BED ///////////
//vase.scale = 0.03;
//vase.pos.y=1;
//vase.pos.x = 4.75;
//vase.pos.z = 4;
//vase.Draw();

/*diningtable.pos.y = 1;
diningtable.pos.x= -6.5;
diningtable.pos.z=-5;
diningtable.Draw();*/


glEnable(GL_LIGHTING);
ChangeLightColor(0.0f,1.0f,1.0f);
desk.pos.x = 0.65;
desk.pos.z = 2;
desk.pos.y=2;
desk.rot.y=90.0f;
desk.scale=0.02;
desk.Draw();

ChangeLightColor(1.0f,1,0);
car.pos.x= 18;
car.pos.z=10;
car.pos.y=2;
car.scale=0.1;
car.rot.y=90;
car.Draw();

//GLfloat shininess [] = {50};
//glMaterialfv(GL_FRONT,GL_SHININESS,shininess);
ChangeLightColor(0.5f,0.3f,0.3f);
piano.pos.x= -8;
piano.pos.z=-1;
piano.pos.y = 1;
piano.scale=0.003;
piano.Draw();

//ChangeLightColor(0.0f,0.0f,0.0f);
//guitar.pos.x= -8;
//guitar.pos.z=0;
//guitar.pos.y = 1;
//guitar.rot.x =-90 ;
//guitar.scale=0.003;
//guitar.Draw();

ChangeLightColor(0.0f,1.0f,0.0f);
glEnable(GL_LIGHTING);
billiard.pos.y = 1;
billiard.pos.x= -6.5;
billiard.pos.z=-5;
billiard.rot.y = 45;
billiard.scale=0.0009;
billiard.Draw();


glEnable(GL_LIGHTING);
ChangeLightColor(0.0f,0.0f,0.5f);
house.pos.y=1;
house.pos.x=8;
//house.rot.y = 450; 
house.scale=0.05;
house.Draw();



///////GRASS

for(int x = -10;x<27;x+=4){
for(int i = 0; i<19; i++)
{	
ChangeLightColor(0.0f,1.0f,0.0f);
grass.pos.x=x;
//if(x<15 || (x<19 && x>15 && i>1) || (x>19 && x<21 && i>2)|| (x>21 && x<23 && i>2) ||(x>23 && x<25 && i>3)||(x>25 && x<27 && i>4))
	grass.pos.z=28+(-2*i);
grass.scale = 0.003;
grass.Draw();
}
}

//if(cameraLocation.y >=3.5)
//{
//	cameraLocation.y = 3.5;
//}

if(cameraLocation.y<1.5)
{
	cameraLocation.y = 1.5;
}

glutSwapBuffers();

glutPostRedisplay();

}

void processSpecialKeys(int key, int xx, int yy) {

float fraction = 0.9f;

switch (key) {

case GLUT_KEY_LEFT:

angle -= 0.02f;

lineOfSight.x = sin(angle);

lineOfSight.z = -cos(angle);

break;

case GLUT_KEY_RIGHT:

angle += 0.02f;

lineOfSight.x = sin(angle);

lineOfSight.z = -cos(angle);

break;

case GLUT_KEY_UP:

cameraLocation.x += lineOfSight.x * fraction;

cameraLocation.z += lineOfSight.z * fraction;

break;

case GLUT_KEY_DOWN:

cameraLocation.x -= lineOfSight.x * fraction;

cameraLocation.z -= lineOfSight.z * fraction;

break;

default:
break;

}

}
void UseSurfaceMaterials()
{
	// Enable Material Tracking
	glEnable(GL_COLOR_MATERIAL);
	// Set Material Properties which will be assigned by glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	// Set Material's Specular Color
	// Will be applied to all objects
	GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	// Set Material's Shine value (0->128)
	GLfloat shininess[] = {96.0f};
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}

void CreateLightSource()
{
	// Enable Lighting for this OpenGL Program
	glEnable(GL_LIGHTING);
	// Enable Light Source number 0
	// OpengL has 8 light sources
	glEnable(GL_LIGHT0);
	// Define Light source 0 ambient light
	GLfloat ambient[]={0.1f, 0.1f, 0.1, 1.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	// Define Light source 0 diffuse light
	GLfloat diffuse[]={0.4f, 0.4f, 0.4f, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	// Define Light source 0 Specular light
	GLfloat specular[]={1.0f, 1.0f, 1.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	// Finally, define light source 0 position in World Space
	//GLfloat light_position[] = {2.0f, 2.0f, 2.0f, 1.0f};
	GLfloat light_position[] = {cameraLocation.x, cameraLocation.y, cameraLocation.z, 1.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void MyKeyboard(unsigned char thekey,int mouseX,int mouseY)
{
	glClear(GL_COLOR_BUFFER_BIT);
    
    switch (thekey) {
        case 'q':
			cameraLocation.y += 0.5;
            break;

		case 'a':
			cameraLocation.y -= 0.5;
            break;

        case 'w':
			viewAngle -= 0.05;
            break;

		case 's':
			viewAngle += 0.05;
            break;           
        default:
            break;
    }
    
    
    
}

void main(int argc, char **argv)

{

glutInit(&argc, argv);

glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

//CreateLightSource();

glutInitWindowPosition(100, 100);

glutInitWindowSize(1280, 720);

glutCreateWindow("Virtual Tour Around a House");

glutDisplayFunc(mydisplay);

glutSpecialFunc(processSpecialKeys);

glEnable(GL_LIGHTING);

glEnable(GL_LIGHT0);

glEnable(GL_DEPTH_TEST);

glEnable(GL_NORMALIZE);

 UseSurfaceMaterials();
//set the light source properties


GLfloat lightIntensity[] = { 1.0f, 1.0f, 1.0f, 1.0f };

GLfloat light_position[] = { 1.0f, 6.0f, 3.0f, 0.0f };
GLfloat shininess [] = {50};

glLightfv(GL_LIGHT0, GL_POSITION, light_position);

glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

glLightfv(GL_LIGHT0, GL_SPECULAR, lightIntensity);

glLightfv(GL_LIGHT0, GL_SHININESS, shininess);
ChangeLightColor(1.0f,0.0f,0.0f);

glClearColor(0.1, 0.1, 0.1, 0.0);

cameraLocation.x = 0.0;

cameraLocation.y =5.0;

cameraLocation.z = 75.0;

lineOfSight.x = 0.0f;

lineOfSight.y = 0.0f;

lineOfSight.z = 0.0f;

glMatrixMode(GL_PROJECTION);

glLoadIdentity();

gluPerspective(45.0f, 1280/720, 0.1f, 100.0f);

glEnable(GL_DEPTH_TEST);
CreateLightSource();
glClearColor(0.9,0.9,0.9,0.0);

glutKeyboardFunc(MyKeyboard);

house.Load("House3.3DS");
tree.Load("elm.3ds");
//sofa.Load("Car Lamborghini gallardo 2005 N240211.3DS");
//billiard.Load("billiard.3ds");
car.Load("Car Lamborghini gallardo 2005 N240211.3DS");
//lamp.Load("lamp2.3DS");
//desk.Load("desk.3ds");
//candle.Load("candlestick.3DS");
//tv.Load("tv.3DS");
//bed.Load("bed.3DS");
//clock.Load("clock.3ds");
//guitar.Load("guitar.3ds");
//piano.Load("piano1.3DS");
grass.Load("Grass06.3DS");
//tvtable.Load("reciever.3DS");
//vase.Load("vase.3DS");
bench.Load("bench.3ds");
ball.Load("soccer_ball.3ds");
trash.Load("garbagecan.3ds");
cone.Load("TrafficCone.3DS");
cone2.Load("TrafficCone.3DS");
bird.Load("bird.3ds");
bird2.Load("bird.3ds");

glMatrixMode(GL_MODELVIEW);
glutMainLoop();

}

