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


#ifndef ANTUTU_WINDOW_HPP
#define ANTUTU_WINDOW_HPP

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>
#include <string>

namespace Antutu {
    

    // ==========Window Class Declaration==================
    class Window {
    public:
        Window();                                                   // constructor
        Window(int width, int height, const std::string& title);    // parameterized constructor
        ~Window();                                                  // destructor 

        Window(const Window&) = delete;                             // delete copy constructor
        Window& operator=(const Window&) = delete;                  // delete copy assignment
        Window(Window&&) = delete;                                  // delete move constructor
        Window& operator=(Window&&) = delete;                       // delete move assignment

        bool ShouldClose() const;                               // check if window should close
        void PollEvents() const;                                // poll window events
        GLFWwindow* GetNativeWindow() const;                      // get the GLFW window pointer

        // getter and setter for width and height
        inline int GetWidth() const { return m_width; }
        inline int GetHeight() const { return m_height; }
        inline void SetWidth(int width) { m_width = width; }
        inline void SetHeight(int height) { m_height = height; }
    private:
        GLFWwindow* m_window;               // GLFW window pointer
        int m_width;
        int m_height;
        std::string m_title;
    };
}

#endif // ANTUTU_WINDOW_HPP



// #ifndef GLFW_WINDOW_HPP
// #define GLFW_WINDOW_HPP

// // Include Vulkan and GLFW headers instead of OpenGL
// #define GLFW_INCLUDE_VULKAN

// #include <vulkan/vulkan.h>
// #include <GLFW/glfw3.h>
// #include <string>
// #include <stdexcept>
// #include <iostream>

// #include "../Core/Signal.hpp"
// #include "../config/config.h"

// class GLFWWindow {
// public:
//     GLFWWindow();                                       // constructor
//     ~GLFWWindow();                                      // destructor 

//     GLFWWindow(const GLFWWindow&) = delete;             // delete copy constructor
//     GLFWWindow& operator=(const GLFWWindow&) = delete;  // delete copy assignment
//     GLFWWindow(GLFWWindow&&) = delete;                  // delete move constructor
//     GLFWWindow& operator=(GLFWWindow&&) = delete;       // delete move assignment

//     bool shouldClose() const;                           // check if window should close
//     void pollEvents() const;                            // poll window events
//     void waitForEvents() const;                         // wait for window events

//     // Accessors
//     GLFWwindow* getGLFWwindow() const;                  // get the GLFW window pointer
//     VkExtent2D getExtent() const;                       // get the window extent

//     // Events
//     Antutu::Signal<int, int> onFramebufferResize;        // Event for framebuffer resize
//     Antutu::Signal<int, int, int, int> onKey;            // Event for key press/release
//     Antutu::Signal<int, int, int> onMouseButton;         // Event for mouse button press/release
//     Antutu::Signal<double, double> onMouseMove;          // Event for mouse movement
//     Antutu::Signal<double, double> onMouseScroll;        // Event for mouse scroll
//     Antutu::Signal<double, double> onCursorPos;          // Event for cursor position
//     Antutu::Signal<unsigned int> onCharInput;            // Event for character input

// private:
//     // Static callback functions for GLFW
//     static void framebufferResizeCallback(GLFWwindow* window, int width, int height);           // framebuffer
//     static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);   // key
//     static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);      // mouse button
//     static void mouseMoveCallback(GLFWwindow* window, double xpos, double ypos);                // mouse move
//     static void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);        // mouse scroll
//     static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);                // cursor position
//     static void charInputCallback(GLFWwindow* window, unsigned int codepoint);   
    
// private:
//     //create vulkan instance
//     void createVulkanInstance();                        // create Vulkan instance

// private:
//     std::string m_title;                // Window title
//     int m_width;                        // Window dimensions
//     int m_height;                       // Window dimensions
//     bool m_framebufferResized;          // Framebuffer resized flag
//     GLFWwindow* m_window;               // GLFW window pointer
//     VkInstance m_vulkanInstance;        // Vulkan instance
//     VkSurfaceKHR m_surface;             // Vulkan surface
//     static uint32_t s_windowCount;      // Static count of windows
// };

// #endif // GLFW_WINDOW_HPP