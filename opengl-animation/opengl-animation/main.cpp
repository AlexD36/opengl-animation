#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416

float _moveA = 0.0f;
float _moveB = 0.0f;
float _moveC = 0.0f;
float _angle1 = 0.0f;
float speed = 0.02f;

void triangle(float a, float b, float c, float d, float e, float f) {
    glBegin(GL_TRIANGLES);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);
    glEnd();
}

void drawScene() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    glLoadIdentity(); //Reset the drawing perspective
    gluOrtho2D(-12, 38, -19, 14);//range
    glMatrixMode(GL_MODELVIEW);


    ///sky///
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(135, 206, 250);
    glVertex2f(38.0f, 3.0f);
    glVertex2f(38.0f, 14.0f);
    glVertex2f(-12.0f, 14.0f);
    glVertex2f(-12.0f, 3.0f);

    glEnd();

    ///sun///
    glPushMatrix();
    glColor3d(255, 255, 0);
    glTranslatef(30.0, 7.0, 0);
    glutSolidSphere(1.0, 250, 250);
    glPopMatrix();

    ///cloud 1///
    glPushMatrix();

    glTranslatef(_moveC, 0.0f, 0.0f);
    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(1.0, 6.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(1.0, 7.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(2.0, 7.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(2.0, 6.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(0.0, 6.5, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(3.0, 6.5, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPopMatrix();




    ///cloud 2///


    glPushMatrix();

    glTranslatef(_moveC, 0.0f, 0.0f);
    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(15.0, 9.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(15.0, 8.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(16.0, 8.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(16.0, 9.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(14.0, 8.5, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(17.0, 8.5, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPopMatrix();

    ///cloud 3///

    glPushMatrix();

    glTranslatef(_moveC, 0.0f, 0.0f);

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(22.0, 8.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(22.0, 7.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(23.0, 8.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(23.0, 7.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(24.0, 7.5, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(21.0, 7.5, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPopMatrix();

    //mountain
    //right
    glColor3ub(61, 119, 135);
    triangle(11, 3, 22, 3, 16, 7.4);
    glColor3ub(29, 78, 92);
    triangle(11, 3, 13, 3, 16, 7.4);

    //main mountain
    glBegin(GL_QUADS);
    glColor3ub(75, 152, 173);
    glVertex2f(-7, 3);
    glVertex2f(15, 3);
    glVertex2f(5, 12);
    glVertex2f(3, 11.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(5, 12);
    glVertex2f(3, 12.6);
    glVertex2f(0, 9);
    glVertex2f(2.4, 9.5);
    glVertex2f(1.8, 8);
    glVertex2f(3.4, 9.65);
    glVertex2f(5, 7.1);
    glVertex2f(5, 8.4);
    glVertex2f(10, 7.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(61, 119, 135);
    //left 1
    glVertex2f(-22, 3);
    glVertex2f(-15, 3);
    glVertex2f(-18, 6.6);
    glColor3ub(29, 78, 92);
    glVertex2f(-22, 3);
    glVertex2f(-19.6, 3);
    glVertex2f(-18, 6.6);
    //left2
    glColor3ub(61, 119, 135);
    glVertex2f(-16, 3);
    glVertex2f(-5, 3);
    glVertex2f(-11, 7.5);
    glColor3ub(29, 78, 92);
    glVertex2f(-16, 3);
    glVertex2f(-13, 3);
    glVertex2f(-11, 7.5);
    //left big
    glColor3ub(61, 119, 135);
    glVertex2f(-9, 3);
    glVertex2f(3, 3);
    glVertex2f(-6, 9.9);
    glColor3ub(29, 78, 92);
    glVertex2f(-9, 3);
    glVertex2f(-7, 3);
    glVertex2f(-6, 9.9);
    ////mid
    glColor3ub(61, 119, 135);
    glVertex2f(-3, 3);
    glVertex2f(9, 3);
    glVertex2f(3, 6.6);
    glColor3ub(29, 78, 92);
    glVertex2f(-3, 3);
    glVertex2f(0, 3);
    glVertex2f(3, 6.6);
    glEnd();

    ///sea portion///
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(65, 105, 225);
    glVertex2f(38.0f, -19.0f);
    glVertex2f(38.0f, 3.0f);
    glVertex2f(-12.0f, 3.0f);
    glVertex2f(-12.0f, -19.0f);

    glEnd();

    ///left soil portion///
    //polygon 1
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 128, 0);
    glVertex2f(4.0f, 0.0f);
    glVertex2f(6.0f, 1.0f);
    glVertex2f(3.0f, 3.0f);
    glVertex2f(-12.0f, 3.0f);
    glVertex2f(-12.0f, 0.0f);

    glEnd();

    //polygon 2
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 128, 0);
    glVertex2f(5.0f, -3.0f);
    glVertex2f(7.0f, -1.5f);
    glVertex2f(4.0f, 0.0f);
    glVertex2f(-12.0f, 0.0f);
    glVertex2f(-12.0f, -3.0f);

    glEnd();

    //polygon 3
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 128, 0);
    glVertex2f(6.0f, -4.5f);
    glVertex2f(8.0f, -4.0f);
    glVertex2f(5.0f, -3.0f);
    glVertex2f(-12.0f, -3.0f);
    glVertex2f(-12.0f, -4.5f);

    glEnd();

    //polygon 4
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 128, 0);
    glVertex2f(2.0f, -9.0f);
    glVertex2f(9.5f, -7.0f);
    glVertex2f(6.0f, -4.5f);
    glVertex2f(-12.0f, -4.5f);
    glVertex2f(-12.0f, -9.5f);

    glEnd();

    //polygon 5
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 128, 0);
    glVertex2f(2.0f, -11.5f);
    glVertex2f(5.0f, -10.0f);
    glVertex2f(2.0f, -9.0f);
    glVertex2f(-12.0f, -9.0f);
    glVertex2f(-12.0f, -11.5f);

    glEnd();

    ///left sidewise border partition///
     //polygon 1
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(6.0f, 0.5f);
    glVertex2f(6.0f, 1.0f);
    glVertex2f(4.0f, 0.0f);
    glVertex2f(4.5f, -0.25f);

    glEnd();

    //polygon 2
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(7.0f, -2.0f);
    glVertex2f(7.0f, -1.5f);
    glVertex2f(5.0f, -3.0f);
    glVertex2f(5.5f, -3.15f);

    glEnd();

    //polygon 3
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(8.0f, -4.4f);
    glVertex2f(8.0f, -4.0f);
    glVertex2f(6.0f, -4.5f);
    glVertex2f(6.3f, -4.8f);

    glEnd();

    //polygon 4
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(9.5f, -7.5f);
    glVertex2f(9.5f, -7.0f);
    glVertex2f(2.0f, -9.0f);
    glVertex2f(3.0f, -9.3f);

    glEnd();

    //polygon 5
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(5.0f, -10.5f);
    glVertex2f(5.0f, -10.0f);
    glVertex2f(2.0f, -11.5f);
    glVertex2f(2.0f, -12.0f);

    glEnd();

    //polygon 6
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(2.0f, -12.0f);
    glVertex2f(2.0f, -11.5f);
    glVertex2f(-12.0f, -11.5f);
    glVertex2f(-12.0f, -12.0f);

    glEnd();





    ///straw///
    //polygon 1
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(189, 183, 107);
    glVertex2f(2.5f, -3.0f);
    glVertex2f(2.0f, -1.0f);
    glVertex2f(-3.0f, -1.0f);
    glVertex2f(-3.5f, -3.0f);

    glEnd();

    //polygon 2
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(189, 183, 107);
    glVertex2f(2.0f, -1.0f);
    glVertex2f(1.0f, 0.5f);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(-3.0f, -1.0f);

    glEnd();
    //polygon 3
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(189, 183, 107);
    glVertex2f(1.0f, 0.5f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-2.0f, 0.5f);

    glEnd();

    ///triangle///

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(189, 183, 107);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(-0.5f, 1.2f);
    glVertex2f(-1.0f, 1.0f);

    glEnd();

    //polygon

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(189, 183, 107);
    glVertex2f(-0.4f, 1.1f);
    glVertex2f(-0.4f, 1.5f);
    glVertex2f(-0.6f, 1.5f);
    glVertex2f(-0.6f, 1.1f);

    glEnd();


    ///house on left side///
    //polygon 1
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(139, 69, 19);
    glVertex2f(-2.7f, 1.2f);
    glVertex2f(-6.7f, 1.2f);
    glVertex2f(-5.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);

    glEnd();


    //polygon 2
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(139, 69, 19);
    glVertex2f(-6.5f, 1.0f);
    glVertex2f(-6.7f, 1.2f);
    glVertex2f(-8.5f, -1.0f);
    glVertex2f(-8.0f, -1.0f);

    glEnd();

    //polygon 3
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(205, 133, 63);
    glVertex2f(-6.5f, 1.0f);
    glVertex2f(-8.0f, -1.0f);
    glVertex2f(-8.0f, -2.5f);
    glVertex2f(-5.0f, -3.0f);
    glVertex2f(-5.0f, -1.0f);

    glEnd();

    //polygon 4
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(128, 135, 32);
    glVertex2f(-6.0f, -2.0f);
    glVertex2f(-6.0f, -1.0f);
    glVertex2f(-7.0f, -1.0f);
    glVertex2f(-7.0f, -2.0f);

    glEnd();

    //polygon 5
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(139, 69, 19);
    glVertex2f(-5.0f, -3.0f);
    glVertex2f(-8.0f, -2.5f);
    glVertex2f(-8.3f, -2.9f);
    glVertex2f(-5.0f, -3.5f);

    glEnd();

    //polygon 6
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(184, 134, 11);
    glVertex2f(-1.5f, -3.0f);
    glVertex2f(-1.5f, -1.0f);
    glVertex2f(-5.0f, -1.0f);
    glVertex2f(-5.0f, -3.0f);

    glEnd();

    //polygon 7
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(139, 69, 19);
    glVertex2f(-5.0f, -3.0f);
    glVertex2f(-5.0f, -3.5f);
    glVertex2f(-1.0f, -3.5f);
    glVertex2f(-1.5f, -3.0f);

    glEnd();


    ///door:left
    //polygon a
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(-2.5f, -3.0f);
    glVertex2f(-2.5f, -1.2f);
    glVertex2f(-4.0f, -1.2f);
    glVertex2f(-4.0f, -3.0f);

    glEnd();

    //polygon b
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(128, 135, 32);
    glVertex2f(-3.3f, -3.0f);
    glVertex2f(-3.3f, -1.4f);
    glVertex2f(-4.0f, -1.2f);
    glVertex2f(-4.0f, -3.0f);

    glEnd();

    //polygon c
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(128, 135, 32);
    glVertex2f(-2.5f, -3.0f);
    glVertex2f(-2.5f, -1.2f);
    glVertex2f(-3.2f, -1.4f);
    glVertex2f(-3.2f, -3.0f);

    glEnd();

    ///tree left side
    //polygon 1
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-9.5, 1);
    glVertex2f(-9, 1.5);
    glVertex2f(-9.5, 2.5);
    glVertex2f(-10, 2);
    glEnd();

    //polygon 2
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-9, 1.5);
    glVertex2f(-8.5, 1);
    glVertex2f(-8, 2);
    glVertex2f(-8, 2.5);
    glEnd();

    //polygon 3
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-9.5, 1);
    glVertex2f(-9.5, -3.5);
    glVertex2f(-9, -4);
    glVertex2f(-8.5, -3.5);
    glVertex2f(-8.5, 1);
    glEnd();

    //polygon 4
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(-8.5, -3);
    glVertex2f(-9.5, -3);
    glVertex2f(-10.5, -3.5);
    glVertex2f(-7.5, -3.5);
    glEnd();



    //triangle 1
    glBegin(GL_TRIANGLES);
    glColor3ub(139, 69, 19);
    glVertex2f(-10, -0.5);
    glVertex2f(-9.5, -1);
    glVertex2f(-9.5, -0.6);
    glEnd();

    //triangle 2
    glBegin(GL_TRIANGLES);
    glColor3ub(139, 69, 19);
    glVertex2f(-9.5, 1);
    glVertex2f(-9, 1.5);
    glVertex2f(-8.5, 1);
    glEnd();



    ///right soil portion///
    //polygon1//
    glBegin(GL_POLYGON);

    glColor3ub(0, 128, 0);
    glVertex2f(13.0f, 3.0f);
    glVertex2f(16.0f, 1.0f);
    glVertex2f(38.0f, 1.0f);
    glVertex2f(38.0f, 3.0f);

    glEnd();

    //polygon2//
    glBegin(GL_POLYGON);

    glColor3ub(0, 128, 0);
    glVertex2f(16, 1);
    glVertex2f(14, 0);
    glVertex2f(17, -1.5);
    glVertex2f(38, -1.5);
    glVertex2f(38, 1);

    glEnd();

    //polygon3//
    glBegin(GL_POLYGON);

    glColor3ub(0, 128, 0);
    glVertex2f(17, -1.5);
    glVertex2f(15, -3);
    glVertex2f(18, -4);
    glVertex2f(38, -4);
    glVertex2f(38, -1.5);

    glEnd();

    //polygon4//
    glBegin(GL_POLYGON);

    glColor3ub(0, 128, 0);
    glVertex2f(18, -4);
    glVertex2f(16, -4.5);
    glVertex2f(21, -7);
    glVertex2f(38, -7);
    glVertex2f(38, -4);

    glEnd();

    //polygon5//
    glBegin(GL_POLYGON);

    glColor3ub(0, 128, 0);
    glVertex2f(21, -7);
    glVertex2f(19, -8);
    glVertex2f(22, -9);
    glVertex2f(38, -9);
    glVertex2f(38, -7);

    glEnd();

    ///right sidewise border partition///

    //polygon1//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(12.5, 3);
    glVertex2f(15.6, 0.8);
    glVertex2f(16, 1);
    glVertex2f(13, 3);

    glEnd();

    //polygon2//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(14, -0.5);
    glVertex2f(16.4, -1.9);
    glVertex2f(17, -1.5);
    glVertex2f(14, 0);

    glEnd();

    //polygon3//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(15, -3.5);
    glVertex2f(17, -4.2);
    glVertex2f(18, -4);
    glVertex2f(15, -3);

    glEnd();

    //polygon4//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(16, -5);
    glVertex2f(20.5, -7.2);
    glVertex2f(21, -7);
    glVertex2f(16, -4.5);

    glEnd();

    //polygon5//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(19, -8.5);
    glVertex2f(22, -9.5);
    glVertex2f(22, -9);
    glVertex2f(19, -8);

    glEnd();

    //polygon6//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(38, -9);
    glVertex2f(22, -9);
    glVertex2f(22, -9.5);
    glVertex2f(38, -9.5);

    glEnd();

    ///house on right side///

    //polygon1//
    glBegin(GL_POLYGON);

    //glColor3ub(25,25,112);
    glColor3ub(47, 79, 79);
    glVertex2f(25.3, 1.2);
    glVertex2f(21.3, 1.2);
    glVertex2f(23, -1);
    glVertex2f(27, -1);

    glEnd();

    //polygon2//
    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    //glColor3ub(139,69,19);
    glVertex2f(21.5, 1);
    glVertex2f(21.3, 1.2);
    glVertex2f(19.5, -1);
    glVertex2f(20, -1);

    glEnd();

    //polygon3//
    glBegin(GL_POLYGON);

    glColor3ub(184, 134, 11);
    glVertex2f(21.5, 1);
    glVertex2f(20, -1);
    glVertex2f(20, -2.5);
    glVertex2f(23, -3);
    glVertex2f(23, -1);

    glEnd();

    //polygon4//
    glBegin(GL_POLYGON);

    glColor3ub(160, 82, 45);
    glVertex2f(22, -2);
    glVertex2f(22, -1);
    glVertex2f(21, -1);
    glVertex2f(21, -2);

    glEnd();

    //polygon5//
    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    //glColor3ub(139,69,19);
    glVertex2f(23, -3);
    glVertex2f(20, -2.5);
    glVertex2f(19.7, -2.9);
    glVertex2f(23, -3.5);

    glEnd();

    //polygon6//
    glBegin(GL_POLYGON);

    glColor3ub(205, 133, 63);
    glVertex2f(26.5, -3);
    glVertex2f(26.5, -1);
    glVertex2f(23, -1);
    glVertex2f(23, -3);

    glEnd();

    //polygon7//
    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    //glColor3ub(139,69,19);
    glVertex2f(23, -3);
    glVertex2f(23, -3.5);
    glVertex2f(27, -3.5);
    glVertex2f(26.5, -3);

    glEnd();

    ///door:right///
    //polygon a//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(25.5, -3);
    glVertex2f(25.5, -1.2);
    glVertex2f(24, -1.2);
    glVertex2f(24, -3);

    glEnd();

    //polygon b//
    glBegin(GL_POLYGON);

    glColor3ub(160, 82, 45);
    glVertex2f(24.7, -3);
    glVertex2f(24.7, -1.4);
    glVertex2f(24, -1.2);
    glVertex2f(24, -3);

    glEnd();

    //polygon c//
    glBegin(GL_POLYGON);

    glColor3ub(160, 82, 45);
    glVertex2f(25.5, -3);
    glVertex2f(25.5, -1.2);
    glVertex2f(24.8, -1.4);
    glVertex2f(24.8, -3);

    glEnd();
    

    ///tree upper side///

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-10.5, 2.5, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-9.5, 3.0, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-7.5, 1.5, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-7.5, 2.5, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-8.5, 3.5, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-10.0, 4.0, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-8.0, 4.0, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-9.0, 5.0, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();


    ///boat-1 motion left to right
    glPushMatrix();
    //glColor3d(1,0,0);
    glTranslatef(_moveA, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(1.0f, -14.0f);
    glVertex2f(1.50f, -13.0f);
    glVertex2f(-2.0f, -13.0f);
    glVertex2f(-3.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(2.0f, -14.5f);
    glVertex2f(2.0f, -14.0f);
    glVertex2f(-3.0f, -14.0f);
    glVertex2f(-3.0f, -14.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(-3.0f, -14.5f);
    glVertex2f(-3.0f, -14.0f);
    glVertex2f(-4.5f, -13.7f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(2.0f, -14.5f);
    glVertex2f(3.5f, -13.7f);
    glVertex2f(2.0f, -14.0f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(2.0f, -14.0f);
    glVertex2f(1.5f, -13.0f);
    glVertex2f(1.0f, -14.0f);

    glEnd();

    glPopMatrix();

    ///////////////
    ///boat-2 motion right to left
    glPushMatrix();
    //glColor3d(1,0,0);
    glTranslatef(_moveB, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(22.0f, -17.5f);
    glVertex2f(21.0f, -16.5f);
    glVertex2f(17.50f, -16.5f);
    glVertex2f(18.0f, -17.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(22.0f, -18.0f);
    glVertex2f(22.0f, -17.5f);
    glVertex2f(17.0f, -17.5f);
    glVertex2f(17.0f, -18.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 99, 71);
    glVertex2f(20.5f, -16.5f);
    glVertex2f(21.0f, -14.5f);
    glVertex2f(18.5f, -14.5f);
    glVertex2f(18.0f, -16.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(19.8f, -14.5f);
    glVertex2f(19.8f, -14.0f);
    glVertex2f(19.7f, -14.0f);
    glVertex2f(19.7f, -14.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(17.0f, -18.0f);
    glVertex2f(17.0f, -17.5f);
    glVertex2f(15.5f, -17.2f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(22.0f, -17.5f);
    glVertex2f(22.0f, -18.0f);
    glVertex2f(23.5f, -17.2f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(17.0f, -17.5f);
    glVertex2f(18.0f, -17.5f);
    glVertex2f(17.5f, -16.5f);

    glEnd();

    glPopMatrix();


    ///windmill structure///
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(192, 192, 192);
    //glColor3ub(0,206,209);

    glVertex2f(31.0f, 2.0f);
    glVertex2f(30.0f, -6.0f);
    glVertex2f(34.0f, -6.0f);
    glVertex2f(33.0f, 2.0f);
    glVertex2f(32.5f, 3.0f);
    glVertex2f(31.5f, 3.0f);



    glEnd();


    //circle//
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(32.0f, 3.0f, 0.0f);
    glutSolidSphere(0.5, 150, 150);
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);


    glBegin(GL_QUADS);// first stand to hold the blade
    glColor3ub(255, 255, 0);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(5.0f, 0.0f);
    glVertex2f(5.0f, 0.25f);
    glVertex2f(0.0f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);// second stand to hold the blade
    glColor3ub(255, 255, 0);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(-0.25f, 5.0f);
    glVertex2f(-0.25f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);// third stand to hold the blade
    glColor3ub(255, 255, 0);
    glVertex2f(0.0f, -0.25f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-5.0f, 0.0f);
    glVertex2f(-5.0f, -0.25f);
    glEnd();

    glBegin(GL_QUADS);// fourth stand to hold the blade
    glColor3ub(255, 255, 0);
    glVertex2f(0.25f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -5.0f);
    glVertex2f(0.25f, -5.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// first triangular blade to hold the blade
    glColor3ub(128, 0, 0);
    glVertex2f(0.25f, 0.0f);
    glVertex2f(5.0f, -2.5f);
    glVertex2f(5.0f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// second triangular blade to hold the blade
    glColor3ub(128, 0, 0);
    glVertex2f(0.0f, 0.025f);
    glVertex2f(2.5f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// third triangular blade to hold the blade
    glColor3ub(128, 0, 0);
    glVertex2f(-0.25f, 0.0f);
    glVertex2f(-5.0f, 2.5f);
    glVertex2f(-5.0f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// fourth triangular blade to hold the blade
    glColor3ub(128, 0, 0);
    glVertex2f(0.0f, -0.025f);
    glVertex2f(-2.5f, -5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();







    glPopMatrix();






    glutSwapBuffers();
}


void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


}

void drawScene2() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    glLoadIdentity(); //Reset the drawing perspective
    gluOrtho2D(-12, 38, -19, 14);//range
    glMatrixMode(GL_MODELVIEW);


    ///sky///
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(38.0f, 3.0f);
    glVertex2f(38.0f, 14.0f);
    glVertex2f(-12.0f, 14.0f);
    glVertex2f(-12.0f, 3.0f);

    glEnd();

    ///Stars///

    glPushMatrix();


    glPointSize(2.0);
    glColor3ub(255, 255, 255);

    glBegin(GL_POINTS);

    glVertex2f(1, 4);
    glVertex2f(2, 7.5);
    glVertex2f(4, 5);
    glVertex2f(-2, 8);
    glVertex2f(30, 5);
    glVertex2f(-1, 9);
    glVertex2f(35, 7);
    glVertex2f(-3, 7);
    glVertex2f(-7, 5);
    glVertex2f(10, 7.5);
    glVertex2f(12, 8.5);
    glVertex2f(-11, 6);
    glVertex2f(37, 7.5);
    glVertex2f(-10, 4.5);
    glVertex2f(13, 7);
    glVertex2f(14, 7.5);
    glVertex2f(18, 10);
    // glVertex2f(-10,4.5);

    glEnd();



    glPopMatrix();


    ///moon///
        //1st circle for moon

    glPushMatrix();
    glColor3ub(217, 217, 217);
    glTranslatef(-8.0, 7.0, 0);
    glutSolidSphere(1, 250, 250);
    glPopMatrix();

    //2nd circle for moon

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(-8, 7.25, 0);
    glutSolidSphere(1, 250, 250);
    glPopMatrix();



    ///cloud 1///
    glPushMatrix();

    glTranslatef(_moveC, 0.0f, 0.0f);
    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(1.0, 6.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(1.0, 7.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(2.0, 7.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(2.0, 6.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(0.0, 6.5, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(3.0, 6.5, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPopMatrix();



    ///cloud 2///




    glPushMatrix();



    glTranslatef(_moveC, 0.0f, 0.0f);
    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(15.0, 9.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();



    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(15.0, 8.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();



    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(16.0, 8.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();



    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(16.0, 9.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();



    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(14.0, 8.5, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();



    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(17.0, 8.5, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();



    glPopMatrix();


    ///cloud 3///

    glPushMatrix();

    glTranslatef(_moveC, 0.0f, 0.0f);

    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(22.0, 8.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(22.0, 7.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(23.0, 8.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(23.0, 7.0, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(24.0, 7.5, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(105, 105, 105);
    glTranslatef(21.0, 7.5, 0);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPopMatrix();

    ///sea portion///
    glBegin(GL_POLYGON);
    glColor3ub(20, 40, 80);
    glVertex2f(38.0f, -19.0f);
    glVertex2f(38.0f, 3.0f);
    glVertex2f(-12.0f, 3.0f);
    glVertex2f(-12.0f, -19.0f);
    glEnd();

    ///left soil portion///
    //polygon 1
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 128, 0);
    glVertex2f(4.0f, 0.0f);
    glVertex2f(6.0f, 1.0f);
    glVertex2f(3.0f, 3.0f);
    glVertex2f(-12.0f, 3.0f);
    glVertex2f(-12.0f, 0.0f);

    glEnd();

    //polygon 2
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 128, 0);
    glVertex2f(5.0f, -3.0f);
    glVertex2f(7.0f, -1.5f);
    glVertex2f(4.0f, 0.0f);
    glVertex2f(-12.0f, 0.0f);
    glVertex2f(-12.0f, -3.0f);

    glEnd();

    //polygon 3
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 128, 0);
    glVertex2f(6.0f, -4.5f);
    glVertex2f(8.0f, -4.0f);
    glVertex2f(5.0f, -3.0f);
    glVertex2f(-12.0f, -3.0f);
    glVertex2f(-12.0f, -4.5f);

    glEnd();

    //polygon 4
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 128, 0);
    glVertex2f(2.0f, -9.0f);
    glVertex2f(9.5f, -7.0f);
    glVertex2f(6.0f, -4.5f);
    glVertex2f(-12.0f, -4.5f);
    glVertex2f(-12.0f, -9.5f);

    glEnd();

    //polygon 5
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 128, 0);
    glVertex2f(2.0f, -11.5f);
    glVertex2f(5.0f, -10.0f);
    glVertex2f(2.0f, -9.0f);
    glVertex2f(-12.0f, -9.0f);
    glVertex2f(-12.0f, -11.5f);

    glEnd();

    ///left sidewise border partition///
     //polygon 1
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(6.0f, 0.5f);
    glVertex2f(6.0f, 1.0f);
    glVertex2f(4.0f, 0.0f);
    glVertex2f(4.5f, -0.25f);

    glEnd();

    //polygon 2
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(7.0f, -2.0f);
    glVertex2f(7.0f, -1.5f);
    glVertex2f(5.0f, -3.0f);
    glVertex2f(5.5f, -3.15f);

    glEnd();

    //polygon 3
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(8.0f, -4.4f);
    glVertex2f(8.0f, -4.0f);
    glVertex2f(6.0f, -4.5f);
    glVertex2f(6.3f, -4.8f);

    glEnd();

    //polygon 4
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(9.5f, -7.5f);
    glVertex2f(9.5f, -7.0f);
    glVertex2f(2.0f, -9.0f);
    glVertex2f(3.0f, -9.3f);

    glEnd();

    //polygon 5
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(5.0f, -10.5f);
    glVertex2f(5.0f, -10.0f);
    glVertex2f(2.0f, -11.5f);
    glVertex2f(2.0f, -12.0f);

    glEnd();

    //polygon 6
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0, 0, 0);
    glVertex2f(2.0f, -12.0f);
    glVertex2f(2.0f, -11.5f);
    glVertex2f(-12.0f, -11.5f);
    glVertex2f(-12.0f, -12.0f);

    glEnd();
    //mountain
    //right
    glColor3ub(20, 50, 60);
    triangle(11, 3, 22, 3, 16, 7.4);
    glColor3ub(10, 30, 40);
    triangle(11, 3, 13, 3, 16, 7.4);
    //main mountain
    glBegin(GL_QUADS);
    glColor3ub(40, 90, 110);
    glVertex2f(-7, 3);
    glVertex2f(15, 3);
    glVertex2f(5, 12);
    glVertex2f(3, 11.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(150, 150, 150);
    glVertex2f(5, 12);
    glVertex2f(3, 12.6);
    glVertex2f(0, 9);
    glVertex2f(2.4, 9.5);
    glVertex2f(1.8, 8);
    glVertex2f(3.4, 9.65);
    glVertex2f(5, 7.1);
    glVertex2f(5, 8.4);
    glVertex2f(10, 7.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(20, 50, 60);
    //left 1
    glVertex2f(-22, 3);
    glVertex2f(-15, 3);
    glVertex2f(-18, 6.6);
    glColor3ub(10, 30, 40);
    glVertex2f(-22, 3);
    glVertex2f(-19.6, 3);
    glVertex2f(-18, 6.6);
    //left2
    glColor3ub(20, 50, 60);
    glVertex2f(-16, 3);
    glVertex2f(-5, 3);
    glVertex2f(-11, 7.5);
    glColor3ub(10, 30, 40);
    glVertex2f(-16, 3);
    glVertex2f(-13, 3);
    glVertex2f(-11, 7.5);
    //left big
    glColor3ub(20, 50, 60);
    glVertex2f(-9, 3);
    glVertex2f(3, 3);
    glVertex2f(-6, 9.9);
    glColor3ub(10, 30, 40);
    glVertex2f(-9, 3);
    glVertex2f(-7, 3);
    glVertex2f(-6, 9.9);
    ////mid
    glColor3ub(20, 50, 60);
    glVertex2f(-3, 3);
    glVertex2f(9, 3);
    glVertex2f(3, 6.6);
    glColor3ub(10, 30, 40);
    glVertex2f(-3, 3);
    glVertex2f(0, 3);
    glVertex2f(3, 6.6);
    glEnd();

    ///straw///
    //polygon 1
    glBegin(GL_POLYGON);
    glColor3ub(100, 100, 50);
    glVertex2f(2.5f, -3.0f);
    glVertex2f(2.0f, -1.0f);
    glVertex2f(-3.0f, -1.0f);
    glVertex2f(-3.5f, -3.0f);
    glEnd();

    //polygon 2
    glBegin(GL_POLYGON);
    glColor3ub(100, 100, 50);
    glVertex2f(2.0f, -1.0f);
    glVertex2f(1.0f, 0.5f);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(-3.0f, -1.0f);
    glEnd();

    //polygon 3
    glBegin(GL_POLYGON);
    glColor3ub(100, 100, 50);
    glVertex2f(1.0f, 0.5f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-2.0f, 0.5f);
    glEnd();

    ///triangle///
    glBegin(GL_POLYGON);
    glColor3ub(100, 100, 50);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(-0.5f, 1.2f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    //polygon
    glBegin(GL_POLYGON);
    glColor3ub(100, 100, 50);
    glVertex2f(-0.4f, 1.1f);
    glVertex2f(-0.4f, 1.5f);
    glVertex2f(-0.6f, 1.5f);
    glVertex2f(-0.6f, 1.1f);
    glEnd();

    ///house on left side///
    //polygon 1
    glBegin(GL_POLYGON);
    glColor3ub(40, 20, 10);
    glVertex2f(-2.7f, 1.2f);
    glVertex2f(-6.7f, 1.2f);
    glVertex2f(-5.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    //polygon 2
    glBegin(GL_POLYGON);
    glColor3ub(40, 20, 10);
    glVertex2f(-6.5f, 1.0f);
    glVertex2f(-6.7f, 1.2f);
    glVertex2f(-8.5f, -1.0f);
    glVertex2f(-8.0f, -1.0f);
    glEnd();

    //polygon 3
    glBegin(GL_POLYGON);
    glColor3ub(80, 50, 20);
    glVertex2f(-6.5f, 1.0f);
    glVertex2f(-8.0f, -1.0f);
    glVertex2f(-8.0f, -2.5f);
    glVertex2f(-5.0f, -3.0f);
    glVertex2f(-5.0f, -1.0f);
    glEnd();

    //polygon 4
    glBegin(GL_POLYGON);
    glColor3ub(50, 55, 15);
    glVertex2f(-6.0f, -2.0f);
    glVertex2f(-6.0f, -1.0f);
    glVertex2f(-7.0f, -1.0f);
    glVertex2f(-7.0f, -2.0f);
    glEnd();

    //polygon 5
    glBegin(GL_POLYGON);
    glColor3ub(40, 20, 10);
    glVertex2f(-5.0f, -3.0f);
    glVertex2f(-8.0f, -2.5f);
    glVertex2f(-8.3f, -2.9f);
    glVertex2f(-5.0f, -3.5f);
    glEnd();

    //polygon 6
    glBegin(GL_POLYGON);
    glColor3ub(70, 50, 5);
    glVertex2f(-1.5f, -3.0f);
    glVertex2f(-1.5f, -1.0f);
    glVertex2f(-5.0f, -1.0f);
    glVertex2f(-5.0f, -3.0f);
    glEnd();

    //polygon 7
    glBegin(GL_POLYGON);
    glColor3ub(40, 20, 10);
    glVertex2f(-5.0f, -3.0f);
    glVertex2f(-5.0f, -3.5f);
    glVertex2f(-1.0f, -3.5f);
    glVertex2f(-1.5f, -3.0f);
    glEnd();

    ///door:left
    //polygon a
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-2.5f, -3.0f);
    glVertex2f(-2.5f, -1.2f);
    glVertex2f(-4.0f, -1.2f);
    glVertex2f(-4.0f, -3.0f);
    glEnd();

    //polygon b
    glBegin(GL_POLYGON);
    glColor3ub(50, 55, 15);
    glVertex2f(-3.3f, -3.0f);
    glVertex2f(-3.3f, -1.4f);
    glVertex2f(-4.0f, -1.2f);
    glVertex2f(-4.0f, -3.0f);
    glEnd();

    //polygon c
    glBegin(GL_POLYGON);
    glColor3ub(50, 55, 15);
    glVertex2f(-2.5f, -3.0f);
    glVertex2f(-2.5f, -1.2f);
    glVertex2f(-3.2f, -1.4f);
    glVertex2f(-3.2f, -3.0f);
    glEnd();

    ///tree left side
    //polygon 1
    glBegin(GL_POLYGON);
    glColor3ub(40, 20, 10);
    glVertex2f(-9.5, 1);
    glVertex2f(-9, 1.5);
    glVertex2f(-9.5, 2.5);
    glVertex2f(-10, 2);
    glEnd();

    //polygon 2
    glBegin(GL_POLYGON);
    glColor3ub(40, 20, 10);
    glVertex2f(-9, 1.5);
    glVertex2f(-8.5, 1);
    glVertex2f(-8, 2);
    glVertex2f(-8, 2.5);
    glEnd();

    //polygon 3
    glBegin(GL_POLYGON);
    glColor3ub(40, 20, 10);
    glVertex2f(-9.5, 1);
    glVertex2f(-9.5, -3.5);
    glVertex2f(-9, -4);
    glVertex2f(-8.5, -3.5);
    glVertex2f(-8.5, 1);
    glEnd();

    //polygon 4
    glBegin(GL_POLYGON);
    glColor3ub(40, 20, 10);
    glVertex2f(-8.5, -3);
    glVertex2f(-9.5, -3);
    glVertex2f(-10.5, -3.5);
    glVertex2f(-7.5, -3.5);
    glEnd();

    //triangle 1
    glBegin(GL_TRIANGLES);
    glColor3ub(40, 20, 10);
    glVertex2f(-10, -0.5);
    glVertex2f(-9.5, -1);
    glVertex2f(-9.5, -0.6);
    glEnd();

    //triangle 2
    glBegin(GL_TRIANGLES);
    glColor3ub(40, 20, 10);
    glVertex2f(-9.5, 1);
    glVertex2f(-9, 1.5);
    glVertex2f(-8.5, 1);
    glEnd();

    ///right soil portion///
    //polygon1//
    glBegin(GL_POLYGON);
    glColor3ub(0, 64, 0);
    glVertex2f(13.0f, 3.0f);
    glVertex2f(16.0f, 1.0f);
    glVertex2f(38.0f, 1.0f);
    glVertex2f(38.0f, 3.0f);
    glEnd();


    //polygon2//
    glBegin(GL_POLYGON);

    glColor3ub(0, 128, 0);
    glVertex2f(16, 1);
    glVertex2f(14, 0);
    glVertex2f(17, -1.5);
    glVertex2f(38, -1.5);
    glVertex2f(38, 1);

    glEnd();

    //polygon3//
    glBegin(GL_POLYGON);

    glColor3ub(0, 128, 0);
    glVertex2f(17, -1.5);
    glVertex2f(15, -3);
    glVertex2f(18, -4);
    glVertex2f(38, -4);
    glVertex2f(38, -1.5);

    glEnd();

    //polygon4//
    glBegin(GL_POLYGON);

    glColor3ub(0, 128, 0);
    glVertex2f(18, -4);
    glVertex2f(16, -4.5);
    glVertex2f(21, -7);
    glVertex2f(38, -7);
    glVertex2f(38, -4);

    glEnd();

    //polygon5//
    glBegin(GL_POLYGON);

    glColor3ub(0, 128, 0);
    glVertex2f(21, -7);
    glVertex2f(19, -8);
    glVertex2f(22, -9);
    glVertex2f(38, -9);
    glVertex2f(38, -7);

    glEnd();

    ///right sidewise border partition///

    //polygon1//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(12.5, 3);
    glVertex2f(15.6, 0.8);
    glVertex2f(16, 1);
    glVertex2f(13, 3);

    glEnd();

    //polygon2//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(14, -0.5);
    glVertex2f(16.4, -1.9);
    glVertex2f(17, -1.5);
    glVertex2f(14, 0);

    glEnd();

    //polygon3//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(15, -3.5);
    glVertex2f(17, -4.2);
    glVertex2f(18, -4);
    glVertex2f(15, -3);

    glEnd();

    //polygon4//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(16, -5);
    glVertex2f(20.5, -7.2);
    glVertex2f(21, -7);
    glVertex2f(16, -4.5);

    glEnd();

    //polygon5//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(19, -8.5);
    glVertex2f(22, -9.5);
    glVertex2f(22, -9);
    glVertex2f(19, -8);

    glEnd();

    //polygon6//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(38, -9);
    glVertex2f(22, -9);
    glVertex2f(22, -9.5);
    glVertex2f(38, -9.5);

    glEnd();

    ///house on right side///

    //polygon1//
    glBegin(GL_POLYGON);

    //glColor3ub(25,25,112);
    glColor3ub(47, 79, 79);
    glVertex2f(25.3, 1.2);
    glVertex2f(21.3, 1.2);
    glVertex2f(23, -1);
    glVertex2f(27, -1);

    glEnd();

    //polygon2//
    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    //glColor3ub(139,69,19);
    glVertex2f(21.5, 1);
    glVertex2f(21.3, 1.2);
    glVertex2f(19.5, -1);
    glVertex2f(20, -1);

    glEnd();

    //polygon3//
    glBegin(GL_POLYGON);

    glColor3ub(184, 134, 11);
    glVertex2f(21.5, 1);
    glVertex2f(20, -1);
    glVertex2f(20, -2.5);
    glVertex2f(23, -3);
    glVertex2f(23, -1);

    glEnd();

    //polygon4//
    glBegin(GL_POLYGON);

    glColor3ub(160, 82, 45);
    glVertex2f(22, -2);
    glVertex2f(22, -1);
    glVertex2f(21, -1);
    glVertex2f(21, -2);

    glEnd();

    //polygon5//
    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    //glColor3ub(139,69,19);
    glVertex2f(23, -3);
    glVertex2f(20, -2.5);
    glVertex2f(19.7, -2.9);
    glVertex2f(23, -3.5);

    glEnd();

    //polygon6//
    glBegin(GL_POLYGON);

    glColor3ub(205, 133, 63);
    glVertex2f(26.5, -3);
    glVertex2f(26.5, -1);
    glVertex2f(23, -1);
    glVertex2f(23, -3);

    glEnd();

    //polygon7//
    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    //glColor3ub(139,69,19);
    glVertex2f(23, -3);
    glVertex2f(23, -3.5);
    glVertex2f(27, -3.5);
    glVertex2f(26.5, -3);

    glEnd();

    ///door:right///
    //polygon a//
    glBegin(GL_POLYGON);

    glColor3ub(0, 0, 0);
    glVertex2f(25.5, -3);
    glVertex2f(25.5, -1.2);
    glVertex2f(24, -1.2);
    glVertex2f(24, -3);

    glEnd();

    //polygon b//
    glBegin(GL_POLYGON);

    glColor3ub(160, 82, 45);
    glVertex2f(24.7, -3);
    glVertex2f(24.7, -1.4);
    glVertex2f(24, -1.2);
    glVertex2f(24, -3);

    glEnd();

    //polygon c//
    glBegin(GL_POLYGON);

    glColor3ub(160, 82, 45);
    glVertex2f(25.5, -3);
    glVertex2f(25.5, -1.2);
    glVertex2f(24.8, -1.4);
    glVertex2f(24.8, -3);

    glEnd();

    ///tree upper side///

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-10.5, 2.5, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-9.5, 3.0, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-7.5, 1.5, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-7.5, 2.5, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-8.5, 3.5, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-10.0, 4.0, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-8.0, 4.0, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(50, 205, 50);
    glTranslatef(-9.0, 5.0, 0);
    glutSolidSphere(1.0, 150, 150);
    glPopMatrix();

    ///boat-1 motion left to right
    glPushMatrix();
    //glColor3d(1,0,0);
    glTranslatef(_moveA, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(1.0f, -14.0f);
    glVertex2f(1.50f, -13.0f);
    glVertex2f(-2.0f, -13.0f);
    glVertex2f(-3.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(2.0f, -14.5f);
    glVertex2f(2.0f, -14.0f);
    glVertex2f(-3.0f, -14.0f);
    glVertex2f(-3.0f, -14.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(-3.0f, -14.5f);
    glVertex2f(-3.0f, -14.0f);
    glVertex2f(-4.5f, -13.7f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(2.0f, -14.5f);
    glVertex2f(3.5f, -13.7f);
    glVertex2f(2.0f, -14.0f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(2.0f, -14.0f);
    glVertex2f(1.5f, -13.0f);
    glVertex2f(1.0f, -14.0f);

    glEnd();

    glPopMatrix();

    ///////////////
    ///boat-2 motion right to left
    glPushMatrix();
    //glColor3d(1,0,0);
    glTranslatef(_moveB, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(22.0f, -17.5f);
    glVertex2f(21.0f, -16.5f);
    glVertex2f(17.50f, -16.5f);
    glVertex2f(18.0f, -17.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(22.0f, -18.0f);
    glVertex2f(22.0f, -17.5f);
    glVertex2f(17.0f, -17.5f);
    glVertex2f(17.0f, -18.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 99, 71);
    glVertex2f(20.5f, -16.5f);
    glVertex2f(21.0f, -14.5f);
    glVertex2f(18.5f, -14.5f);
    glVertex2f(18.0f, -16.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(19.8f, -14.5f);
    glVertex2f(19.8f, -14.0f);
    glVertex2f(19.7f, -14.0f);
    glVertex2f(19.7f, -14.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(17.0f, -18.0f);
    glVertex2f(17.0f, -17.5f);
    glVertex2f(15.5f, -17.2f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(22.0f, -17.5f);
    glVertex2f(22.0f, -18.0f);
    glVertex2f(23.5f, -17.2f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(17.0f, -17.5f);
    glVertex2f(18.0f, -17.5f);
    glVertex2f(17.5f, -16.5f);

    glEnd();

    glPopMatrix();

    ///windmill structure///
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(192, 192, 192);
    //glColor3ub(0,206,209);

    glVertex2f(31.0f, 2.0f);
    glVertex2f(30.0f, -6.0f);
    glVertex2f(34.0f, -6.0f);
    glVertex2f(33.0f, 2.0f);
    glVertex2f(32.5f, 3.0f);
    glVertex2f(31.5f, 3.0f);



    glEnd();


    //circle//
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(32.0f, 3.0f, 0.0f);
    glutSolidSphere(0.5, 150, 150);
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);


    glBegin(GL_QUADS);// first stand to hold the blade
    glColor3ub(255, 255, 0);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(5.0f, 0.0f);
    glVertex2f(5.0f, 0.25f);
    glVertex2f(0.0f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);// second stand to hold the blade
    glColor3ub(255, 255, 0);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(-0.25f, 5.0f);
    glVertex2f(-0.25f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);// third stand to hold the blade
    glColor3ub(255, 255, 0);
    glVertex2f(0.0f, -0.25f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-5.0f, 0.0f);
    glVertex2f(-5.0f, -0.25f);
    glEnd();

    glBegin(GL_QUADS);// fourth stand to hold the blade
    glColor3ub(255, 255, 0);
    glVertex2f(0.25f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -5.0f);
    glVertex2f(0.25f, -5.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// first triangular blade to hold the blade
    glColor3ub(128, 0, 0);
    glVertex2f(0.25f, 0.0f);
    glVertex2f(5.0f, -2.5f);
    glVertex2f(5.0f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// second triangular blade to hold the blade
    glColor3ub(128, 0, 0);
    glVertex2f(0.0f, 0.025f);
    glVertex2f(2.5f, 5.0f);
    glVertex2f(0.0f, 5.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// third triangular blade to hold the blade
    glColor3ub(128, 0, 0);
    glVertex2f(-0.25f, 0.0f);
    glVertex2f(-5.0f, 2.5f);
    glVertex2f(-5.0f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// fourth triangular blade to hold the blade
    glColor3ub(128, 0, 0);
    glVertex2f(0.0f, -0.025f);
    glVertex2f(-2.5f, -5.0f);
    glVertex2f(0.0f, -5.0f);
    glEnd();







    glPopMatrix();






    glutSwapBuffers();
}






void SpecialInput(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:

        glutDisplayFunc(drawScene);
        break;
    case GLUT_KEY_DOWN:

        glutDisplayFunc(drawScene2);
        break;

    }
    glutPostRedisplay();
}



void update1(int value) {

    _moveA += speed;
    if (_moveA > 38)
    {
        _moveA = -38;
    }
    //Notify GLUT that the display has changed

//_moveA += 0.11;

    glutTimerFunc(20, update1, 0); //Notify GLUT to call update again in 25 milliseconds
    glutPostRedisplay();
}

void handleMouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON)
    {
        speed += 0.05f;
    }


    else if (button == GLUT_RIGHT_BUTTON)
    {
        speed -= 0.05f;
    }
    glutPostRedisplay();
}
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
    case 's'://stops
        speed = 0.0f;
        break;
    case 'r'://runs
        speed = 0.02f;
        break;
        glutPostRedisplay();
    }
}

void update2(int value) {


    if (_moveB < -36)
    {
        _moveB = +38;
    }
    //Notify GLUT that the display has changed

    _moveB -= 0.13;

    glutTimerFunc(20, update2, 0); //Notify GLUT to call update again in 25 milliseconds
    glutPostRedisplay();
}
//function for windlmill
void update3(int value) {

    _angle1 -= 2.0f;
    if (_angle1 > 360.0)
    {
        _angle1 -= 360;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed

    glutTimerFunc(10, update3, 0); //Notify GLUT to call update again in 25 milliseconds
}
void update4(int value) {


    if (_moveC > +36)
    {
        _moveC = -38;
    }
    //Notify GLUT that the display has changed

    _moveC += 0.13;

    glutTimerFunc(20, update4, 0); //Notify GLUT to call update again in 25 milliseconds
    glutPostRedisplay();
}







int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);







    glutInitWindowSize(1500, 1000);
    glutCreateWindow("Transformation");


    init();
    glutSpecialFunc(SpecialInput);


    glutDisplayFunc(drawScene);
    glutTimerFunc(20, update1, 0); //Add a timer
    glutTimerFunc(20, update2, 0); //Add a timer

    glutTimerFunc(10, update3, 0);
    glutTimerFunc(20, update4, 0);
    glutKeyboardFunc(handleKeypress);

    glutMouseFunc(handleMouse);
    glutMainLoop();
    return 0;
}
