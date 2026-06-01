#ifndef MODIFIERS_H
#define MODIFIERS_H

#include "unit.h"

enum class AccessModifier : Unit::Flags {
    UNDEFINED = 0,
    PUBLIC = 1 << 0,
    PROTECTED = 1 << 1,
    PRIVATE = 1 << 2
};

enum class MethodModifier : Unit::Flags {
    UNDEFINED = 0,
    STATIC = 1 << 0,
    CONST = 1 << 1,
    VIRTUAL = 1 << 2
};

/// @brief Побитовое ИЛИ.
inline constexpr MethodModifier operator|(MethodModifier a, MethodModifier b) noexcept
{
    return (MethodModifier)((Unit::Flags)a | (Unit::Flags)b);
}

/// @brief Побитовое И.
inline constexpr MethodModifier operator&(MethodModifier a, MethodModifier b) noexcept
{
    return (MethodModifier)((Unit::Flags)a & (Unit::Flags)b);
}

#endif // MODIFIERS_H
