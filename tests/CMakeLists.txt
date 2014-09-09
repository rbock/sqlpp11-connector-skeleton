macro (build_and_run arg)
	# Add headers to sources to enable file browsing in IDEs
	add_executable("Sqlpp11Skeleton${arg}" "${arg}.cpp" ${sqlpp_headers})
	target_link_libraries("Sqlpp11Skeleton${arg}" sqlpp-skeleton)
	#target_link_libraries("Sqlpp11Skeleton${arg}" nativeclient)
	add_test("Sqlpp11Skeleton${arg}" "${arg}")
endmacro ()

build_and_run(SkeletonTest)
