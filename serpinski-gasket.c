#include <GL/freeglut.h>

#define POINTS 500000

void my-init()
{
    /*
     * attributes
     */

    glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
    glColor3f(1.0, 0.0, 0.0); /*  draw in red */

    /* 
     * set up viewing
     */

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 50.0, 0.0, 50.0);
    glMatrixMode(GL_MODELVIEW); 
}

void draw-serpinski()
{
    GLfloat vertices[3][2] = {{0.0,0.0}, {25.0,50.0}, {50.0, 0.0}}; /* triangle */
    int i, j, k;
    int rand(); /* random number */
    GLfloat p[2] = {7.5, 5.0}; /* arbitrary point inside triangle */

    glClear(GL_COLOR_BUFFER_BIT); /* clear the window */

    /*
     * compute POINTS 
     */

    glBegin(GL_POINTS);

    for( k=0; k<POINTS; k++)
    {
        j = rand()%3; /* pick a vertex at random */

        /* compute point halfway between vertex and old point */

        p[0] = (p[0] + vertices[j][0])/2;
        p[1] = (p[1] + vertices[j][1])/2;

        /* plot point */

        glVertex2fv(p);
    }

    glEnd();
    glFlush(); 
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("simple Open GL window");
    glutDisplayFunc(draw-serpinski);
    my-init();
    glutMainLoop(); 
}
