cmake_minimum_required( VERSION 3.14 )
include( FetchContent )

#######################################################################
# Declare project dependencies
#######################################################################

FetchContent_Declare( range-v3-adapter
    GIT_REPOSITORY  https://github.com/njoy/range-v3-adapter
    GIT_TAG         origin/master
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( catch-adapter
    GIT_REPOSITORY  https://github.com/njoy/catch-adapter
    GIT_TAG         origin/master
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( Log
    GIT_REPOSITORY  https://github.com/njoy/Log
    GIT_TAG         origin/master
    GIT_SHALLOW     TRUE
    )

FetchContent_Declare( dimwits
    GIT_REPOSITORY  https://github.com/njoy/DimensionalAnalysis
    GIT_TAG         origin/master
    GIT_SHALLOW     TRUE
    )

#######################################################################
# Load dependencies
#######################################################################

FetchContent_MakeAvailable(
    range-v3-adapter
    catch-adapter
    Log
    dimwits
    )
