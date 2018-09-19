[![Build Status](http://jenkins.njoy21.io:8080/buildStatus/icon?job=constants)](http://jenkins.njoy21.io:8080/job/constants/)

# constants
This repository contains a collection of mathematical and physical constants. Additional information about the constants provided&mdash;and their values&mdash; see the associated README files.

**Note:** For the mathematical constants, their values are actually given in three places in this repository:

1. in the associated `README.md` files;
2. in the header file that defines the value for C++; and
3. in the files used to test/verify the values.
While every effort is made to ensure that each of these values are the same, inconsistencies may appear. If discovered, please [file an issue](https://github.com/njoy/constants/issues).

## Mathematical Constants
The (short) list of mathematical constants was taken from [Wikipedia:Mathematical constant](https://en.wikipedia.org/wiki/Mathematical_constant). While there are many more constants given there, we have limited this initially to the [Basic mathematical constants](https://en.wikipedia.org/wiki/Mathematical_constant#Basic_mathematical_constants).

| Name                      | Variable name | Value                 | Reference                                                 | Reference Date | 
| ----                      | ------------- | -----                 | ---------                                                 | --------       | 
| Archimedes constant (π)   | `pi`          | 3.141 592 653 589 793 | [http://mathworld.wolfram.com/Pi.html]()                  | 2018-09-13     | 
| Euler's number (e)        | `e`           | 2.718 281 828 459 045 | [http://mathworld.wolfram.com/e.html]()                   | 2018-09-13     | 
| Pythagoras' constant (√2) | `root2`       | 1.414 213 562 373 095 | [http://mathworld.wolfram.com/PythagorassConstant.html]() | 2018-09-13     | 

## Physical Constants
Unlike mathematical constants, physical constants can change based on the current understanding and measurement capabilities of physics. Thus we can have different versions of the constants. 

The worldwide standard for the physical constants is maintained by [Committee on Data of the International Council for Science (CODATA)](https://www.codata.org). We have taken our physical constant values from their publication.

For each CODATA release, we provide two maps; one for the data values and one for their associated uncertainty. The keys are the same in both maps. There are some physical constants that are defined to be exact (e.g., the speed of light). Their uncertainty, is, therefore, zero.

### CODATA2014
The raw data for this is contained in [CODATA2014.txt](resources/CODATA2014.txt) which was downloaded from [https://physics.nist.gov/cuu/Constants/Table/allascii.txt](https://physics.nist.gov/cuu/Constants/Table/allascii.txt) on 2018-09-13.

#### Constants
| Quantity                          | Variable name      | Value               | Uncertainty         | Unit           | 
| --------                          | -------------      | ----                | ------              | ------         | 
| Avogadro constant                 | `avogadro`         | 6.022 140 857 e23   | 0.000 000 074 e23   | mol^-1         | 
| Boltzmann constant                | `boltzmann`        | 1.380 648 52  e-23  | 0.000 000 79  e-23  | J K^-1         | 
| Boltzmann constant                | `k`                | 1.380 648 52  e-23  | 0.000 000 79  e-23  | J K^-1         | 
| Elementary charge                 | `elementaryCharge` | 1.602 176 6208 e-19 | 0.000 000 0098 e-19 | C              | 
| Newtonian constant of gravitation | `G`                | 6.674 08 e-11       | 0.000 31 e-11       | m^3 kg^-1 s^-2 | 
| Newtonian constant of gravitation | `newtonianGravity` | 6.674 08 e-11       | 0.000 31 e-11       | m^3 kg^-1 s^-2 | 
| Planck constant                   | `planck`           | 6.626 070 040 e-34  | 0.000 000 081 e-34  | J s            | 
| Planck constant                   | `h`                | 6.626 070 040 e-34  | 0.000 000 081 e-34  | J s            | 
| Speed of light in a vacuum        | `c`                | 2.997 924 58  e8    | 0.0                 | m s^-1         | 
| Speed of light in a vacuum        | `speedOfLight`     | 2.997 924 58  e8    | 0.0                 | m s^-1         | 

#### Particle masses
| Quantity                          | Variable name      | Value               | Uncertainty         | Unit           | 
| --------                          | -------------      | ----                | ------              | ------         | 
| electron mass                     | `electronMass`     | 9.109 383 56 e-31   | 0.000 000 11 e-31   | kg             | 
| neutron mass                      | `neutronMass`      | 1.674 927 471 e-27  | 0.000 000 021 e-27  | kg             | 
| proton mass                       | `protonMass`       | 1.672 621 898 e-27  | 0.000 000 021 e-27  | kg             | 
| deuteron mass                     | `deuteronMass`     | 3.343 583 719 e-27  | 0.000 000 041 e-27  | kg             | 
| helion mass                       | `helionMass`       | 5.006 412 700 e-27  | 0.000 000 062 e-27  | kg             | 
| triton mass                       | `tritonMass`       | 5.007 356 665 e-27  | 0.000 000 062 e-27  | kg             | 
| alpha particle mass               | `alphaMass`        | 6.644 657 230 e-27  | 0.000 000 082 e-27  | kg             | 


## Derived Constants
Some constants are derived from others, but used sufficiently often that it is worth pre-computing the values. Their values are not listed here, but the variable names are.

 | Quanitity      | Value           | Unit | 
 | ----           | -----           | ---- | 
 | Reduced Planck | `hbar`          | J s  | 
 | Reduced Planck | `reducedPlanck` | J s  | 


## Using the constants
Here is an example of how the mathematical constants can be used.
```cpp
#include "constants.hpp"

double r{1.0};

auto area = njoy::constants::pi*r**2;

auto CODATA = njoy::constants::CODATA2014;

auto c = CODATA[c];
auto cUncertainty = CODATA.uncertainty[c]; // 0.0
auto h = CODATA[Planck];
auto hUncertainty = CODATA.uncertainty[Planck];
```

## A note on floating point arithmetic 
Some values of these constants are known to much greater precision than what we have reported here (e.g., `pi` and `e`.) We have limited the number of significant digits in this repository to 16 as anything more would be insignificant in floating point arithmetic.

## LICENSE
This software is copyrighted by Los Alamos National Laboratory and distributed according to the conditions in the accompanying [LICENSE](LICENSE) file. 
