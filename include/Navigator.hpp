#pragma once

#include <Window.hpp>

#include <string>

/// @brief Side bar
class Navigator : public Window {
public:
    void Update() override;

    /// @brief Get the size of the Navigator (so that MainView can align itself)
    /// @return 
    ImVec2 GetSize();
private:
    /// @brief The last known size of the Navigator
    ImVec2 Size;
};