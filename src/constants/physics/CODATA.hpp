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

CONSTANT_TYPE( speedOfLight );
CONSTANT_TYPE( c );

#undef CONSTANT_TYPE

}
} // namespace constants
} // namespace njoy
#endif  // NJOY_CONSTANTS_PHYSICS_CODATA_HPP
