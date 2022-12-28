#pragma once

#include <Song.hpp>
#include <SFML/Audio.hpp>

#include <Playlist.hpp>

class App;

/// @brief Class which plays audio files
class SongPlayer {
public:
    /// @brief Get the current song
    /// @return The current song
    const Song& GetCurrentSong() const&;
    /// @brief Set the current song
    /// @param NewSong The new song
    void SetCurrentSong(const Song& NewSong);

    /// @brief Get the current playlist that is being played
    /// @return The current playlist
    Playlist GetCurrentPlaylist() const;

    /// @brief Sets the current playlist
    /// @param NewPlaylist The new playlist. Set this to nullptr to use the default playlist.
    void SetCurrentPlaylist(const Playlist* NewPlaylist);

    /// @brief Get the current position (in seconds) of the song
    /// @return The current position (in seconds)
    float GetCurrentPosition() const;
    /// @brief Go to a certain position in the song
    /// @param NewPosition The new position (in seconds)
    void SetCurrentPosition(const float& NewPosition);

    /// @brief Is the song playing?
    /// @return If the song is playing
    bool IsPlaying() const;
    /// @brief Check if a certain song is playing
    /// @param Song The song to check for
    /// @param Playlist The ID of the playlist to check for
    /// @return If the song is playing
    bool IsPlaying(SongManager::Reference Song, const std::string& Playlist);

    SongPlayer();

    /// @brief Get if the song player has a song loaded
    /// @return If a song is loaded
    const bool& HasSong() const&;

    /// @brief Play the song
    void Play();

    /// @brief Pause the song
    void Pause();
private:
    /// @brief Pointer to the current song
    ///        TODO: change this to a SongManager::Reference
    const Song* currentSong;

    /// @brief TODO: Remove
    Song emptySong;

    /// @brief Music object
    sf::Music currentMusic;

    /// @brief Is a song loaded
    bool hasLoadedSong = false;

    /// @brief The current playlist
    ///        TODO: change this to a PlaylistManager::Reference
    const Playlist* playlist;
};