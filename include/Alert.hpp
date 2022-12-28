#pragma once

#include <Window.hpp>

/// @brief Class which displays a simple message
class Alert : public Window 
{
public:
    void Update() override;

    Alert(const std::string& Alert = "");
private:
    std::string text;
};