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

/*! \class ArincLine
 *
 * \brief Строка ARINC файла
 */

#ifndef ARINCLINE_H
#define ARINCLINE_H

#include <string>
#include "ArincLineMaps.h"

class ArincLine : public std::string
{
	private:
		std::string getSpan( Arinc::Field field ) const;

		static ArincLineMaps m_maps;

		mutable Arinc::Type m_cached_type;

	public:
		ArincLine();

		ArincLine( const std::string & line );

		ArincLine & operator=( const std::string & str );

		Arinc::Type type() const;

		Arinc::Subsection subsection() const;

		std::string data( Arinc::Field field ) const;

		const ArincLineMap & map() const;


		/*
		\\	static
		*/
		static Arinc::Type type( const std::string & str );

		static Arinc::Subsection subsection( const std::string & str );

		const ArincLineMap & map( Arinc::Subsection ss );
};


#endif

