#ifndef NJOY_CONSTANTS_PHYSICS_CODATA_HPP
#define NJOY_CONSTANTS_PHYSICS_CODATA_HPP

#include "dimwits.hpp"
using namespace dimwits;

namespace njoy{
namespace constants{
namespace physics{

#define CONSTANT_TYPE( NAME ) \
 \
  struct NAME##_t : hana::type< NAME##_t >{}; \
  static constexpr NAME##_t NAME{}; \

CONSTANT_TYPE( avogadro );
CONSTANT_TYPE( boltzmann );
CONSTANT_TYPE( G );
CONSTANT_TYPE( elementaryCharge );
CONSTANT_TYPE( newtonianGravitation );
CONSTANT_TYPE( k );
CONSTANT_TYPE( planck );
CONSTANT_TYPE( h );
CONSTANT_TYPE( hbar );
CONSTANT_TYPE( reducedPlanck );
CONSTANT_TYPE( speedOfLight );
CONSTANT_TYPE( c );

CONSTANT_TYPE( a );

CONSTANT_TYPE( electronMass );
CONSTANT_TYPE( neutronMass );
CONSTANT_TYPE( protonMass );
CONSTANT_TYPE( deuteronMass );
CONSTANT_TYPE( helionMass );
CONSTANT_TYPE( tritonMass );
CONSTANT_TYPE( alphaMass );

#undef CONSTANT_TYPE

}
} // namespace constants
} // namespace njoy
#endif  // NJOY_CONSTANTS_PHYSICS_CODATA_HPP
