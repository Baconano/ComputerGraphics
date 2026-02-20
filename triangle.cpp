#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // glfwWindowHint tells us what options we want to configure, where we can select the option from a large enum of possible options prefixed wiht glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE) this is for Mac OS X
    GLFWwindow* window = glfwCreateWindow(800,600, "LearnOpenGL", NULL ,NULL);
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    /*glfwFCreateWindow function requires the window width and height as its first two arguments.
     Third argunent allows us to create a name for the window;
     We can ignore the last 2 parameters.
    */
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to intialize GLAD" << std::endl;
        return -1;
    }
    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();
    }
    glfwTerminate();
     return 0;
}