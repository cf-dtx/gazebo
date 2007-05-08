/*
 *  Gazebo - Outdoor Multi-Robot Simulator
 *  Copyright (C) 2003  
 *     Nate Koenig & Andrew Howard
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
/*
 * Desc: Gazebo Error
 * Author: Nathan Koenig
 * Date: 07 May 2007
 * SVN info: $Id$
 */

#include "GazeboError.hh"

using namespace gazebo;

////////////////////////////////////////////////////////////////////////////////
/// Default constructor
GazeboError::GazeboError(const std::string func, const std::string str, 
                         const int code)
{
  this->func = func;
  this->str = str;
  this->code = code;
}


////////////////////////////////////////////////////////////////////////////////
/// Destructor
GazeboError::~GazeboError()
{
}

////////////////////////////////////////////////////////////////////////////////
/// Return the error function
std::string GazeboError::GetErrorFunc() const
{
  return this->func;
}

////////////////////////////////////////////////////////////////////////////////
/// Return the error string
std::string GazeboError::GetErrorStr() const
{
  return this->str;
}

////////////////////////////////////////////////////////////////////////////////
/// Return the error code
int GazeboError::GetErrorCode() const
{
  return this->code;
}

////////////////////////////////////////////////////////////////////////////////
/// Ostream operator for Gazebo Error
std::ostream &operator<<(std::ostream &out, const gazebo::GazeboError &err)
{
  return out << err.GetErrorFunc()
            << "(" << err.GetErrorCode() << ")"
            << " : "
            << err.GetErrorStr();
}
