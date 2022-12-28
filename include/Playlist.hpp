#pragma once

#include "Song.hpp"

#include <Manager.hpp>

class App;

/// @brief Playlist class
class Playlist : public Manageable {
public:
    /// @brief Add a song
    /// @param Song The song to add
    void AddSong(const SongManager::Reference& Song);
    /// @brief Remove a song based on it's index
    /// @param Index The index to remove
    void RemoveSong(int Index);
    /// @brief Swap two songs around
    /// @param FirstIndex The index of the first song
    /// @param SecondIndex The index of the second song
    void SwapSong(size_t FirstIndex, size_t SecondIndex);

    /// @brief Get a song's index
    /// @param Song The song to get the index for
    /// @return The index of the song
    unsigned int GetSongIndex(const SongManager::Reference& Song) const;

    /// @brief Get how many songs are in this playlist
    /// @return How many song are in this playlist
    unsigned int GetLength() const;

    void SerializeToFile(const std::string& File) const override;
    void DeserializeFromFile(const std::string& File) override;
    [[nodiscard]] nlohmann::json Serialize() const override;
    void Deserialize(const nlohmann::json& json) override;

    /// @brief Get a song after the given song
    /// @param ID The song to get the song after
    /// @return The song after
    SongManager::Reference GetSongAfter(const SongManager::Reference& ID) const;
    /// @brief Get a song before the given song
    /// @param ID The song to get the song before
    /// @return The song before
    SongManager::Reference GetSongBefore(const SongManager::Reference& ID) const;

    /// @brief Get a vector of all the songs
    /// @return A vector of all the songs
    const std::vector<SongManager::Reference>& GetSongs() const;

    /// @brief Get this Playlist's ID
    /// @return This Playlist's ID
    const std::string& GetID() const&;

    /// @brief Set this Playlist's name
    /// @param Name The new name
    void SetName(const std::string& Name);
    /// @brief Get this Playlist's name
    /// @return This Playlist's name
    const std::string& GetName() const&;

    /// @brief Set this Playlist's icon
    /// @param Icon The new icon
    void SetIcon(const Icon& Icon);
    /// @brief Get this Playlist's icon
    /// @return This playlist's icon
    const Icon& GetIcon() const&;

    void operator =(const Playlist& Other);

    /// @brief Get a playlist containing all songs
    /// @return A playlist containing all the songs
    static Playlist GetDefaultPlaylist();

    /// @brief Get if this playlist has a song
    /// @param Song The song to search for
    bool HasSong(SongManager::Reference Song) const;

    Playlist();
private:
    std::vector<std::string> ToString() const;

    std::vector<SongManager::Reference> songs;
    std::string name;
    Icon icon;
    std::string ID;
};

using PlaylistManager = Manager<Playlist>;