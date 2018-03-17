#include "env.hpp"
#include "Renderer.hpp"

int main(int argc, char *argv[])
{
	Env env(1280, 720);
	Renderer render;
	while (glfwWindowShouldClose(env.window) == false) {
		std::cout << "coucou" << std::endl;
		glfwSwapBuffers(env.window);
		if (glfwGetKey (env.window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(env.window, 1);
		}
        glfwPollEvents();
	}
    glfwTerminate();
	return 0;
}
