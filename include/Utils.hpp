#pragma once

#include <string>
#include <fstream>

#include <algorithm>

#include <vector>

#include <random>

/// @brief Utility functions
///        TODO: Move non-templated functions to Utils.cpp
namespace Utils
{
    /// @brief Generate a random string
    /// @param Length The length of the string
    /// @return The generated string
    static std::string GenerateRandomString(size_t Length)
    {
        std::string possible_characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        std::random_device rd;
        std::mt19937 engine(rd());
        std::uniform_int_distribution<> dist(0, possible_characters.size()-1);
        std::string ret = "";
        for(int i = 0; i < Length; i++){
            int random_index = dist(engine); //get index between 0 and possible_characters.size()-1
            ret += possible_characters[random_index];
        }
        return ret;
    }

    /// @brief Read all the contents of a file
    /// @param File The file to read from
    /// @return The file's contents
    static std::string ReadFile(const std::string& File)
    {
        std::ifstream reader(File);

        std::string string((std::istreambuf_iterator<char>(reader)),
                 std::istreambuf_iterator<char>());
        
        reader.close();

        return string;
    }

    /// @brief Find an object in a vector
    /// @tparam T The type of object
    /// @param vector The vector
    /// @param item The item to search for
    /// @return If the item was found
    template <typename T>
    static bool FindInVector(const std::vector<T>& vector, T item) {
        for(const T& Item : vector) {
            if(item == Item) {
                return true;
            }
        }

        return false;
    }

    /// @brief Converts seconds to string in this format: HH:MM:SS
    /// @param time The seconds
    /// @return The seconds in a string
    static std::string ConvertNumberToTime(const int& time) {
        std::string seconds = std::to_string(time % 60);
        std::string minutes = std::to_string((time / 60) % 60);
        std::string hours = std::to_string((time / 3600) % 60);

        std::string fullString;

        if(hours != "0") {
            if(hours.length() == 1) {
                hours.insert(0, "0");
            }
            fullString.append(hours + ":");
        }

        if(minutes.length() == 1) {
            minutes.insert(0, "0");
        }if(minutes.length() == 0) {
            minutes.append("00");
        }

        fullString.append(minutes + ":");

        if(seconds.length() == 1) {
            seconds.insert(0, "0");
        }

        fullString.append(seconds);

        return fullString;
    }

    /// @brief Convert a string to lower characters
    ///        TODO: this shouldn't use tolower
    /// @param str The string
    /// @return The string, but lower
    static std::string ToLower(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), tolower);

        return str;
    }

    /// @brief Write to a file
    /// @param file The file to write to
    /// @param contents The contents to write
    /// @param mode The openmode to use
    static void WriteFile(const std::string& file, const std::string& contents, std::ios_base::openmode mode = std::ios::out) 
    {
        std::ofstream writer(file, mode);
        writer << contents;
        writer.close();
    }
} // namespace Utils
