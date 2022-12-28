#include <MainViews/PlaylistView.hpp>

#include <App.hpp>

#include <EditPlaylist.hpp>

#include <Widgets.hpp>

AppState::State PlaylistView::GetType() const
{
    return AppState::State::Playlist;
}

void PlaylistView::Update()
{
    imgui::SetWindowFontScale(2);

    if(imgui::Selectable(PlaylistManager::Get().GetByID(App::Get().state.current).GetName().c_str())) {
        App::Get().gui.AddWindow<EditPlaylist>(App::Get().state.current);
    }

    imgui::SetWindowFontScale(1);

    imgui::NewLine();
    imgui::Separator();
    imgui::NewLine();

    for(uint64_t i; SongManager::Reference song : PlaylistManager::Get().GetByID(App::Get().state.current).GetSongs()) {
        if(song.Exists()) {
            Widgets::DisplaySong(song, i, PlaylistManager::Get().GetByID(App::Get().state.current));
        }

        i++;
    }
}

PlaylistView::PlaylistView(MainView& MainView)
    :   State(MainView)
    {}