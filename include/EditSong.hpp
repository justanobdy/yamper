#pragma once

#include <Window.hpp>

#include <Song.hpp>

#include <SelectArtist.hpp>

/// @brief Class which edits a song
class EditSong : public Window
{
public:
    EditSong(SongManager::Reference Song);

    void Update() override;
private:
    /// @brief The reference to the original song
    SongManager::Reference SongReference;

    /// @brief A temporary song object which will be copied to the original song when the editing is done
    ::Song TempSong;

    /// @brief A janky solution to the issue that the artist selector is a different window
    ///        TODO: Make SelectArtist a context menu or something
    SelectArtist* Selector;
};