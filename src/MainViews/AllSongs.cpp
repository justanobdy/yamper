#include <MainViews/AllSongs.hpp>

#include <App.hpp>

#include <iostream>

#include <Widgets.hpp>

AllSongs::AllSongs(MainView& MainView)
    :   State(MainView)
{
    
}

AppState::State AllSongs::GetType() const
{
    return AppState::State::AllSongs;
}

void AllSongs::Update()
{
    Playlist playlist = Playlist::GetDefaultPlaylist();

    for(uint64_t i = 0; SongManager::Reference song : playlist.GetSongs()) {
        if(SongManager::Get().Exists(song)) {
            Playlist defaultPlaylist = Playlist::GetDefaultPlaylist();
            Widgets::DisplaySong(song, i, defaultPlaylist);
        }

        i++;
    }
}