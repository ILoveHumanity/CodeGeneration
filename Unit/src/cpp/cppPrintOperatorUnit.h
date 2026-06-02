#ifndef CPPPRINTOPERATORUNIT_H
#define CPPPRINTOPERATORUNIT_H

#include "AbstractPrintOperatorUnit.h"
#include <string>

class CppPrintOperatorUnit : public AbstractPrintOperatorUnit
{
public:
    explicit CppPrintOperatorUnit( const std::string& text );
    ~CppPrintOperatorUnit() = default;
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // CPPPRINTOPERATORUNIT_H
