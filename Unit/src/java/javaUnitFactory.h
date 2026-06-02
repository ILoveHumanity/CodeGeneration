#ifndef JAVAUNITFACTORY_H
#define JAVAUNITFACTORY_H

#include "AbstractUnitFactory.h"
#include <memory>

/// @brief Конкретная реализация фабрики для генерации кода на Java.
class JavaUnitFactory : public AbstractUnitFactory {
public:
    /// @brief Конструктор.
    JavaUnitFactory() = default;

    /// @brief Деструктор
    ~JavaUnitFactory() = default;

    /// @brief Создаёт Java класс.
    /// @param[in] name Имя класса.
    /// @return Указатель на объект JavaClassUnit.
    std::shared_ptr<AbstractClassUnit> createClassUnit(const std::string& name) const override;

    /// @brief Создаёт Java метод.
    /// @param[in] name Имя метода.
    /// @param[in] returnType Тип возвращаемого значения.
    /// @param[in] flags Флаги модификаторов метода.
    /// @return Указатель на объект JavaMethodUnit.
    std::shared_ptr<AbstractMethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, MethodModifier flags) const override;

    /// @brief Создаёт Java оператор печати.
    /// @param[in] text Текст для печати.
    /// @return Указатель на объект JavaPrintOperatorUnit.
    std::shared_ptr<AbstractPrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override;
};

#endif // JAVAUNITFACTORY_H
