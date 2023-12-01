// libosm
// Copyright (C) 2023 Maritsu
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

// placeholder
struct PlaceholderType {};

#include <string>
#include <vector>

namespace libosm {

class BasicSource {
protected:
	std::u8string _name;
	std::u8string _abbrev;

public:
	virtual ~BasicSource();

	virtual std::vector<PlaceholderType> search(const std::u8string& query) = 0;

	std::u8string getName() const;
	std::u8string getAbbrev() const;
};

}
