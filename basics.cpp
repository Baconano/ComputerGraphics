#include <GLFW/glfw3.h>
#include <iostream>

int main(){
    glfwInit(); // Starts the Lbrary 
    GLFWwindow* window = glfwCreateWindow(800, 600, "Test", NULL, NULL); // Creates a window from 800 pixels wide and 600 pixels height  Test is the title 

    while (!glfwWindowShouldClose(window)){// keeps the window open and listens to keyboards, mouse etc
        glfwPollEvents(); 
    }
    glfwTerminate();
}