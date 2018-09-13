#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "constants/math.hpp"

using namespace njoy;

SCENARIO( "Testing mathematical constants" ){

  REQUIRE( 3.141 == constants::math::pi );
  REQUIRE( 2.718 == constants::math::e );
  REQUIRE( 1.414 == constants::math::root2 );
}
