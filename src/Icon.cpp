#include <Icon.hpp>

#include <filesystem>

const bool& Icon::IsLoaded() const&
{
    return loaded;
}

const sf::Texture& Icon::GetTexture() const&
{
    return texture;
}

const sf::Sprite& Icon::GetSprite() const&
{
    return sprite;
}

void Icon::SetFile(const std::string& File)
{
    directory = File;

    if(!std::filesystem::exists(File)) {
        // error
        return;
    }

    if(!texture.loadFromFile(File)) {
        // error
        return;
    }

    sprite.setTexture(texture);

    loaded = true;
}

const std::string& Icon::GetFile() const&
{
    return directory;
}

Icon::Icon(const std::string& File)
{
    loaded = false;
    SetFile(File);
}

Icon::Icon()
{
    loaded = false;
}