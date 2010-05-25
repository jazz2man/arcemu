/*
 * ArcEmu MMORPG Server
 * Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
 * Copyright (C) 2008-2010 <http://www.ArcEmu.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "../Common.h"

namespace Arcemu{
	namespace Threading{


		unsigned long AtomicCounter::operator++(){
			unsigned long val = 0;

#ifdef WIN32
			val = InterlockedIncrement( reinterpret_cast< volatile LONG* >( &counter ) );
#else
#if defined( __GNUC__ ) && ( defined( __i386__  ) || defined( __ia64__ ) )
			val = __sync_add_and_fetch( &counter, 1 );
#endif
#endif

			return val;
		}

		unsigned long AtomicCounter::operator--(){
			unsigned long val = 0;

#ifdef WIN32
			val = InterlockedDecrement( reinterpret_cast< volatile LONG* >( &counter ) );
#else
#if defined( __GNUC__ ) && ( defined( __i386__  ) || defined( __ia64__ ) )
			val = __sync_add_and_fetch( &counter, -1 );
#endif
#endif
			return val;
		}
	}
}
