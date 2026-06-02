#ifndef UNIT_H
#define UNIT_H

#include <memory>
#include <string>

class Unit {
public:
    using Flags = unsigned int;
public:
    /// @brief Виртуальный деструктор.
    virtual ~Unit() = default;

    /// @brief Добавляет вложенный узел.
    /// @param[in] unit Вложенный узел.
    /// @param[in] Flags Дополнительные флаги добавления.
    virtual void add( const std::shared_ptr< Unit >& , Flags);

    /// @brief Формирует текстовое представление узла.
    /// @param[in] level Уровень отступа.
    /// @return Текст узла.
    virtual std::string compile( unsigned int level = 0 ) const = 0;
protected:
    /// @brief Создает отступа для заданного уровня.
    /// @param[in] level Уровень отступа.
    /// @return Строка пробелов для отступа.
    virtual std::string generateShift( unsigned int level ) const;
};

#endif // UNIT_H
