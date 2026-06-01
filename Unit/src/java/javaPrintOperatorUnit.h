#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H

#include "AbstractPrintOperatorUnit.h"
#include <string>

class JavaPrintOperatorUnit : public AbstractPrintOperatorUnit
{
public:
    explicit JavaPrintOperatorUnit( const std::string& text );
    ~JavaPrintOperatorUnit() = default;
    std::string compile( unsigned int level = 0 ) const override;
};

#endif // JAVAPRINTOPERATORUNIT_H
