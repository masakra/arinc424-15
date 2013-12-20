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

#include "ArincObject.h"

#include "ArincLine.h"

ArincObject::ArincObject()
	: m_interface( 0 )
{
}

ArincObject::ArincObject( ArincObjectInterface * interface )
	: m_interface( interface )
{
}

ArincObject::ArincObject( const string & str )
	: m_interface( ArincLine::line( str ) )
{
}

ArincObject::ArincObject( const char * str )
	: m_interface( ArincLine::line( str ) )
{
}

ArincObject::~ArincObject()
{
	if ( m_interface )
		delete m_interface;
}

ArincObjectInterface *
ArincObject::operator->()
{
	return m_interface;
}

ArincObject &
ArincObject::operator=( const ArincObject & other )
{
	if ( m_interface )
		delete m_interface;

	m_interface = other.m_interface;

	return *this;
}

ArincObject &
ArincObject::operator=( const string & str )
{
	if ( m_interface )
		delete m_interface;

	m_interface = ArincLine::line( str );

	return *this;
}

