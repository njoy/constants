#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "constants/physics/CODATA2014.hpp"

using namespace njoy;
using namespace dimwits;

SCENARIO( "Testing CODATA2014 physical constants and uncertainties" ){
  auto constants = njoy::constants::physics::CODATA2014;

  REQUIRE( 299792458*meter/second == njoy::constants::physics::CODATA2014[constants::physics::speedOfLight] );
  REQUIRE( 299792458*meter/second == constants[constants::physics::c] );
}
