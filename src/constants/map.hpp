template< typename Values, typename Uncertainty >
struct Map_t{
private:
  Values values;
public:
  Uncertainty uncertainty;

  constexpr Map_t( Values v, Uncertainty u ):
    values( v ),
    uncertainty( u )
  { }

  template <typename Key>
  constexpr decltype(auto) operator[](Key&& key) & {
    return static_cast<Values&>(values)[
        std::forward<Key>(key)];
  }
  template <typename Key>
  constexpr decltype(auto) operator[](Key&& key) && {
    return static_cast<Values&&>(values)[
        std::forward<Key>(key)];
  }
  template <typename Key>
  constexpr decltype(auto) operator[](Key&& key) const& {
    return static_cast<Values const&>(values)[
        std::forward<Key>(key)];
  }
};

// Deduction guide
template< typename Values, typename Keys >
Map_t( Values values, Keys keys ) -> Map_t< Values, Keys >;

