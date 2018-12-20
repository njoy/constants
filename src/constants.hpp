#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include "boost/hana.hpp"
#include "dimwits.hpp"

using namespace boost;
using namespace dimwits;

namespace njoy {
namespace constants {

#include "constants/math.hpp"
#include "constants/tags.hpp"
#include "constants/derived.hpp"
#include "constants/map.hpp"
#include "constants/src/addUncertainty.hpp"

} // namespace constants
} // namespace njoy

#endif // CONSTANTS_HPP
