#include <Song.hpp>

#include <nlohmann/json.hpp>

#include <Utils.hpp>

#include <filesystem>

float Song::GetLength() const
{
    if(std::filesystem::exists(File)) {
        sf::Music Music;
    
        Music.openFromFile(File);

        return Music.getDuration().asSeconds();
    }else {
        return 0;
    }
}

const std::string& Song::GetFile() const&
{
    return File;
}

void Song::SetFile(const std::string& File)
{
    this->File = File;
}

const Icon& Song::GetIcon() const&
{
    return icon;
}

void Song::SetIcon(const Icon& Icon)
{
    this->icon = Icon;
}

void Song::AddArtist(const std::string& ID)
{
    ArtistIDs.push_back(ID);
}

const std::vector<std::string>& Song::GetArtists() const&
{
    return ArtistIDs;
}

//const std::string& Song::GetID() const&
//{
//    return ID;
//}

void Song::SetName(const std::string& Name)
{
    name = Name;
}

const std::string& Song::GetName() const&
{
    return name;
}

Song::Song()
{
    this->ID = Utils::GenerateRandomString(10);
    this->File = "";
    this->name = "";
    this->ArtistIDs = {};
}

void Song::RemoveArtist(const std::string& ID)
{
    for(int i = 0; i < ArtistIDs.size(); i++) {
        if(ArtistIDs[i] == ID) {
            ArtistIDs.erase(ArtistIDs.begin() + i);
        }
    }
}


void Song::SerializeToFile(const std::string& File) const
{
    Utils::WriteFile(File, Serialize().dump(4));
}

nlohmann::json Song::Serialize() const
{
    nlohmann::json json;

    json["ArtistIDs"] = ArtistIDs;
    json["Icon"] = icon.GetFile();
    json["File"] = File;
    json["ID"] = ID;
    json["Name"] = name;

    return json;
}

void Song::DeserializeFromFile(const std::string& File)
{
    Deserialize(Utils::ReadFile(File));
}

void Song::Deserialize(const nlohmann::json& json)
{
    for(const std::string& item : json["ArtistIDs"]) {
        ArtistIDs.push_back(item);
    }
    icon = Icon(json["Icon"]);
    File = json["File"];
    ID = json["ID"];
    name = json["Name"];
}
