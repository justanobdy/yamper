#pragma once

#include <string>

#include <Window.hpp>

#include <AppState.hpp>

#include <vector>

class State;

/// @brief Class which shows the main view
class MainView : public Window {
public:
    void Update() override;

    ~MainView();

    MainView();

    friend class State;

    /// @brief Add a state
    /// @tparam T The state to add
    template <typename T>
        requires std::is_base_of<State, T>::value
    void AddState() 
    {
        T* state = new T(*this);

        states.push_back(state);
    }

    friend class State;
private:
    /// @brief A vector containing a raw pointer of all the states
    std::vector<State*> states;

    /// @brief The ID of the current playlist
    std::string currentPlaylistID;
};