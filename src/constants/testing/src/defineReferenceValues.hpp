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

decltype( auto ) defineReferenceValues( std::istream&& is ){
  auto result = ranges::getlines( is )
    | ranges::view::drop( 11 )
    | ranges::view::transform( testing::split )
    | ranges::to_vector;

  return ranges::to_<
    std::map< std::string, std::pair< double, double > > >( result );
}
