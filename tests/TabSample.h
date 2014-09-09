/*
 * Copyright (c) 2013, Roland Bock
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 * 
 *  * Redistributions of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice, 
 *    this list of conditions and the following disclaimer in the documentation 
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SQLPP_TAB_SAMPLE_H
#define SQLPP_TAB_SAMPLE_H

#include <sqlpp11/table.h>
#include <sqlpp11/column_types.h>


namespace TabFoo_
{
	struct Omega
	{
		struct _name_t
		{
			static constexpr const char* _get_name() { return "omega"; }
			template<typename T>
				struct _member_t
				{
					T omega;
					T& operator()() { return omega; }
					const T& operator()() const { return omega; }
				};
		};
		using _traits = sqlpp::make_traits<sqlpp::bigint>;
	};
}

struct TabFoo: sqlpp::table_t<
									TabFoo, 
									TabFoo_::Omega
													 >
{
	using _value_type = sqlpp::no_value_t;
	struct _name_t
	{
		static constexpr const char* _get_name() { return "tab_foo"; }
		template<typename T>
			struct _member_t
			{
				T tabFoo;
				T& operator()() { return tabFoo; }
				const T& operator()() const { return tabFoo; }
			};
	};
	template<typename Db>
		void serialize_impl(std::ostream& os, Db& db) const
		{
			os << _name_t::_get_name();
		}
};

namespace TabSample_
{
	struct Alpha
	{
		struct _name_t
		{
			static constexpr const char* _get_name() { return "alpha"; }
			template<typename T>
				struct _member_t
				{
					T alpha;
					T& operator()() { return alpha; }
					const T& operator()() const { return alpha; }
				};
		};
		using _traits = sqlpp::make_traits<sqlpp::bigint, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update, sqlpp::tag::can_be_null>;
	};

	struct Beta
	{
		struct _name_t
		{
			static constexpr const char* _get_name() { return "beta"; }
			template<typename T>
				struct _member_t
				{
					T beta;
					T& operator()() { return beta; }
					const T& operator()() const { return beta; }
				};
		};
		using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::can_be_null, sqlpp::tag::trivial_value_is_null, sqlpp::tag::must_not_update>;
	};

	struct Gamma
	{
		struct _name_t
		{
			static constexpr const char* _get_name() { return "gamma"; }
			template<typename T>
				struct _member_t
				{
					T gamma;
					T& operator()() { return gamma; }
					const T& operator()() const { return gamma; }
				};
		};
		using _traits = sqlpp::make_traits<sqlpp::boolean>;
	};
}

struct TabSample: sqlpp::table_t<
									TabSample, 
									TabSample_::Alpha, 
									TabSample_::Beta,
									TabSample_::Gamma
													 >
{
	using _value_type = sqlpp::no_value_t;
	struct _name_t
	{
		static constexpr const char* _get_name() { return "tab_sample"; }
		template<typename T>
			struct _member_t
			{
				T tabSample;
				T& operator()() { return tabSample; }
				const T& operator()() const { return tabSample; }
			};
	};
	template<typename Db>
		void serialize_impl(std::ostream& os, Db& db) const
		{
			os << _name_t::_get_name();
		}
};

#endif
