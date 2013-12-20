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

#include "ArincLineD.h"

ArincLineD::ArincLineD( const string & line )
	: ArincLine( line )
{
}

string
ArincLineD::frequency() const
{
	return substr( 22, 5 );
}

string
ArincLineD::ident() const
{
	return substr( 19, 2 ) + substr( 13, 4 );
}

string
ArincLineD::name() const
{
	return substr( 93, 30 );
}

string
ArincLineD::navClass() const
{
	return substr( 27, 5 );
}

string
ArincLineD::airportIcao() const
{
	return substr( 10, 2 ) + substr( 6, 4 );
}

Coordinates
ArincLineD::coordinates() const
{
	return Coordinates( longitude( substr( 41, 10 ) ), latitude( substr( 32, 9 ) ) );
}

Coordinates
ArincLineD::coordinatesDme() const
{
	return Coordinates( longitude( substr( 64, 10 ) ), latitude( substr( 55, 9 ) ) );
}


