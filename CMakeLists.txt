project(webrtc)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

set(sctp_build_programs OFF)
add_subdirectory(usrsctp)

# Need https://stackoverflow.com/questions/37719094/is-it-possible-to-link-a-cmake-project-to-subprojects
set(USRSCTP_LIBRARY ${CMAKE_SOURCE_DIR}/usrsctp/usrsctplib/libusrsctp.so)
set(USRSCTP_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/usrsctp/usrsctplib)
set(DISABLE_SPDLOG ON)
add_subdirectory(librtcdcpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})

