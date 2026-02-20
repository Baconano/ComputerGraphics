#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width , int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // glfwWindowHint tells us what options we want to configure, where we can select the option from a large enum of possible options prefixed wiht glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE) this is for Mac OS X
    
    
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH,SCR_HEIGHT, "LearnOpenGL", NULL ,NULL);
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
    /*glfwFCreateWindow function requires the window width and height as its first two arguments.
     Third argunent allows us to create a name for the window;
     We can ignore the last 2 parameters.
    */
   
    //glad: loads all openGL function pointers
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to intialize GLAD" << std::endl;
        return -1;
    }
    // render
    while (!glfwWindowShouldClose(window)){
        // input
        processInput(window);

        //render
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events (Keys pressed/released, mouse etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    //glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
     return 0;
}
// processing all input: query GLFW wwhether relevant keys are pressed/released this frame and react accordingly

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window,true);
    }
}
// glfw: whenever the window size changed (by OS or user resize) this callbnack fuinction executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    // makes sure the viewpoint matches new window dimensions, width and height will be significantly larger than specified  on retina displays
    glViewport(0,0,width,height);
}
