#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H

#include "AbstractClassUnit.h"
#include <vector>
#include <string>

class CppClassUnit : public AbstractClassUnit
{
public:
    static const std::vector< std::string > ACCESS_MODIFIERS;
public:
    explicit CppClassUnit( const std::string& name );
    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override;
    std::string compile( unsigned int level = 0 ) const override;
private:
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

#endif // CPPCLASSUNIT_H
