#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "constants/physics/CODATA2014.hpp"

using namespace njoy;
using namespace dimwits;

SCENARIO( "Testing CODATA2014 physical constants and uncertainties" ){
  auto constants = njoy::constants::physics::CODATA2014;
  auto uncertainties = njoy::constants::physics::CODATA2014Uncertainty;

  CHECK( 2.99792458E8*meter/second == njoy::constants::physics::CODATA2014[
         constants::physics::speedOfLight ] );
  CHECK( 2.99792458E8*meter/second == constants[ constants::physics::c ] );
  CHECK( 0.0*meter/second == njoy::constants::physics::CODATA2014Uncertainty[
         constants::physics::speedOfLight ] );
  CHECK( 0.0*meter/second == uncertainties[ constants::physics::c ] );

  CHECK( 6.022140857E23/mole == constants[ constants::physics::avogadro ] );
  CHECK( 0.000000074E23/mole == uncertainties[ constants::physics::avogadro ] );

  CHECK( 1.38064852e-23*joule/mole == 
         constants[ constants::physics::boltzmann ] );
  CHECK( 1.38064852e-23*joule/mole == constants[ constants::physics::k ] );
  CHECK( 0.00000079e-23*joule/mole == 
         uncertainties[ constants::physics::boltzmann ] );
  CHECK( 0.00000079e-23*joule/mole == uncertainties[ constants::physics::k ] );

  CHECK( 6.626070040e-34*joule*second== 
         constants[ constants::physics::planck ] );
  CHECK( 6.626070040e-34*joule*second== constants[ constants::physics::h ] );
  CHECK( 0.000000081e-34*joule*second == 
         uncertainties[ constants::physics::planck ] );
  CHECK( 0.000000081e-34*joule*second == 
         uncertainties[ constants::physics::h ] );
  CHECK( 1.0545718000e-34*joule*second== 
         constants[ constants::physics::hbar ] );
  CHECK( 0.000000013e-34*joule*second == 
         uncertainties[ constants::physics::hbar ] );

  // Masses
  CHECK( 6.644657230e-27*kilo( gram ) == 
         constants[ constants::physics::alphaMass ] );
  CHECK( 0.000000082e-27*kilo( gram ) == 
         uncertainties[ constants::physics::alphaMass ] );

  CHECK( 1.674927471e-27*kilo( gram ) == 
         constants[ constants::physics::neutronMass ] );
  CHECK( 0.000000021e-27*kilo( gram ) == 
         uncertainties[ constants::physics::neutronMass ] );

  CHECK( 9.10938356e-31*kilo( gram ) == 
         constants[ constants::physics::electronMass ] );
  CHECK( 0.00000011e-31*kilo( gram ) == 
         uncertainties[ constants::physics::electronMass ] );

  CHECK( 1.672621898e-27*kilo( gram ) == 
         constants[ constants::physics::protonMass ] );
  CHECK( 0.000000021e-27*kilo( gram ) == 
         uncertainties[ constants::physics::protonMass ] );

  CHECK( 3.343583719e-27*kilo( gram ) == 
         constants[ constants::physics::deuteronMass ] );
  CHECK( 0.000000041e-27*kilo( gram ) == 
         uncertainties[ constants::physics::deuteronMass ] );

  CHECK( 5.007356665e-27*kilo( gram ) == 
         constants[ constants::physics::tritonMass ] );
  CHECK( 0.000000062e-27*kilo( gram ) == 
         uncertainties[ constants::physics::tritonMass ] );

  CHECK( 5.006412700e-27*kilo( gram ) == 
         constants[ constants::physics::helionMass ] );
  CHECK( 0.000000062e-27*kilo( gram ) == 
         uncertainties[ constants::physics::helionMass ] );
}
