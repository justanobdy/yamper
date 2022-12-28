#pragma once

#include <Window.hpp>

#include <App.hpp>

/// @brief The settings window
class SettingsWindow : public Window {
public:
    SettingsWindow();

    void Update() override;

    /// @brief Apply the settings
    void Apply();
private:
    /// @brief A copy of the settings, which will be applied when Ok is pressed
    App::Settings settings;
};