#define CATCH_CONFIG_MAIN

#include <fstream>
#include <typeinfo>

#include "catch.hpp"

#include "constants.hpp"
#include "constants/CODATA2014.hpp"
#include "constants/testing.hpp"

using namespace njoy::constants;
using namespace dimwits;

auto stringFor = hana::make_map(
  hana::make_pair( avogadro, std::string{ "Avogadro constant" } ),
  hana::make_pair( boltzmann, std::string{ "Boltzmann constant" } ),
  hana::make_pair( electric, std::string{ "electric constant" } ),
  hana::make_pair( electronRadius, std::string{ "classical electron radius" } ),
  hana::make_pair( elementaryCharge, std::string{ "elementary charge" } ),
  hana::make_pair( faraday, std::string{ "Faraday constant" } ),
  hana::make_pair( fineStructure, std::string{ "fine-structure constant" } ),
  hana::make_pair( conductanceQuantum, std::string{ "conductance quantum" } ),
  hana::make_pair( magnetic, std::string{ "mag. constant" } ),
  hana::make_pair( magneticFluxQuantum, std::string{ "mag. flux quantum" } ),
  hana::make_pair( molarGas, std::string{ "molar gas constant" } ),
  hana::make_pair( newtonianGravitation, 
                   std::string{ "Newtonian constant of gravitation" } ),
  hana::make_pair( planck, std::string{ "Planck constant" } ),
  hana::make_pair( hbar, std::string{ "Planck constant over 2 pi" } ),
  hana::make_pair( rydberg, std::string{ "Rydberg constant" } ),
  hana::make_pair( speedOfLight, std::string{ "speed of light in vacuum" } ),
  hana::make_pair( stefanBoltzmann, std::string{ "Stefan-Boltzmann constant" } ),

  // Masses
  hana::make_pair( electronMass, std::string{ "electron mass" } ),
  hana::make_pair( neutronMass, std::string{ "neutron mass" } ),
  hana::make_pair( protonMass, std::string{ "proton mass" } ),
  hana::make_pair( deuteronMass, std::string{ "deuteron mass" } ),
  hana::make_pair( helionMass, std::string{ "helion mass" } ),
  hana::make_pair( tritonMass, std::string{ "triton mass" } ),
  hana::make_pair( alphaMass, std::string{ "alpha particle mass" } )
);

template< typename MAP >
void checkMap( MAP& map ){
  auto referenceValues = 
      testing::defineReferenceValues( std::ifstream("CODATA2014.txt") );

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
