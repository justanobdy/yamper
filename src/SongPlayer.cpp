#include <SongPlayer.hpp>

#include <App.hpp>

SongPlayer::SongPlayer()
{
    currentSong = &emptySong;
    playlist = nullptr;
}

//void SongPlayer::PreloadSong(const Song* Song) 
//{
//    nextSong = Song;
//
//    nextMusic.openFromFile(nextSong->GetDirectory());
//}

float SongPlayer::GetCurrentPosition() const
{
    if(hasLoadedSong) {
        return currentMusic.getPlayingOffset().asSeconds();
    }else {
        return 0;
    }
}

void SongPlayer::SetCurrentPosition(const float& NewPosition)
{
    // This is a quick hack I made because in order for sf::Music::setPlayingOffset to work correctly, the sf::Music object must have been started.
    if(!IsPlaying()) {
        currentMusic.play();
        currentMusic.pause();
    }

    currentMusic.setPlayingOffset(sf::seconds(NewPosition));
}

void SongPlayer::SetCurrentSong(const Song& NewSong)
{
    currentSong = &NewSong;

    if(currentMusic.openFromFile(currentSong->GetFile())) {
        hasLoadedSong = true;
    }
}

void SongPlayer::SetCurrentPlaylist(const Playlist* NewPlaylist)
{
    playlist = NewPlaylist;
}

const Song& SongPlayer::GetCurrentSong() const&
{
    return *currentSong;
}

const bool& SongPlayer::HasSong() const&
{
    return hasLoadedSong;
}

void SongPlayer::Play() {
    if(hasLoadedSong) {
        if(GetCurrentPosition() != 0) {
            currentMusic.play();
        }else {
            float position = GetCurrentPosition();
            currentMusic.play();
            currentMusic.setPlayingOffset(sf::seconds(position));
        }
    }
}

void SongPlayer::Pause() {
    currentMusic.pause();
}

bool SongPlayer::IsPlaying() const
{
    return currentMusic.getStatus() == sf::Music::Status::Playing;
}

Playlist SongPlayer::GetCurrentPlaylist() const
{
    // If no playlist is currently selected, then return the default playlist
    if(playlist == nullptr) {
        return Playlist::GetDefaultPlaylist();
    }else {
        return *playlist;
    }
}

bool SongPlayer::IsPlaying(SongManager::Reference Song, const std::string& Playlist)
{
    if(currentSong != nullptr) {
        return *currentSong == Song.Get() && IsPlaying() && GetCurrentPlaylist().GetName() == Playlist;
    }else {
        return false;
    }
}
