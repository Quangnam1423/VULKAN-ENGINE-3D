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

// =========================GLFWWindow.hpp=========================
#ifndef GLFW_WINDOW_HPP
#define GLFW_WINDOW_HPP

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <string>
#include <stdexcept>
#include <iostream>

#include "../Core/Event.hpp"
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
    static void charInputCallback(GLFWwindow* window, unsigned int codepoint);   
    
private:
    //create vulkan instance
    void createVulkanInstance();                        // create Vulkan instance

private:
    std::string m_title;                // Window title
    int m_width;                        // Window dimensions
    int m_height;                       // Window dimensions
    bool m_framebufferResized;          // Framebuffer resized flag
    GLFWwindow* m_window;               // GLFW window pointer
    VkInstance m_vulkanInstance;        // Vulkan instance
    VkSurfaceKHR m_surface;             // Vulkan surface
    static uint32_t s_windowCount;      // Static count of windows
};

#endif // GLFW_WINDOW_HPP