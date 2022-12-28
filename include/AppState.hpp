#pragma once

#include <string>

/// @brief A struct for the app's current state
struct AppState {
    enum State {
        AllPlaylists,
        AllSongs,
        Song,
        Playlist,
        SongByArtist
    };

    State state = State::AllSongs;

    std::string current = "";
};