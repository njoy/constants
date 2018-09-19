
#include "catch.hpp"

#include "constants.hpp"

SCENARIO( "Testing mathematical constants" ){

  REQUIRE( 3.141592653589793 == njoy::constants::pi );
  REQUIRE( 6.283185307179586 == njoy::constants::twopi );
  REQUIRE( 2.718281828459045 == njoy::constants::e );
  REQUIRE( 1.414213562373095 == njoy::constants::root2 );

}
