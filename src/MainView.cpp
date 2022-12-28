#include <MainView.hpp>

#include <App.hpp>

#include <MainViews/State.hpp>

#include <MainViews/AllSongs.hpp>

#include <MainViews/ArtistView.hpp>

#include <MainViews/PlaylistView.hpp>

void MainView::Update() 
{
    // If the theme is YamperDark, make the background of the main view darker than the default window color, to give some contrast

    App& app = App::Get();

    // TODO: we shouldn't hardcode this, there should be a Theme class which contains a "MainView" color
    if(app.settings.theme == App::Settings::Themes::YamperDark)
        imgui::PushStyleColor(ImGuiCol_WindowBg, sf::Color(00, 00, 00));

    imgui::Begin("Main View", nullptr);

    // The size of the Navigator window, we use this to make sure the Navigator isn't on top of any of the songs
    ImVec2 navigatorSize = {-1, -1};

    // If we automatically arrange the windows, we make sure that there is a little bit of indentation so that the Navigator isn't on top of the songs
    // We also add 2 NewLines so that it looks a little better
    if(app.settings.arrangeWindows) {
        if(app.gui.HasWindow<Navigator>()) {
            navigatorSize = app.gui.GetWindow<Navigator>().GetSize();
        }

        imgui::NewLine();
        imgui::NewLine();

        if(navigatorSize.x != -1 && navigatorSize.y != -1) {
            imgui::Indent(navigatorSize.x + 50);
        }
    }

    // Display the correct state
    for(State* state : states) {
        if(state->GetType() == app.state.state) {
            state->Update();
        }
    }

    imgui::NewLine();

    // Unindent, if we arrange the windows
    if(app.settings.arrangeWindows) {
        if(navigatorSize.x != -1 && navigatorSize.y != -1) {
            imgui::Unindent(navigatorSize.x + 50);
        }
    }

    imgui::End();

    // Remove the style color
    if(app.settings.theme == App::Settings::Themes::YamperDark)
        imgui::PopStyleColor();
}

MainView::MainView()
{
    AddState<AllSongs>();
    AddState<ArtistView>();
    AddState<PlaylistView>();
}

MainView::~MainView()
{
    for(State* state : states) {
        delete state;
    }
}