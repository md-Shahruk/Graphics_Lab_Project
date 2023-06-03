#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<cmath>
float count1=30.0f;
float count2=30.0f;
float y_sun=0.0f;
float sky3=20.0f;
float sky2=40.0f;
float sky1=60.0f;
float x_p=0.0f;

/* ---------------------------------------------
   Project Name: Street view with the hill area.
           Name: Md. Shahruk
           Id  : 201-15-3429
        Section: 55_Pc-H1

   ---------------------------------------------
*/


 ///reshape window

 void reshape(int width,int height)
 {

    glClearColor(0.52,0.80,0.92,0.0);
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    float h2w = (float) height/ (float) width;
    float w2h = (float) width/ (float) height;

    if(width<=height)
    {
        gluOrtho2D(0.0,38.0,0.0,38.0*h2w);
    }
    else
    {
        gluOrtho2D(0.0,38.0*w2h,0.0,38.0);
    }
    glMatrixMode(GL_MODELVIEW);

 }


  /// keyboard event set here
  void keyboard(unsigned char key, int kx,int ky){

    switch(key)
        {

        case 27:
            exit(0);
            break;
        case 'f':
            glutFullScreen();
            break;
        case 'b':
            glutPositionWindow(100,100);
            glutReshapeWindow(600,600);
            break;


        }

  }
  ///sun circle
  void sun_wheel(float r,int x,int y){

    float take;
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);

    for (int i=0;i<360;i++){
        take=i*(3.1416/180);
        glVertex2f(x+r*cos(take),y+r*sin(take));
    }
    glEnd();

}
    void increes(int)
    {

        int c = 0;
        if(y_sun<15){
            y_sun+=0.05;
        }else{
        c=1;
        }
        if(c==1){
            if(x_p<85){
                x_p+=0.09;
            }
        }


        glutPostRedisplay();
        glutTimerFunc(15.0, increes, 0);
    }

    ///plane draw

    void plane_draw(){
        //body
        glBegin(GL_QUADS);
        glColor3ub(209, 198, 198);
        glVertex2i((16-25)+x_p,27);
        glVertex2i((16-25)+x_p,29);
        glVertex2i((24-25)+x_p,29);
        glVertex2i((24-25)+x_p,27);
        glEnd();
        //laj
        glBegin(GL_TRIANGLES);
        glColor3ub(51, 44, 44);
        glVertex2i((13-25)+x_p,30);
        glVertex2i((16-25)+x_p,29);
        glVertex2i((16-25)+x_p,27);
        glEnd();

        //up

        glBegin(GL_TRIANGLES);
        glColor3ub(51, 44, 44);
        glVertex2i((22-25)+x_p,32);
        glVertex2i((22-25)+x_p,29);
        glVertex2i((20-25)+x_p,29);
        glEnd();

        //down
        glBegin(GL_TRIANGLES);
        glColor3ub(51, 44, 44);
        glVertex2i((20-25)+x_p,24);
        glVertex2i((20-25)+x_p,27);
        glVertex2i((22-25)+x_p,27);
        glEnd();

    }

  ///circle draw
  void car_wheel(float r,int x,int y){

    float take;
    glBegin(GL_POLYGON);


    for (int i=0;i<360;i++){
        take=i*(3.1416/180);
        glVertex2f(x+r*cos(take),y+r*sin(take));
    }
    glEnd();

}
 ///road design

  void road(){

   glBegin(GL_POLYGON);
   glColor3ub(160, 142, 142);
   glVertex2i(0,0);
   glVertex2i(0,8);
   glVertex2i(68,8);
   glVertex2i(68,0);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(247, 239, 239);
   glVertex2i(12,6);
   glVertex2i(32,6);
   glVertex2i(32,5);
   glVertex2i(12,5);
   glEnd();

   glBegin(GL_QUADS);
   glColor3ub(247, 239, 239);
   glVertex2i(44,4);
   glVertex2i(44,5);
   glVertex2i(60,5);
   glVertex2i(60,4);
   glEnd();

  }
///car one design
  void car_one(){
      glLoadIdentity();
      count1=count1-0.0040;

        glPushMatrix();
        glTranslated(-count1,0.1,0.0);
     glBegin(GL_POLYGON);
         glColor3ub(229, 52, 52);
         glVertex2i(4,5);
         glVertex2i(4,10);
         glVertex2i(10,10);
         glVertex2i(10,7);
         glVertex2i(15,7);
         glVertex2i(15,5);
     glEnd();

     glBegin(GL_QUADS);
       glColor3ub(66, 49, 49);
       glVertex2i(5,7);
       glVertex2i(5,9);
       glVertex2i(8,9);
       glVertex2i(8,7);
     glEnd();
     glColor3ub(93, 93, 140);
     car_wheel(1.5,6,4);
     car_wheel(1.5,13,4);
     glColor3ub(63, 47, 47);
     car_wheel(0.8,6,4);
     car_wheel(0.8,13,4);
     glPopMatrix();

  }
///car two design
  void car_two(){
      glLoadIdentity();
      count2=count2-0.0040;

        glPushMatrix();
        glTranslated(count2,0.1,0);
     glBegin(GL_POLYGON);
         glColor3ub(191, 86, 87);
         glVertex2i(33,4);
         glVertex2i(33,6);
         glVertex2i(36,8);
         glVertex2i(36,10);
         glVertex2i(56,10);
         glVertex2i(56,4);
     glEnd();
     glBegin(GL_QUADS);
        glColor3ub(224, 179, 179);
       glVertex2i(38,7);
       glVertex2i(38,9);
       glVertex2i(41,9);
       glVertex2i(41,7);
     glEnd();
     glBegin(GL_QUADS);
       glColor3ub(224, 179, 179);
       glVertex2i(44,7);
       glVertex2i(44,9);
       glVertex2i(47,9);
       glVertex2i(47,7);
     glEnd();

     glBegin(GL_QUADS);
        glColor3ub(224, 179, 179);
       glVertex2i(50,7);
       glVertex2i(50,9);
       glVertex2i(54,9);
       glVertex2i(54,7);
     glEnd();
      glColor3ub(93, 93, 140);

      car_wheel(1.5,39,3);
      car_wheel(1.5,51,3);
      glColor3ub(63, 47, 47);
      car_wheel(0.8,39,3);
      car_wheel(0.8,51,3);
      glPopMatrix();

  }
/// Hill one

 void hill_one(){

     glBegin(GL_POLYGON);
      glColor3ub(108,81,74);

      glVertex2f(1,11);
      glVertex2f(6,22);
      glVertex2f(20,12);
      glVertex2f(1,11);

    glEnd();
    glBegin(GL_POLYGON);
      glColor3ub(252, 242, 242);

      glVertex2f(6,22);
      glVertex2f(10,19);
      glVertex2f(7,20);
      glVertex2f(6,19);
      glVertex2f(5,20);

    glEnd();



 }
 ///Hill two
 void hill_two(){
     glBegin(GL_POLYGON);
      glColor3ub(108,81,74);

      glVertex2f(40,12);
      glVertex2f(56,28);
      glVertex2f(68,11);

    glEnd();

    glBegin(GL_POLYGON);
      glColor3ub(252, 242, 242);

      glVertex2f(56,28);
      glVertex2f(59,24);
      glVertex2f(56,25);
      glVertex2f(55,24);
      glVertex2f(53,25);

    glEnd();

 }

 /// green-back
  void green_back(){

   glBegin(GL_POLYGON);
      glColor3ub(34,139,34);

      glVertex2f(1,12);
      glVertex2f(6,14);
      glVertex2f(11,19);
      glVertex2f(16,20);
      glVertex2f(24,20);
      glVertex2f(28,22);
      glVertex2f(32,23);
      glVertex2f(36,24);
      glVertex2f(42,25);
      glVertex2f(46,23);
      glVertex2f(50,24);
      glVertex2f(56,22);
      glVertex2f(60,18);
      glVertex2f(63,12);

    glEnd();


  }
   ///background
   void background(){
     glBegin(GL_QUADS);
    glColor3ub(173, 169, 97);
    glVertex2i(0,8);
    glVertex2i(0,12);
    glVertex2i(68,12);
    glVertex2i(68,0);

    glEnd();

   }
  ///house one
  void house_one(){
    glBegin(GL_QUADS);
    glColor3ub(217,79,51);
    glVertex2i(14,16);
    glVertex2i(14,19);
    glVertex2i(27,18);
    glVertex2i(27,16);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 90, 96);
    glVertex2i(15,11);
    glVertex2i(15,16);
    glVertex2i(26,16);
    glVertex2i(26,11);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(106, 107, 92);
    glVertex2i(16,13);
    glVertex2i(16,15);
    glVertex2i(19,15);
    glVertex2i(19,13);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(100,130,34);
    glVertex2i(21,11);
    glVertex2i(21,15);
    glVertex2i(24,15);
    glVertex2i(24,11);

    glEnd();

  }

  ///house two

  void house_two(){

   glBegin(GL_QUADS);
    glColor3ub(217,79,51);
    glVertex2i(35,18);
    glVertex2i(35,22);
    glVertex2i(48,20);
    glVertex2i(48,18);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(71, 26, 11);
    glVertex2i(36,12);
    glVertex2i(36,18);
    glVertex2i(47,18);
    glVertex2i(47,12);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(125, 165, 143);
    glVertex2i(37,15);
    glVertex2i(37,17);
    glVertex2i(40,17);
    glVertex2i(40,15);

    glEnd();

     //2nd gor
    glBegin(GL_QUADS);
    glColor3ub(122, 56, 34);
    glVertex2i(47,12);
    glVertex2i(47,16);
    glVertex2i(51,16);
    glVertex2i(51,12);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(214, 103, 81);
    glVertex2i(47,16);
    glVertex2i(47,18);
    glVertex2i(51,18);
    glVertex2i(52,16);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(125, 165, 143);
    glVertex2i(48,12);
    glVertex2i(48,15);
    glVertex2i(50,15);
    glVertex2i(50,12);

    glEnd();

  }

  ///cloud art

   void cloud3(){
     glLoadIdentity();
     sky3=sky3-0.0020;


    glPushMatrix();
    glTranslated(-sky3,0.1,0);
    glColor3ub(239, 234, 234);


    car_wheel(1.0,20,30);
    car_wheel(1.0,21,30);
    car_wheel(1.0,22,30);
    car_wheel(1.0,23,30);
    car_wheel(1.0,24,30);
    car_wheel(1.0,25,30);
    car_wheel(1.0,26,30);
    car_wheel(1.0,21,29);
    car_wheel(1.0,22,29);
    car_wheel(1.0,23,29);
    car_wheel(1.0,24,29);
    car_wheel(1.0,25,29);


    glPopMatrix();

   }
 void cloud2(){
     glLoadIdentity();
     sky2=sky2-0.0020;


    glPushMatrix();
    glTranslated(-sky2,0.1,0);
    glColor3ub(239, 234, 234);

    car_wheel(1.0,14,36);
    car_wheel(1.0,15,36);
    car_wheel(1.0,16,36);
    car_wheel(1.0,17,36);
    car_wheel(1.0,15,35);
    car_wheel(1.0,16,35);


    glPopMatrix();

   }

 void cloud1(){
     glLoadIdentity();
      sky1=sky1-0.0020;


    glPushMatrix();
    glTranslated(-sky1,0.1,0);
    glColor3ub(239, 234, 234);

    car_wheel(1.0,4,28);
    car_wheel(1.0,5,28);
    car_wheel(1.0,6,28);
    car_wheel(1.0,7,28);
    car_wheel(1.0,5,27);
    car_wheel(1.0,6,27);

    glPopMatrix();

   }

 ///ground second

  void second_ground(){
      glBegin(GL_POLYGON);
      glColor3ub(53, 160, 79);

      glVertex2i(26,11);
      glVertex2i(28,13);
      glVertex2i(30,12);
      glVertex2i(32,13);
      glVertex2i(34,12);
      //glVertex2i(37,12);
      glVertex2i(40,12);



      glEnd();

   }
   ///lamp desing

   void lamp(){

     glBegin(GL_LINES);
     glColor3ub(255,255,0);
     glVertex2i(30,12);
     glVertex2i(30,15);
     glEnd();

     glColor3ub(143, 201, 44);
     car_wheel(1.0,30,16);
     glColor3ub(226, 232, 60);
     car_wheel(1.7,30,18);

   }
 ///Display
 void display()
 {

    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    //we will draw here
    ///plane
    plane_draw();
    ///cloud
    cloud3();
    cloud2();
    cloud1();

    ///sun moving
    sun_wheel(2.5,36,20+y_sun);

    //cloud();
    background();
    road();
    car_one();
    car_two();
    green_back();
    hill_one();
    hill_two();
    house_one();
    house_two();
    second_ground();
    lamp();
    //

    //display the frame buffer
    glFlush();

 }



 int main(int argc, char** argv)
 {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(60, 50);
    glutInitWindowSize(1000, 1000);


    glutCreateWindow("Hill area with street road.");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(15.0, increes, 0);
    glutIdleFunc(display);


    glutMainLoop();

    return 0;

 }


