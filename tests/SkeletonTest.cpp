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

#include "TabSample.h"
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/skeleton/skeleton.h>

#include <iostream>
#include <vector>


SQLPP_ALIAS_PROVIDER(left);
SQLPP_ALIAS_PROVIDER(right);

namespace skeleton = sqlpp::skeleton;
int main()
{
	skeleton::connection_config config{};
 	config.user = "root";
 	config.database = "sqlpp_sample";
	config.debug = true;
	try
	{
		skeleton::connection db(config);
	}
	catch(const sqlpp::exception& )
	{
		std::cerr << "For testing, you'll need to create a database sqlpp_sample with a table tab_sample, as shown in tests/TabSample.sql" << std::endl;
		throw;
	}
	skeleton::connection db(config);
	db.execute(R"(DROP TABLE IF EXISTS tab_sample)");
	db.execute(R"(CREATE TABLE tab_sample (
			alpha bigint(20) AUTO_INCREMENT DEFAULT NULL,
			beta varchar(255) DEFAULT NULL,
			gamma bool DEFAULT NULL,
			PRIMARY KEY (alpha)
			))");
	db.execute(R"(DROP TABLE IF EXISTS tab_foo)");
	db.execute(R"(CREATE TABLE tab_foo (
		omega bigint(20) DEFAULT NULL
			))");

	TabSample tab;
	// clear the table
	db(remove_from(tab).where(true));

	db(insert_into(tab).default_values());
	db(insert_into(tab).set(tab.gamma = true, tab.beta = "cheesecake"));
	db(insert_into(tab).set(tab.gamma = true, tab.beta = "blueberry muffin"));

	for(const auto& row : db(select(all_of(tab)).from(tab).where(true)))
	{
		std::cerr << "row.alpha: " << row.alpha << ", row.beta: " << row.beta << ", row.gamma: " << row.gamma <<  std::endl;
	};

	return 0;
}
