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

#ifndef SUPHP_ENVIRONMENT_H
#define SUPHP_ENVIRONMENT_H

#include <map>
#include <string>

#include "KeyNotFoundException.hpp"

namespace suPHP {
/**
 * Class containing environment variables.
 */
class Environment {
 private:
  std::map<std::string, std::string> vars;

 public:
  /**
   * Returns (copy of) variable content
   */
  std::string getVar(const std::string& name) const;

  /**
   * Sets variable content
   */
  void setVar(const std::string name, const std::string content);

  /**
   * Adds variable to environment
   */
  void putVar(const std::string name, const std::string content);

  /**
   * Deletes variable from environment if it is set
   */
  void deleteVar(const std::string& name);

  /**
   * Checks whether a variable is set
   */
  bool hasVar(const std::string& name) const;

  /**
   * Returns reference to variable with name
   */
  std::string& operator[](const std::string& name);

  /**
   * Returns const reference to the map which stores the variables
   */
  const std::map<std::string, std::string>& getBackendMap() const;
};
}  // namespace suPHP

#endif  // SUPHP_ENVIRONMENT_H
