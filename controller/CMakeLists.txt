set(NAME libcontroller)

set(HDRS
        controller.hpp
        )

set(SRCS
        controller.cpp
        )

find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(${NAME} ${HDRS} ${SRCS})

target_link_libraries(${NAME} PRIVATE
        Qt5::Core

        libitem
        libdatabase
        libinventory
        )