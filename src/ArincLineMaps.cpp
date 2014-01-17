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
	m_maps[ Arinc::D ][ Arinc::Airport ].interval( 10, 2, 6, 4 );
	m_maps[ Arinc::D ][ Arinc::Ident ].interval( 19, 2, 13, 4 );
	m_maps[ Arinc::D ][ Arinc::Frequency ].interval( 22, 3, 25, 2 );
	m_maps[ Arinc::D ][ Arinc::NavClass ].interval( 27, 5 );
	m_maps[ Arinc::D ][ Arinc::Dme ].interval( 51, 4 );
	m_maps[ Arinc::D ][ Arinc::Merit ].interval( 84 );
	m_maps[ Arinc::D ][ Arinc::Datum ].interval( 84 );
	m_maps[ Arinc::D ][ Arinc::Name ].interval( 93, 30 );
	m_maps[ Arinc::D ][ Arinc::Coordinates ].interval( 32, 19 );
	m_maps[ Arinc::D ][ Arinc::Exceed ].interval( 79, 5 );
	m_maps[ Arinc::D ][ Arinc::Bias ].interval( 85, 2 );
	m_maps[ Arinc::D ][ Arinc::FreqPrd ].interval( 87, 3 );
	m_maps[ Arinc::D ][ Arinc::DmeCoordinates ].interval( 55, 19 );
	m_maps[ Arinc::D ][ Arinc::MagDev ].interval( 74, 5 );
	//DB
	/*
	m_maps[ Arinc::DB ][ Arinc::Coordinates ].interval( 32, 19 );

	// Volume Header
	m_maps[ Arinc::VolumeHeader ][ Arinc::LabelNumber ].interval( 3 );
	m_maps[ Arinc::VolumeHeader ][ Arinc::VolumeNumber ].interval( 4, 6 );
	m_maps[ Arinc::VolumeHeader ][ Arinc::DataFrom ].interval( 37, 14 );
	m_maps[ Arinc::VolumeHeader ][ Arinc::Tracks ].interval( 51, 2 );
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

