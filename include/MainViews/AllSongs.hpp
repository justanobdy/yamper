#pragma once

#include <MainViews/State.hpp>

#include <MainView.hpp>

/// @brief Displays all the songs
class AllSongs : public State {
public:
    void Update() override;

    AppState::State GetType() const override;

    AllSongs(MainView& MainView);
};