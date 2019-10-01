#define CONSTANT_TYPE( NAME ) \
 \
  struct NAME##_t : hana::type< NAME##_t >{}; \
  static constexpr NAME##_t NAME{}

CONSTANT_TYPE( avogadro );
CONSTANT_TYPE( boltzmann );
CONSTANT_TYPE( conductanceQuantum );
CONSTANT_TYPE( electric );
CONSTANT_TYPE( electronRadius );
CONSTANT_TYPE( elementaryCharge );
CONSTANT_TYPE( faraday );
CONSTANT_TYPE( fineStructure );
CONSTANT_TYPE( magnetic );
CONSTANT_TYPE( magneticFluxQuantum );
CONSTANT_TYPE( molarGas );
CONSTANT_TYPE( newtonianGravitation );
CONSTANT_TYPE( planck );
CONSTANT_TYPE( rydberg );
CONSTANT_TYPE( speedOfLight );
CONSTANT_TYPE( stefanBoltzmann );

CONSTANT_TYPE( electronMass );
CONSTANT_TYPE( neutronMass );
CONSTANT_TYPE( protonMass );
CONSTANT_TYPE( deuteronMass );
CONSTANT_TYPE( helionMass );
CONSTANT_TYPE( tritonMass );
CONSTANT_TYPE( alphaMass );

#undef CONSTANT_TYPE

#define ALIAS( original, alias )  static constexpr auto alias = original
  ALIAS( boltzmann, k );
  ALIAS( planck, h );
  ALIAS( newtonianGravitation, G );
  ALIAS( speedOfLight, c );
  ALIAS( conductanceQuantum, G0 );

#undef ALIAS
