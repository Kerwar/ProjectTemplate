enable_testing()

find_package(Catch2 CONFIG REQUIRED)

include(Catch)

include_directories(../headers)

function(add_my_test test_to_add)
add_executable(${test_to_add} ${test_to_add}.cpp)
target_link_libraries(${test_to_add} PUBLIC Catch2::Catch2 librayname)
target_link_libraries(${test_to_add} PRIVATE catch_main)

catch_discover_tests(${test_to_add}
  TEST_PREFIX
  "${test_to_add}."
    )
endfunction()

add_library(catch_main OBJECT catch_main.cpp)
target_link_libraries(catch_main PUBLIC Catch2::Catch2 )

list(APPEND test_sources
    test_file
    )

foreach(file IN LISTS test_sources)
    add_my_test(${file})
endforeach()
