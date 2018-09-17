#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "constants/physics/CODATA2014.hpp"

using namespace dimwits;
namespace physics = njoy::constants::physics;

SCENARIO( "Testing CODATA2014 physical constants and uncertainties" ){
  auto constants = physics::CODATA2014;
  auto uncertainties = physics::CODATA2014Uncertainty;

  CHECK( 2.99792458E8*meter/second == constants[ physics::speedOfLight ] );
  CHECK( 0.0*meter/second == uncertainties[ physics::speedOfLight ] );
  CHECK( 2.99792458E8*meter/second == constants[ physics::c ] );
  CHECK( 0.0*meter/second == uncertainties[ physics::c ] );

  CHECK( 6.022140857E23/mole == constants[ physics::avogadro ] );
  CHECK( 7.4E15/mole == uncertainties[ physics::avogadro ] );
  CHECK( 6.67408e-11*meter*meter*meter/kilo( gram )/second/second == 
         constants[physics::G ] );
  CHECK( 6.67408e-11*meter*meter*meter/kilo( gram )/second/second == 
         constants[physics::newtonianGravitation ] );
  CHECK( 3.1e-15*meter*meter*meter/kilo( gram )/second/second == 
         uncertainties[physics::G ] );
  CHECK( 3.1e-15*meter*meter*meter/kilo( gram )/second/second == 
         uncertainties[physics::newtonianGravitation ] );
  CHECK( 1.38064852e-23*joule/mole == constants[ physics::boltzmann ] );
  CHECK( 7.9e-30*joule/mole == uncertainties[ physics::boltzmann ] );
  CHECK( 1.38064852e-23*joule/mole == constants[ physics::k ] );
  CHECK( 7.9e-30*joule/mole == uncertainties[ physics::k ] );
  CHECK( 6.626070040e-34*joule*second == constants[ physics::planck ] );
  CHECK( 8.1e-42*joule*second == uncertainties[ physics::planck ] );
  CHECK( 6.626070040e-34*joule*second == constants[ physics::h ] );
  CHECK( 8.1e-42*joule*second == uncertainties[ physics::h ] );
  CHECK( 1.0545718000e-34*joule*second == constants[ physics::hbar ] );
  CHECK( 1.3e-42*joule*second == uncertainties[ physics::hbar ] );
  CHECK( 1.0545718000e-34*joule*second == constants[ physics::reducedPlanck ] );
  CHECK( 1.3e-42*joule*second == uncertainties[ physics::reducedPlanck ] );
  CHECK( 1.6021766208e-19*coulomb == constants[ physics::elementaryCharge ] );
  CHECK( 9.8e-28*coulomb == uncertainties[ physics::elementaryCharge ] );

  // Masses
  auto kg = kilo( gram );
  CHECK( 6.644657230e-27*kg == constants[ physics::alphaMass ] );
  CHECK( 0.000000082e-27*kg == uncertainties[ physics::alphaMass ] );

  CHECK( 1.674927471e-27*kg == constants[ physics::neutronMass ] );
  CHECK( 0.000000021e-27*kg == uncertainties[ physics::neutronMass ] );

  CHECK( 9.10938356e-31*kg == constants[ physics::electronMass ] );
  CHECK( 0.00000011e-31*kg == uncertainties[ physics::electronMass ] );

  CHECK( 1.672621898e-27*kg == constants[ physics::protonMass ] );
  CHECK( 0.000000021e-27*kg == uncertainties[ physics::protonMass ] );

  CHECK( 3.343583719e-27*kg == constants[ physics::deuteronMass ] );
  CHECK( 0.000000041e-27*kg == uncertainties[ physics::deuteronMass ] );

  CHECK( 5.007356665e-27*kg == constants[ physics::tritonMass ] );
  CHECK( 0.000000062e-27*kg == uncertainties[ physics::tritonMass ] );

  CHECK( 5.006412700e-27*kg == constants[ physics::helionMass ] );
  CHECK( 0.000000062e-27*kg == uncertainties[ physics::helionMass ] );
}
