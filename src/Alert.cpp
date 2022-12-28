#include <Alert.hpp>

Alert::Alert(const std::string& Alert)
{
    text = Alert;
}

void Alert::Update()
{
    BeginWithID("Alert", true, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoDocking);

    imgui::Text(text.c_str());

    if(imgui::Button("Ok")) {
        Close();
    }

    imgui::End();
}
