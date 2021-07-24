set(NAME libinventory)

set(HDRS
        inventory.hpp
        )

set(SRCS
        inventory.cpp
        )

add_library(${NAME} ${HDRS} ${SRCS})