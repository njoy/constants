template< typename Values, typename Uncertainty >
constexpr auto addUncertainty(Values&& values, Uncertainty&& uncertainty ) {
  return map< Values, Uncertainty >( values, uncertainty );
}
