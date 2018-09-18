
#include "catch.hpp"

#include "constants.hpp"

using namespace dimwits;
using namespace njoy;

// SCENARIO("test all the constants"){
//   auto data = njoy::constants::constants::CODATA2014;
//   auto referenceValues = defineReferenceValues(std::ifstream("allascii.txt"));
//   hana::for_each(data, [&](auto&& pair){
//     auto reference = referenceValues[stringFor[hana::first(pair)]];
//     REQUIRE(reference == hana::second(pair).value);
//   });
// }

SCENARIO( "Testing CODATA2014 physical constants and uncertainties" ){
  auto constants = constants::CODATA2014;
  auto uncertainties = constants::CODATA2014Uncertainty;

  GIVEN( "values of constants" ){
    THEN( "hard-coded values can be checked" ){
      CHECK( 2.99792458E8*meter/second == constants[ constants::speedOfLight ] );
      CHECK( 0.0*meter/second == uncertainties[ constants::speedOfLight ] );
      CHECK( 2.99792458E8*meter/second == constants[ constants::c ] );
      CHECK( 0.0*meter/second == uncertainties[ constants::c ] );

      CHECK( 6.022140857E23/mole == constants[ constants::avogadro ] );
      CHECK( 7.4E15/mole == uncertainties[ constants::avogadro ] );
      CHECK( 6.67408e-11*meter*meter*meter/kilo( gram )/second/second == 
            constants[constants::G ] );
      CHECK( 6.67408e-11*meter*meter*meter/kilo( gram )/second/second == 
            constants[constants::newtonianGravitation ] );
      CHECK( 3.1e-15*meter*meter*meter/kilo( gram )/second/second == 
            uncertainties[constants::G ] );
      CHECK( 3.1e-15*meter*meter*meter/kilo( gram )/second/second == 
            uncertainties[constants::newtonianGravitation ] );
      CHECK( 1.38064852e-23*joule/mole == constants[ constants::boltzmann ] );
      CHECK( 7.9e-30*joule/mole == uncertainties[ constants::boltzmann ] );
      CHECK( 1.38064852e-23*joule/mole == constants[ constants::k ] );
      CHECK( 7.9e-30*joule/mole == uncertainties[ constants::k ] );
      CHECK( 6.626070040e-34*joule*second == constants[ constants::planck ] );
      CHECK( 8.1e-42*joule*second == uncertainties[ constants::planck ] );
      CHECK( 6.626070040e-34*joule*second == constants[ constants::h ] );
      CHECK( 8.1e-42*joule*second == uncertainties[ constants::h ] );
      CHECK( 1.0545718000e-34*joule*second == constants[ constants::hbar ] );
      CHECK( 1.3e-42*joule*second == uncertainties[ constants::hbar ] );
      CHECK( 1.0545718000e-34*joule*second == constants[ constants::reducedPlanck ] );
      CHECK( 1.3e-42*joule*second == uncertainties[ constants::reducedPlanck ] );
      CHECK( 1.6021766208e-19*coulomb == constants[ constants::elementaryCharge ] );
      CHECK( 9.8e-28*coulomb == uncertainties[ constants::elementaryCharge ] );

      // Masses
      auto kg = kilo( gram );
      CHECK( 6.644657230e-27*kg == constants[ constants::alphaMass ] );
      CHECK( 0.000000082e-27*kg == uncertainties[ constants::alphaMass ] );

      CHECK( 1.674927471e-27*kg == constants[ constants::neutronMass ] );
      CHECK( 0.000000021e-27*kg == uncertainties[ constants::neutronMass ] );

      CHECK( 9.10938356e-31*kg == constants[ constants::electronMass ] );
      CHECK( 0.00000011e-31*kg == uncertainties[ constants::electronMass ] );

      CHECK( 1.672621898e-27*kg == constants[ constants::protonMass ] );
      CHECK( 0.000000021e-27*kg == uncertainties[ constants::protonMass ] );

      CHECK( 3.343583719e-27*kg == constants[ constants::deuteronMass ] );
      CHECK( 0.000000041e-27*kg == uncertainties[ constants::deuteronMass ] );

      CHECK( 5.007356665e-27*kg == constants[ constants::tritonMass ] );
      CHECK( 0.000000062e-27*kg == uncertainties[ constants::tritonMass ] );

      CHECK( 5.006412700e-27*kg == constants[ constants::helionMass ] );
      CHECK( 0.000000062e-27*kg == uncertainties[ constants::helionMass ] );
    } // THEN
    THEN( "derived quantities can be verified" ){
      auto c = constants[ constants::c ];
      auto hbar = constants[ constants::hbar ];
      auto planckLength = sqrt( hbar*constants[ constants::G ]/( c*c*c ) );

      CHECK( planckLength.value == Approx( 1.616229E-35 ) );
      CHECK( 1*meter == 1*planckLength.units() );
    }
  } // GIVEN
} //SCENARIO
