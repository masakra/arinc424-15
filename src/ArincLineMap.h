/***************************************************************************
 *   Copyright (C) 2013 by Sergey N Chursanov                              *
 *                                                                         *
 *   email: masakra@mail.ru                                                *
 *   jabber: masakra@jabber.ru                                             *
 *                                                                         *
 *   Permission is hereby granted, free of charge, to any person obtaining *
 *   a copy of this software and associated documentation files (the       *
 *   "Software"), to deal in the Software without restriction, including   *
 *   without limitation the rights to use, copy, modify, merge, publish,   *
 *   distribute, sublicense, and/or sell copies of the Software, and to    *
 *   permit persons to whom the Software is furnished to do so, subject to *
 *   the following conditions:                                             *
 *                                                                         *
 *   The above copyright notice and this permission notice shall be        *
 *   included in all copies or substantial portions of the Software.       *
 *                                                                         *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       *
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    *
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. *
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR     *
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, *
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR *
 *   OTHER DEALINGS IN THE SOFTWARE.                                       *
 ***************************************************************************/

/*! \class ArincLineMap
 *
 * \brief 
 */

#ifndef ARINCLINEMAP_H
#define ARINCLINEMAP_H

#include "Arinc.h"
#include "ArincLineSpan.h"
#include <map>
#include <vector>

class ArincLineMap : public std::map< Arinc::Field, ArincLineSpan >
{
	private:
		mutable Arinc::Type m_cachedType;

	public:
		ArincLineMap();

		/*! \fn Arinc::Type type() const
		 *
		 * \brief Тип карты
		 *
		 * Возможны два типа: Arinc::Standard и Arinc::StandardWay. Если хотя-бы
		 * один из спанов имеет тип Arinc::StandardWay, то вся карта иммет тип
		 * Arinc::StandardWay, иначе Arinc::Standard.
		 */
		Arinc::Type type() const;
};

#endif

