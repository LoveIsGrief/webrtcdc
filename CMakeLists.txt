project(webrtc)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)
aux_source_directory(. SRC_LIST)

# Add libusrcp dep for librtcdcpp
set(sctp_build_programs OFF)
add_subdirectory(usrsctp)

# https://stackoverflow.com/questions/37719094/is-it-possible-to-link-a-cmake-project-to-subprojects
# Point to libusrsctp so that find_package in librtcdcpp can find it
set(USRSCTP_LIBRARY ${CMAKE_BINARY_DIR}/usrsctp/usrsctplib/libusrsctp.so)
set(USRSCTP_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/usrsctp/usrsctplib)

set(DISABLE_SPDLOG ON)
add_subdirectory(librtcdcpp)
add_dependencies(rtcdcpp usrsctp)

# Our main program
add_executable(${PROJECT_NAME} ${SRC_LIST})

# Include librtcdcpp in the executable
target_link_libraries(${PROJECT_NAME} PUBLIC rtcdcpp)
