#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <range/v3/all.hpp>

using namespace njoy;

auto stringFor = hana::make_map(
  hana::make_pair( constants::speedOfLight, 
                   std::string{"speed of light in vacuum"})
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
