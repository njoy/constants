#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "constants/math.hpp"

using namespace njoy;

SCENARIO( "Testing mathematical constants" ){

  REQUIRE( 3.14159265358979323 == constants::math::pi );
}
