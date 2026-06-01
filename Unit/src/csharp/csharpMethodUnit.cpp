#include "CSharpMethodUnit.h"
#include "Modifiers.h"

CSharpMethodUnit::CSharpMethodUnit( const std::string& name, const std::string& returnType, MethodModifier flags ) : AbstractMethodUnit(name, returnType, flags) {}

std::string CSharpMethodUnit::compile( unsigned int level ) const
{
    // Проверяем допустимость флагов
    if( m_flags != (m_flags & (MethodModifier::STATIC | MethodModifier::VIRTUAL)) ) {
        throw std::invalid_argument("Unsupported C# method modifier.");
    }
    std::string result;
    if( (m_flags & MethodModifier::STATIC) == MethodModifier::STATIC ) {
        result += "static ";
    } else if( (m_flags & MethodModifier::VIRTUAL) == MethodModifier::VIRTUAL ) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";
    for( const auto& b : m_body ) {
        result += b->compile( level + 1 ); // Рекурсивный вызов compile для тела
    }
    result += generateShift( level ) + "}\n";
    return result;
}
