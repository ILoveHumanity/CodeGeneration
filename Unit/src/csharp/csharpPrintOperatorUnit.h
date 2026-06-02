#ifndef CSHARPPRINTOPERATORUNIT_H
#define CSHARPPRINTOPERATORUNIT_H

#include "AbstractPrintOperatorUnit.h"
#include <string>

class CSharpPrintOperatorUnit : public AbstractPrintOperatorUnit
{
public:
    explicit CSharpPrintOperatorUnit( const std::string& text );
    ~CSharpPrintOperatorUnit() = default;
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // CSHARPPRINTOPERATORUNIT_H
