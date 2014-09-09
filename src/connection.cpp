/*
 * Copyright (c) 2013, Roland Bock
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 *   Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 *   Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <iostream>
#include <sqlpp11/exception.h>
#include <sqlpp11/skeleton/connection.h>
#include "detail/prepared_statement_handle.h"
#include "detail/result_handle.h"
#include "detail/connection_handle.h"

namespace sqlpp
{
	namespace skeleton
	{
		connection::connection(connection_config config):
			_handle(new detail::connection_handle_t(config))
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		connection::~connection()
		{
			// FIXME
		}

		char_result_t connection::select_impl(const std::string& statement)
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		bind_result_t connection::run_prepared_select_impl(prepared_statement_t& prepared_statement)
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		size_t connection::run_prepared_insert_impl(prepared_statement_t& prepared_statement)
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		size_t connection::run_prepared_update_impl(prepared_statement_t& prepared_statement)
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		size_t connection::run_prepared_remove_impl(prepared_statement_t& prepared_statement)
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		prepared_statement_t connection::prepare_impl(const std::string& statement, size_t no_of_parameters, size_t no_of_columns)
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		size_t connection::insert_impl(const std::string& statement)
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		void connection::execute(const std::string& command)
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		size_t connection::update_impl(const std::string& statement)
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		size_t connection::remove_impl(const std::string& statement)
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		std::string connection::escape(const std::string& s) const
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		void connection::start_transaction()
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		void connection::commit_transaction()
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		void connection::rollback_transaction(bool report)
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

		void connection::report_rollback_failure(const std::string message) noexcept
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}
	}
}

