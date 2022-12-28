#include <AddArtist.hpp>

#include <portable-file-dialogs.h>

#include <App.hpp>

#include <Alert.hpp>

void AddArtist::Update()
{
    BeginWithID("Add Artist", true, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoDocking);

    imgui::InputText("Name", &name);

    if(imgui::Button("...")) {
        pfd::open_file dialog = pfd::open_file("Select Icon", ".");

        if(dialog.result().size() > 0) {
            icon = dialog.result()[0];
        }
    }

    imgui::SameLine();

    imgui::InputText("Icon", &icon);

    if(imgui::Button("Ok")) {
        bool exists = false;

        for(ArtistManager::Reference ref : ArtistManager::Get().GetReferences()) {
            if(ref.Get().GetName() == name) {
                exists = true;
            }
        }

        if(exists) {
            App::Get().gui.AddWindow<Alert>("Artist already exists!");
        }
        else if(name == "") {
            App::Get().gui.AddWindow<Alert>("No name given!");
        }
        else {
            ArtistManager::Get().Add(Artist(name, icon));
            Close();
        }
    }

    imgui::End();
}
