struct ReducedPlanck : hana::type< ReducedPlanck >{
  template< typename MAP >
  constexpr decltype( auto ) operator()( MAP&& map ) const {
    return map[ planck ]/( twopi );
  }
};

ReducedPlanck hbar;
