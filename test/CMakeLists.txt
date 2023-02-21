set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-conversion")

add_executable(test_max test_max.c)
target_link_libraries(test_max
  PRIVATE data_handling
  PUBLIC ${CRITERION}
)

add_test(
  NAME test_max
  COMMAND test_max ${CRITERION_FLAGS}
)

add_executable(test_min test_min.c)
target_link_libraries(test_min
  PRIVATE data_handling
  PUBLIC ${CRITERION}
)

add_test(
  NAME test_min
  COMMAND test_min ${CRITERION_FLAGS}
)
