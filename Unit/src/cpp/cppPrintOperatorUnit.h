#ifndef CPPPRINTOPERATORUNIT_H
#define CPPPRINTOPERATORUNIT_H

#include "unit.h"
#include <string>

class CppPrintOperatorUnit : public Unit
{
public:
    explicit CppPrintOperatorUnit( const std::string& text );
    std::string compile( unsigned int level = 0 ) const override;
private:
    std::string m_text;
};

#endif // CPPPRINTOPERATORUNIT_H
