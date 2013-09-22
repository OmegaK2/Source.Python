/**
* =============================================================================
* Source Python
* Copyright (C) 2012-2013 Source Python Development Team.  All rights reserved.
* =============================================================================
*
* This program is free software; you can redistribute it and/or modify it under
* the terms of the GNU General Public License, version 3.0, as published by the
* Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
* details.
*
* You should have received a copy of the GNU General Public License along with
* this program.  If not, see <http://www.gnu.org/licenses/>.
*
* As a special exception, the Source Python Team gives you permission
* to link the code of this program (as well as its derivative works) to
* "Half-Life 2," the "Source Engine," and any Game MODs that run on software
* by the Valve Corporation.  You must obey the GNU General Public License in
* all respects for all other code used.  Additionally, the Source.Python
* Development Team grants this exception to all derivative works.
*/

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "level_init_listeners_wrap.h"
#include "utility/call_python.h"

//-----------------------------------------------------------------------------
// Static singletons.
//-----------------------------------------------------------------------------
static CLevelInitListenerManager s_LevelInitListenerManager;

//-----------------------------------------------------------------------------
// Overload for passing the arguments
//-----------------------------------------------------------------------------
void CLevelInitListenerManager::call_listeners( char const *pMapName )
{
	for(int i = 0; i < m_vecCallables.Count(); i++)
	{
		BEGIN_BOOST_PY()

			// Get the PyObject instance of the callable
			PyObject* pCallable = m_vecCallables[i].ptr();

			// Call the callable
			CALL_PY_FUNC(pCallable, pMapName);

		END_BOOST_PY_NORET()
	}
}

//-----------------------------------------------------------------------------
// LevelInitListenerManager accessor.
//-----------------------------------------------------------------------------
CLevelInitListenerManager* get_level_init_listener_manager()
{
	return &s_LevelInitListenerManager;
}