#include <Player.hpp>

#include <imgui_internal.h>

// From: https://stackoverflow.com/a/70073137
void TextCentered(std::string text)
{
    float win_width = ImGui::GetWindowSize().x;
    float text_width = ImGui::CalcTextSize(text.c_str()).x;

    float text_indentation = (win_width - text_width) * 0.5f;

    float min_indentation = 20.0f;
    if (text_indentation <= min_indentation)
    {
        text_indentation = min_indentation;
    }

    ImGui::SameLine(text_indentation);
    ImGui::PushTextWrapPos(win_width - text_indentation);
    ImGui::TextWrapped(text.c_str());
    ImGui::PopTextWrapPos();
}

void Player::Update()
{
    /*
        Warning:

            This code contains a lot of weird imgui stuff, to get everything to position right.

            You've been warned
    */

    App& app = App::Get();

    int flags = ImGuiWindowFlags_NoTitleBar;

    if (app.settings.arrangeWindows)
    {
        flags |= ImGuiWindowFlags_NoMove | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoDocking;
    }

    imgui::Begin("Player", nullptr, flags);

    // imgui::SetWindowSize(ImVec2(app.GetWindow().getSize().x * 0.45, app.GetWindow().getSize().y * 0.1 < 95 ? 95 : app.GetWindow().getSize().y * 0.1));

    // Display the song name, if there is a song
    if (app.songPlayer.HasSong())
    {
        TextCentered(app.songPlayer.GetCurrentSong().GetName());
    }
    else
    {
        imgui::NewLine();
    }

    // If there is no song playing, then disable everything here
    imgui::BeginDisabled(!app.songPlayer.HasSong());

    /*
        Section: Control buttons (Back, Play/Pause, Forward)
    */

    // Size of the buttons
    float ButtonSizeX = 100;
    float ButtonSizeY = 50;

    float scale = imgui::GetIO().FontGlobalScale;

    ImVec2 ActualButtonSize = ImVec2(ButtonSizeX * scale, ButtonSizeY * scale);

    // The amount of control buttons
    float buttonAmount = 3;

    // Move the imgui cursor to the appropriate position to have the buttons centered
    imgui::SetCursorPosX(imgui::GetWindowSize().x / 2 - ((ActualButtonSize.x * (buttonAmount / 2) /* Use half the button amount so that the buttons are centered */) + imgui::GetStyle().ItemSpacing.x));

    if (imgui::Button("Back", ActualButtonSize))
    {
        // Make sure there is another song before this one

        SongManager::Reference CurrentSong = SongManager::Get().GetReferenceByID(app.songPlayer.GetCurrentSong().GetID());
        SongManager::Reference lastSong = app.songPlayer.GetCurrentPlaylist().GetSongBefore(CurrentSong);

        if (lastSong.Exists())
        {
            app.songPlayer.SetCurrentSong(lastSong.Get());
            app.songPlayer.Play();
        }
    }
    imgui::SameLine();
    if (imgui::Button("playpause", ActualButtonSize))
    {
        if (app.songPlayer.HasSong())
        {
            if (!app.songPlayer.IsPlaying())
            {
                app.songPlayer.Play();
            }
            else
            {
                app.songPlayer.Pause();
            }
        }
    }
    imgui::SameLine();
    if (imgui::Button("Forward", ActualButtonSize))
    {
        // Makes sure there is another song after this one

        SongManager::Reference CurrentSong = SongManager::Get().GetReferenceByID(app.songPlayer.GetCurrentSong().GetID());
        SongManager::Reference nextSong = app.songPlayer.GetCurrentPlaylist().GetSongAfter(CurrentSong);

        if (nextSong.Exists())
        {
            app.songPlayer.SetCurrentSong(nextSong.Get());
            app.songPlayer.Play();
        }
    }

    /*
        Section: Time slider
    */

    if (app.settings.arrangeWindows)
    {
        imgui::PushItemWidth(app.GetWindow().getSize().x / 3);
    }
    else
    {
        // Make sure the slider is centered if the window is not automatically arranged
        imgui::PushItemWidth(imgui::GetWindowSize().x / 2);
        imgui::SetCursorPosX(imgui::GetWindowSize().x - imgui::CalcItemWidth() * 1.5);
    }

    // The slider itself
    imgui::SliderFloat("##Time", &currentTime, 0, app.songPlayer.GetCurrentSong().GetLength(), Utils::ConvertNumberToTime(currentTime).c_str());

    if (imgui::IsItemDeactivatedAfterEdit() && imgui::IsMouseReleased(ImGuiMouseButton_Left))
    {
        app.songPlayer.SetCurrentPosition(currentTime);
    }

    if(!imgui::IsItemActive()) {
        currentTime = app.songPlayer.GetCurrentPosition();
    }

    imgui::PopItemWidth();

    // Make sure nothing else is disabled
    imgui::EndDisabled();

    // We only set the window's position retroactively if the windows are automatically arranged, since the window automatically resizes to fit it's contents
    if (app.settings.arrangeWindows)
    {
        imgui::SetWindowPos(ImVec2(app.GetWindow().getSize().x / 2 - imgui::GetWindowSize().x / 2, app.GetWindow().getSize().y - imgui::GetWindowSize().y - 30));
    }

    imgui::End();
}