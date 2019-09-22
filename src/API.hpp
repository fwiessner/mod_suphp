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

#ifndef SUPHP_API_H

namespace suPHP {
class API;
}

#define SUPHP_API_H

#include <string>
#include "CommandLine.hpp"
#include "Environment.hpp"
#include "File.hpp"
#include "GroupInfo.hpp"
#include "Logger.hpp"
#include "UserInfo.hpp"

namespace suPHP {
/**
 * Class encapsulating system-specific API.
 */
class API {
 public:
  /**
   * Get environment variable
   */
  virtual Environment getProcessEnvironment() = 0;

  /**
   * Get UserInfo from username
   */
  virtual UserInfo getUserInfo(const std::string username) = 0;

  /**
   * Get UserInfo from UID
   */
  virtual UserInfo getUserInfo(const int uid) = 0;

  /**
   * Get GroupInfo from groupname
   */
  virtual GroupInfo getGroupInfo(const std::string groupname) = 0;

  /**
   * Get GroupInfo from GID
   */
  virtual GroupInfo getGroupInfo(const int gid) = 0;

  /**
   * Get UserInfo for effective UID
   */
  virtual UserInfo getEffectiveProcessUser() = 0;

  /**
   * Get UserInfo for real UID
   */
  virtual UserInfo getRealProcessUser() = 0;

  /**
   * Get GroupInfo for effective GID
   */
  virtual GroupInfo getEffectiveProcessGroup() = 0;

  /**
   * Get GroupInfo for real GID
   */
  virtual GroupInfo getRealProcessGroup() = 0;

  /**
   * Get Logger implementation
   */
  virtual Logger& getSystemLogger() = 0;

  /**
   * Set UID of current process
   */
  virtual void setProcessUser(const UserInfo& user) const = 0;

  /**
   * Set GID of current process
   */
  virtual void setProcessGroup(const GroupInfo& group) const = 0;

  /**
   * Returns username from UserInfo
   */
  virtual std::string UserInfo_getUsername(const UserInfo& uinfo) const = 0;

  /**
   * Returns group from UserInfo
   */
  virtual GroupInfo UserInfo_getGroupInfo(const UserInfo& uinfo) const = 0;

  /**
   * Returns home directory from UserInfo
   */
  virtual std::string UserInfo_getHomeDirectory(
      const UserInfo& uinfo) const = 0;

  /**
   * Checks whether UserInfo objects represents the super-user
   */
  virtual bool UserInfo_isSuperUser(const UserInfo& uinfo) const = 0;

  /**
   * Returns groupname from GroupInfo
   */
  virtual std::string GroupInfo_getGroupname(const GroupInfo& ginfo) const = 0;

  /**
   * Checks whether file exists
   */
  virtual bool File_exists(const File& file) const = 0;

  /**
   * Returns real path to file
   */
  virtual std::string File_getRealPath(const File& file) const = 0;

  /**
   * Checks for a permission bit
   */
  virtual bool File_hasPermissionBit(const File& file, FileMode perm) const = 0;

  /**
   * Returns UID of file
   */
  virtual UserInfo File_getUser(const File& file) const = 0;

  /**
   * Returns GID of file
   */
  virtual GroupInfo File_getGroup(const File& file) const = 0;

  /**
   * Checks whether a file is a symlink
   */
  virtual bool File_isSymlink(const File& file) const = 0;

  /**
   * Runs another program (replaces current process)
   */
  virtual void execute(std::string program, const CommandLine& cline,
                       const Environment& env) const = 0;

  /**
   * Returns current working directory
   */
  virtual std::string getCwd() const = 0;

  /**
   * Sets current working directory
   */
  virtual void setCwd(const std::string& dir) const = 0;

  /**
   * Sets umask
   */
  virtual void setUmask(int umask) const = 0;

  /**
   * Changes root directory for the current process
   */
  virtual void chroot(const std::string& dir) const = 0;
};
}  // namespace suPHP

#endif  // SUPHP_API_H
