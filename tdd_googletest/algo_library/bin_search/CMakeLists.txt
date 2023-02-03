project(bin_search)

set(BIN_SEARCH_SOURCES
bin_search.cpp bin_search.h
)

add_library(bin_search OBJECT ${BIN_SEARCH_SOURCES})

