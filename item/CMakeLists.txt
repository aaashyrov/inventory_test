set(NAME libitem)

set(HDRS
        item.hpp
        )

set(SRCS
        item.cpp
        )

add_library(${NAME} ${HDRS} ${SRCS})