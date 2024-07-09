#include <iostream>
#include <glad/glad.h>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

int main()
{
    std::cout << "Hello, World!" << std::endl;

    if (!glfwInit())
        exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window = glfwCreateWindow(800, 600, "My Title", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {

        std::cout << "Failed to initialize GLAD" << std::endl;

        return -1;
    }
    glViewport(0, 0, 800, 600);
    int x;
    while (!glfwWindowShouldClose(window))

    {

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}