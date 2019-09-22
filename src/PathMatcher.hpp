/*
  suPHP - (c)2002-2013 Sebastian Marsching <sebastian@marsching.com>
          (c)2018 John Lightsey <john@nixnuts.net>

  This file is part of suPHP.

  suPHP is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  suPHP is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with suPHP; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#ifndef SUPHP_PATHMATCHER_H
#define SUPHP_PATHMATCHER_H

#include <string>

#include "GroupInfo.hpp"
#include "KeyNotFoundException.hpp"
#include "ParsingException.hpp"
#include "UserInfo.hpp"

namespace suPHP {

template <class TUserInfo = UserInfo, class TGroupInfo = GroupInfo>
class PathMatcher {
 private:
  const TUserInfo& user;
  const TGroupInfo& group;
  std::string lookupVariable(std::string str);

 public:
  /**
   * Contructor
   */
  PathMatcher(const TUserInfo& cuser, const TGroupInfo& cgroup)
      : user(cuser), group(cgroup){};

  /**
   * Checks wheter a path matches a pattern
   */
  bool matches(std::string pattern, std::string path);

  /**
   * Resolves variables in a string
   */
  std::string resolveVariables(std::string str, bool unescape = true);
};
}  // namespace suPHP

#endif  // SUPHP_PATHMATCHER_H
