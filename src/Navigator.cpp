#include <Navigator.hpp>

#include <App.hpp>

void Navigator::Update()
{
    int flags = 0;

    App& app = App::Get();

    if(app.settings.arrangeWindows) {
        flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDocking;
    }

    imgui::Begin("Navigator", nullptr, flags);

    if(imgui::Button("All Songs"))
    {
        app.state.state = AppState::State::AllSongs;
    }

    if(app.settings.arrangeWindows) {
        // Make the window size a 10% of the app's window's width, and 85% of the height
        imgui::SetWindowSize(ImVec2(app.GetWindow().getSize().x * 0.1, app.GetWindow().getSize().y * 0.85));

        // Make the window a little offset from the top, and a little offset to the right
        imgui::SetWindowPos(ImVec2(float(app.GetWindow().getSize().x) * 0.055f - imgui::GetWindowSize().x / 2, App::Get().GetWindow().getSize().y / 2 - imgui::GetWindowSize().y / 2));

        // Make sure the window position doesn't overlap with the MenuBar
        if(imgui::GetWindowPos().y < 55) {
            ImVec2 newPos = imgui::GetWindowPos();

            newPos.y = 55;

            imgui::SetWindowPos(newPos);
        }
    }

    imgui::Separator();

    // Display the user's playlists
    for(const Playlist& playlist : PlaylistManager::Get().GetAll()) {
        if(imgui::Button(std::string(playlist.GetName() + "##" + playlist.GetID()).c_str())) {
            app.state.state = AppState::State::Playlist;
            app.state.current = playlist.GetID();
        }
    }

    // Store the size, since MainView indents itself to make sure that the Navigator isn't on top of any songs
    Size = imgui::GetWindowSize();

    imgui::End();
}

ImVec2 Navigator::GetSize()
{
    return Size;
}