#pragma once

#include <Song.hpp>
#include <Manager.hpp>
#include <Playlist.hpp>

/// @brief Namepace which contains some useful widgets
namespace Widgets
{
    /// @brief Displays a song, and its artists
    /// @param Song The song to display
    /// @param Index The index of the song in the current playlist
    /// @param CurrentPlaylist The current playlist
    void DisplaySong(SongManager::Reference Song, size_t Index, Playlist& CurrentPlaylist);

    /// @brief Result from AddContext
    enum ContextResult {
        DeleteSong,
        None,
        RemoveFromPlaylist,
        AddToPlaylist
    };
    
    /// @brief Function which displays a context menu 
    ///        which contains common song functions (add/remove from playlist)
    /// @param Song The song to make a context for
    /// @param CurrentPlaylist The song's playlist
    /// @return The result of the context menu (if there was one)
    ContextResult AddContext(SongManager::Reference Song, Playlist& CurrentPlaylist);

    /// @brief Starts the given song, if it is not already playing
    ///        TODO: Move to SongPlayer
    /// @param Song The song to play
    /// @param Playlist The playlist it is in
    void StartSong(SongManager::Reference Song, Playlist& Playlist);

    /// @brief Checks if Song is the current song playing 
    ///        TODO: Move to SongPlayer
    /// @param Song The song
    /// @param Playlist The playlist its in
    /// @return If Song is the current song
    bool IsCurrentSong(SongManager::Reference Song, Playlist& Playlist);
} // namespace Widgets
