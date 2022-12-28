#include <EditSong.hpp>

#include <App.hpp>

#include <portable-file-dialogs.h>

#include <Alert.hpp>

EditSong::EditSong(SongManager::Reference Song)
    :   SongReference(Song)
{
    TempSong = SongReference.Get();
    Selector = nullptr;
}

void EditSong::Update()
{
    BeginWithID("Edit Song", true, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoDocking);

    std::string name = TempSong.GetName();
    imgui::InputText("Song Name", &name);
    TempSong.SetName(name);

    if(imgui::Button("...##1")) {
        pfd::open_file dialog = pfd::open_file("Select a song", ".", {"Audio Files", "*.mp3 *.ogg *.flac *.wav"});

        if(dialog.result().size() > 0) {
            TempSong.SetFile(dialog.result()[0]);
        }
    }

    imgui::SameLine();

    std::string path = TempSong.GetFile();
    imgui::InputText("File path", &path);
    TempSong.SetFile(path);

    if(imgui::Button("...##2")) {
        pfd::open_file dialog = pfd::open_file("Select an icon", ".", {"Image Files", "*.png *.jpg *.bmp"});

        if(dialog.result().size() > 0) {
            TempSong.SetIcon(dialog.result()[0]);
        }
    }

    imgui::SameLine();

    std::string icon = TempSong.GetIcon().GetFile();
    imgui::InputText("Icon Directory", &icon);
    TempSong.SetIcon(icon);

    if(imgui::Button("Select Artists") && Selector == nullptr) {
        Selector = App::Get().gui.AddWindow<SelectArtist>();

        Selector->onFinished.Connect([&](auto vector) {
            Selector = nullptr;

            for(const std::string& item : vector) {
                if(!Utils::FindInVector(TempSong.GetArtists(), item)) {
                    TempSong.AddArtist(item);
                }
            } 
        });

        Selector->onClosed.Connect([&] {
            Selector = nullptr;
        });
    }

    imgui::Text("Selected artists:");

    for(int i = 0; i < TempSong.GetArtists().size(); i++) {
        if(imgui::Selectable(ArtistManager::Get().GetByID(TempSong.GetArtists()[i]).GetName().c_str())) {
            TempSong.RemoveArtist(TempSong.GetArtists()[i]);
            i--;
        }
    }

    if(imgui::Button("Ok")) {
        if(TempSong.GetName() == "") {
            App::Get().gui.AddWindow<Alert>("Song has no name!");
        }else if(TempSong.GetFile() == "") {
            App::Get().gui.AddWindow<Alert>("No file selected!");
        }else {
            SongReference.Get() = TempSong;

            SongManager::Get().SerializeToFile("songs.json");

            Close();
        }
    }

    imgui::End();

    if(!IsOpen() && Selector != nullptr) {
        Selector->Close();
    }
}