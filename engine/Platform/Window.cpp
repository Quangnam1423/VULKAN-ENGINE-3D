/*
Antutu Vulkan Engine
Copyright (C) 2025 Quangnam1423

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

// =========================Antutu::Window.cpp===========================
#include "Window.hpp"
#include <stdexcept>

namespace Antutu 
{
// ==========================default constructor=========================
    Window::Window() 
        : Window(800, 600, "Antutu Window")
    {

    }

// ==========================parameter constructor=========================
    Window::Window(int width, int height, const std::string& title)
        : m_width(width), m_height(height), m_title(title)
    {
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // No OpenGL context
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE); // Make window resizable

        m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
        if (!m_window) {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }
    }

// ================================destructor==============================
    Window::~Window()
    {
        if (m_window) {
            glfwDestroyWindow(m_window);
            m_window = nullptr;
        }
        glfwTerminate();
    }

// =========================public methods==================================
    bool Window::ShouldClose() const
    {
        return glfwWindowShouldClose(m_window);
    }

    void Window::PollEvents() const
    {
        glfwPollEvents();
    }

    GLFWwindow* Window::GetNativeWindow() const
    {
        return m_window;
    }
}

// // =========================GLFWWindow.cpp=========================
// #include "GLFWWindow.hpp"

// // ==========================constructor=========================
// GLFWWindow::GLFWWindow()
//     : m_title(ENGINE_NAME), 
//     m_width(ENGINE_WIDTH_DEFAULT), 
//     m_height(ENGINE_HEIGHT_DEFAULT), 
//     m_window(nullptr), 
//     m_vulkanInstance(VK_NULL_HANDLE),
//     m_framebufferResized(false)
// {
//     // Initialize GLFW
//     if (!glfwInit()) {
//         throw std::runtime_error("Failed to initialize GLFW");
//     }

//     // Specify that we do not want to create an OpenGL context
//     glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

//     // Create the GLFW window
//     m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
//     if (!m_window) {
//         glfwTerminate();
//         throw std::runtime_error("Failed to create GLFW window");
//     }

//     // Set the user pointer to this instance for use in static callbacks
//     glfwSetWindowUserPointer(m_window, this);

//     // Set up GLFW callbacks
//     glfwSetFramebufferSizeCallback(m_window, framebufferResizeCallback);
//     glfwSetKeyCallback(m_window, keyCallback);
//     glfwSetMouseButtonCallback(m_window, mouseButtonCallback);
//     glfwSetCursorPosCallback(m_window, mouseMoveCallback);
//     glfwSetScrollCallback(m_window, mouseScrollCallback);
//     glfwSetCharCallback(m_window, charInputCallback);
// }

// // ==========================destructor=========================
// GLFWWindow::~GLFWWindow() {
//     vkDestroySurfaceKHR(m_vulkanInstance, m_surface, nullptr);          // Destroy Vulkan surface
//     vkDestroyInstance(m_vulkanInstance, nullptr);                       // Destroy Vulkan instance
//     if (m_window)  {                                                    // Destroy GLFW window
//         glfwDestroyWindow(m_window);
//         m_window = nullptr;
//     }
//     glfwTerminate();
// }

// // =========================public methods=========================
// bool GLFWWindow::shouldClose() const {
//     return glfwWindowShouldClose(m_window);
// }

// void GLFWWindow::pollEvents() const {
//     glfwPollEvents();
// }

// void GLFWWindow::waitForEvents() const {
//     glfwWaitEvents();
// }

// GLFWwindow* GLFWWindow::getGLFWwindow() const {
//     return m_window;
// }

// VkExtent2D GLFWWindow::getExtent() const {
//     return VkExtent2D{ static_cast<uint32_t>(m_width), static_cast<uint32_t>(m_height) };
// }

// // ========================static callback functions=========================
// void GLFWWindow::framebufferResizeCallback(GLFWwindow* window, int width, int height)
// {
//     GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
//     if (glfwWindow) {
//         glfwWindow->m_framebufferResized = true;
//         glfwWindow->m_width = width;
//         glfwWindow->m_height = height;
//         glfwWindow->onFramebufferResize.operator()(width, height);
//     }
// }

// void GLFWWindow::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
//     GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
//     if (glfwWindow) {
//         glfwWindow->onKey(key, scancode, action, mods);
//     }
// }

// void GLFWWindow::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
// {
//     GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
//     if (glfwWindow) {
//         glfwWindow->onMouseButton(button, action, mods);
//     }
// }

// void GLFWWindow::mouseMoveCallback(GLFWwindow* window, double xpos, double ypos)
// {
//     GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
//     if (glfwWindow) {
//         glfwWindow->onMouseMove(xpos, ypos);
//     }
// }

// void GLFWWindow::mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
// {
//     GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
//     if (glfwWindow) {
//         glfwWindow->onMouseScroll(xoffset, yoffset);
//     }
// }

// void GLFWWindow::cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
// {
//     GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
//     if (glfwWindow) {
//         glfwWindow->onCursorPos(xpos, ypos);
//     }
// }

// void GLFWWindow::charInputCallback(GLFWwindow* window, unsigned int codepoint)
// {
//     GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
//     if (glfwWindow) {
//         glfwWindow->onCharInput(codepoint);
//     }
// }

// void GLFWWindow::createVulkanInstance()
// {
//     VkApplicationInfo appInfo{};
//     appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
//     appInfo.pApplicationName = m_title.c_str();
//     appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
//     appInfo.pEngineName = ENGINE_NAME;
//     appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
//     appInfo.apiVersion = VK_API_VERSION_1_0;

//     VkInstanceCreateInfo createInfo{};
//     createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
//     createInfo.pApplicationInfo = &appInfo;

//     uint32_t glfwExtensionCount = 0;
//     const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
//     createInfo.enabledExtensionCount = glfwExtensionCount;
//     createInfo.ppEnabledExtensionNames = glfwExtensions;

//     if (vkCreateInstance(&createInfo, nullptr, &m_vulkanInstance) != VK_SUCCESS) {
//         throw std::runtime_error("Failed to create Vulkan instance!");
//     }

//     //VkSurfaceKHR
// }