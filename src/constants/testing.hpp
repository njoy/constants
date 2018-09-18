#include <iostream>
#include <map>
#include <range/v3/all.hpp>

auto stringFor = hana::make_map(
  hana::make_pair(njoy::constants::physics::speedOfLight, std::string{"speed of light in vacuum"})
);


auto toPair = [](auto splitLine){ 
  auto entries = splitLine 
    | ranges::view::take(2)
    | ranges::view::transform(ranges::to_<std::string>)
    | ranges::to_vector;
  return std::make_pair(entries.front(), std::stod(entries.back()));
};

auto defineReferenceValues( std::istream&& is ){
  return ranges::getlines(is)
    | ranges::view::drop(10)
    | ranges::view::transform(ranges::view::split)
    | ranges::view::transform(toPair)
    | ranges::to_<std::map<std::string,double>>;
}
