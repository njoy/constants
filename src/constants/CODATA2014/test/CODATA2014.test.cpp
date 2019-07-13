#define CATCH_CONFIG_MAIN

#include <fstream>
#include <typeinfo>

#include "catch.hpp"

#include "constants.hpp"
#include "constants/CODATA2014.hpp"

#include "constants/CODATA2014/test/testing.hpp"

using namespace dimwits;

template< typename MAP >
void checkMap( MAP& map ){
  auto referenceValues = 
      defineReferenceValues( std::ifstream("CODATA2018.txt") );

  hana::for_each( hana::keys( map ), [&]( auto&& key ){
    auto refKey = stringFor[ key ];

    GIVEN( "constant: " + refKey ){
      auto reference = referenceValues[ refKey ];

      // Hiding our shame
      auto verifyIfExists = [&](auto key) {
        return hana::overload(
          []( hana::true_ ){ return true; },
          [&]( auto value ){ return reference.second == value.value; } 
        )( hana::find( map.uncertainty, key ).value_or( hana::true_c ) );
      };
      CHECK( fabs( 1 - (reference.first/map[ key ].value ) ) < 5E-10 );
      CHECK( verifyIfExists( key ) );
    }
  });
}

SCENARIO("test all the constants"){

  checkMap( CODATA2014 );

  auto aliasMap = addUncertainty(
    hana::make_map(
      hana::make_pair( k, CODATA2014[ k ] ),
      hana::make_pair( h, CODATA2014[ h ] ),
      hana::make_pair( G, CODATA2014[ G ] ),
      hana::make_pair( c, CODATA2014[ c ] )
    ),

    // Uncertainties
    hana::make_map(
      hana::make_pair( k, CODATA2014.uncertainty[ k ] ),
      hana::make_pair( h, CODATA2014.uncertainty[ h ] ),
      hana::make_pair( G, CODATA2014.uncertainty[ G ] ),
      hana::make_pair( c, CODATA2014.uncertainty[ c ] )
    )
  );

  checkMap( aliasMap );
}
