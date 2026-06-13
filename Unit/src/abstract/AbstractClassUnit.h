#ifndef ABSTRACTCLASSUNIT_H
#define ABSTRACTCLASSUNIT_H

#include "unit.h"
#include "Modifiers.h"
#include <string>
#include <memory>

/// @brief Абстрактный базовый класс для представления класса на любом языке
class AbstractClassUnit : public Unit
{
public:
    /// @brief Конструктор.
    /// @param[in] name Имя класса.
    explicit AbstractClassUnit(const std::string& name);

    /// @brief Виртуальный деструктор.
    virtual ~AbstractClassUnit() = default;

    /// @brief Формирует текстовое представление класса.
    /// @param[in] level Уровень отступа.
    /// @return Текст класса.
    virtual std::string compile( unsigned int level = 0 ) const = 0;

    using Unit::add;
    /// @brief Добавляет вложенный узел с модификатором доступа.
    /// @param[in] unit Вложенный узел.
    /// @param[in] flags Модификатор доступа.
    virtual void add( const std::shared_ptr< Unit >& unit, AccessModifier flags ) = 0;

protected:
    std::string m_name; ///< Имя класса
};

#endif // ABSTRACTCLASSUNIT_H
