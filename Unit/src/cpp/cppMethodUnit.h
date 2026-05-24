#ifndef CPPMETHODUNIT_H
#define CPPMETHODUNIT_H

#include "AbstractMethodUnit.h"
#include <vector>
#include <string>


class CppMethodUnit : public AbstractMethodUnit
{
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    CppMethodUnit( const std::string& name, const std::string& returnType, Flags flags );
    ~CppMethodUnit() = default;
    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) override;
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // CPPMETHODUNIT_H
