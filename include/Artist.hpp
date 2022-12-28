#pragma once

#include <string>

#include <nlohmann/json.hpp>

#include <Manageable.hpp>

#include <Manager.hpp>

/// @brief Artist class
class Artist : public Manageable {
public:
    /// @brief Set the artist's name
    /// @param Name The new name
    void SetName(const std::string& Name);
    /// @brief Get the artist's name
    /// @return The artist's name
    const std::string& GetName() const&;

    /// @brief Set a new icon for the artist
    ///        TODO: use the Icon class instead of strings
    /// @param Icon The new Icon
    void SetIcon(const std::string& Icon);
    /// @brief Get the artist's current icon
    /// @return The current icon
    const std::string& GetIcon() const&;

    void SerializeToFile(const std::string& File) const override;
    void DeserializeFromFile(const std::string& File) override;
    [[nodiscard]] nlohmann::json Serialize() const override;
    void Deserialize(const nlohmann::json& json) override;

    friend bool operator==(const Artist& First, const Artist& Second) {
        return First.ID == Second.ID;
    }

    Artist();

    Artist(const std::string& name, const std::string& icon);

    const std::string& GetID() const&;
private:
    std::string Name;
    std::string icon;

    std::string ID;
};

using ArtistManager = Manager<Artist>;