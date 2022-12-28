#pragma once

#include <Artist.hpp>
#include <Window.hpp>

/// @brief Window which adds an artist
///        TODO: Remove this
class AddArtist : public Window
{
public:
    void Update() override;

    using Window::Window;
private:
    std::string name;
    std::string icon;
};