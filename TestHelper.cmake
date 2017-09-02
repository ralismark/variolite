# a virtual target to build test dependenies before actual testing
add_custom_target(test_deps)
add_test(NAME build_test_deps
	COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target test_deps --config $<CONFIGURATION>
	)

# register a test that should fail compilation
function(add_fail_test TEST_NAME) # Args are source
	add_executable(${TEST_NAME} ${ARGN})
	set_target_properties(${TEST_NAME} PROPERTIES
		EXCLUDE_FROM_ALL TRUE
		EXCLUDE_FROM_DEFAULT_BUILD TRUE)
	add_test(NAME ${TEST_NAME}
		COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target ${TEST_NAME} --config $<CONFIGURATION>
		)
	set_tests_properties(failing_${TEST_NAME} PROPERTIES WILL_FAIL TRUE)
endfunction()

# register a test given the source files
function(add_pass_test TEST_NAME) # Args are source
	add_executable(${TEST_NAME} ${ARGN})
	add_dependencies(test_deps ${TEST_NAME})
	set_target_properties(${TEST_NAME} PROPERTIES
		EXCLUDE_FROM_ALL TRUE)
	add_test(${TEST_NAME} ${TEST_NAME})
	set_tests_properties(${TEST_NAME} PROPERTIES DEPENDS build_test_deps)
endfunction()
