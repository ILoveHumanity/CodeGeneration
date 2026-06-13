#include "cppMethodUnit.h"
#include "Modifiers.h"

CppMethodUnit::CppMethodUnit( const std::string& name, const std::string& returnType, MethodModifier flags ) : AbstractMethodUnit(name, returnType, flags) {}

std::string CppMethodUnit::compile( unsigned int level ) const {
    if( m_flags != (m_flags & (MethodModifier::STATIC | MethodModifier::VIRTUAL | MethodModifier::CONST)) ) {
        throw std::invalid_argument("Unsupported C++ method modifier.");
    }
    std::string result = generateShift( level );
    if( (m_flags & MethodModifier::STATIC) == MethodModifier::STATIC ) {
        result += "static ";
    } else if( (m_flags & MethodModifier::VIRTUAL) == MethodModifier::VIRTUAL ) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if( (m_flags & MethodModifier::CONST) == MethodModifier::CONST ) {
        result += " const";
    }
    result += " {\n";
    for( const auto& b : m_body ) {
        result += b->compile( level + 1 ); // Рекурсивный вызов compile для тела
    }
    result += generateShift( level ) + "}\n";
    return result;
}
