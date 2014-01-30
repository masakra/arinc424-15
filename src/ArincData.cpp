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

#include <stdio.h>		// Для Win*
#include <stdlib.h>		// Для Win*
#include <math.h>

ArincData::ArincData()
	: m_field( Arinc::Undefined ), m_type( Invalid )
{
}

ArincData::ArincData( Arinc::Field field, int i )
	: m_field( field ), m_type( Int ), m_int( i )
{
}

ArincData::ArincData( Arinc::Field field, double d )
	: m_field( field ), m_type( Double ), m_double( d )
{
}

ArincData::ArincData( Arinc::Field field, const std::string & str )
	: m_field( field ), m_type( String ), m_string( new std::string( str ) )
{
}

ArincData::ArincData( Arinc::Field field, const Coordinates & coords )
	: m_field( field ), m_type( Coords ), m_coordinates( new Coordinates( coords ) )
{
}

ArincData::ArincData( const ArincData & other )		// copy constractor
	: m_field( other.m_field ), m_type( other.m_type )
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

int
ArincData::toInt() const
{
	switch ( m_type ) {
		case Int:
			return m_int;

		case Double:
			return round( m_double );

		case String:
			return strtol( m_string->c_str(), 0, 10 );

		case Invalid:
		case Coords:
		default:
			return 0;
	}
}

double
ArincData::toDouble() const
{
	switch ( m_type ) {
		case Int:
			return m_int;

		case Double:
			return m_double;

		case String:
			return strtod( m_string->c_str(), 0 );

		case Invalid:
		case Coords:
		default:
			return 0;
	}
}

std::string
ArincData::toStdString() const
{
	char buf[ STR_BUF_SIZE ];

	switch ( m_type ) {
		case Int:
			snprintf( buf, STR_BUF_SIZE, "%i", m_int );
			return buf;

		case Double:
			snprintf( buf, STR_BUF_SIZE, "%64.4f", m_double );
			return buf;

		case String:
			return *m_string;

		case Coords:
			return m_coordinates->strShort();

		default:
			;
	}

	return std::string();
}

Coordinates
ArincData::toCoordinates() const
{
	switch ( m_type ) {
		case Coords:
			return *m_coordinates;

		case String: {
			if ( m_string->size() == 19 &&
					( ( *m_string )[ 0 ] == geo::North || ( *m_string )[ 0 ] == geo::South ) &&
					( ( *m_string )[ 9 ] == geo::West || ( *m_string )[ 9 ] == geo::East ) )
				return coordinates( *m_string );
		}

		default:
			;
	}

	return Coordinates();
}

Latitude
ArincData::latitude( const std::string & str )	// static
{
	// проверка строки str на валидность

	if ( str.size() != 9 ) {
		printf("ERROR !!! arinc latitude string to Longitude convertion, size mismatch, %lu != 9.\n", str.size() );
		return Latitude();
	}

	const char semisphere = str.at( 0 );

	if ( semisphere != geo::North && semisphere != geo::South ) {
		printf("ERROR !!! arinc latitude string starts with \"%c\" nor \"N\" and \"S\".\n", semisphere );
		return Latitude();
	}

	// непосредственно преобразования

	const double g = Coordinate::gmsc2g( str.substr( 1, 2 ), str.substr( 3, 2 ), str.substr( 5, 2 ), str.substr( 7, 2 ) );

	return Latitude( semisphere == geo::North ? g : -g );
}

Longitude
ArincData::longitude( const std::string & str )	// static
{
	// проверка строки str на валидность

	if ( str.size() != 10 ) {
		printf("ERROR !!! arinc longitude string to Longitude convertion, size mismatch, %lu != 10.\n", str.size() );
		return Longitude();
	}

	const char semisphere = str.at( 0 );

	if ( semisphere != geo::East && semisphere != geo::West ) {
		printf("ERROR !!! arinc longitude string starts with \"%c\" nor \"E\" and \"W\".\n", semisphere );
		return Longitude();
	}

	// непосредственно преобразования

	const double g = Coordinate::gmsc2g( str.substr( 1, 3 ), str.substr( 4, 2 ),
			str.substr( 6, 2 ), str.substr( 8, 2 ) );

	return Longitude( semisphere == geo::East ? g : -g );
}

Coordinates
ArincData::coordinates( const std::string & coords_str )	 // static
{
	return Coordinates( longitude( coords_str.substr( 9, 10 ) ), latitude( coords_str.substr( 0, 9 ) ) );
}

Coordinates
ArincData::coordinates( const std::string & lon_str, const std::string & lat_str )	 // static
{
	return Coordinates( longitude( lon_str ), latitude( lat_str ) );
}

Arinc::Field
ArincData::field() const
{
	return m_field;
}

ArincData::Type
ArincData::fieldType() const
{
	return fieldType( m_field );
}

ArincData::Type
ArincData::fieldType( Arinc::Field field ) // static
{
	if ( field == Arinc::Undefined )
		return Invalid;

	else if ( field <= Arinc::Zone )
		return String;

	else if ( field <= Arinc::Coordinates )
		return Coords;

	else if ( field <= Arinc::Exceed )
		return Int;

	else if ( field <= Arinc::MagDev )
		return Double;

	return Invalid;
}

