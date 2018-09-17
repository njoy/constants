[![Build Status](http://jenkins.njoy21.io:8080/buildStatus/icon?job=constants)](http://jenkins.njoy21.io:8080/job/constants/)

# constants
This repository contains a collection of [mathematical](src/constants/math/README.md) and [physical](src/constants/physics/README.md) constants. Additional information about the constants provided&mdash;and their values&mdash; see the associated README files.

**Note:** For the mathematical constants, their values are actually given in three places in this repository:

1. in the associated `README.md` files;
2. in the header file that defines the value for C++; and
3. in the files used to test/verify the values.
While every effort is made to ensure that each of these values are the same, inconsistencies may appear. If discovered, please [file an issue](https://github.com/njoy/constants/issues).


### Using the constants
Here is an example of how the mathematical constants can be used.
```cpp
#include "constants/math.hpp"

double r{1.0};

auto area = njoy::constants::math::pi*r**2;

#include "constants/physics/CODATA2014.hpp"

auto CODATA = njoy::constants::CODATA2014;
auto CODATAUncertainty = njoy::constants::CODATA2014Uncertainty;

auto c = CODATA[c];
auto cUncertainty = CODATAUncertainty[c]; // 0.0
auto hbar = CODATA[Planck];
auto hbarUncertainty = CODATAUncertainty[Planck];
```

## A note on floating point arithmetic 
Some values of these constants are known to much greater precision than what we have reported here (e.g., `pi` and `e`.) We have limited the number of significant digits in this repository to 16 as anything more would be insignificant in floating point arithmetic.

## LICENSE
This software is copyrighted by Los Alamos National Laboratory and distributed according to the conditions in the accompanying [LICENSE](LICENSE) file. 
