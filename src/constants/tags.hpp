#ifndef NJOY_CONSTANTS_TAGS_HPP
#define NJOY_CONSTANTS_TAGS_HPP

#define CONSTANT_TYPE( NAME ) \
 \
  struct NAME##_t : hana::type< NAME##_t >{}; \
  static constexpr NAME##_t NAME{}; \

CONSTANT_TYPE( avogadro );
CONSTANT_TYPE( boltzmann );
// CONSTANT_TYPE( k );
CONSTANT_TYPE( elementaryCharge );
// CONSTANT_TYPE( G );
CONSTANT_TYPE( newtonianGravitation );
CONSTANT_TYPE( planck );
// CONSTANT_TYPE( h );
CONSTANT_TYPE( speedOfLight );
// CONSTANT_TYPE( c );

CONSTANT_TYPE( electronMass );
CONSTANT_TYPE( neutronMass );
CONSTANT_TYPE( protonMass );
CONSTANT_TYPE( deuteronMass );
CONSTANT_TYPE( helionMass );
CONSTANT_TYPE( tritonMass );
CONSTANT_TYPE( alphaMass );

#undef CONSTANT_TYPE

#define ALIAS( original, alias )  static constexpr auto alias = original;
  ALIAS( boltzmann, k );
  ALIAS( planck, h );
  ALIAS( newtonianGravitation, G );
  ALIAS( speedOfLight, c );

#undef ALIAS

#endif  // NJOY_CONSTANTS_TAGS_HPP
