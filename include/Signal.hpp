#pragma once

#include <functional>
#include <vector>
#include <unordered_map>

/// @brief A simple class which implements signals
/// @tparam ...Args The arguments this signal passes
template <typename ...Args>
class Signal {
public:
    /// @brief Simple typedef
    typedef std::function<void(Args...)> Callback;

    /// @brief Add a signal
    /// @param Function The function to connect
    /// @return The ID of the signal
    unsigned int Connect(const Callback& Function) {
        Callbacks[lastID] = Function;

        return lastID++;
    }
 
    unsigned int operator()(const Callback& Function) {
        return Connect(Function);
    }

    /// @brief Call the signal
    /// @param ...Arguments The arguments to pass
    void Emit(Args...  Arguments) {
        for(const auto& [id, item] : Callbacks) {
            item(Arguments...);
        }
    }

    /// @brief Disconnect a signal
    /// @param Index The signal to remove
    void Disconnect(const unsigned int& Index) {
        Callbacks.erase(Index);
    }
private:
    /// @brief All the callbacks
    std::unordered_map<unsigned int, Callback> Callbacks;

    /// @brief The last ID that was used
    unsigned int lastID = 0;
};