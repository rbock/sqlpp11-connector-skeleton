add_library(sqlpp-skeleton 
		connection.cpp
		prepared_statement.cpp
		char_result.cpp
		bind_result.cpp
		detail/connection_handle.cpp)

install(TARGETS sqlpp-skeleton DESTINATION lib)
