struct ReducedPlanck : hana::type< ReducedPlanck >{
  template< typename MAP >
  constexpr decltype( auto ) operator()( MAP&& map ) const {
    return map[ planck ]/( 2*pi );
  }
};
// static constexpr ReducedPlanck reducedPlanck;
static constexpr ReducedPlanck hbar;
