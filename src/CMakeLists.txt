add_library(array_helpers array_helpers.c array_helpers.h)
add_library(csv2data csv2data.c csv2data.h)
#add_library(count_plot count_plot.c count_plot.h)
# add_library(data_types data_types.h)

add_executable(main main.c)
# add_executable(check check.c)
# target_link_libraries(check csv2data)
# target_link_libraries(check data_types)

target_link_libraries(array_helpers data_types)
target_link_libraries(csv2data data_types)
#target_link_libraries(count_plot data_types)

target_link_libraries(main array_helpers)
target_link_libraries(main csv2data)
target_link_libraries(main count_plot)




