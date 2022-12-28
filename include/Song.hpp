#pragma once

#include <string>

#include "Artist.hpp"

#include <SFML/Audio.hpp>

#include <nlohmann/json.hpp>

#include <SFML/Graphics.hpp>

#include <Icon.hpp>

#include <Manageable.hpp>

#include <Manager.hpp>

/// @brief Song class
class Song : public Manageable {
public:
    bool operator==(const Song& other) {
        return other.ID == ID;
    }

    /// @brief Add an artist
    /// @param ID The ID of the artist to add
    void AddArtist(const std::string& ID);
    /// @brief Get all the artists
    /// @return The IDs of all the artists
    const std::vector<std::string>& GetArtists() const&;
    /// @brief Remove an artist
    /// @param ID The artist to remove
    void RemoveArtist(const std::string& ID);

    /// @brief Set the icon
    /// @param Icon The icon
    void SetIcon(const Icon& Icon);
    /// @brief Get the icon
    /// @return The icon
    const Icon& GetIcon() const&;

    /// @brief Set the file
    /// @param File The file
    void SetFile(const std::string& File);
    /// @brief Get the current file
    /// @return The current file
    const std::string& GetFile() const&;

    void SerializeToFile(const std::string& File) const override;
    void DeserializeFromFile(const std::string& File) override;
    [[nodiscard]] nlohmann::json Serialize() const override;
    void Deserialize(const nlohmann::json& json) override;

    /// @brief Get length (in seconds) of the song
    /// @return Length (in seconds)
    float GetLength() const;

    /// @brief Set the song's name
    /// @param Name The name of the song
    void SetName(const std::string& Name);
    /// @brief Get the song's name
    /// @return The name of the song
    const std::string& GetName() const&;

    Song();
private:
    /// @brief A list of all the artists
    std::vector<std::string> ArtistIDs;

    /// @brief The song's icon
    Icon icon;

    /// @brief The song's file
    std::string File;

    /// @brief The song's name
    std::string name;
};

using SongManager = Manager<Song>;