
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
      auto reference = referenceValues[ refKey ];

      // Hiding our shame
      auto verifyIfExists = [&](auto key) {
        return hana::overload(
          []( hana::true_ ){ return true; },
          [&]( auto value ){ return reference.second == value.value; } 
        )( hana::find( CODATA.uncertainty, key ).value_or( hana::true_c ) );
      };
      CHECK( fabs( 1 - (reference.first/CODATA[ key ].value ) ) < 5E-10 );
      CHECK( verifyIfExists( key ) );
    }
  });
}
