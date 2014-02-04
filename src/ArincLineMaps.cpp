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

#include "ArincLineMaps.h"


ArincLineMaps::ArincLineMaps()
{
	// D
	m_maps[ Arinc::D ][ Arinc::Airport ].span( 10, 2, 6, 4 );
	m_maps[ Arinc::D ][ Arinc::Ident ].span( 19, 2, 13, 4 );
	m_maps[ Arinc::D ][ Arinc::Frequency ].span( 22, 5 );//3, 25, 2 );
	m_maps[ Arinc::D ][ Arinc::NavClass ].span( 27, 5 );
	m_maps[ Arinc::D ][ Arinc::Dme ].span( 51, 4 );
	m_maps[ Arinc::D ][ Arinc::Merit ].span( 84 );
	m_maps[ Arinc::D ][ Arinc::Datum ].span( 84 );
	m_maps[ Arinc::D ][ Arinc::Name ].span( 93, 30 );
	m_maps[ Arinc::D ][ Arinc::Coordinates ].span( 32, 19 );
	m_maps[ Arinc::D ][ Arinc::Exceed ].span( 79, 5 );
	m_maps[ Arinc::D ][ Arinc::Bias ].span( 85, 2 );
	m_maps[ Arinc::D ][ Arinc::FreqPrd ].span( 87, 3 );
	m_maps[ Arinc::D ][ Arinc::DmeCoordinates ].span( 55, 19 );
	m_maps[ Arinc::D ][ Arinc::MagDev ].span( 74, 5 );
	//DB
	//m_maps[ Arinc::DB ][ Arinc::Airport ].span( 6, 4 );		// оно есть, но всегда пустое
	m_maps[ Arinc::DB ][ Arinc::Ident ].span( 19, 2, 13, 4 );
	m_maps[ Arinc::DB ][ Arinc::Frequency ].span( 22, 5 );
	m_maps[ Arinc::DB ][ Arinc::NavClass ].span( 27, 5 );
	m_maps[ Arinc::DB ][ Arinc::Coordinates ].span( 32, 19 );
	m_maps[ Arinc::DB ][ Arinc::MagDev ].span( 74, 5 );
	m_maps[ Arinc::DB ][ Arinc::Datum ].span( 90, 3 );
	m_maps[ Arinc::DB ][ Arinc::Name ].span( 93, 30 );
	//EA
	m_maps[ Arinc::EA ][ Arinc::Ident ].span( 19, 2, 13, 5 );
	m_maps[ Arinc::EA ][ Arinc::WaypointType ].span( 26, 3 );
	m_maps[ Arinc::EA ][ Arinc::WaypointUsage ].span( 29, 2 );
	m_maps[ Arinc::EA ][ Arinc::Coordinates ].span( 32, 19 );
	m_maps[ Arinc::EA ][ Arinc::MagDev ].span( 74, 5 );
	m_maps[ Arinc::EA ][ Arinc::Datum ].span( 84, 3 );
	m_maps[ Arinc::EA ][ Arinc::WaypointFormat ].span( 95, 3 );
	m_maps[ Arinc::EA ][ Arinc::Name ].span( 98, 5 );
	//EM
	//EP
	m_maps[ Arinc::EP ][ Arinc::Region ].span( 10, 2, 6, 4 );
	m_maps[ Arinc::EP ][ Arinc::Duplicate ].span( 27, 2 );
	m_maps[ Arinc::EP ][ Arinc::Fix ].span( 36, 2, 34, 2, 29, 5 );
	m_maps[ Arinc::EP ][ Arinc::CourseIb ].span( 39, 4 );
	m_maps[ Arinc::EP ][ Arinc::Turn ].span( 43 );
	m_maps[ Arinc::EP ][ Arinc::Distance ].span( 44, 3 );
	m_maps[ Arinc::EP ][ Arinc::Time ].span( 47, 2 );
	m_maps[ Arinc::EP ][ Arinc::AltitMin ].span( 49, 5 );
	m_maps[ Arinc::EP ][ Arinc::AltitMax ].span( 54, 5 );
	m_maps[ Arinc::EP ][ Arinc::Speed ].span( 59, 3 );
	m_maps[ Arinc::EP ][ Arinc::Comment ].span( 98, 25 );
	//ER
	m_maps[ Arinc::ER ][ Arinc::Ident ].span( 13, 6, Arinc::Way );
	m_maps[ Arinc::ER ][ Arinc::Order ].span( 25, 4 );
	m_maps[ Arinc::ER ][ Arinc::Fix ].span( 36, 2, 34, 2, 29, 5 );
	m_maps[ Arinc::ER ][ Arinc::WaypointDescription ].span( 39, 4 );
	m_maps[ Arinc::ER ][ Arinc::Border ].span( 43 );
	m_maps[ Arinc::ER ][ Arinc::RouteType ].span( 44 );
	m_maps[ Arinc::ER ][ Arinc::Level ].span( 45 );
	m_maps[ Arinc::ER ][ Arinc::Direction ].span( 46 );
	m_maps[ Arinc::ER ][ Arinc::CruisingTable ].span( 47, 2 );
	m_maps[ Arinc::ER ][ Arinc::EuIndicator ].span( 49 );
	m_maps[ Arinc::ER ][ Arinc::RecdNav ].span( 54, 2, 50, 4 );
	m_maps[ Arinc::ER ][ Arinc::Rnp ].span( 56, 3 );
	m_maps[ Arinc::ER ][ Arinc::Theta ].span( 62, 4 );
	m_maps[ Arinc::ER ][ Arinc::CourseOb ].span( 70, 4 );
	m_maps[ Arinc::ER ][ Arinc::Distance ].span( 74, 4 );
	m_maps[ Arinc::ER ][ Arinc::CourseIb ].span( 78, 4 );
	m_maps[ Arinc::ER ][ Arinc::AltitMin ].span( 83, 5 );
	m_maps[ Arinc::ER ][ Arinc::AltitMin2 ].span( 88, 5 );
	m_maps[ Arinc::ER ][ Arinc::AltitMax ].span( 93, 5 );

	/*
	// Volume Header
	m_maps[ Arinc::VolumeHeader ][ Arinc::LabelNumber ].span( 3 );
	m_maps[ Arinc::VolumeHeader ][ Arinc::VolumeNumber ].span( 4, 6 );
	m_maps[ Arinc::VolumeHeader ][ Arinc::DataFrom ].span( 37, 14 );
	m_maps[ Arinc::VolumeHeader ][ Arinc::Tracks ].span( 51, 2 );
	*/
}

ArincLineMap &
ArincLineMaps::operator[]( Arinc::Subsection ss )
{
	return m_maps[ ss ];
}

const ArincLineMap &
ArincLineMaps::operator[]( Arinc::Subsection ss ) const
{
	return m_maps[ ss ];
}

