#ifndef CPPMETHODUNIT_H
#define CPPMETHODUNIT_H

#include "AbstractMethodUnit.h"
#include <vector>
#include <string>


class CppMethodUnit : public AbstractMethodUnit
{
public:
    CppMethodUnit( const std::string& name, const std::string& returnType, Flags flags );
    ~CppMethodUnit() = default;
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // CPPMETHODUNIT_H
