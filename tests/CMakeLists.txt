macro(get_testname OUTVAR SRC)
	get_filename_component(TESTNAME ${SRC} NAME_WE)
	get_filename_component(TESTPATH ${SRC} DIRECTORY)
	file(RELATIVE_PATH PATHNAME_REL
		${CMAKE_CURRENT_LIST_DIR}
		${TESTPATH}/${TESTNAME})
	string(REGEX REPLACE "[\\/]" "--" ${OUTVAR} ${PATHNAME_REL})
endmacro()

file(GLOB_RECURSE TEST_PASS_SRC *.pass.cpp)
foreach(SRC ${TEST_PASS_SRC})
	get_testname(TESTNAME ${SRC})
	add_pass_test(${TESTNAME} ${SRC})
endforeach(SRC)

file(GLOB_RECURSE TEST_FAIL_SRC *.fail.cpp)
foreach(SRC ${TEST_FAIL_SRC})
	get_testname(TESTNAME ${SRC})
	add_fail_test(${TESTNAME} ${SRC})
endforeach(SRC)

add_custom_target(invalidate_test_list
	COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_LIST_FILE}
	)
add_dependencies(test_deps invalidate_test_list)
