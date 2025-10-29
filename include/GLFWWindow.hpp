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

// =========================GLFWWindow.hpp=========================
#ifndef GLFW_WINDOW_HPP
#define GLFW_WINDOW_HPP

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <string>
#include <stdexcept>
#include <iostream>

#include "common/Event.hpp"
#include "config/config.h"

class GLFWWindow {
public:
    GLFWWindow();                                       // constructor
    ~GLFWWindow();                                      // destructor 

    GLFWWindow(const GLFWWindow&) = delete;             // delete copy constructor
    GLFWWindow& operator=(const GLFWWindow&) = delete;  // delete copy assignment
    GLFWWindow(GLFWWindow&&) = delete;                  // delete move constructor
    GLFWWindow& operator=(GLFWWindow&&) = delete;       // delete move assignment

    bool shouldClose() const;                           // check if window should close
    void pollEvents() const;                            // poll window events
    void waitForEvents() const;                         // wait for window events

    // Accessors
    GLFWwindow* getGLFWwindow() const;                  // get the GLFW window pointer
    VkExtent2D getExtent() const;                       // get the window extent

    // Events
    Antutu::Event<int, int> onFramebufferResize;        // Event for framebuffer resize
    Antutu::Event<int, int, int, int> onKey;            // Event for key press/release
    Antutu::Event<int, int, int> onMouseButton;         // Event for mouse button press/release
    Antutu::Event<double, double> onMouseMove;          // Event for mouse movement
    Antutu::Event<double, double> onMouseScroll;        // Event for mouse scroll
    Antutu::Event<double, double> onCursorPos;          // Event for cursor position
    Antutu::Event<unsigned int> onCharInput;            // Event for character input

private:
    // Static callback functions for GLFW
    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);           // framebuffer
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);   // key
    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);      // mouse button
    static void mouseMoveCallback(GLFWwindow* window, double xpos, double ypos);                // mouse move
    static void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);        // mouse scroll
    static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);                // cursor position
    static void charInputCallback(GLFWwindow* window, unsigned int codepoint);                  // char input

private:
    std::string m_title;                // Window title
    int m_width;                        // Window dimensions
    int m_height;                       // Window dimensions
    bool m_framebufferResized;          // Framebuffer resized flag
    GLFWwindow* m_window;               // GLFW window pointer
    VkInstance m_vulkanInstance;        // Vulkan instance

    static uint32_t s_windowCount;      // Static count of windows
};

#endif // GLFW_WINDOW_HPP