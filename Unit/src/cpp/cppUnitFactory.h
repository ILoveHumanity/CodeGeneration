#ifndef CPPUNITFACTORY_H
#define CPPUNITFACTORY_H

#include "AbstractUnitFactory.h"
#include <memory>

/// @brief Конкретная реализация фабрики для генерации кода на C++.
class CppUnitFactory : public AbstractUnitFactory {
public:
    /// @brief Конструктор.
    CppUnitFactory() = default;

    /// @brief Деструктор
    ~CppUnitFactory() = default;

    /// @brief Создаёт C++ класс.
    /// @param[in] name Имя класса.
    /// @return Указатель на объект CppClassUnit.
    std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name) const override;

    /// @brief Создаёт C++ метод.
    /// @param[in] name Имя метода.
    /// @param[in] returnType Тип возвращаемого значения.
    /// @param[in] flags Флаги модификаторов метода.
    /// @return Указатель на объект CppMethodUnit.
    std::shared_ptr<AbstractMethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, MethodModifier flags) const override;

    /// @brief Создаёт C++ оператор печати.
    /// @param[in] text Текст для печати.
    /// @return Указатель на объект CppPrintOperatorUnit.
    std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override;
};

#endif // CPPUNITFACTORY_H
