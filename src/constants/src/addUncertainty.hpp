template< typename Base1, typename Base2 >
constexpr auto addUncertainty(Base1 values, Base2 uncertainty ) {
  return map< Base1, Base2 >( values, uncertainty );
}
