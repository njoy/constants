template< typename Value, typename Uncertainty >
struct Map_t{
  Value value;
  Uncertainty uncertainty;

  constexpr Map_t( Value v, Uncertainty u ):
    value( v ),
    uncertainty( u )
  { }

  template <typename Key>
  constexpr decltype(auto) operator[](Key&& key) & {
    return static_cast<Value&>(value)[
        std::forward<Key>(key)];
  }
  template <typename Key>
  constexpr decltype(auto) operator[](Key&& key) && {
    return static_cast<Value&&>(value)[
        std::forward<Key>(key)];
  }
  template <typename Key>
  constexpr decltype(auto) operator[](Key&& key) const& {
    return static_cast<Value const&>(value)[
        std::forward<Key>(key)];
  }
};

// Deduction guide
template< typename Value, typename Keys >
Map_t( Value value, Keys keys ) -> Map_t< Value, Keys >;

