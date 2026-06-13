#include "JavaPrintOperatorUnit.h"
#include <string>

JavaPrintOperatorUnit::JavaPrintOperatorUnit( const std::string& text ) : AbstractPrintOperatorUnit( text ) {}

std::string JavaPrintOperatorUnit::compile( unsigned int level ) const {
    return generateShift( level ) + "System.out.println( \"" + m_text + "\" );\n";
}
