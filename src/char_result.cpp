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
#include <sqlpp11/skeleton/char_result.h>
#include "detail/result_handle.h"


namespace sqlpp
{
	namespace skeleton
	{
		char_result_t::char_result_t()
		{}

		char_result_t::char_result_t(std::unique_ptr<detail::result_handle>&& handle):
			_handle(std::move(handle))
		{
			if (!_handle)
				throw std::runtime_error("Skeleton: Constructing char_result without valid handle");

			if (_handle->debug)
				std::cerr << "Skeleton debug: Constructing result, using handle at " << _handle.get() << std::endl;
		}

		char_result_t::~char_result_t() = default;
		char_result_t::char_result_t(char_result_t&& rhs) = default;
		char_result_t& char_result_t::operator=(char_result_t&&) = default;

		bool char_result_t::next_impl()
		{
			throw std::runtime_error(std::string("missing code in ") +  __FILE__ + ", line " + std::to_string(__LINE__));
		}

	}
}

