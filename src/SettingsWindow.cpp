#include <SettingsWindow.hpp>

SettingsWindow::SettingsWindow()
{
    settings = App::Get().settings;
}

void SettingsWindow::Update() 
{
    bool open = true;
    imgui::Begin("Settings", &open);

    if(!open) {
        Close();
    }

    imgui::Checkbox("Automatically arrange windows", &settings.arrangeWindows);

    imgui::Combo("Theme", reinterpret_cast<int*>(&settings.theme), "Light\0Dark\0Classic\0Yamper Dark\0");

    if(imgui::Button("Ok")) {
        Apply();

        Close();
    }

    imgui::End();
}

void SettingsWindow::Apply()
{
    App::Get().settings = settings;

    App::Get().SaveSettings();
}