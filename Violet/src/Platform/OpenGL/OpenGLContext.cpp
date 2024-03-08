#include "vlpch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Violet {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle){
		VL_CORE_ASSERT(windowHandle, "Window Handle is null!");
	}
	void OpenGLContext::Init() {
		glfwMakeContextCurrent(m_WindowHandle);

		// GLAD���ʼ��
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		VL_CORE_ASSERT(status, "Faild to initialize Glad!");

		VL_CORE_INFO("OpenGL Info: ");
		VL_CORE_INFO(" Vendor: {0} ", glGetString(GL_VENDOR));
		VL_CORE_INFO(" Renderer : {0} ", glGetString(GL_RENDERER));
		VL_CORE_INFO(" Version: {0} ", glGetString(GL_VERSION));
	}
	void OpenGLContext::SwapBuffers() {
		glfwSwapBuffers(m_WindowHandle);
	}


}