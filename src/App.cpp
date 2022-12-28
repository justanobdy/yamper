#include <App.hpp>

#include <filesystem>

#include <iostream>

void theme(ImGuiStyle* style) {
    style->Colors[ImGuiCol_Text]                  = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style->Colors[ImGuiCol_TextDisabled]          = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    style->Colors[ImGuiCol_WindowBg]              = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
    style->Colors[ImGuiCol_ChildBg]               = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
    style->Colors[ImGuiCol_PopupBg]               = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
    style->Colors[ImGuiCol_Border]                = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    style->Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style->Colors[ImGuiCol_FrameBg]               = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
    style->Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    style->Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    style->Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    style->Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    style->Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    style->Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    style->Colors[ImGuiCol_CheckMark]             = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
    style->Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
    style->Colors[ImGuiCol_ButtonActive]          = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
    style->Colors[ImGuiCol_Header]                = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
    style->Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
    style->Colors[ImGuiCol_HeaderActive]          = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
    style->Colors[ImGuiCol_Separator]             = style->Colors[ImGuiCol_Border];
    style->Colors[ImGuiCol_SeparatorHovered]      = ImVec4(0.41f, 0.42f, 0.44f, 1.00f);
    style->Colors[ImGuiCol_SeparatorActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    style->Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style->Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.29f, 0.30f, 0.31f, 0.67f);
    style->Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    style->Colors[ImGuiCol_Tab]                   = ImVec4(0.08f, 0.08f, 0.09f, 0.83f);
    style->Colors[ImGuiCol_TabHovered]            = ImVec4(0.33f, 0.34f, 0.36f, 0.83f);
    style->Colors[ImGuiCol_TabActive]             = ImVec4(0.23f, 0.23f, 0.24f, 1.00f);
    style->Colors[ImGuiCol_TabUnfocused]          = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
    style->Colors[ImGuiCol_TabUnfocusedActive]    = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
    style->Colors[ImGuiCol_DockingPreview]        = ImVec4(0.26f, 0.59f, 0.98f, 0.70f);
    style->Colors[ImGuiCol_DockingEmptyBg]        = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    style->Colors[ImGuiCol_PlotLines]             = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    style->Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    style->Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style->Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    style->Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    style->Colors[ImGuiCol_DragDropTarget]        = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
    style->Colors[ImGuiCol_NavHighlight]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    style->Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    style->Colors[ImGuiCol_NavWindowingDimBg]     = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    style->Colors[ImGuiCol_ModalWindowDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
    style->Colors[ImGuiCol_DockingPreview]        = ImVec4(0.667f, 0.727f, 0.797f, 0.7f);
    style->GrabRounding                           = style->FrameRounding = 4;
    style->WindowRounding = 5;

    ImVec4* colors = style->Colors;

    colors[ImGuiCol_Border]                 = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);
    colors[ImGuiCol_Button]                 = ImVec4(0.11f, 0.11f, 0.12f, 1.00f);

    colors[ImGuiCol_PopupBg]                = ImVec4(0.05f, 0.05f, 0.058f, 1.f);

    colors[ImGuiCol_WindowBg]               = ImVec4(0.09f, 0.09f, 0.10f, 1.00f);
    colors[ImGuiCol_FrameBg]                = ImVec4(0.17f, 0.17f, 0.18f, 1.00f);
    colors[ImGuiCol_Button]                 = ImVec4(0.17f, 0.17f, 0.18f, 1.00f);

    colors[ImGuiCol_TitleBg]                = ImVec4(0.10f, 0.10f, 0.11f, 1.00f);
    colors[ImGuiCol_TitleBgActive]          = ImVec4(0.13f, 0.13f, 0.14f, 1.00f);

    colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
    colors[ImGuiCol_FrameBgActive]          = ImVec4(0.15f, 0.15f, 0.16f, 1.00f);
    colors[ImGuiCol_SliderGrab]             = ImVec4(0.39f, 0.39f, 0.40f, 1.00f);
    colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.35f, 0.35f, 0.36f, 1.00f);

    style->PopupRounding = 4;

    style->WindowBorderSize = 0;
}

App::App()
{
    initialized = false;
}

void App::Setup() 
{
    initialized = true;

    if(std::filesystem::exists("artists.json")) {
        ArtistManager::Get().DeserializeFromFile("artists.json");
    }

    if(std::filesystem::exists("songs.json")) {
        SongManager::Get().DeserializeFromFile("songs.json");
    }

    if(std::filesystem::exists("playlists.json")) {
        PlaylistManager::Get().DeserializeFromFile("playlists.json");
    }
}

void App::Run() {
    SetupImGui();

    LoadSettings();

    //imgui::GetStyle().ScaleAllSizes(2);
    imgui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    window.create(sf::VideoMode(1920, 1080), "yamper");

    theme(&imgui::GetStyle());

    imgui::GetIO().Fonts->Clear();

    ImFontConfig c;

    c.OversampleH = 2;
    c.OversampleV = 2;

    imgui::GetIO().Fonts->AddFontFromFileTTF("Roboto-Medium.ttf", 40.f, &c);

    imgui::GetIO().FontGlobalScale = 0.5;

    imgui::SFML::UpdateFontTexture();

    window.setFramerateLimit(60);

    while(window.isOpen()) {
        PollEvent();

        Update();

        Draw();
    }
}

sf::RenderWindow& App::GetWindow()
{
    return window;
}

void App::SaveSettings()
{
    nlohmann::json json;

    json["Settings"] = settings;

    Utils::WriteFile("settings.json", json.dump(4));
}

void App::LoadSettings()
{
    if(!std::filesystem::exists("settings.json")) return;

    nlohmann::json json = nlohmann::json::parse(Utils::ReadFile("settings.json"));

    settings = json["Settings"];
}

void App::PollEvent() {
    sf::Event event;

    while(window.pollEvent(event)) {
        imgui::SFML::ProcessEvent(event);

        if(event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void App::Draw() {
    window.clear();

    imgui::SFML::Render(window);

    window.display();
}

void App::Update() {
    UpdateSettings();

    sf::Time deltaTime = delta.restart();

    imgui::SFML::Update(window, deltaTime);

    imgui::DockSpaceOverViewport();

    gui.Update();

    //imgui::ShowDemoWindow();

    //imgui::ShowStyleEditor();
}

void App::SetupImGui() {
    imgui::SFML::Init(window);
}

void App::UpdateSettings()
{
    if(settings.theme != currentTheme) {
        currentTheme = settings.theme;

        std::vector<std::function<void(ImGuiStyle* style)>> themes = {
            imgui::StyleColorsLight,
            imgui::StyleColorsDark,
            imgui::StyleColorsClassic,
            theme
        };

        themes.at((int)currentTheme)(&imgui::GetStyle());
    }
}

App& App::Get()
{
    static App app;
    if(!app.initialized) {
        app.Setup();
    }
    return app;
}