#include "CSharpPrintOperatorUnit.h"
#include <string>

CSharpPrintOperatorUnit::CSharpPrintOperatorUnit( const std::string& text ) : AbstractPrintOperatorUnit( text ) {}

std::string CSharpPrintOperatorUnit::compile( unsigned int level ) const {
    return generateShift( level ) + "System.Console.WriteLine( \"" + m_text + "\" );\n";
}
