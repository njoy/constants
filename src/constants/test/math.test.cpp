
#include "catch.hpp"

#include "constants.hpp"

SCENARIO( "Testing mathematical constants" ){

  CHECK( 3.141592653589793 == njoy::constants::pi );
  CHECK( 6.283185307179586 == njoy::constants::twopi );
  CHECK( 2.718281828459045 == njoy::constants::e );
  CHECK( 1.414213562373095 == njoy::constants::root2 );

}
