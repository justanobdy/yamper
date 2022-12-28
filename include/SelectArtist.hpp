#pragma once

#include <Window.hpp>
#include <Artist.hpp>
#include <Signal.hpp>

/// @brief Window which displays a list of all the artists, and lets the user choose artists
class SelectArtist : public Window
{
public:
    void Update() override;

    /// @brief Called when Ok is pressed
    Signal<std::vector<std::string>> onFinished;
private:
    /// @brief The current search term
    std::string search;

    /// @brief The IDs of the artists currently selected
    std::vector<std::string> artists;
};