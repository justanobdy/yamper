#pragma once

#include <ISerializable.hpp>
#include <IDObject.hpp>

/// @brief Base class for objects that will be used with Manager<T>
class Manageable : public ISerializeable, public IDObject
{};