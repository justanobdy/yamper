#include <GUI.hpp>

#include <AddArtist.hpp>
#include <SettingsWindow.hpp>

#include <App.hpp>

#include <portable-file-dialogs.h>

#include <EditSong.hpp>

void GUI::Update() {
    imgui::BeginMainMenuBar();

    if(imgui::BeginMenu("File")) {
        if(imgui::MenuItem("Add Song..")) {
            Song newSong;

            newSong.SetName("New Song");

            SongManager::Get().Add(newSong);

            AddWindow<EditSong>(SongManager::Get().GetReferences().back());
        }if(imgui::MenuItem("Add Songs..")) {
            pfd::open_file result = pfd::open_file("title", ".", {"Audio Files", "*.mp3 *.wav *.ogg *.flac"}, true);

            for(const std::string& song : result.result()) {
                Song newSong;

                newSong.SetFile(song);

                std::string name = std::filesystem::path(song).stem().string();
                newSong.SetName(name);

                SongManager::Get().Add(newSong);

                SongManager::Get().SerializeToFile("songs.json");
            }
        }if(imgui::MenuItem("Add Artist..")) {
            AddWindow<AddArtist>();
        }if(imgui::MenuItem("Add Playlist..")) {
            Playlist newPlaylist;

            newPlaylist.SetName("New Playlist");
            newPlaylist.SetIcon(Icon(""));

            

            PlaylistManager::Get().Add(newPlaylist);
        }

        imgui::EndMenu();
    }

    if(imgui::BeginMenu("Tools")) {
        if(imgui::MenuItem("Settings")) {
            AddWindow<SettingsWindow>();
        }

        imgui::EndMenu();
    }

    imgui::EndMainMenuBar();

    for(Window* Window : Windows) {
        if(!Window->IsOpen()) {
            int index = GetIndexByID(Window->GetID());

            Windows.erase(Windows.begin() + index);

            continue;
        }

        Window->Update();
    }
}

GUI::GUI()
{
    AddWindow<Navigator>();
}

int GUI::GetIndexByID(const std::string& ID) 
{
    for(int i = 0; i < Windows.size(); i++) {
        if(Windows[i]->GetID() == ID) {
            return i;
        }
    }

    return -1;
}