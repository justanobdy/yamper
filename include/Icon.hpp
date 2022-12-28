#pragma once

#include <string>

#include <SFML/Graphics.hpp>

/// @brief Icon class
class Icon {
public:
    /// @brief Was the texture for this icon loaded?
    /// @return If the texture was loaded
    const bool& IsLoaded() const&;

    /// @brief Get the texture
    /// @return The texture
    const sf::Texture& GetTexture() const&;

    /// @brief Get the sprite
    /// @return The sprite
    const sf::Sprite& GetSprite() const&;

    /// @brief Set the Icon's file
    /// @param File The new file
    void SetFile(const std::string& File);
    /// @brief Get the Icon's file
    /// @return The file
    const std::string& GetFile() const&;

    Icon();

    Icon(const std::string& File);
private:
    /// @brief Was the texture loaded?
    bool loaded;

    /// @brief The Icon's file
    std::string directory;

    /// @brief The Icon's texture
    sf::Texture texture;

    /// @brief The Icon's sprite
    sf::Sprite sprite;
};