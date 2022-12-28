#pragma once

#include <string>

/// @brief Interface for serializable types
class ISerializeable {
public:
    /// @brief Serializes to the given file
    /// @param File The file to write to
    virtual void SerializeToFile(const std::string& File) const = 0;
    /// @brief Deserializes from the given file
    /// @param File The file to read from
    virtual void DeserializeFromFile(const std::string& File) = 0;
    /// @brief Serializes the class
    [[nodiscard]] virtual nlohmann::json Serialize() const = 0;
    /// @brief Deserializes the class
    /// @param json The json to deserialize from
    virtual void Deserialize(const nlohmann::json& json) = 0;
};