#ifndef NJOY_CONSTANTS_CODATA2014_HPP
#define NJOY_CONSTANTS_CODATA2014_HPP

#include "constants.hpp"

namespace njoy {
namespace constants {

static constexpr auto CODATA2014 = addUncertainty(
  hana::make_map(
    hana::make_pair( avogadro     , 6.022140857e23/mole ),
    hana::make_pair( boltzmann    , 1.38064852e-23*joule/kelvin ),
    hana::make_pair( conductanceQuantum, 7.7480917310e-5*siemens ),
    hana::make_pair( electric, 8.854187817e-12*farad/meter ),
    hana::make_pair( electronRadius, 2.8179403227e-15*meter ),
    hana::make_pair( elementaryCharge, 1.6021766208e-19*coulomb ),
    hana::make_pair( faraday, 9.648533289e4*coulomb/mole ),
    hana::make_pair( fineStructure, 7.2973525664e-3*meter/meter ),
    hana::make_pair( magnetic, 12.566370614e-7*newton/ampere/ampere ),
    hana::make_pair( magneticFluxQuantum, 2.067833831e-15*weber ),
    hana::make_pair( molarGas, 8.3144598*joule/mole/kelvin ),
    hana::make_pair( newtonianGravitation,
      6.67408e-11*meter*meter*meter/kilo( gram )/second/second ),
    hana::make_pair( planck       , 6.626070040e-34*joule*second ),
    hana::make_pair( reducedPlanck, 1.054571800e-34*joule*second ),
    hana::make_pair( rydberg, 1.0973731568508e7/meter ),
    hana::make_pair( speedOfLight , 2.99792458e8*meter/second ),
    hana::make_pair( stefanBoltzmann,
      5.670367e-8*watt/meter/meter/kelvin/kelvin/kelvin/kelvin ),

    // Masses
    hana::make_pair( electronMass , 9.10938356e-31*kilo( gram ) ),
    hana::make_pair( neutronMass  , 1.674927471e-27*kilo( gram ) ),
    hana::make_pair( protonMass   , 1.672621898e-27*kilo( gram ) ),
    hana::make_pair( deuteronMass , 3.343583719e-27*kilo( gram ) ),
    hana::make_pair( helionMass   , 5.0064127000e-27*kilo( gram ) ),
    hana::make_pair( tritonMass   , 5.007356665e-27*kilo( gram ) ),
    hana::make_pair( alphaMass    , 6.644657230e-27*kilo( gram ) )
  ),
  // Uncertainties
  hana::make_map(
    hana::make_pair( avogadro     , 0.000000074e23/mole ),
    hana::make_pair( boltzmann    , 0.00000079e-23*joule/kelvin ),
    hana::make_pair( electric, 0.0*farad/meter ),
    hana::make_pair( electronRadius, 1.9e-24*meter ),
    hana::make_pair( elementaryCharge, 0.0000000098e-19*coulomb ),
    hana::make_pair( faraday, 5.9e-4*coulomb/mole ),
    hana::make_pair( fineStructure, 1.7e-12*meter/meter ),
    hana::make_pair( conductanceQuantum, 1.8E-14*siemens ),
    hana::make_pair( magnetic, 0.0*newton/ampere/ampere ),
    hana::make_pair( magneticFluxQuantum, 1.3e-23*weber ),
    hana::make_pair( molarGas, 4.8e-6*joule/mole/kelvin ),
    hana::make_pair( newtonianGravitation,
                    0.00031e-11*meter*meter*meter/kilo( gram )/second/second ),
    hana::make_pair( planck       , 0.000000081e-34*joule*second ),
    hana::make_pair( reducedPlanck, 0.000000013e-34*joule*second ),
    hana::make_pair( rydberg, 6.5e-5/meter ),
    hana::make_pair( speedOfLight , 0.0*meter/second ),
    hana::make_pair( stefanBoltzmann,
                     1.3e-13*watt/meter/meter/kelvin/kelvin/kelvin/kelvin ),

    // Masses
    hana::make_pair( electronMass , 0.00000011e-31*kilo( gram ) ),
    hana::make_pair( neutronMass  , 0.000000021e-27*kilo( gram ) ),
    hana::make_pair( protonMass   , 0.000000021e-27*kilo( gram ) ),
    hana::make_pair( deuteronMass , 0.000000041e-27*kilo( gram ) ),
    hana::make_pair( helionMass   , 0.000000062e-27*kilo( gram ) ),
    hana::make_pair( tritonMass   , 0.000000062e-27*kilo( gram ) ),
    hana::make_pair( alphaMass    , 0.000000082e-27*kilo( gram ) )
  )
);

}
}
#endif // NJOY_CONSTANTS_CODATA2014_HPP
