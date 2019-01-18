/*
// This file is part of Functions.

// Functions is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.

// Functions is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with Functions.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef __FUNCTIONS_COLORS_H
#define __FUNCTIONS_COLORS_H

#include <ostream>

namespace Color {
    enum Code {
        FG_RED = 31,
        FG_GREEN = 32,
        FG_BLUE = 34,
        FG_MAGENTA = 35,
        FG_DEFAULT = 0
    };

    std::ostream &operator<<(std::ostream &os, Code code) {
        return os << "\033[" << static_cast<int>(code) << "m";
    }
} // namespace Color

#endif // __FUNCTIONS_COLORS_H