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

#include "ArincLineSpan.h"

ArincLineSpan::ArincLineSpan()
	: std::vector< unsigned char >(), m_type( Arinc::NoType )
{
}

bool
ArincLineSpan::isValid() const
{
	return size() > 1 && at( 1 ) != 0;
}

void
ArincLineSpan::span( unsigned char st1, unsigned char le1, Arinc::Type type )
{
	clear();

	m_type = type;

	push_back( st1 );
	push_back( le1 );
}

void
ArincLineSpan::span( unsigned char st1, unsigned char le1, unsigned char st2, unsigned char le2, Arinc::Type type )
{
	span( st1, le1, type );

	push_back( st2 );
	push_back( le2 );
}

void
ArincLineSpan::span( unsigned char st1, unsigned char le1, unsigned char st2, unsigned char le2,
		unsigned char st3, unsigned char le3, Arinc::Type type )
{
	span( st1, le1, st2, le2, type );

	push_back( st3 );
	push_back( le3 );
}

bool
ArincLineSpan::haveFirstPart() const
{
	return size() >= 2 && at( 1 ) != 0;
}

int
ArincLineSpan::start1() const
{
	return size() >= 1 ? at( 0 ) : -1;
}

int
ArincLineSpan::length1() const
{
	return size() >= 2 ? at( 1 ) : -1;
}

bool
ArincLineSpan::haveSecondPart() const
{
	return size() >= 4 && at( 3 ) != 0;
}

int
ArincLineSpan::start2() const
{
	return size() >= 3 ? at( 2 ) : -1;
}

int
ArincLineSpan::length2() const
{
	return size() >= 4 ? at( 3 ) : -1;
}

bool
ArincLineSpan::haveThirdPart() const
{
	return size() >= 6 && at( 5 ) != 0;
}

int
ArincLineSpan::start3() const
{
	return size() >=6 ? at( 4 ) : -1;
}

int
ArincLineSpan::length3() const
{
	return size() >= 6 ? at( 5 ) : -1;
}

Arinc::Type
ArincLineSpan::type() const
{
	return m_type;
}

