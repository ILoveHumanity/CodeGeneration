#ifndef CSHARPUNITFACTORY_H
#define CSHARPUNITFACTORY_H

#include "AbstractUnitFactory.h"
#include <memory>

/// @brief Конкретная реализация фабрики для генерации кода на C#.
class CSharpUnitFactory : public AbstractUnitFactory {
public:
    /// @brief Конструктор.
    CSharpUnitFactory() = default;

    /// @brief Деструктор
    ~CSharpUnitFactory() = default;

    /// @brief Создаёт C# класс.
    /// @param[in] name Имя класса.
    /// @return Указатель на объект CSharpClassUnit.
    std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name) const override;

    /// @brief Создаёт C# метод.
    /// @param[in] name Имя метода.
    /// @param[in] returnType Тип возвращаемого значения.
    /// @param[in] flags Флаги модификаторов метода.
    /// @return Указатель на объект CSharpMethodUnit.
    std::shared_ptr<AbstractMethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, MethodModifier flags) const override;

    /// @brief Создаёт C# оператор печати.
    /// @param[in] text Текст для печати.
    /// @return Указатель на объект CSharpPrintOperatorUnit.
    std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override;
};

#endif // CSHARPUNITFACTORY_H
