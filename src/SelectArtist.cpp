#include <SelectArtist.hpp>

#include <App.hpp>

void SelectArtist::Update()
{
    BeginWithID("Select Artist", true, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoDocking);

    if(imgui::Button("Ok")) {
        Close();

        if(artists.size() > 0) {
            onFinished.Emit(artists);
        }
    }

    std::string selectedArtists;

    for(const std::string& artist : artists) {
        if(selectedArtists.size() > 0) {
            selectedArtists.append(", ");
        }

        selectedArtists.append(ArtistManager::Get().GetByID(artist).GetName());
    }

    selectedArtists.insert(0, "Selected artists: ");

    imgui::Text(selectedArtists.c_str());

    imgui::InputText("##search", &search);

    imgui::BeginChildFrame(imgui::GetID("Artists"), ImVec2(0, ImGui::GetFrameHeightWithSpacing() * 5));

    for(const Artist& artist : ArtistManager::Get().GetAll()) {
        if(Utils::ToLower(artist.GetName()).find(Utils::ToLower(search)) != std::string::npos) {
            if(imgui::Selectable(artist.GetName().c_str()) && !Utils::FindInVector(artists, artist.GetID())) {
                artists.push_back(artist.GetID());
            }
        }
    }

    imgui::EndChild();

    imgui::End();
}
