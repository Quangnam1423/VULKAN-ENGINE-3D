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

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include <string>
#include <vector>
#include <chrono>

#include "Event.hpp"

class GLFWWindow;

namespace Antutu {
    class Application {

    public:
        // Configuration structure for the application
        struct AppConfig {
            std::string title = "Antutu";
            uint32_t width = 1600;
            uint32_t height = 900;
            bool enableVSync = true;
            bool enableValidation = false;
            bool enableImGui = true;
        };

    public:

        // Constructor and Destructor
        Application(const AppConfig& config);
        virtual ~Application();

        Application(const Application&) = delete;
        Application& operator=(const Application&) = delete;
        
        //  Public Methods

        /**
         * @brief Run the main application loop.
         */
        void run();

        /**
         * @brief Close the application.
         */
        void close();

        /**
         * @brief Get the main application window.
         * @return Pointer to the main GLFWWindow.
         */
        inline GLFWWindow* getMainWindow() const { return m_mainWindow.get(); } 

        /**
         * @brief Check if the application is currently running.
         * @return True if running, false otherwise.
         */
        inline bool isRunning() const { return m_isRunning; }

    protected:
        // Virtual methods to be overridden by derived classes

        /** 
         * @brief Initialize the application. To be implemented by derived classes.
         */
        virtual void onInit() = 0;

        /**
         * @brief Update the application state. To be implemented by derived classes.
         * @param deltaTime Time elapsed since the last frame.
         */
        virtual void onUpdate(float deltaTime) = 0;

        /**
         * @brief Shutdown the application. To be implemented by derived classes.
         */
        virtual void onShutdown() = 0;

        /**
         * @brief Handle events. To be implemented by derived classes.
         * @param e The event to handle.
         */
        virtual void onEvent(const Event<>& e) = 0;

    protected:
        AppConfig m_config;
        bool m_isRunning;
        bool m_minimized;

        std::unique_ptr<GLFWWindow> m_mainWindow;
        std::chrono::steady_clock::time_point m_lastFrameTime;

        // future std::unique_ptr<Renderer> m_renderer;
        // future std::unique_ptr<SceneManager> m_scene;
        // future std::unique_ptr<IPCManager> m_uiManager;

    };
} // namespace Antutu

#endif // APPLICATION_HPP namespace Antutu