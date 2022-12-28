#pragma once

#include <string>

#include <Utils.hpp>

/// @brief Base class for objects which have an ID
class IDObject {
public:
    /// @brief Get the ID
    /// @return The ID
    std::string GetID() const
    {
        return ID;
    }

    /// @brief Reroll the ID
    void RerollID()
    {
        ID = Utils::GenerateRandomString(10);
    }

    IDObject()
    {
        RerollID();
    }
protected:
    /// @brief The ID
    std::string ID;
};