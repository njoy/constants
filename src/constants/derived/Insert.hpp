struct Insert {
  template< typename MAP, typename C >
  constexpr decltype( auto ) operator()( MAP map, C callable ) const{
    return hana::insert( map, hana::make_pair( callable, callable( map ) ) );
  }
};
static constexpr Insert insert{};
