// rainbow.cpp

// Copyright <2025> <JAMES C. WILLIAMS>

// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files(the “Software”), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and /or
// sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions :

// The above copyright notice and this permission notice shall be included in all copies or substantial
// portions of the Software.

// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <iostream>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <cmath>
#include <Windows.h>
#include <D:\Downloads\glew-2.1.0\include\GL\glew.h>
#include <D:\Downloads\glfw-3.4.bin.WIN64\include\GLFW\glfw3.h>
#include <gl\GL.h>
#include <C:\Users\plati\source\repos\GRAPHICS\GRAPHICS\GRAPHICS.h>




using namespace std;




int flag = 0;


static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
        flag = 1;;
}

int main()
{
    std::cout << "display_check\n\n\n\n";
    char Q = ' ';
    double x1 = 0., x2 = 0., y1 = 0., y2 = 0, z1 = 0., z2 = 0.;
    double pi = 3.14159265359;
    double ohm = 0.;
    double x = 0., y = 0., z = 0.;
    
display_setup:
    flag = true;
    glfwInit();
    if (!glfwInit())
    {
        std::cout << "GLFW INITIALIZATION FAILURE\n\n";
        glfwTerminate();
        return 0;
    }
    GLFWwindow* window = glfwCreateWindow(800, 600, "display_check", NULL, NULL);
    glfwMakeContextCurrent(window);
    int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    if (state == GLFW_PRESS && flag == 1)
    {
        goto term;
    }
    goto cont;
term:
    glfwTerminate();
    return 0;
cont:
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
display:
    for (int i = 0; i < 628; i++)
    {
        glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3d(-50.0, 50.0, 0.0);
        glVertex3d(50.0, 50.0, 0.0);
        glVertex3d(50.0, -50.0, 0.0);
        glVertex3d(-50.0, -50.0, 0.0);
        glEnd();

        
        

        glBegin(GL_LINE_LOOP);
        ohm = (i / 100.);
        x = sin(ohm) * 20.;
        y = cos(ohm) * 20.;
        z = 0.;


        // Spectral Color

        float r, b, g, l = i/2.+380.;

        if (l < 380.0)  r = 0.00;
        else if (l < 400.0) r = 0.05 - 0.05 * sin(pi * (l - 366.0) / 33.0);
        else if (l < 435.0) r = 0.31 * sin(pi * (l - 395.0) / 81.0);
        else if (l < 460.0) r = 0.31 * sin(pi * (l - 412.0) / 48.0);
        else if (l < 540.0) r = 0.00;
        else if (l < 590.0) r = 0.99 * sin(pi * (l - 540.0) / 104.0);
        else if (l < 670.0) r = 1.00 * sin(pi * (l - 507.0) / 182.0);
        else if (l < 730.0) r = 0.32 - 0.32 * sin(pi * (l - 670.0) / 128.0);
        else              r = 0.00;
        if (l < 454.0) g = 0.00;
        else if (l < 617.0) g = 0.78 * sin(pi * (l - 454.0) / 163.0);
        else              g = 0.00;
        if (l < 380.0) b = 0.00;
        else if (l < 400.0) b = 0.14 - 0.14 * sin(pi * (l - 364.0) / 35.0);
        else if (l < 445.0) b = 0.96 * sin(pi * (l - 395.0) / 104.0);
        else if (l < 510.0) b = 0.96 * sin(pi * (l - 377.0) / 133.0);
        else              b = 0.00;



        x1 = x - 10.;
        x2 = x + 10.;
        y1 = y + 10.;
        y2 = y - 10.;
        z1 = z - 10.;
        z2 = z + 10.;
        glColor3f(r, g+.1, b);
        glVertex3d(x1, y1, z1);
        glVertex3d(x2, y1, z1);
        glVertex3d(x2, y2, z1);
        glVertex3d(x1, y2, z1);
        glVertex3d(x1, y1, z1);
        glColor3f(r, g, b+.1);
        glVertex3d(x1 + 10., y1 + 10., z2);
        glVertex3d(x2 + 10., y1 + 10., z2);
        glVertex3d(x2 + 10., y2 + 10., z2);
        glVertex3d(x1 + 10., y2 + 10., z2);
        glVertex3d(x1 + 10., y1 + 10., z2);
        glVertex3d(x2 + 10., y1 + 10., z2);
        glColor3f(r+.1,g,b);
        glVertex3d(x2, y1, z1);
        glVertex3d(x2, y2, z1);
        glColor3f(r,b,g+.1);
        glVertex3d(x2 + 10., y2 + 10., z2);
        glVertex3d(x1 + 10., y2 + 10., z2);
        glColor3f(r,g,b+.1);
        glVertex3d(x1, y2, z1);
        glEnd();
        glFlush();
        glfwSwapBuffers(window);
        Sleep(1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    goto display;
}
