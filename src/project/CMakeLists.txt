cmake_minimum_required(VERSION 3.15)
project(hlluajit) # This decides the DLL name!

# Defines
set(HASHLINK_PATH "$ENV{HASHLINK}" CACHE PATH "Path to HashLink installation")

# Libraries
add_library(${CMAKE_PROJECT_NAME} SHARED fuckyou.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib/Windows/lua51.lib)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/include")
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${HASHLINK_PATH}/include")

# Give HashLink our HDLL
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME}
    POST_BUILD
    COMMAND cp ${CMAKE_CURRENT_BINARY_DIR}/Release/${CMAKE_PROJECT_NAME}.dll ${HASHLINK_PATH}/${CMAKE_PROJECT_NAME}.hdll
    COMMENT "Copying hdll to HashLink directory..."
    VERBATIM
)

# Give HashLink our LIB
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME}
    POST_BUILD
    COMMAND cp ${CMAKE_CURRENT_BINARY_DIR}/Release/${CMAKE_PROJECT_NAME}.lib ${HASHLINK_PATH}
    VERBATIM
)