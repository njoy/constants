template< typename Values, typename Uncertainty >
struct map{
private:
  Values values;
public:
  Uncertainty uncertainty;

  constexpr map(Values v, Uncertainty u ):
    Values( v ),
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
map( Values values, Keys keys ) -> map< Values, Keys >;

