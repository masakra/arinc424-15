/***************************************************************************
 *   Copyright (C) 2014 by Sergey N Chursanov                              *
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

#include "ArincData.h"

ArincData::ArincData()
	: m_type( Invalid )
{
}

ArincData::ArincData( int i )
	: m_type( Int ), m_int( i )
{
}

ArincData::ArincData( double d )
	: m_type( Double ), m_double( d )
{
}

ArincData::ArincData( const std::string & str )
	: m_type( String ), m_string( new std::string( str ) )
{
}

ArincData::ArincData( const Coordinates & coords )
	: m_type( Coords ), m_coordinates( new Coordinates( coords ) )
{
}

ArincData::ArincData( const ArincData & other )		// copy constractor
	: m_type( other.m_type )
{
	switch ( m_type ) {
		case Int:
			m_int = other.m_int;
			break;

		case Double:
			m_double = other.m_double;
			break;

		case String:
			if ( m_string != 0 )
				delete m_string;
			m_string = other.m_string;
			break;

		case Coords:
			if ( m_coordinates != 0 )
				delete m_coordinates;
			m_coordinates = other.m_coordinates;
			break;

		default:
			;
	}
}

ArincData::~ArincData()
{
	clearPointer();
}

void
ArincData::clearPointer()
{
	switch ( m_type ) {
		case String:
			if ( m_string != 0 )
				delete m_string;
			break;

		case Coords:
			if ( m_coordinates != 0 )
				delete m_coordinates;
			break;

		default:
			;
	}

	m_string = 0;
}

void
ArincData::setString( const std::string & str )
{
	clearPointer();

	m_string = new std::string( str );
}

ArincData &
ArincData::operator=( const std::string & str )
{
	setString( str );

	return *this;
}

std::string
ArincData::toStdString() const
{
	switch ( m_type ) {
		case Int:
			break;

		case Double:
			break;

		case String:
			return std::string( *m_string );

		case Coords:
			return m_coordinates->strShort();

		default:
			;
	}

	return std::string();
}

