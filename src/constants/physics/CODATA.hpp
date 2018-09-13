#ifndef NJOY_CONSTANTS_PHYSICS_CODATA_HPP
#define NJOY_CONSTANTS_PHYSICS_CODATA_HPP

#include "dimwits.hpp"
using namespace dimwits;

namespace njoy{
namespace constants{
namespace physics{

struct SpeedOfLight: hana::type< SpeedOfLight >{};
static constexpr SpeedOfLight speedOfLight{};
struct C: hana::type< C >{};
static constexpr C c{};

}
} // namespace constants
} // namespace njoy
#endif  // NJOY_CONSTANTS_PHYSICS_CODATA_HPP
