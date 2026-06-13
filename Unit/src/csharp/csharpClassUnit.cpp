#include "CSharpClassUnit.h"
#include "Modifiers.h"
#include <stdexcept>

int toCSharpAccessModifiersID(AccessModifier flags){
    switch (flags) {
    case AccessModifier::PUBLIC:
        return 0;
    case AccessModifier::PROTECTED:
        return 1;
    case AccessModifier::PRIVATE:
        return 2;
    case AccessModifier::UNDEFINED: // ?
        return 2;
    case AccessModifier::INTERNAL:
        return 3;
    case AccessModifier::PROTECTED_INTERNAL:
        return 4;
    case AccessModifier::PRIVATE_PROTECTED:
        return 5;
    case AccessModifier::FILE:
        return 6;
    default:
        throw std::invalid_argument("Unsupported C# class access modifier.");
    }
}

const std::vector< std::string > CSharpClassUnit::ACCESS_MODIFIERS = {
    "public",
    "protected",
    "private",
    "internal",
    "protected internal",
    "private protected",
    "file"
};

CSharpClassUnit::CSharpClassUnit( const std::string& name ) : AbstractClassUnit( name ) {
    m_fields.resize( ACCESS_MODIFIERS.size() );
}

void CSharpClassUnit::add( const std::shared_ptr< Unit >& unit, AccessModifier flags )
{
    int accessModifier = toCSharpAccessModifiersID(flags);
    m_fields[ accessModifier ].push_back( unit );
}

// Функция генерации кода класса на C#
std::string CSharpClassUnit::compile( unsigned int level ) const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    // Проходим по всем возможным модификаторам доступа
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
    {
        // Если список юнитов для текущего модификатора пуст, пропускаем его
        if( m_fields[ i ].empty() )
        {
            continue;
        }

        // Проходим по всем юнитам, добавленным с этим модификатором
        for( const auto& f : m_fields[ i ] )
        {
            // Рекурсивно вызываем compile для каждого юнита, увеличивая уровень отступа
            // Добавляем модификатор доступа
            result += ACCESS_MODIFIERS[ i ] + " " + f->compile( level + 1 );
        }
    }
    // Закрываем фигурную скобку класса
    result += generateShift( level ) + "};\n";
    return result;
}
