template< typename Base1, typename Base2 >
struct map: Base1{
  Base2 uncertainty;
  constexpr map(Base1 b1, Base2 b2 ):
    Base1( b1 ),
    uncertainty( b2 )
  { }
};
