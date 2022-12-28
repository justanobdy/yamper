#pragma once

#include <Window.hpp>

#include <App.hpp>

#include <iostream>

/// @brief Window which displays all the song controls
class Player : public Window {
public:
    void Update() override;
private:
    /// @brief The current time of the song slider
    float currentTime;
};