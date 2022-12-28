#pragma once

#include <imgui.h>
#include <imgui_stdlib.h>

#include <Utils.hpp>

#include <Signal.hpp>

#include <iostream>

#include <IDObject.hpp>

namespace imgui = ImGui;

class App;

/// @brief Base class for windows in yamper
class Window : public IDObject {
private:
    /// @brief Is this window open?
    bool open = true;
protected:
    /// @brief Function called when this window is close
    virtual void OnClose() {}
public:
    /// @brief Update function
    virtual void Update() {}
    
    /// @brief Get if the window is open
    /// @return If the window is open
    const bool& IsOpen() const&
    {
        return open;
    }

    /// @brief Get the window's ID
    /// @return The window's ID
    const std::string& GetID() const&
    {
        return ID;
    }

    /// @brief Call imgui::Begin, but with the ID of the window added at the end
    /// @param title The title to use
    /// @param hasClose If there is a close button
    /// @param flags The flags to use
    /// @return the value of imgui::Begin
    inline bool BeginWithID(const std::string& title, bool hasClose = false, ImGuiWindowFlags flags = ImGuiWindowFlags_None)
    {
        bool value = imgui::Begin(std::string(title + "##" + ID).c_str(), (hasClose ? &open : nullptr), flags);

        if(!open) {
            Close();
        }

        return value;
    }

    /// @brief Close the window
    void Close()
    {
        open = false;

        onClosed.Emit();

        OnClose();
    }

    /// @brief Signal emitted when this window is closed
    Signal<> onClosed;
};