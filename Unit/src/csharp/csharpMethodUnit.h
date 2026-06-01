#ifndef CSHARPMETHODUNIT_H
#define CSHARPMETHODUNIT_H

#include "AbstractMethodUnit.h"
#include <vector>
#include <string>

class CSharpMethodUnit : public AbstractMethodUnit
{
public:
    CSharpMethodUnit( const std::string& name, const std::string& returnType, MethodModifier flags );
    ~CSharpMethodUnit() = default;
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // CSHARPMETHODUNIT_H
