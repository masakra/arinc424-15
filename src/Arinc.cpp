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

#include "Arinc.h"


const char *
Arinc::subsectionName( Subsection ss ) // static
{
	static const char * names[] = {
		"Неизвестно",
		"Координатная сетка для минимальных высот вне маршрута (MORA)",
		"Навигационное средство ОВЧ",
		"Навигационное средство ОПРС"
		"Промежуточный пункт маршрута (ППМ)",
		"Маркерный маяк",
		"Схема полёта в зоне ожидания",
		"Воздушная трасса",
		"Предпочтительный маршрут",
		"Ограничение на авиатрассе",
		"Средство связи на трассе",
		"Контрольная точка вертодрома",
		"Средство связи вертодрома",
		"Контрольная точка аэродрома",
		"Район входа аэродрома",
		"Точка маршрута в районе аэродрома",
		"Стандартная схемы вылета по приборам (ВЫХОД)",
		"Стандартная схема захода на посадку (ВХОД)",
		"Схема захода на посадку",
		"Взлётно-посадочная полоса (ВПП)",
		"Курсовой или глиссадный радиомаяк",
		"Микроволновая система посадки",
		"Курсовой маркерный маяк",
		"ОПРС аэроузла",
		"Минимальная безопасная абсолютная высота (MSA)",
		"Средство связи аэродрома",
		"Маршрут авиакомпании",
		"Крейсерский эшелон",
		"Географические координаты",
		"Контролируемое ВД",
		"ФИР/УИР",
		"Ограниченное ВД"
	};

	if ( ss > EO )
		return 0;
	else
		return names[ ss - Unknown ];
}

const char *
Arinc::subsectionAbbr( Subsection ss )
{
	static const char * abbr[] = {
		"Unknown",
		"AS",
		"D ",
		"DB",
		"EA",
		"EM",
		"EP",
		"ER",
		"EU",
		"EV",
		"PA",
		"PB",
		"PC",
		"PD",
		"PE",
		"PF",
		"PG",
		"PI",
		"PL",
		"PM",
		"PS",
		"PV",
		"PN",
		"R ",
		"UC",
		"UR",
		"UF",
		"TC",
		"TG",
		"HA",
		"HV",
		"ET",
		"EO"
	};

	if ( ss > EO )
		return 0;
	else
		return abbr[ ss - Unknown ];
}

const char *
Arinc::fieldName( Field field )
{
	static const char * names[] = {
		0,					// Undefined

		"airport",			// Airport
		"cycle",			// Cycle
		"datum",			// Datum
		"dme",				// Dme
		"ident",			// Ident
		"merit",			// Merit
		"name",				// Name
		"navclass",			// NavClass
		"zone",				// Zone

		"dmecoordinates",	// DmeCoordinates
		"coordinates",		// Coordinates

		"frequency",		// Frequency	numeric( 6,2 )
		"freqprd",

		"bias",
		"exceed",

		"magdev"			// MagDev		numeric( 4,1 )
	};

	return names[ field ];
}

