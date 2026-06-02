#ifndef ABSTRACTMETHODUNIT_H
#define ABSTRACTMETHODUNIT_H

#include "unit.h"
#include "Modifiers.h"
#include <string>
#include <memory>
#include <vector>

/// @brief Абстрактный базовый класс для представления метода на любом языке
class AbstractMethodUnit : public Unit
{
public:
    /// @brief Конструктор.
    /// @param[in] name Имя метода.
    /// @param[in] returnType Тип возвращаемого значения.
    /// @param[in] flags  Флаги/модификаторы метода.
    explicit AbstractMethodUnit(const std::string& name, const std::string& returnType, MethodModifier flags);

    /// @brief Виртуальный деструктор
    virtual ~AbstractMethodUnit() = default;

    /// @brief Формирует текстовое представление метода.
    /// @param[in] level Уровень отступа.
    /// @return Текст метода.
    virtual std::string compile(unsigned int level = 0) const override = 0;

    /// @brief Добавляет оператор в тело метода.
    /// @param[in] unit Вложенный оператор.
    /// @param[in] flags Дополнительные флаги (не используются).
    void add( const std::shared_ptr< Unit >& unit, Flags flags = 0 ) override;

protected:
    std::string m_name; ///< Имя метода
    std::string m_returnType; ///< Тип возвращаемого значения
    MethodModifier m_flags; ///< Флаги/модификаторы метода
    std::vector<std::shared_ptr<Unit>> m_body; ///< Тело метода (вектор операторов)
};

#endif // ABSTRACTMETHODUNIT_H
