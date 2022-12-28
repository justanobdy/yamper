#pragma once

#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include <GUI.hpp>

#include <SongPlayer.hpp>

#include <AppState.hpp>

#include <Playlist.hpp>
#include <Manager.hpp>

namespace imgui = ImGui;

/// @brief App class which draws the windows and handles events
class App
{
public:
    /// @brief Runs the app
    void Run();

    GUI gui;

    SongPlayer songPlayer;

    AppState state;

    /// @brief Gets the app's window
    /// @return The app's window
    sf::RenderWindow &GetWindow();

    /// @brief Struct containing all the settings
    struct Settings
    {
        /// @brief Should all the windows be automatically arranged?
        bool arrangeWindows = true;

        enum Themes
        {
            Light,
            Dark,
            Classic,
            YamperDark
        };

        /// @brief The theme of the app
        Themes theme = YamperDark;
    };

    /// @brief The settings
    Settings settings;

    /// @brief Saves the settings
    void SaveSettings();
    /// @brief Loads the settings
    void LoadSettings();

    void Setup();

    /// @brief Returns the instance of the app
    /// @return The instance of the app
    [[nodiscard]] static App& Get();
private:
    App();

    App(App&&) = delete;
    App(App&) = delete;

    /// @brief Sets up ImGui for use
    void SetupImGui();
    /// @brief Handles poll events
    void PollEvent();
    /// @brief Draws everything to the screen
    void Draw();
    /// @brief Updates everything
    void Update();

    void UpdateSettings();

    /// @brief The window
    sf::RenderWindow window;

    /// @brief Delta time clock
    sf::Clock delta;

    /// @brief TODO: Remove this
    Settings::Themes currentTheme = Settings::Themes::YamperDark;

    /// @brief Was this app initialized?
    bool initialized = false;
};

static void to_json(nlohmann::json &json, const App::Settings &settings)
{
    json = {{"ArrangeWindows", settings.arrangeWindows}, {"Theme", static_cast<int>(settings.theme)}};
}

static void from_json(const nlohmann::json &json, App::Settings &settings)
{
    settings = {json.at("ArrangeWindows"), static_cast<App::Settings::Themes>(json.at("Theme"))};
}