//Primastuti(Ayi), Kyungsung University, Busan, South Korea
//3th year
//nov 2008
//program showing 5 different fractal tree, click right mouse to select the tree :)
//the parameter x, y, z in every function actually has no function,,
//you can delete it if you want,,
//i just let them there in case i need them when want to edit the code ,, :)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gl/glut.h>       // gltools library

typedef float M3DVector3f[3];
// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

// Which Drawing Method
#define DRAW_FIRST    0
#define DRAW_SECOND   1
#define DRAW_THIRD    2
#define DRAW_FOURTH   3
#define DRAW_FIFTH    4
int iMethod = DRAW_FIRST;   // Default, draw first tree
int i=0, moving[5] = { 3, 0, 2, 1, 0};

void m3dCrossProduct(M3DVector3f result, const M3DVector3f u, const M3DVector3f v)
{
 result[0] = u[1]*v[2] - v[1]*u[2];
 result[1] = -u[0]*v[2] + v[0]*u[2];
 result[2] = u[0]*v[1] - v[0]*u[1];
}

void m3dFindNormal(M3DVector3f result, const M3DVector3f point1, const M3DVector3f point2,
       const M3DVector3f point3)
{
 M3DVector3f v1,v2;  // Temporary vectors

 // Calculate two vectors from the three points. Assumes counter clockwise
 // winding!
 v1[0] = point1[0] - point2[0];
 v1[1] = point1[1] - point2[1];
 v1[2] = point1[2] - point2[2];

 v2[0] = point2[0] - point3[0];
 v2[1] = point2[1] - point3[1];
 v2[2] = point2[2] - point3[2];

 // Take the cross product of the two vectors to get
 // the normal vector.
 m3dCrossProduct(result, v1, v2);
}

void ProcessMenu(int value)
{
    iMethod = value; // Save menu identifier as method flag
    glutPostRedisplay(); // Trigger a redraw
}

/***************************first tree function*********************************/
void draw_branch(GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{
 GLUquadricObj *pObj; // Quadric object
 pObj =gluNewQuadric();
 gluQuadricNormals(pObj, GLU_SMOOTH);

 glPushMatrix();
 gluSphere(pObj, size, 26, 13);
 gluCylinder(pObj, size, size, length, 26, 13);
 glTranslatef(0.0f, 0.0f, length);
 gluSphere(pObj, size, 26, 13);
 glPopMatrix();
}

void divide_branch(int n, GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{
 if(n){
  if(n<4)
  glColor3ub(0, 255, 0); //green (leaf)
  else glColor3ub(92, 51, 23); //sweet brown (branch)
  glPushMatrix();
  draw_branch(size, length, x, y, z); //main branch
  glTranslatef(0.0, 0.0, length);
  glRotatef(45, 0.0, 1.0, 0.0);
  divide_branch(n-1, size*0.7, length*0.7, x, y, z); //right branch
  glRotatef(-90, 0.0, 1.0, 0.0);
  divide_branch(n-1, size*0.7, length*0.7, x, y, z ); //left branch
  glPopMatrix();
 }
 else
  draw_branch(size, length, x, y, z);
}
/******************************end of first tree function**********************************/

/***************************second tree function*********************************/
//use draw_brach from first tree function ;D

void divide_branch_second(int n, GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{
 if(n){
  if(n<2)
  glColor3ub(0, 100, 0); //brigth dark green (leaf)
  else glColor3ub(92, 64, 51); //dark brown (branch)

  glPushMatrix();
  draw_branch(size, length, x, y, z); //main branch
  glTranslatef(0.0, 0.0, length);
  glRotatef(45, 0.0, 1.0, 0.0);
  divide_branch_second(n-1, size*0.7, length*0.7, x, y, z); //right branch
  glRotatef(-90, 0.0, 1.0, 0.0);
  divide_branch_second(n-1, size*0.7, length*0.7, x, y, z ); //left branch
  glRotatef(-90, 1.0, 0.0, 1.0);
  divide_branch_second(n-1, size*0.7, length*0.7, x, y, z ); //upper branch
  glRotatef(90, 0.0, 01.0, 0.0);
  divide_branch_second(n-1, size*0.7, length*0.7, x, y, z ); //lower branch
  glPopMatrix();
 }
 else{
  glPushMatrix();
  glScalef(2.0, 0.5, 1.0);
  draw_branch(size, length, x, y, z);
  glPopMatrix();
 }
}
/******************************end of second tree function**********************************/
/***************************third tree function*********************************/
//use draw_brach from first tree function ;D

void divide_branch_third(int n, GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{
 if(n){
  if(n<4)
  glColor3ub(107, 79, 65); //brigth dark brown (young branch)
  else glColor3ub(92, 64, 51); //dark brown (branch)

  glPushMatrix();
  draw_branch(size, length, x, y, z); //main branch
  glTranslatef(0.0, 0.0, length);
  glRotatef(45, 0.0, 1.0, 0.0);
  divide_branch_third(n-1, size*0.7, length*0.7, x, y, z); //right branch
  if(n>3){
  glRotatef(-90, 0.0, 1.0, 0.0);
  divide_branch_third(n-1, size*0.5, length*0.5, x, y, z ); //left branch
  if(n>2){
  glRotatef(-90, 1.0, 0.0, 1.0);
  divide_branch_third(n-1, size*0.7, length*0.3, x, y, z ); //upper branch
  if(n>1){
  glRotatef(90, 0.0, 01.0, 0.0);
  divide_branch_third(n-1, size*0.6, length*0.7, x, y, z ); //lower branch
  }}}
  glPopMatrix();
 }
 else{
  glPushMatrix();
  glColor3ub(0, 100, 0); //brigth dark green (leaf)
  glScalef(2.0, 0.5, 1.0);
  draw_branch(0.5, 0.3, x, y, z);
  glPopMatrix();
 }
}
/******************************end of third tree function**********************************/
/******************************fourth tree function************************************/

void divide_branch_fourth(int n, GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{
 if(n){
  if(n<2)
  glColor3ub(47, 79, 47); //pine green (leaf)
  else glColor3ub(109, 91, 64); //bright black brown (branch)
  glPushMatrix(); //first
  draw_branch(size, length, x, y, z); //main branch
  glTranslatef(0.0, 0.0, length*0.4);
  glPushMatrix(); //second
  glRotatef(100, 0.0, 1.0, 0.0);
  divide_branch_fourth(n-1, size*0.9, length*0.5, x, y, z); //right branch
  glRotatef(-200, 0.0, 1.0, 0.0);
  divide_branch_fourth(n-1, size*0.9, length*0.5, x, y, z ); //left branch
  glPopMatrix(); //second
  glTranslatef(0.0, 0.0, length*0.2);
  glPushMatrix(); //third
  glRotatef(100, 0.0, 1.0, 0.0);
  divide_branch_fourth(n-1, size*0.9, length*0.3, x, y, z); //right branch
  glRotatef(-200, 0.0, 1.0, 0.0);
  divide_branch_fourth(n-1, size*0.9, length*0.3, x, y, z ); //left branch
  glPopMatrix(); //third
  glTranslatef(0.0, 0.0, length*0.2);
  glPushMatrix(); //fourth
  glRotatef(100, 0.0, 1.0, 0.0);
  divide_branch_fourth(n-1, size*0.9, length*0.15, x, y, z); //right branch
  glRotatef(-200, 0.0, 1.0, 0.0);
  divide_branch_fourth(n-1, size*0.9, length*0.15, x, y, z ); //left branch
  glPopMatrix(); //fourth
  glTranslatef(0.0, 0.0, length*0.1);
  glPushMatrix(); //fifth
  divide_branch_fourth(n-1, size*0.9, length*0.1, x, y, z); //right branch
  glPopMatrix(); //fifth
  glPopMatrix(); //first
 }
 else{
  draw_branch(size, length, x, y, z);
 }
}
/******************************end of fourth tree function**********************************/
/******************************fifth tree function************************************/
void draw_branch_fifth(GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{
 glPushMatrix();
 glScalef(0.50f, 3.0f, 1.0f);
 draw_branch(size, length, 0.0, 0.0, 0.0);
 glTranslatef(0.0, 0.0, length);
 glRotatef(50, 0.0, 1.0, 0.0);
 draw_branch(size, length*0.7, 0.0, 0.0, 0.0);
 glTranslatef(0.0, 0.0, length*0.7);
 glRotatef(50, 0.0, 1.0, 0.0);
 draw_branch(size*0.5, length*0.5, 0.0, 0.0, 0.0);
 glTranslatef(0.0, 0.0, length*0.5);
 glRotatef(50, 0.0, 1.0, 0.0);
 draw_branch(size*0.3, length*0.3, 0.0, 0.0, 0.0);
 glTranslatef(0.0, 0.0, length*0.3);
 glRotatef(50, 0.0, 1.0, 0.0);
 draw_branch(size*0.3, length*0.1, 0.0, 0.0, 0.0);


 glPopMatrix();
}

void divide_branch_fifth(int n, GLfloat size, GLfloat length, GLfloat x, GLfloat y, GLfloat z)
{

 if(n){
  if(n<2)
  glColor3ub(0, 100, 0); //brigth dark green (leaf)
  else glColor3ub(92, 64, 51); //dark brown (branch)

  glPushMatrix();
  draw_branch_fifth(size, length, x, y, z); //main branch
  glTranslatef(0.0, 0.0, length);
  glRotatef(30, 0.0, 1.0, 0.0);
  divide_branch_fifth(n-1, size*0.7, length*1.5, x, y, z); //right branch
  glRotatef(-60, 0.0, 1.0, 0.0);
  divide_branch_fifth(n-1, size*0.7, length*1.5, x, y, z ); //left branch
  glRotatef(-60, 1.0, 0.0, 1.0);
  divide_branch_fifth(n-1, size*0.7, length*1.5, x, y, z ); //upper branch
  glRotatef(60, 0.0, 01.0, 0.0);
  divide_branch_fifth(n-1, size*0.7, length*1.5, x, y, z ); //lower branch
  glPopMatrix();
 }
 else{
  glColor3ub(0, 100, 0); //brigth dark green (leaf)
  draw_branch_fifth(size, length, x, y, z);
 }
}
/******************************end of fifth tree function**********************************/

// Called to draw scene
void RenderScene(void)
{
 M3DVector3f vNormal; // Storeage for calculated surface normal

 // Clear the window with current clearing color
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 switch(iMethod){ //start switch

 /*******************************first tree*********************************/
 case DRAW_FIRST:
 {
 // Save the matrix state and do the rotations
 glPushMatrix();
 //glTranslatef(-10.0f, 10.0f, 0.0f);
 glRotatef(xRot, 1.0f, 0.0f, 0.0f);
 glRotatef(yRot, 0.0f, 1.0f, 0.0f);
 //glScalef(0.5, 0.5, 0.5);
 divide_branch(9, 1, 5, 0.0, 0.0, 0.0);
 glPopMatrix();
 glutSwapBuffers();// Display the results
 }
 break;
 /***************************end of first tree********************************/

 /*******************************second tree*********************************/
 case DRAW_SECOND:
 {
 // Save the matrix state and do the rotations
 glPushMatrix();
 //glTranslatef(10.0f, 0.0f, 0.0f);
 glRotatef(xRot, 1.0f, 0.0f, 0.0f);
 glRotatef(yRot, 0.0f, 1.0f, 0.0f);
 //glScalef(0.5, 0.5, 0.5);
 divide_branch_second(5, 1, 5, 0.0, 0.0, 0.0);
 glPopMatrix();
 glutSwapBuffers();// Display the results
 }
 break;
 /***********************end of second tree****************************/
 /*******************************third tree*********************************/
 case DRAW_THIRD:
 {
 // Save the matrix state and do the rotations
 glPushMatrix();
 //glTranslatef(10.0f, 0.0f, 0.0f);
 glRotatef(xRot, 1.0f, 0.0f, 0.0f);
 glRotatef(yRot, 0.0f, 1.0f, 0.0f);
 //glScalef(0.5, 0.5, 0.5);
 divide_branch_third(6, 0.5, 7, 0.0, 0.0, 0.0);
 glPopMatrix();
 glutSwapBuffers();// Display the results
 }
 break;
 /***********************end of third tree****************************/
 /*******************************fourth tree*********************************/
 case DRAW_FOURTH:
 {
 // Save the matrix state and do the rotations
 glPushMatrix();
 //glTranslatef(10.0f, 0.0f, 0.0f);
 glRotatef(xRot, 1.0f, 0.0f, 0.0f);
 glRotatef(yRot, 0.0f, 1.0f, 0.0f);
 //glScalef(0.5, 0.5, 0.5);
 divide_branch_fourth(3, 0.3, 13, 0.0, 0.0, 0.0);
 glPopMatrix();
 glutSwapBuffers();// Display the results
 }
 break;
 /***********************end of fourth tree****************************/
 /*******************************fifth tree*********************************/
 case DRAW_FIFTH:
 {
 // Save the matrix state and do the rotations
 glPushMatrix();
 //glTranslatef(10.0f, 0.0f, 0.0f);
 glRotatef(xRot, 1.0f, 0.0f, 0.0f);
 glRotatef(yRot, 0.0f, 1.0f, 0.0f);
 //glScalef(0.5, 0.5, 0.5);
 divide_branch_fifth(3, 0.3, 1, 0.0, 0.0, 0.0);
 glPopMatrix();
 glutSwapBuffers();// Display the results
 }
 break;
 /***********************end of fifth tree****************************/
 }//end of switch
}

// This function does any needed initialization on the rendering
// context.
void SetupRC()
{
    // Light values and coordinates
    GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat  specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glEnable(GL_DEPTH_TEST); // Hidden surface removal
    glFrontFace(GL_CCW);  // Counter clock-wise polygons face out
    glEnable(GL_CULL_FACE);  // Do not calculate inside of jet

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR, specular);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);

    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // All materials hereafter have full specular reflectivity
    // with a high shine
    glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
    glMateriali(GL_FRONT, GL_SHININESS, 128);

    // white background
    //glClearColor(1.0f, 1.0f, 1.0f, 1.0f ); //white
 //  219;219;112 yellow
 glClearColor(0.85f, 0.85f, 0.430f, 1.0f);

    glEnable(GL_NORMALIZE);
}

/////////////////////////////////////////////////////
// Handle arrow keys
void SpecialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)
        xRot-= 5.0f;

    if(key == GLUT_KEY_DOWN)
        xRot += 5.0f;

    if(key == GLUT_KEY_LEFT)
        yRot -= 5.0f;

    if(key == GLUT_KEY_RIGHT)
        yRot += 5.0f;

    if(key > 356.0f)
        xRot = 0.0f;

    if(key < -1.0f)
        xRot = 355.0f;

    if(key > 356.0f)
        yRot = 0.0f;

    if(key < -1.0f)
        yRot = 355.0f;

    // Refresh the Window
    glutPostRedisplay();
}


//////////////////////////////////////////////////////////
// Reset projection and light position
void ChangeSize(int w, int h)
{
    GLfloat fAspect;
    GLfloat lightPos[] = { -50.f, 50.0f, 100.0f, 1.0f };

    // Prevent a divide by zero
    if(h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    fAspect = (GLfloat) w / (GLfloat) h;
    gluPerspective(45.0f, fAspect, 1.0f, 225.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glTranslatef(0.0f, 0.0f, -50.0f);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400,400);
 glutInitWindowPosition(100, 100);
 glutCreateWindow(".:OpenGL - 5 Fractal Tree:.        (right click the mouse)");

 // Create the Menu
 glutCreateMenu(ProcessMenu);
 glutAddMenuEntry("simple fractal tree",DRAW_FIRST);
 glutAddMenuEntry("rain forest tree",DRAW_SECOND);
    glutAddMenuEntry("auntumn tree",DRAW_THIRD);
 glutAddMenuEntry("poor pine tree",DRAW_FOURTH);
 glutAddMenuEntry("pandanus tree",DRAW_FIFTH);
 glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    SetupRC();
    glutMainLoop();

    return 0;
}

