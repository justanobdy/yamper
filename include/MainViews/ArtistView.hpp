#pragma once

#include <MainViews/State.hpp>

/// @brief Displays all the songs by an artist
class ArtistView : public State {
public:
    void Update() override;

    AppState::State GetType() const override;

    ArtistView(MainView& MainView);
};