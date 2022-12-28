#pragma once

#include <Window.hpp>

/// @brief A class which edits a playlist
class EditPlaylist : public Window {
public:
    EditPlaylist(const std::string& playlist);

    void Update() override;

    void Apply();
private:
    /// @brief The ID of the playlist to edit
    const std::string playlist;

    /// @brief Temporary name
    std::string name;
    /// @brief Temporary icon directory
    std::string icon;
};