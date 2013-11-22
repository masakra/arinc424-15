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

#include "ArincLine.h"

ArincLine::ArincLine( const string & line )
	: string( line )
{
}

ArincLine::Type
ArincLine::type() const
{
	switch ( at( 0 ) ) {
		case 'S':
			return Standard;

		case 'T':
			return Tailored;

		default:
			return Undefined;
	}
}

Arinc::Subsection
ArincLine::subsection() const
{
	switch ( at( 4 ) ) {		// section code
		case 'A':
			switch ( at( 5 ) ) {
				case 'S':
					return Arinc::AS;
				default:
					return Arinc::Unknown;
			}

		case 'D':
			switch ( at( 5 ) ) {
				case ' ':
					return Arinc::D;
				case 'B':
					return Arinc::DB;
				default:
					return Arinc::Unknown;
			}
	}
}

string
ArincLine::zone() const
{
	if ( type() == Standard )
		return substr( 1, 3 );

	else
		return string();
}

string
ArincLine::cycle() const
{
	return substr( 128, 4 );
}

