#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H

#include "AbstractClassUnit.h"
#include <vector>
#include <string>

class JavaClassUnit : public AbstractClassUnit
{
public:
    static const std::vector< std::string > ACCESS_MODIFIERS;

public:
    explicit JavaClassUnit( const std::string& name );
    void add( const std::shared_ptr< Unit >& unit, AccessModifier flags ) override;
    std::string compile( unsigned int level = 0 ) const override;

private:
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

#endif // JAVACLASSUNIT_H
