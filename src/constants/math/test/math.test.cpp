#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "constants/math.hpp"

using namespace njoy;

SCENARIO( "Testing mathematical constants" ){

  REQUIRE( 3.141592653589793 == constants::math::pi );
  REQUIRE( 2.718281828459045 == constants::math::e );
  REQUIRE( 1.414213562373095 == constants::math::root2 );

}
