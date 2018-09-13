#ifndef NJOY_CONSTANTS_PHYSICS_CODATA2014_HPP
#define NJOY_CONSTANTS_PHYSICS_CODATA2014_HPP

#include "constants/physics/CODATA.hpp"

namespace njoy{
namespace constants{
namespace physics{

auto CODATA2014 = hana::make_map(
  hana::make_pair( speedOfLight, 299792458*meter/second ),
  hana::make_pair( c, 299792458*meter/second )
);

}
} // namespace constants
} // namespace njoy
#endif  // NJOY_CONSTANTS_PHYSICS_CODATA2014_HPP

