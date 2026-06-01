#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H

#include "AbstractMethodUnit.h"
#include <vector>
#include <string>

class JavaMethodUnit : public AbstractMethodUnit
{
public:
    JavaMethodUnit( const std::string& name, const std::string& returnType, MethodModifier flags );
    ~JavaMethodUnit() = default;
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // JAVAMETHODUNIT_H
