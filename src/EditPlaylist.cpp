#include <EditPlaylist.hpp>

#include <App.hpp>

#include <Playlist.hpp>

#include <Manager.hpp>

EditPlaylist::EditPlaylist(const std::string& playlist)
    :   playlist(playlist)
{
    if(!PlaylistManager::Get().Exists(playlist))
        Close();
    
    const Playlist& list = PlaylistManager::Get().GetByID(playlist);

    name = list.GetName();
    icon = list.GetIcon().GetFile();
}

void EditPlaylist::Update()
{
    BeginWithID("Edit Playlist", true, ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_AlwaysAutoResize);

    imgui::InputText("Name", &name);

    //imgui::InputText("Icon", &icon);

    if(imgui::Button("Ok")) {
        Apply();

        Close();
    }

    imgui::End();
}

void EditPlaylist::Apply()
{
    if(!PlaylistManager::Get().Exists(playlist))
        Close();
    
    Playlist& list = PlaylistManager::Get().GetByID(playlist);

    list.SetName(name);
    list.SetIcon(Icon(icon));

    PlaylistManager::Get().SerializeToFile("playlists.json");
}
