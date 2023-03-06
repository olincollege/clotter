set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-conversion")

add_executable(test_max test_max.c)
target_link_libraries(test_max
  PRIVATE array_helpers
  PUBLIC ${CRITERION}
)

add_test(
  NAME test_max
  COMMAND test_max ${CRITERION_FLAGS}
)

add_executable(test_min test_min.c)
target_link_libraries(test_min
  PRIVATE array_helpers
  PUBLIC ${CRITERION}
)

add_test(
  NAME test_min
  COMMAND test_min ${CRITERION_FLAGS}
)

add_executable(test_mean test_mean.c)
target_link_libraries(test_mean
  PRIVATE array_helpers
  PUBLIC ${CRITERION}
  m
)

add_test(
  NAME test_mean
  COMMAND test_mean ${CRITERION_FLAGS}
)

add_executable(test_max_scalar test_max_scalar.c)
target_link_libraries(test_max_scalar
  PRIVATE array_helpers
  PUBLIC ${CRITERION}
  m
)

add_test(
  NAME test_max_scalar
  COMMAND test_max_scalar ${CRITERION_FLAGS}
)
