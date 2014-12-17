/*--------------------------------------------------------------------
Task is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.

Task is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

See GNU Lesser General Public License at <http://www.gnu.org/licenses/>.
--------------------------------------------------------------------*/

#ifndef TASKMACROS_H
#define TASKMACROS_H

#define TASK_DECLARE_BEGIN(name) \
    class name : public Task      \
    {                             \
    public:                       \
      name(uint32_t timeIntervalMs) :                    \
        Task(timeIntervalMs)     \
      {};                         \
    private:                      

#define TASK_DECLARE_FUNCTION virtual void 

#define TASK_DECLARE_END  };

#endif