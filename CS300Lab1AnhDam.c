// Anh Dam - Lab 1

#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void randomColor() {
    glColor3ub( rand()%255, rand()%255, rand()%255 );
}

void display () {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();           //start with the identity matrix
    gluOrtho2D(0,500,0,420);        //how object is mapped to window
    
    glTranslatef(43,320,0);    /* translate model to appropriate point */
    
    glPointSize(7.0);       //pen size
    glBegin(GL_POINTS);
    randomColor();
    glVertex2i(40,60);
    glVertex2i(80,80);
    glVertex2i(40,40);
    glVertex2i(20,60);
    glVertex2i(0,0);
    glEnd();
    
    glTranslatef(0,-100,0);    /* translations are cumulative */
    glLineWidth(3.0);
    glBegin(GL_LINES);
    randomColor();
    glVertex2i(80,100);
    glVertex2i(80,80);
    glVertex2i(40,100);
    glVertex2i(20,60);
    glEnd();
    
    glTranslatef(166,0,0);
    glBegin(GL_LINE_STRIP);
    randomColor();
    glVertex2i(20,60);
    glVertex2i(40,80);
    glVertex2i(80,60);
    glVertex2i(20,20);
    glEnd();
    
    glTranslatef(166,0,0);
    glBegin(GL_LINE_LOOP);
    randomColor();
    glVertex2i(20,60);
    glVertex2i(80,80);
    glVertex2i(40,40);
    glVertex2i(60,20);
    glVertex2i(0,0);
    glEnd();
    
    glTranslatef(-320,-100,0);
    glBegin(GL_TRIANGLES);
    randomColor();
    glVertex2i(-20,20);
    glVertex2i(20,-20);
    glVertex2i(0,20);
    glEnd();
    
    glTranslatef(166,0,0);
    glBegin(GL_TRIANGLE_STRIP);
    randomColor();
    glVertex2i(-60,20);
    glVertex2i(-20,30);
    glVertex2i(0,10);
    glVertex2i(-30,-30);
    glVertex2i(-60,-40);
    glEnd();
    
    glTranslatef(166,0,0);
    glBegin(GL_TRIANGLE_FAN);
    randomColor();
    glVertex2i(10, 10);
    glVertex2i(60, 10);
    glVertex2i(80,30);
    glVertex2i(60,60);
    glVertex2i(10,60);
    glVertex2i(0,30);
    glEnd();
    
    glTranslatef(-320,-100,0);
    glBegin(GL_QUADS);
    randomColor();
    glVertex2i(40, 40);
    glVertex2i(0, 40);
    glVertex2i(0, 0);
    glVertex2i(40, 0);
    glEnd();
    
    glTranslatef(166,0,0);
    glBegin(GL_QUAD_STRIP);
    randomColor();
    glVertex2i(80, 60);
    glVertex2i(60, 60);
    glVertex2i(80, 85);
    glVertex2i(60, 70);
    glVertex2i(70, 60);
    glVertex2i(50, 40);
    glVertex2i(80, 70);
    glEnd();
    
    glTranslatef(166,0,0);
    glBegin(GL_POLYGON);
    randomColor();
    glVertex2i(20, 20);
    glVertex2i(60, 10);
    glVertex2i(60,30);
    glVertex2i(50,60);
    glVertex2i(10,60);
    glVertex2i(0,30);
    glEnd();

    //Create an object or a scene
    glTranslatef(10, 320, 0);
    glBegin(GL_POLYGON);
    randomColor();
    glVertex2i(80, 30);
    glVertex2i(30, 80);
    glVertex2i(30, 30);
    glVertex2i(50, 40);
    glVertex2i(80, 80);
    glVertex2i(0, 0);

    glEnd();
    
    glFlush();
    
}


void reshape ( int w, int h ) {
    glViewport(0, 0, w, h);
    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) {
        // width is smaller, go from -50 .. 50 in width
        glOrtho(-50.0, 50.0, -50.0/aspect, 50.0/aspect, -1.0, 1.0);
    } else {
        // height is smaller, go from -50 .. 50 in height
        glOrtho(-50.0*aspect, 50.0*aspect, -50.0, 50.0, -1.0, 1.0);
    }
}

void keyboard(unsigned char key, int x, int y)
{
#pragma unused(x,y)
    switch (key) {
        case 'q':
            exit(0);
        case 'p':
            randomColor();
    }
}

int main ( int argc, char * argv[] ) {
    glutInit(&argc,argv);
    
    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB);
    
    /* create and set up a window */
    glutCreateWindow("Lab 1");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
    
    /* tell GLUT to wait for events */
    glutMainLoop();
    return 0;
}
