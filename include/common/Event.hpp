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
#ifndef EVENT_HPP
#define EVENT_HPP

#include <functional>
#include <unordered_map>
#include <cstdint>

namespace Antutu {
    template<typename... Args>
    class Event {
    public:
        using CallbackType = std::function<void(Args...)>;                  // Define the callback type

        Event() = default;                                                  // default constructor
        ~Event() = default;                                                 // default destructor

        Event(const Event&) = delete;                                       // delete copy constructor
        Event& operator=(const Event&) = delete;                            // delete copy assignment
        Event(Event&&) = delete;                                            // delete move constructor
        Event& operator=(Event&&) = delete;                                 // delete move assignment

        /**
         * @brief Subscribe to the event with a callback function.
         * @param callback The callback function to be invoked when the event is triggered.(normal function, lambda, functor  etc.)
         * @return A unique ID for the subscription, used for unsubscription.
         */
        uint64_t subscribe(const CallbackType& callback) {
            uint64_t id = m_nextID++;
            m_listeners[id] = callback;
            return id;
        }

        /**
         * @brief Unsubscribe from the event using the unique ID.
         * @param id The unique ID of the subscription to be removed.
         * @return True if the subscription was successfully removed, false otherwise.
         */
        bool unsubscribe(uint64_t id) {
            return m_listeners.erase(id) > 0;
        }

        /**
         * @brief Clear all subscriptions from the event.
         */
        void clear() {
            m_listeners.clear();
        }



        /**
         * @brief Functor operator to invoke the event.
         * @param args The arguments to be passed to the callbacks.
         */
        void operator()(Args... args) {
            invoke(args...);
        }

    private:

        /**
         * @brief Invoke all subscribed callbacks with the provided arguments.
         * @param args The arguments to be passed to the callbacks.
         */
        void invoke(Args... args) {
            for (const auto& [id, callback] : m_listeners) {
                if (callback) {
                    callback(args...);
                }
            }
        }

    private:
        std::unordered_map<uint64_t, CallbackType> m_listeners;
        uint64_t m_nextID = 0;
    };
} // namespace Antutu

#endif // EVENT_HPP