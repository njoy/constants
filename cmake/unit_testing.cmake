#######################################################################
# Setup
#######################################################################

message( STATUS "Adding constants unit testing" )
enable_testing()


#######################################################################
# Unit testing directories
#######################################################################

add_subdirectory( src/constants/CODATA2014/test )
add_subdirectory( src/constants/CODATA2018/test )
add_subdirectory( src/constants/math/test )
