#ifndef MODIFIERS_H
#define MODIFIERS_H

#include "unit.h"

enum class AccessModifier : Unit::Flags {
    UNDEFINED = 0,
    PUBLIC = 1,
    PROTECTED = 2,
    PRIVATE = 3,
    INTERNAL = 4, // C#
    PROTECTED_INTERNAL = 5, // C#
    PRIVATE_PROTECTED = 6, // C#
    FILE = 7 // C#
};

enum class MethodModifier : Unit::Flags {
    UNDEFINED = 0,
    STATIC = 1 << 0,
    CONST = 1 << 1,
    VIRTUAL = 1 << 2
};

/// @brief Побитовое ИЛИ.
inline MethodModifier operator|(MethodModifier a, MethodModifier b) noexcept
{
    return (MethodModifier)((Unit::Flags)a | (Unit::Flags)b);
}

/// @brief Побитовое И.
inline MethodModifier operator&(MethodModifier a, MethodModifier b) noexcept
{
    return (MethodModifier)((Unit::Flags)a & (Unit::Flags)b);
}

#endif // MODIFIERS_H
