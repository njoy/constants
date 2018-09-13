# constants
This repository contains a collection of mathematical and physical constants. 

**Note:** For the mathematical constants, their values are actually given in three places in this repository:

1. Here in the `README.md` file,
2. In the header file that defines the value for C++, and
3. In the files used to test/verify the values.
While every effort is made to ensure that each of these values are the same, inconsistencies may appear. If discovered, please [file an issue](https://github.com/njoy/constants/issues).

## Mathematical Constants
The (short) list of mathematical constants was taken from [Wikipedia:Mathematical constant](https://en.wikipedia.org/wiki/Mathematical_constant). While there are many more constants given there, we have limited this initially to the [Basic mathematical constants](https://en.wikipedia.org/wiki/Mathematical_constant#Basic_mathematical_constants).

  | Name                      | Variable name | Value               | Reference                                                 | Reference Date | 
  | ----                      | ------------- | -----               | ---------                                                 | 
  | Archimedes constant (π)   | `pi`          | `3.141592653589793` | [http://mathworld.wolfram.com/Pi.html]()                  | 2018-09-13     | 
  | Euler's number (e)        | `e`           | `2.718281828459045` | [http://mathworld.wolfram.com/e.html]()                   | 2018-09-13     | 
  | Pythagoras' constant (√2) | `root2`       | `1.414213562373095` | [http://mathworld.wolfram.com/PythagorassConstant.html]() | 2018-09-13     | 


### Using mathematical constants
Here is an example of how the mathematical constants can be used.
```cpp
#include "constants/math.hpp"

double r{1.0};

auto area = njoy::constants::math::pi*r**2;
```

## Physical Constants
Unlike mathematical constants, physical constants can change based on the current understanding and measurement capabilities of physics. Thus we can have different versions of the constants. 

The worldwide standard for the physical constants is maintained by [Committee on Data of the International Council for Science (CODATA)](https://www.codata.org). We have taken our physical constant values from their publication. For information about what values are maintained in this repository, see the respective README files:

- [CODATA2014](src/constants/physics/CODATA2014/README.md)
- CODATA2018 This should be published in 2019. We will update the repository after the publication.

For each CODATA release, we provide two maps; one for the data values and one for their associated uncertainty. The keys are the same in both maps. There are some physical constants that are defined to be exact (e.g., the speed of light). Their uncertainty, is, therefore, zero.

```cpp

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
