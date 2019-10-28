#ifndef NJOY_CONSTANTS_CODATA2018_HPP
#define NJOY_CONSTANTS_CODATA2018_HPP

#include "constants.hpp"

namespace njoy {
namespace constants {

static constexpr auto CODATA2018 = addUncertainty(
  hana::make_map(
    hana::make_pair( avogadro     , 6.02214076e23/mole ),
    hana::make_pair( boltzmann    , 1.380649e-23*joule/kelvin ),
    hana::make_pair( conductanceQuantum, 7.748091729e-5*siemens ),
    hana::make_pair( electric, 8.8541878128e-12*farad/meter ),
    hana::make_pair( electronRadius, 2.8179403262e-15*meter ),
    hana::make_pair( elementaryCharge, 1.602176634e-19*coulomb ),
    hana::make_pair( faraday, 9.648533212e4*coulomb/mole ),
    hana::make_pair( fineStructure, 7.2973525693e-3*meter/meter ),
    hana::make_pair( magnetic, 1.25663706212e-6*newton/ampere/ampere ),
    hana::make_pair( magneticFluxQuantum, 2.067833848e-15*weber ),
    hana::make_pair( molarGas, 8.314462618*joule/mole/kelvin ),
    hana::make_pair( newtonianGravitation, 
      6.67430e-11*meter*meter*meter/kilo( gram )/second/second ),
    hana::make_pair( planck       , 6.62607015e-34*joule*second ),
    hana::make_pair( reducedPlanck, 1.054571817e-34*joule*second ),
    hana::make_pair( rydberg, 1.0973731568160e7/meter ),
    hana::make_pair( speedOfLight , 2.99792458e8*meter/second ),
    hana::make_pair( stefanBoltzmann, 
      5.670374419e-8*watt/meter/meter/kelvin/kelvin/kelvin/kelvin ),

    // Masses
    hana::make_pair( electronMass , 9.1093837015e-31*kilo( gram ) ),
    hana::make_pair( neutronMass  , 1.67492749804e-27*kilo( gram ) ),
    hana::make_pair( protonMass   , 1.67262192369e-27*kilo( gram ) ),
    hana::make_pair( deuteronMass , 3.3435837724e-27*kilo( gram ) ),
    hana::make_pair( helionMass   , 5.0064127796e-27*kilo( gram ) ),
    hana::make_pair( tritonMass   , 5.0073567446e-27*kilo( gram ) ),
    hana::make_pair( alphaMass    , 6.6446573357e-27*kilo( gram ) )
  ),
  // Uncertainties
  hana::make_map(
    hana::make_pair( avogadro     , 0.0/mole ),
    hana::make_pair( boltzmann    , 0.0*joule/kelvin  ),
    hana::make_pair( conductanceQuantum, 0.0*siemens ),
    hana::make_pair( electric, 1.3e-21*farad/meter ),
    hana::make_pair( electronRadius, 1.3e-24*meter ),
    hana::make_pair( elementaryCharge, 0.0*coulomb ),
    hana::make_pair( faraday, 0.0*coulomb/mole ),
    hana::make_pair( fineStructure, 1.1e-12*meter/meter ),
    hana::make_pair( magnetic, 1.9e-16*newton/ampere/ampere ),
    hana::make_pair( magneticFluxQuantum, 0.0*weber ),
    hana::make_pair( molarGas, 0.0*joule/mole/kelvin ),
    hana::make_pair( newtonianGravitation, 
                    1.5e-15*meter*meter*meter/kilo( gram )/second/second ),
    hana::make_pair( planck       , 0.0*joule*second ),
    hana::make_pair( reducedPlanck, 0.0*joule*second ),
    hana::make_pair( rydberg, 2.1e-5/meter ),
    hana::make_pair( speedOfLight , 0.0*meter/second ),
    hana::make_pair( stefanBoltzmann, 
                     0.0*watt/meter/meter/kelvin/kelvin/kelvin/kelvin ),

    // Masses
    hana::make_pair( electronMass , 0.0000000028e-31*kilo( gram ) ),
    hana::make_pair( neutronMass  , 0.00000000095e-27*kilo( gram ) ),
    hana::make_pair( protonMass   , 0.00000000051e-27*kilo( gram ) ),
    hana::make_pair( deuteronMass , 0.0000000010e-27*kilo( gram ) ),
    hana::make_pair( helionMass   , 0.0000000015e-27*kilo( gram ) ),
    hana::make_pair( tritonMass   , 0.0000000015e-27*kilo( gram ) ),
    hana::make_pair( alphaMass    , 0.0000000020e-27*kilo( gram ) )
  )
);

} // namespace constants
} // namespace njoy
#endif // NJOY_CONSTANTS_CODATA2018_HPP
