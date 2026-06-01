#include "cppClassUnit.h"
#include "Modifiers.h"
#include <stdexcept>

int toCppAccessModifiersID(AccessModifier flags){
    switch (flags) {
    case AccessModifier::PUBLIC:
        return 0;
    case AccessModifier::PROTECTED:
        return 1;
    case AccessModifier::PRIVATE:
        return 2;
    case AccessModifier::UNDEFINED:
        return 2;
    default:
        throw std::invalid_argument("Unsupported C++ class access modifier.");
    }
}

const std::vector< std::string > CppClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };

CppClassUnit::CppClassUnit( const std::string& name ) : AbstractClassUnit( name ) {
    m_fields.resize( ACCESS_MODIFIERS.size() );
}

void CppClassUnit::add( const std::shared_ptr< Unit >& unit, AccessModifier flags )
{
    int accessModifier = toCppAccessModifiersID(flags);
    m_fields[ accessModifier ].push_back( unit );
}

std::string CppClassUnit::compile( unsigned int level ) const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] ) {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}
