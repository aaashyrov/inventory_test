set(NAME libinventory)

set(HDRS
        inventory.hpp
        )

set(SRCS
        inventory.cpp
        )

find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(${NAME} ${HDRS} ${SRCS})

target_link_libraries(${NAME} PRIVATE
        Qt5::Core
        )