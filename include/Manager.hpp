#pragma once

#include <concepts>
#include <nlohmann/json.hpp>

#include <Utils.hpp>

#include <Manageable.hpp>

/// @brief A class which provides functions for managing items, which have an ID and are serializeable. Each item *must* have its own ID.
///        TODO: Move non-template functions to Manager.cpp
/// @tparam T The type to manage
template <typename T>
    requires std::is_base_of<Manageable, T>::value
class Manager : public ISerializeable {
public:
    /// @brief A class which holds a reference to the managed object.
    ///        This class can check if the object still exists, 
    ///        and return a reference to the object.
    class Reference {
    public:
        /// @brief Create a Reference from an ID
        /// @param ID The ID to create a reference for
        explicit Reference(const std::string& ID)
            :   RefID(ID)
        {}

        /// @brief Create a Reference from an IDObject
        /// @param Object The IDObject to create a reference for
        explicit Reference(const IDObject& Object)
            :   RefID(Object.GetID())
        {}

        /// @brief Get a reference to the object this points to
        /// @return A reference to the object this points to
        T& Get()
        {
            return Manager<T>::Get().GetByID(RefID);
        }

        /// @brief Const version of Get
        /// @return A reference to the object this points to
        const T& GetConst() const
        {
            return Manager<T>::Get().GetByID(RefID);
        }

        /// @brief Is this reference null?
        /// @return If this reference is null
        bool IsNull() const
        {
            return RefID == "\0";
        }

        /// @brief Checks if the object this points to exists
        /// @return If the object exists
        bool Exists() const
        {
            return !IsNull() && Manager<T>::Get().Exists(RefID);
        }

        explicit operator std::string()
        {
            return RefID;
        }

        explicit operator T&()
        {
            return Get();
        }

        /// @brief Get the ID of the object this points to
        /// @return The ID of the object this points to
        std::string GetID() const
        {
            return RefID;
        }

        const bool operator==(const Reference& Other) const
        {
            return RefID == Other.RefID;
        }

        /// @brief Get a null Reference
        /// @return A null Reference
        static Reference GetNull()
        {
            return Reference("\0");
        }
    protected:
        /// @brief The ID of the object this points to
        std::string RefID;
    };

    /// @brief Add an item
    /// @param Item The item to add
    /// @param RerollIDIfAlreadyExists If this is true, the ID will be rerolled if there is already an object with the same ID
    /// @return If the item was added or not
    bool Add(T Item, bool RerollIDIfAlreadyExists = true) 
    {
        if(!Exists(Item)) {
            items.push_back(Item);
            return true;
        }else if(RerollIDIfAlreadyExists) {
            while(Exists(Item)) {
                Item.RerollID();
            }

            return Add(Item, RerollIDIfAlreadyExists);
        }

        return false;
    }

    /// @brief Removes an item
    /// @param Reference The item to remove
    void Remove(const Reference& Reference) 
    {
        if(Exists(Reference)) {
            items.erase(items.begin() + GetIndex(Reference.GetID()));
        }
    }

    /// @brief Get a reference to an item from an ID
    /// @param ID The ID of the object to find
    /// @return The Reference, if one was found
    Reference GetReferenceByID(const std::string& ID)
    {
        if(Exists(Reference(ID))) {
            return Reference(items.at(GetIndex(ID)));
        }else {
            return Reference::GetNull();
        }
    }

    /// @brief Return an Object by its ID
    /// @param ID The ID to find
    /// @return The object (if one was found)
    T& GetByID(const std::string& ID)
    {
        if(Exists(Reference(ID))) {
            return items.at(GetIndex(ID));
        }
    }

    /// @brief Get if an object exists
    /// @param Reference The object to search for
    /// @return If the object exists
    bool Exists(const Reference& Reference)
    {
        return Exists(Reference.GetID());
    }

    /// @brief Get if an object exists
    /// @param ID The ID to search for
    /// @return If the object exists
    bool Exists(const std::string& ID)
    {
        return GetIndex(ID) != -1;
    }

    /// @brief Get if an object exists
    /// @param Item The object to search for
    /// @return If the object exists
    bool Exists(const T& Item)
    {
        return GetIndex(Item.GetID()) != -1;
    }

    virtual void SerializeToFile(const std::string& File) const override
    {
        Utils::WriteFile(File, Serialize().dump(4));
    }

    virtual void DeserializeFromFile(const std::string& File) override
    {
        nlohmann::json json = nlohmann::json::parse(Utils::ReadFile(File));

        Deserialize(json);
    }

    virtual nlohmann::json Serialize() const override
    {
        nlohmann::json json;

        for(const ISerializeable& item : items) {
            json.push_back(item.Serialize());
        }

        return json;
    }

    virtual void Deserialize(const nlohmann::json& json) override
    {
        for(const nlohmann::json& item : json) {
            T newItem;

            newItem.Deserialize(item);

            items.push_back(newItem);
        }
    }

    /// @brief Returns the vector containing all the objects
    /// @return The vector containing all the objects
    std::vector<T>& GetAll()
    {
        return items;
    }

    /// @brief Gets a vector with references to all the objects
    /// @return All the references
    std::vector<Reference> GetReferences()
    {
        std::vector<Reference> refs;

        for(const T& item : Get().GetAll()) {
            refs.push_back(Reference(item));
        }

        return refs;
    }

    /// @brief Get the instance of this Manager
    /// @return The instance
    static Manager<T>& Get()
    {
        static Manager<T> instance;
        return instance;
    }

    /// @brief Returns the item's index based on it's ID
    /// @param ID The ID to search for
    /// @return The index (-1 if it was not found)
    int GetIndex(const std::string& ID) 
    {
        for(int i = 0; const T& item : items) {
            if(item.GetID() == ID) {
                return i;
            }

            i++;
        }

        return -1;
    }

    Manager(Manager&) = delete;
    Manager(Manager&&) = delete;
private:
    Manager() = default;

    /// @brief the vector of items
    std::vector<T> items;
};