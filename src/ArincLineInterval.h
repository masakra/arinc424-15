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

/*! \class ArincLineInterval
 *
 * \brief Интервал для вырезки дынных
 *
 * Может быть два интервала. В этом случае результаты вырезок конкатенируются.
 */

#ifndef ARINCLINEINTERVAL_H
#define ARINCLINEINTERVAL_H

#include <vector>

class ArincLineInterval : public std::vector< unsigned char >
{
	public:
		ArincLineInterval();

		void interval( unsigned char st1, unsigned char le1 = 1 );

		void interval( unsigned char st1, unsigned char le1, unsigned char st2, unsigned char le2 );

		bool isValid() const;

		bool haveFirstPart() const;

		int start1() const;
		int length1() const;

		bool haveSecondPart() const;

		int start2() const;
		int length2() const;
};

#endif

