#include <Artist.hpp>

#include <Utils.hpp>

#include <nlohmann/json.hpp>

void Artist::SetName(const std::string& Name) 
{
    this->Name = Name;
}

const std::string& Artist::GetName() const&
{
    return Name;
}

const std::string& Artist::GetID() const&
{
    return ID;
}

void Artist::Deserialize(const nlohmann::json& json)
{
    Name = json["Name"];
    icon = json["Icon"];
    ID = json["ID"];
}

nlohmann::json Artist::Serialize() const
{
    nlohmann::json json;

    json["Name"] = Name;
    json["Icon"] = icon;
    json["ID"] = ID;

    return json;
}

void Artist::SerializeToFile(const std::string& File) const 
{
    Utils::WriteFile(File, Serialize().dump(4));
}

void Artist::DeserializeFromFile(const std::string& File)
{
    Deserialize(nlohmann::json::parse(Utils::ReadFile(File)));
}

void Artist::SetIcon(const std::string& Icon) 
{
    icon = Icon;
}

const std::string& Artist::GetIcon() const&
{
    return icon;
}

Artist::Artist()
    :   ID(Utils::GenerateRandomString(10))
{

}

Artist::Artist(const std::string& name, const std::string& icon)
    :   ID(Utils::GenerateRandomString(10))
{
    Name = name;
    this->icon = icon;
}