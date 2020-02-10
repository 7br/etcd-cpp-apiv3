file(GLOB_RECURSE CPP_CLIENT_SRC RELATIVE "${CMAKE_SOURCE_DIR}/src"
                  "${CMAKE_SOURCE_DIR}/proto/*.cc"
                  "${CMAKE_SOURCE_DIR}/src/*.cpp"
                  "${CMAKE_SOURCE_DIR}/v3/src/*.cpp")

add_library(etcd-cpp-api SHARED ${CPP_CLIENT_SRC})
set_property(TARGET etcd-cpp-api PROPERTY CXX_STANDARD 11)
target_include_directories(etcd-cpp-api PRIVATE ${CMAKE_SOURCE_DIR}/proto)

target_link_libraries(etcd-cpp-api
                      ${CPPREST_LIB}
                      ${Boost_LIBRARIES}
                      ${PROTOBUF_LIBRARIES}
                      ${OPENSSL_LIBRARIES}
                      ${GRPC_LIBRARIES})

install (TARGETS etcd-cpp-api DESTINATION lib)
install (FILES ../etcd/Client.hpp
               ../etcd/SyncClient.hpp
               ../etcd/Response.hpp
               ../etcd/Value.hpp
               ../etcd/Watcher.hpp
               DESTINATION include/etcd)

