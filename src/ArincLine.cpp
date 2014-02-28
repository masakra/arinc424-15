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
#include <stdio.h>		// для Win*
#include <stdlib.h>		// для Win*
#include <math.h>

#include "ArincLineSpan.h"

ArincLineMaps ArincLine::m_maps;

ArincLine::ArincLine()
	: m_cachedType( Arinc::NoType )
{
}

ArincLine::ArincLine( const std::string & line )
	: std::string( line ), m_cachedType( Arinc::NoType )
{
}

ArincLine &
ArincLine::operator=( const std::string & str )
{
	m_cachedType = Arinc::NoType;
	std::string::operator=( str );
	return *this;
}

std::string
ArincLine::data( Arinc::Field field ) const
{
	return getSpan( field );
}

const ArincLineMap &
ArincLine::map() const
{
	return m_maps[ subsection() ];
}

const ArincLineMap &
ArincLine::map( Arinc::Subsection ss )
{
	//printf("map( %s )\n", Arinc::subsectionAbbr( ss ) );
	return m_maps[ ss ];
}

Arinc::Type
ArincLine::type() const
{
	if ( m_cachedType != Arinc::NoType )
		return m_cachedType;

	if ( size() < 3 )
		return m_cachedType;	// Arinc::NoType

	m_cachedType = type( *this );	// static function call

	// проверка на Arinc::Way
	if ( m_cachedType == Arinc::Standard )
		m_cachedType = m_maps[ subsection() ].type();

	return m_cachedType;
}

Arinc::Type
ArincLine::type( const std::string & str ) // static
{
	switch ( str.at( 0 ) ) {
		case 'S':
			return Arinc::Standard;

		case 'T':
			return Arinc::Tailored;

		default: {
			printf("%s\n", str.c_str() );
			const std::string type = str.substr( 0, 3 );

			if ( type == "VOL" )
				return Arinc::VolumeHeader;

			else if ( type == "HDR1" )
				return Arinc::Header1;

			else if ( type == "HDR2" )
				return Arinc::Header2;

			else if ( type == "EOF" )
				return Arinc::EndOfFile;

			else if ( type == "EOV" )
				return Arinc::EndOfVolume;

			else
				return Arinc::NoType;
		}
	}
}

Arinc::Subsection
ArincLine::subsection( const std::string & str ) // static
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
			switch ( str.at( 5 ) != ' ' ? str.at( 5 ) : str.at( 12 ) ) {		// section subcode
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

std::string
ArincLine::getSpan( Arinc::Field field ) const
{
	const ArincLineSpan & span = m_maps[ subsection() ][ field ];

	if ( ! span.isValid() ) {
		printf("span is invalid\n");
		return std::string();
	}

	std::string str;

	//printf("param = %i, start1 = %i, length1 = %i\n", dataType, span.start1(), span.length1() );

	if ( span.haveFirstPart() )
		str = substr( span.start1(), span.length1() );

	if ( span.haveSecondPart() )
		str += substr( span.start2(), span.length2() );

	if ( span.haveThirdPart() )
		str += substr( span.start3(), span.length3() );

	return str;
}

/*
std::string
ArincLine::data( Arinc::DataString data ) const
{
	return getSpan( data );
}
*/

Arinc::Subsection
ArincLine::subsection() const
{
	if ( type() != Arinc::Standard && type() != Arinc::Way )
		return Arinc::Unknown;

	return subsection( *this );
}

/*
int
ArincLine::data( Arinc::DataInt data ) const
{
	const std::string str = getSpan( data );

	switch ( data ) {
		case Arinc::Bias:
			return round( geo::nm2m( strtol( str.c_str(), 0, 10 ) / 10.0 ) );

		default:
			return strtol( str.c_str(), 0, 10 );
	}
}

double
ArincLine::data( Arinc::DataDouble data ) const
{
	const std::string str = getSpan( data );

	switch ( data ) {
		case Arinc::MagDev:
			return decodeMagDev( str );

		default:
			return strtod( str.c_str(), 0 );
	}
}

Coordinates
ArincLine::data( Arinc::DataCoordinates data ) const
{
	const std::string str = getSpan( data );

	if ( str.empty() )
		return Coordinates();
	else
		return Coordinates( longitude( str.substr( 9, 10 ) ), latitude( str.substr( 0, 9 ) ) );
}
*/

/*
double
ArincLine::decodeMagDev( const std::string & str )
{
	const double md = strtol( str.substr( 1, 4 ).c_str(), 0, 10 ) / 10.0;

	return str.at( 0 ) == geo::West ? -md : md;
}
*/


