#ifndef ABSTRACTUNITFACTORY_H
#define ABSTRACTUNITFACTORY_H

#include <memory>
#include <string>
#include "Modifiers.h"
#include "AbstractClassUnit.h"
#include "AbstractMethodUnit.h"
#include "AbstractPrintOperatorUnit.h"

/// @brief Абстрактная фабрика для генерации кода.
class AbstractUnitFactory {
public:
    /// @brief Виртуальный деструктор.
    virtual ~AbstractUnitFactory() = default;

    /// @brief Создаёт класс.
    /// @param[in] name Имя класса.
    /// @return Указатель на объект.
    virtual std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name) const = 0;

    /// @brief Создаёт метод.
    /// @param[in] name Имя метода.
    /// @param[in] returnType Тип возвращаемого значения.
    /// @param[in] flags Флаги модификаторов метода.
    /// @return Указатель на объект.
    virtual std::shared_ptr<AbstractMethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, MethodModifier flags) const = 0;

    /// @brief Создаёт оператор печати.
    /// @param[in] text Текст для печати.
    /// @return Указатель на объект.
    virtual std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const = 0;
};


#endif // ABSTRACTUNITFACTORY_H
