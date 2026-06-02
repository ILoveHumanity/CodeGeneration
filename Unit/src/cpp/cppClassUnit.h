#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H

#include "AbstractClassUnit.h"
#include <vector>
#include <string>

/// @brief C++ класс
class CppClassUnit : public AbstractClassUnit
{
public:
    static const std::vector< std::string > ACCESS_MODIFIERS; ///< Имена модификаторов доступа.
public:
    /// @brief Конструктор.
    /// @param[in] name Имя класса.
    explicit CppClassUnit( const std::string& name );

    /// @brief Деструктор
    ~CppClassUnit() = default;

    /// @brief Добавляет вложенный узел с модификатором доступа.
    /// @param[in] unit Вложенный узел.
    /// @param[in] flags Модификатор доступа.
    void add( const std::shared_ptr< Unit >& unit, AccessModifier flags ) override;

    /// @brief Формирует текстовое представление класса.
    /// @param[in] level Уровень отступа.
    /// @return Текст класса.
    std::string compile( unsigned int level = 0 ) const override;
private:
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields; ///< Набор секций доступа и их элементов.
};

#endif // CPPCLASSUNIT_H
