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

#include <iostream>

#include "ArincLineD.h"
#include "ArincLineDb.h"

#include <Geo>

ArincLine::ArincLine( const string & line )
	: string( line )
{
}

void
ArincLine::stub( const char * fn_name ) const
{
	printf("WARNING !!! Arinc line \"%s\" don't have field for %s() function.\n",
			Arinc::subsectionAbbr( subsection() ), fn_name );
}

ArincLine::Type
ArincLine::type( const string & str ) // static
{
	switch ( str.at( 0 ) ) {
		case 'S':
			return Standard;

		case 'T':
			return Tailored;

		default:
			return Undefined;
	}
}

Arinc::Subsection
ArincLine::subsection( const string & str ) // static
{
	switch ( str.at( 4 ) ) {		// section code
		case 'A':
			switch ( str.at( 5 ) ) {		// section subcode
				case 'S':
					return Arinc::AS;
				default:
					return Arinc::Unknown;
			}

		case 'D':
			switch ( str.at( 5 ) ) {		// section subcode
				case ' ':
					return Arinc::D;
				case 'B':
					return Arinc::DB;
				default:
					return Arinc::Unknown;
			}

		case 'E':
			switch ( str.at( 5 ) ) {		// section subcode
				case 'A':
					return Arinc::EA;
				case 'M':
					return Arinc::EM;
				case 'P':
					return Arinc::EP;
				case 'R':
					return Arinc::ER;
				case 'T':
					return Arinc::ET;
				case 'U':
					return Arinc::EU;
				case 'V':
					return Arinc::EV;
				default:
					return Arinc::Unknown;
			}

		case 'H':
			switch ( str.at( 12 ) ) {		// section subcode
				case 'A':
					return Arinc::HA;
				case 'V':
					return Arinc::HV;
				default:
					return Arinc::Unknown;
			}

		case 'P':
			switch ( str.at( 12 ) ) {		// section subcode
				case 'A':
					return Arinc::PA;
				case 'B':
					return Arinc::PB;
				case 'C':
					return Arinc::PC;
				case 'D':
					return Arinc::PD;
				case 'E':
					return Arinc::PE;
				case 'F':
					return Arinc::PF;
				case 'G':
					return Arinc::PG;
				case 'I':
					return Arinc::PI;
				case 'L':
					return Arinc::PL;
				case 'M':
					return Arinc::PM;
				case 'N':
					return Arinc::PN;
				case 'S':
					return Arinc::PS;
				case 'V':
					return Arinc::PV;
				default:
					return Arinc::Unknown;
			}

		case 'R':
			switch ( str.at( 5 ) ) {		// section subcode
				case ' ':
					return Arinc::R;
				default:
					return Arinc::Unknown;
			}

		case 'T':
			switch ( str.at( 5 ) ) {		// section subcode
				case 'C':
					return Arinc::TC;
				case 'G':
					return Arinc::Unknown;
			}

		case 'U':
			switch ( str.at( 5 ) ) {		// section subcode
				case 'C':
					return Arinc::UC;
				case 'F':
					return Arinc::UF;
				case 'R':
					return Arinc::UR;
				default:
					return Arinc::Unknown;
			}

		default:
			return Arinc::Unknown;
	}
}

string
ArincLine::frequency() const
{
	stub("frequency");
	return string();
}

string
ArincLine::navClass() const
{
	stub("navClass");
	return string();
}

string
ArincLine::zone() const
{
	if ( type( *this ) == Standard )
		return substr( 1, 3 );

	else
		return string();
}

Coordinates
ArincLine::coordinates() const
{
	stub("coordinates");
	return Coordinates();
}

Coordinates
ArincLine::coordinatesDme() const
{
	stub("coordinatesDme");
	return Coordinates();
}

string
ArincLine::cycle() const
{
	return substr( 128, 4 );
}

Arinc::Subsection
ArincLine::subsection() const
{
	return subsection( *this );
}

ArincLine *
ArincLine::line( const string & str )	// static
{
	switch ( subsection( str ) ) {
		case Arinc::D:
			return new ArincLineD( str );

		case Arinc::DB:
			return new ArincLineDb( str );

		default:
			return 0;
	}
}

string
ArincLine::airportIcao() const
{
	stub("airportIcao");
	return string();
}

Latitude
ArincLine::latitude( const string & str )	// static
{
	// проверка строки str на валидность

	if ( str.size() != 9 ) {
		printf("ERROR !!! arinc latitude string to Longitude convertion, size mismatch, %lu != 9.\n", str.size() );
		return Latitude();
	}

	const char semisphere = str.at( 0 );

	if ( semisphere != North && semisphere != South ) {
		printf("ERROR !!! arinc latitude string starts with \"%c\" nor \"N\" and \"S\".\n", semisphere );
		return Latitude();
	}

	// непосредственно преобразования

	const double g = Coordinate::gmsc2g( str.substr( 1, 2 ), str.substr( 3, 2 ), str.substr( 5, 2 ), str.substr( 7, 2 ) );

	return Latitude( semisphere == North ? g : -g );
}

Longitude
ArincLine::longitude( const string & str )	// static
{
	// проверка строки str на валидность

	if ( str.size() != 10 ) {
		printf("ERROR !!! arinc longitude string to Longitude convertion, size mismatch, %lu != 10.\n", str.size() );
		return Longitude();
	}

	const char semisphere = str.at( 0 );

	if ( semisphere != East && semisphere != West ) {
		printf("ERROR !!! arinc longitude string starts with \"%c\" nor \"E\" and \"W\".\n", semisphere );
		return Longitude();
	}

	// непосредственно преобразования

	const double g = Coordinate::gmsc2g( str.substr( 1, 3 ), str.substr( 4, 2 ),
			str.substr( 6, 2 ), str.substr( 8, 2 ) );

	return Longitude( semisphere == East ? g : -g );
}

