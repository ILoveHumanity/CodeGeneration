#include "JavaClassUnit.h"
#include "Modifiers.h"
#include <stdexcept>

int toJavaAccessModifiersID(AccessModifier flags){
    switch (flags) {
    case AccessModifier::PUBLIC:
        return 0;
    case AccessModifier::PROTECTED:
        return 1;
    case AccessModifier::PRIVATE:
        return 2;
    case AccessModifier::UNDEFINED:
        return 3;
    default:
        throw std::invalid_argument("Unsupported Java class access modifier.");
    }
}

const std::vector< std::string > JavaClassUnit::ACCESS_MODIFIERS = {
    "public ",
    "protected ",
    "private ",
    ""
};

JavaClassUnit::JavaClassUnit( const std::string& name ) : AbstractClassUnit( name ) {
    m_fields.resize( ACCESS_MODIFIERS.size() );
}

void JavaClassUnit::add( const std::shared_ptr< Unit >& unit, AccessModifier flags )
{
    int accessModifier = toJavaAccessModifiersID(flags);
    m_fields[ accessModifier ].push_back( unit );
}

// Функция генерации кода класса на Java
std::string JavaClassUnit::compile( unsigned int level ) const
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
            result += ACCESS_MODIFIERS[ i ] + f->compile( level + 1 );
        }
    }
    // Закрываем фигурную скобку класса
    result += generateShift( level ) + "}\n";
    return result;
}
