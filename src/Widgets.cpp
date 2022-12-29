#include <Widgets.hpp>

#include <App.hpp>

#include <EditSong.hpp>

#include <Alert.hpp>

void Widgets::StartSong(SongManager::Reference Song, Playlist& Playlist)
{
    App& app = App::Get();

    bool isCurrentSong = IsCurrentSong(Song, Playlist);

    if(!isCurrentSong) {
        app.songPlayer.SetCurrentSong(Song.Get());

        app.songPlayer.Play();
    }else {
        if(app.songPlayer.IsPlaying()) {
            app.songPlayer.Pause();
        }else {
            app.songPlayer.Play();
        }
    }

    if(Playlist.GetName() != "\0") {
        app.songPlayer.SetCurrentPlaylist(&Playlist);
    }else {
        app.songPlayer.SetCurrentPlaylist(nullptr);
    }
}

Widgets::ContextResult Widgets::AddContext(SongManager::Reference Song, Playlist& CurrentPlaylist)
{
    Widgets::ContextResult result = None;

    App& app = App::Get();

    if(imgui::BeginPopupContextItem()) {
        if(imgui::MenuItem("Delete song")) {
            result = DeleteSong;
        
            SongManager::Get().Remove(Song);
        
            SongManager::Get().SerializeToFile("songs.json");
        }
        if(imgui::MenuItem("Edit Song")) {
            app.gui.AddWindow<EditSong>(Song);
        }
        if(CurrentPlaylist.GetName() != "\0" && imgui::MenuItem("Remove from playlist")) {
            CurrentPlaylist.RemoveSong(CurrentPlaylist.GetSongIndex(Song));

            // Make sure we save the change
            PlaylistManager::Get().SerializeToFile("playlists.json");

            result = RemoveFromPlaylist;
        }if(imgui::BeginMenu("Add to playlist")) {
            for(Playlist& playlist : PlaylistManager::Get().GetAll()) {
                if(imgui::MenuItem(playlist.GetName().c_str())) {
                    // Having the same song in the playlist multiple times causes undefined behaviour, so we don't allow it
                    if(playlist.HasSong(Song)) {
                        App::Get().gui.AddWindow<Alert>(Song.GetConst().GetName() + " is already in " + playlist.GetName() + ".");
                    }else {
                        playlist.AddSong(Song);

                        // Make sure we save the change
                        PlaylistManager::Get().SerializeToFile("playlists.json");

                        result = AddToPlaylist;
                    }
                }
            }

            imgui::Separator();

            if(imgui::MenuItem(" + Add to New Playlist")) {
                Playlist newPlaylist;

                newPlaylist.SetName("New Playlist");
                newPlaylist.AddSong(Song);

                PlaylistManager::Get().Add(newPlaylist);
            }

            imgui::EndMenu();
        }
        imgui::EndPopup();
    }

    return result;
}

bool Widgets::IsCurrentSong(SongManager::Reference Song, Playlist& Playlist)
{
    App& app = App::Get();

    // The the song player playing this song?
    if(app.songPlayer.GetCurrentSong() == Song.Get()) {
        if(Playlist.GetName() == "\0" || Playlist.GetID() == app.songPlayer.GetCurrentPlaylist().GetID()) {
            return true;
        }
    }

    return false;
}

void Widgets::DisplaySong(SongManager::Reference Song, size_t Index, Playlist& CurrentPlaylist)
{
    static std::string currentSelected;

    App& app = App::Get();

    std::string currentIteration = std::to_string(Index);

    bool pressed = false;

    const float scale = imgui::GetIO().FontGlobalScale;

    const float imageSize = 100;

    Widgets::ContextResult result;

    // Only display an image if it is loaded
    if(Song.Get().GetIcon().IsLoaded()) {
        // Display the image
        imgui::Image(Song.Get().GetIcon().GetTexture(), sf::Vector2f(imageSize * scale, imageSize * scale));
        imgui::SameLine();
    }

    std::string ButtonText;

    // If the song being played is the current song, the text of the button is pause, if not, the text of the button is play
    if(imgui::Button(IsCurrentSong(Song, CurrentPlaylist) && app.songPlayer.IsPlaying() ? std::string("pause##" + currentIteration).c_str() : std::string("play##" + currentIteration).c_str())) {
        StartSong(Song, CurrentPlaylist);
    }

    // Add the context menu to the button
    AddContext(Song, CurrentPlaylist);

    imgui::SameLine();

    std::string selectableName = Song.Get().GetName() + "##" + currentIteration;
    if(imgui::Selectable(selectableName.c_str(), (selectableName == currentSelected))) {
        //StartSong(reference, CurrentPlaylist);
        currentSelected = selectableName;
    }

    // Add the context menu to the selectable
    result = AddContext(Song, CurrentPlaylist);

    // Stop the function if the song was deleted
    if (result == DeleteSong) {
        return;
    }

    // If an icon is loaded, make sure the the artist name is lined up with the icon
    if(Song.Get().GetIcon().IsLoaded())
        imgui::SetCursorPosY(imgui::GetCursorPosY() - 40 * scale);

    // Display the artist
    imgui::Indent(120 * scale);

    for(int i = 0; i < Song.Get().GetArtists().size(); i++) {
        const std::string& currentArtist = Song.Get().GetArtists()[i];
        
        if(imgui::Selectable(std::string(ArtistManager::Get().GetByID(currentArtist).GetName() + "##" + Song.Get().GetID()).c_str())) {
            app.state.state = AppState::State::SongByArtist;
            app.state.current = currentArtist;
        }
    }

    imgui::Unindent(120 * scale);

    imgui::NewLine();

    if(!imgui::IsAnyItemHovered() && imgui::IsMouseClicked(ImGuiMouseButton_Left))
        currentSelected = "";
}