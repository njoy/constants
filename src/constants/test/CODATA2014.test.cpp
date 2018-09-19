
#include <fstream>
#include <typeinfo>

#include "catch.hpp"

#include "constants.hpp"

#include "constants/test/testing.hpp"

using namespace dimwits;

SCENARIO("test all the constants"){
  auto CODATA = CODATA2014;
  auto referenceValues = defineReferenceValues( std::ifstream("CODATA2014.txt") );

  hana::for_each( hana::keys( CODATA ), [&]( auto&& key ){
    auto refKey = stringFor[ key ];

    GIVEN( "constant: " + refKey ){
      auto reference = referenceValues[ stringFor[ key ] ];

      CHECK( reference.first == CODATA[ key ].value );
      CHECK( 
        hana::if_( key ^hana::in^ hana::keys( CODATA.uncertainty ), 
                  reference.second == CODATA.uncertainty[ key ].value,
                  true )
      );
    }
  });
}
