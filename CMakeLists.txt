########################################################################
# Preamble
########################################################################

cmake_minimum_required( VERSION 3.16 )
project( constants LANGUAGES CXX )

########################################################################
# Dependencies
########################################################################

include( cmake/constants_dependencies.cmake )

########################################################################
# Project targets
########################################################################

add_library( constants INTERFACE )
target_include_directories( constants INTERFACE src/ )
target_link_libraries( constants
    INTERFACE range-v3-adapter
    INTERFACE catch-adapter
    INTERFACE Log
    INTERFACE dimwits
    )
