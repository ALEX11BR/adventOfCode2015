add_executable(d4p1 p1.cpp)
add_executable(d4p2 p2.cpp)

find_package(OpenSSL)
target_link_libraries(d4p1 PRIVATE OpenSSL::Crypto)
target_link_libraries(d4p2 PRIVATE OpenSSL::Crypto)
