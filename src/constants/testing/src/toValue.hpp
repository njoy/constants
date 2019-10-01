template< typename L >
decltype( auto ) toValue( L&& line, int begin, int end ){
  auto v = ranges::to_< std::string >(
    line
      | ranges::view::slice( begin, end )
      | ranges::view::adjacent_remove_if( []( auto&& e1, auto&& e2 ){
        return (e1 == '.') and ( (e2 == '.') or ( std::isspace( e2 ) ) ); } )
      | ranges::view::filter( [](auto&& e ){ return not std::isspace( e ); } )
    );
  return v == "(exact)" ? 0.0 :  std::stod( v );
}
