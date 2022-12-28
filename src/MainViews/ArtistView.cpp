#include <MainViews/ArtistView.hpp>

#include <App.hpp>

#include <Widgets.hpp>

void ArtistView::Update()
{
    App& app = App::Get();

    if(!ArtistManager::Get().Exists(app.state.current)) return;

    Artist& artist = ArtistManager::Get().GetByID(app.state.current);

    imgui::SetWindowFontScale(2);

    imgui::Text(artist.GetName().c_str());

    imgui::SetWindowFontScale(1);

    imgui::NewLine();

    imgui::Separator();

    imgui::NewLine();

    for(uint64_t i; SongManager::Reference ref : SongManager::Get().GetReferences()) {
        if(Utils::FindInVector(ref.Get().GetArtists(), artist.GetID())) {
            Playlist defaultPlaylist = Playlist::GetDefaultPlaylist();
            Widgets::DisplaySong(ref, i, defaultPlaylist);
        
            i++;
        }
    }
}

AppState::State ArtistView::GetType() const
{
    return AppState::SongByArtist;
}

ArtistView::ArtistView(MainView& MainView)
    :   State(MainView)
{

}