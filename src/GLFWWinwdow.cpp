
/*
MIT License

Copyright (c) 2025 Quangnam1423

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


// =========================GLFWWindow.cpp=========================
#include "GLFWWindow.hpp"

GLFWWindow::GLFWWindow()
    : m_title(ENGINE_NAME), 
    m_width(ENGINE_WIDTH_DEFAULT), 
    m_height(ENGINE_HEIGHT_DEFAULT), 
    m_window(nullptr), 
    m_vulkanInstance(VK_NULL_HANDLE),
    m_framebufferResized(false)
{
    // Initialize GLFW
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    // Specify that we do not want to create an OpenGL context
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // Create the GLFW window
    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
    if (!m_window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    // Set the user pointer to this instance for use in static callbacks
    glfwSetWindowUserPointer(m_window, this);

    // Set up GLFW callbacks
    glfwSetFramebufferSizeCallback(m_window, framebufferResizeCallback);
    glfwSetKeyCallback(m_window, keyCallback);
    glfwSetMouseButtonCallback(m_window, mouseButtonCallback);
    glfwSetCursorPosCallback(m_window, mouseMoveCallback);
    glfwSetScrollCallback(m_window, mouseScrollCallback);
    glfwSetCharCallback(m_window, charInputCallback);
}

GLFWWindow::~GLFWWindow() {
    if (m_window) {
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }
    glfwTerminate();
}

bool GLFWWindow::shouldClose() const {
    return glfwWindowShouldClose(m_window);
}

void GLFWWindow::pollEvents() const {
    glfwPollEvents();
}

void GLFWWindow::waitForEvents() const {
    glfwWaitEvents();
}

GLFWwindow* GLFWWindow::getGLFWwindow() const {
    return m_window;
}

VkExtent2D GLFWWindow::getExtent() const {
    return VkExtent2D{ static_cast<uint32_t>(m_width), static_cast<uint32_t>(m_height) };
}

// Static callback implementations
void GLFWWindow::framebufferResizeCallback(GLFWwindow* window, int width, int height)
{
    GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
    if (glfwWindow) {
        glfwWindow->m_framebufferResized = true;
        glfwWindow->m_width = width;
        glfwWindow->m_height = height;
        glfwWindow->onFramebufferResize.operator()(width, height);
    }
}

void GLFWWindow::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
    if (glfwWindow) {
        glfwWindow->onKey(key, scancode, action, mods);
    }
}

void GLFWWindow::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
    if (glfwWindow) {
        glfwWindow->onMouseButton(button, action, mods);
    }
}

void GLFWWindow::mouseMoveCallback(GLFWwindow* window, double xpos, double ypos)
{
    GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
    if (glfwWindow) {
        glfwWindow->onMouseMove(xpos, ypos);
    }
}

void GLFWWindow::mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
    if (glfwWindow) {
        glfwWindow->onMouseScroll(xoffset, yoffset);
    }
}

void GLFWWindow::cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
    if (glfwWindow) {
        glfwWindow->onCursorPos(xpos, ypos);
    }
}

void GLFWWindow::charInputCallback(GLFWwindow* window, unsigned int codepoint)
{
    GLFWWindow* glfwWindow = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(window));
    if (glfwWindow) {
        glfwWindow->onCharInput(codepoint);
    }
}