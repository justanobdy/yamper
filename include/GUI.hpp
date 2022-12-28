#pragma once

#include <typeinfo>

#include <concepts>

#include <vector>

#include <imgui.h>

#include "Window.hpp"

#include <Navigator.hpp>

#include <memory>

/// @brief Class which handles GUI-related stuff
class GUI {
public:
    /// @brief Add a window
    /// @tparam T The type of window to add (must be Window derived)
    /// @tparam ...Args The types of arguments to pass to the constructor
    /// @param ...Arguments The arguments to pass to the constructor
    /// @return 
    template <typename T, typename ...Args>
        requires std::is_base_of<Window, T>::value
    T* AddWindow(Args... Arguments) {
        Windows.push_back(new T(Arguments...));

        return dynamic_cast<T*>(Windows.back());
    }

    /// @brief Removes a window
    /// @tparam T The type of window to remove (removes the first one found)
    template <typename T>
        requires std::is_base_of<Window, T>::value
    void RemoveWindow() {
        for(int i = 0; i < Windows.size(); i++) {
            if(typeid(*Windows[i]) == typeid(T)) {
                Windows.erase(Windows.begin() + i);
                break;
            }
        }
    }

    /// @brief Returns a window
    /// @tparam T The type of window
    /// @return The first window of that type found
    template <typename T>
        requires std::is_base_of<Window, T>::value
    T& GetWindow() {
        for(int i = 0; i < Windows.size(); i++) {
            if(typeid(T) == typeid(*Windows[i])) {
                return *(T*)Windows[i];
            }
        }
    }

    /// @brief Checks if a window exists
    /// @tparam T The type of window
    /// @return If the window exists or not
    template <typename T>
        requires std::is_base_of<Window, T>::value
    bool HasWindow() {
        for(const Window* window : Windows) {
            if(typeid(T) == typeid(*window)) {
                return true;
            }
        }

        return false;
    }

    /// @brief Update the GUI
    void Update();

    GUI();
private:
    /// @brief A vector which contains a raw pointer to the all the currently active windows (since these are raw heap-allocated pointers, they must be freed at deletion)
    std::vector<Window*> Windows;

    /// @brief Returns a window's index the vector from an ID
    /// @param ID The ID to search for
    /// @return The ID
    int GetIndexByID(const std::string& ID);
};