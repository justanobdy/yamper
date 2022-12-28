#include <Playlist.hpp>

#include <App.hpp>

void Playlist::Deserialize(const nlohmann::json& json)
{
    for(const std::string& item : json["Songs"]) {
        songs.push_back(SongManager::Get().GetReferenceByID(item));
    }
    name = json["Name"];
    icon = Icon(json["Icon"]);
    ID = json["ID"];
}


nlohmann::json Playlist::Serialize() const 
{
    nlohmann::json json;

    json["Songs"] = ToString();
    json["Name"] = name;
    json["Icon"] = icon.GetFile();
    json["ID"] = ID;

    return json;
}

void Playlist::SerializeToFile(const std::string& File) const 
{
    Utils::WriteFile(File, Serialize().dump(4));
}

void Playlist::DeserializeFromFile(const std::string& File)
{
    Deserialize(nlohmann::json::parse(Utils::ReadFile(File)));
}

void Playlist::AddSong(const SongManager::Reference& Song)
{
    songs.push_back(Song);
}

void Playlist::RemoveSong(int Index)
{
    songs.erase(songs.begin() + Index);
}

unsigned int Playlist::GetSongIndex(const SongManager::Reference& Song) const
{
    for(int i = 0; i < songs.size(); i++) {
        if(songs[i] == Song) {
            return i;
        }
    }
}

unsigned int Playlist::GetLength() const
{
    return songs.size();
}

SongManager::Reference Playlist::GetSongAfter(const SongManager::Reference& ID) const
{
    if(GetSongIndex(ID) + 1 < songs.size()) {
        return GetSongs().at(GetSongIndex(ID) + 1);
    }else {
        return SongManager::Reference::GetNull();
    }
}

SongManager::Reference Playlist::GetSongBefore(const SongManager::Reference& ID) const
{
    if(GetSongIndex(ID) > 0) {
        return GetSongs().at(GetSongIndex(ID) - 1);
    }else {
        return SongManager::Reference::GetNull();
    }
}

const std::vector<SongManager::Reference>& Playlist::GetSongs() const
{
    return songs;
}

const std::string& Playlist::GetID() const&
{
    return ID;
}

void Playlist::SetName(const std::string& Name)
{
    name = Name;
}

const std::string& Playlist::GetName() const&
{
    return name;
}

void Playlist::SetIcon(const Icon& Icon)
{
    icon = Icon;
}

const Icon& Playlist::GetIcon() const&
{
    return icon;
}

void Playlist::SwapSong(size_t FirstIndex, size_t SecondIndex)
{
    /*SongManager::Reference temp = songs[FirstIndex];

    songs.erase(songs.begin() + FirstIndex);

    songs.insert(songs.begin() + Index, temp);*/
}

std::vector<std::string> Playlist::ToString() const
{   
    std::vector<std::string> vector;

    for(const SongManager::Reference& song : songs) {
        vector.push_back(song.GetConst().GetID());
    }

    return vector;
}

void Playlist::operator=(const Playlist& Other)
{
    songs = Other.songs;
    name = Other.name;
    icon = Other.icon;
    ID = Other.ID;
}

Playlist::Playlist()

{
}


Playlist Playlist::GetDefaultPlaylist()
{
    Playlist defaultPlaylist;

    defaultPlaylist.SetName("\0");

    for(SongManager::Reference ref : SongManager::Get().GetReferences()) {
        defaultPlaylist.AddSong(ref);
    }

    return defaultPlaylist;
}


bool Playlist::HasSong(SongManager::Reference Song) const
{
    return Utils::FindInVector(songs, Song);
}