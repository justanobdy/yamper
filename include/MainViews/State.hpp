#pragma once

#include <MainView.hpp>

#include <vector>

/// @brief Base class for MainView states
class State {
public:
    /// @brief Update function
    virtual void Update() {};

    /// @brief Get the State which this implements
    /// @return The State this implements
    virtual AppState::State GetType() const = 0;

    State(MainView& MainView);
protected:
    /// @brief The MainView object which owns this
    MainView& mainView;
};
