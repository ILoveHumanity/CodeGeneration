#ifndef MODIFIERS_H
#define MODIFIERS_H

#include "unit.h"

enum class AccessModifier : Unit::Flags {
    PUBLIC,
    PROTECTED,
    PRIVATE
};
const Unit::Flags cppAccessModifierMask = 0b111;


enum class MethodModifier : Unit::Flags {
    UNDEFINED = 0,
    STATIC = 1 << 0,
    CONST = 1 << 1,
    VIRTUAL = 1 << 2
};
const Unit::Flags cppMethodModifierMask = 0b111;



#endif // MODIFIERS_H
