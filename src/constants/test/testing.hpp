#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <range/v3/all.hpp>

using namespace njoy::constants;

auto stringFor = hana::make_map(
  hana::make_pair( avogadro, std::string{ "Avogadro constant" } ),
  hana::make_pair( boltzmann, std::string{ "Boltzmann constant" } ),
  hana::make_pair( elementaryCharge, std::string{ "elementary charge" } ),
  hana::make_pair( k, std::string{ "Boltzmann constant" } ),
  hana::make_pair( G, std::string{ "Newtonian constant of gravitation" } ),
  hana::make_pair( newtonianGravitation, std::string{ "Newtonian constant of gravitation" } ),
  hana::make_pair( planck, std::string{ "Planck constant" } ),
  hana::make_pair( h, std::string{ "Planck constant" } ),
  hana::make_pair( hbar, std::string{ "Planck constant over 2 pi" } ),
  hana::make_pair( c, std::string{ "speed of light in vacuum" } ),
  hana::make_pair( speedOfLight, std::string{ "speed of light in vacuum" } ),

  // Masses
  hana::make_pair( electronMass, std::string{ "electron mass" } ),
  hana::make_pair( neutronMass, std::string{ "neutron mass" } ),
  hana::make_pair( protonMass, std::string{ "proton mass" } ),
  hana::make_pair( deuteronMass, std::string{ "deuteron mass" } ),
  hana::make_pair( helionMass, std::string{ "helion mass" } ),
  hana::make_pair( tritonMass, std::string{ "triton mass" } ),
  hana::make_pair( alphaMass, std::string{ "alpha particle mass" } )
);

auto toValue = []( auto& line, int begin, int end ){
  auto v = ranges::to_< std::string >( 
    line 
      | ranges::view::slice( begin, end )
      | ranges::view::filter( []( auto&& e ){ return not std::isspace( e ); } )
  );
  return v == "(exact)" ? 0.0 :  std::stod( v ); 
};

auto split = []( auto line ){
  auto key = ranges::to_< std::string >( 
    line 
      | ranges::view::slice( 0, 60 )
      | ranges::view::reverse
      | ranges::view::drop_while( []( auto&& e ){ return std::isspace( e ); } )
      | ranges::view::reverse
  );
  auto value = toValue( line, 60, 85 );
  auto uncert = toValue( line, 85, 110 );

  return std::make_pair( key, std::make_pair( value, uncert ) );
};

auto defineReferenceValues( std::istream&& is ){
  auto result = ranges::getlines( is )
    | ranges::view::drop( 10 )
    | ranges::view::transform( split )
    | ranges::to_vector;

  return ranges::to_< 
    std::map< std::string, std::pair< double, double > > >( result );
}
