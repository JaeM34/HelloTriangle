#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


class HelloTriangleApplication {
public:
    GLFWwindow* window;

    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    void initWindow() {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        //Disabling resizeable
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        //Setting size of window
        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    }
    void initVulkan() {

    }
    void mainLoop() {
        while(!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
    }
    void cleanup(){
        glfwDestroyWindow(window);

        glfwTerminate();
    }
};

int main() {
    HelloTriangleApplication app;

    try{
        app.run();
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}