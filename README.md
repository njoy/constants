r constants
This repository contains a collection of mathematical and physical constants. 

**Note:** For the constants given here, their values are actually given in three places in this repository:

1. Here in the `README.md` file,
2. In the header file that defines the value for C++, and
3. In the files used to test/verify the value.
While every effort is made to ensure that each of these values are the same, inconsistencies may appear. If discovered, please [file an issue](https://github.com/njoy/constants/issues).

## Mathematical Constants
The (short) list of mathematical constants was taken from [Wikipedia:Mathematical constant](https://en.wikipedia.org/wiki/Mathematical_constant). While there are many more constants given there, we have limited this initially to the [Basic mathematical constants](https://en.wikipedia.org/wiki/Mathematical_constant#Basic_mathematical_constants).

  | Name                      | Variable name | Value               | Reference                                                 | Reference Date | 
  | ----                      | ------------- | -----               | ---------                                                 | 
  | Archimedes constant (π)   | `pi`          | `3.141592653589793` | [http://mathworld.wolfram.com/Pi.html]()                  | 2018-09-13     | 
  | Euler's number (e)        | `e`           | `2.718281828459045` | [http://mathworld.wolfram.com/e.html]()                   | 2018-09-13     | 
  | Pythagoras' constant (√2) | `root2`       | `1.414213562373095` | [http://mathworld.wolfram.com/PythagorassConstant.html]() | 2018-09-13     | 

### Using mathematical constants

```cpp
#include "constants/math.hpp"

double r{1.0};

auto area = njoy::constants::math::pi*r**2;
```

## A note on floating point arithmetic 
Some values of these constants are known to much greater precision than what we have reported here (e.g., `pi` and `e`.) We have limited the number of significant digits in this repository to 16 as anything more would be insignificant in floating point arithmetic.

## LICENSE
This software is copyrighted by Los Alamos National Laboratory and distributed according to the conditions in the accompanying [LICENSE](LICENSE) file. 
