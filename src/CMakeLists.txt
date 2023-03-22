add_library(array_helpers array_helpers.c array_helpers.h)
add_library(csv2data csv2data.c csv2data.h)
add_library(countplot countplot.c countplot.h)
add_library(data_types data_types.c data_types.h)

add_executable(clotter main.c)
# add_executable(check check.c)
# target_link_libraries(check csv2data)
# target_link_libraries(check data_types)

target_link_libraries(array_helpers data_types)
target_link_libraries(csv2data data_types)
target_link_libraries(countplot data_types array_helpers m)

target_link_libraries(clotter array_helpers)
target_link_libraries(clotter csv2data)
target_link_libraries(clotter countplot)
target_link_libraries(clotter m)




