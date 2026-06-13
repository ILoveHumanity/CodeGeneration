#include "AbstractClassUnit.h"
#include <stdexcept>

AbstractClassUnit::AbstractClassUnit(const std::string& name) : m_name(name) {}

void AbstractClassUnit::add( const std::shared_ptr< Unit >& , AccessModifier ) {
    throw std::runtime_error( "Not supported" );
}
