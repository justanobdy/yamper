#pragma once

#include <MainViews/State.hpp>

/// @brief Displays a playlist
class PlaylistView : public State {
public:
    void Update();

    AppState::State GetType() const;

    PlaylistView(MainView& MainView);
};