#include "cppClassUnit.h"
#include "Modifiers.h"

int toCppAccessModifiersID(Unit::Flags flags){
    switch ((AccessModifier)flags) {
    case AccessModifier::PUBLIC:
        return 0;
    case AccessModifier::PROTECTED:
        return 1;
    case AccessModifier::PRIVATE:
        return 2;
    default:
        return -1;
    }
}

const std::vector< std::string > CppClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };

CppClassUnit::CppClassUnit( const std::string& name ) : AbstractClassUnit( name ) {
    m_fields.resize( ACCESS_MODIFIERS.size() );
}

void CppClassUnit::add( const std::shared_ptr< Unit >& unit, Flags flags )
{
    int accessModifier = toCppAccessModifiersID((Unit::Flags)AccessModifier::PRIVATE);
    if( flags == (flags & cppAccessModifierMask)) {
        accessModifier = toCppAccessModifiersID(flags);
    }
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
