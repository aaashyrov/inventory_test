set(NAME libdatabase)

set(HDRS
        sqlitedb.hpp
        database.hpp
        )

set(SRCS
        sqlitedb.cpp
        database.cpp
        )

find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(${NAME} ${HDRS} ${SRCS})

target_link_libraries(${NAME} PRIVATE
        Qt5::Core
        )