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

/*! \class Arinc
 *
 * \brief 
 */

#ifndef ARINC_H
#define ARINC_H

#define SUBSECTION_ABBR_BUF_SIZE 4

class ArincObjectInterface;

class Arinc
{
	private:

		/*
		\\	static
		*/
	public:
		/*! \enum Subsection
		 *
		 * \brief Подсекции ARINC
		 *
		 * Нельзя изменять !!! Многие источники данных опираются на enum Subsection
		 * как на индекс массива.
		 */
		enum Subsection {
			Unknown = 0,
			AS,		///< минимальная безопасная высота полёта вне маршрута (MORA)
			// раздел D. Навигационные средства
			D,		///< навигационные средства ОВЧ
			DB,		///< навигационные средства ОПРС
			// раздел E. Маршрут
			EA,		///< ППМ - промежуточная точка маршрута
			EM,		///< маркер авиатрассы раздела
			EP,		///< схемы полёта в зоне ожидания
			ER,		///< воздушные трассы
			EU,		///< ограничения воздушных трасс
			EV,		///< средства связи
			// раздел P. Аэродромы
			PA,		///< контрольные точки аэродромов
			PB,		///< районы входа
			PC,		///< контрольные точки аэроузла
			PD,		///< стандартная схема вылета по приборам (ВЫХОД)
			PE,		///< схемы стандартного маршрута прибытия (ВХОД)
			PF,		///< схемы захода на посадку
			PG,		///< ВПП - взлётно-посадочная полоса
			PI,		///< курсовой радиомаяк
			PL,		///< микроволновая система посадки
			PM,		///< маркеры курсового маяка
			PS,		///< минимальная высота сектора
			PV,		///< средства связи раздела
			PN,		///< ОПРС аэроузла
			// раздел R. Трассы авиакомпаний
			R,		///< трассы
			// раздел U. Ограниченное воздушное пространство
			UC,		///< контролируемое воздушное пространство
			UR,		///< ограниченное воздушное пространство
			UF,		///< ФИР/УИР
			// раздел T. Таблицы
			TC,		///< таблицы крейсерских эшелонов
			TG,		///< таблица географических координат
			HA,		///< вертодромы
			HV,		///< средство связи вертодрома
			ET,		///< предпочтительные маршруты
			EO		///< препятствия на маршруте
			////////////////////////////////////////////////////
			/// служебные строки файла в формате Arinc424-15 ///
			////////////////////////////////////////////////////
		};

		enum Type {
			NoType = 0,			///< Нет типа
			VolumeHeader,		///< Головная метка тома
			Header1,
			Header2,
			EndOfFile,
			EndOfVolume,
			Standard,		// Standard точечный объект
			Way,			// Standard объект-путь
			Tailored
		};

		enum Field {
			// ArincData::String
			Undefined = 0,

			Address,		///< Адрес средства связи ФИР/УИР из четырех символов
			Airport,		///< Код ICAO аэропорта с 2-х символьным кодом зоны
			AirspaceClass,	///< Класс воздушного пространства 5.215
			AirspaceType,	///< Тип воздушного пространства 5.213
			AltitDescription,	///< Описание высоты
			AltitMax,		///< Максимальная высота
			AltitMaxUnit,	///< Начало отсчёта максимальной высоты 5.133
			AltitMin,		///< Минимальная высота
			AltitMin2,		///< Минимальная высота 2
			AltitMinUnit,	///< Начало отсчёта минимальной высоты 5.133
			AltitTransition,	///< Высота перехода \sa LevelTransition
			Angle,			///< Вертикальный угол 5.70
			ArcBearing,		///< Пеленг дуги 5.120
			ArcCoordinates,	///< Координаты начала дуги
			ArcDistance,	///< Длина дуги 5.119
			ArcRadius,		///< Радиус дуги или окружности
			Atc,			///< Air Traffic Control (УВД) 5.81
			Bearing,		///< Bearing - пеленг
			Bearing1,
			Bearing2,
			Bearing3,
			Bearing4,
			Bearing5,
			Bias,			///< Смещение ILS/DME
			Border,			///< Код границы (5.18)
			Boundary,		///< Тип линии границы 5.118
			Comment,		///< Примечание
			CommType,		///< CommunicationsType - тип станции связи
			Coordinates,	///< Координаты
			CourseIb,		///< Курс, заданный Магнитный Путевой Угол (МПУ) на... (inbound)
			CourseOb,		///< Курс, заданный Магнитный Путевой Угол (МПУ) от... (outbound)
			CrossingHeight,	///< Threshold Crossing Height 5.67
			CruisingTable,	///< Таблица крейсерских эшелонов 5.134
			Cycle,			///< Цикл AIRAC в котором были последние изменения
			Datum,			///< Код исходного ориентира
			Direction,		///< Ограничение по направлению 5.115
			Displacement,	///< Threshold Displacement Distance 5.69
			Distance,		///< Расстояние
			DistanceCommunications,	///< Ограничение расстояния для станции 5.188
			DistanceDescription, ///< Описание расстояния 5.187
			DistanceTime,	///< Расстояние или время 5.27
			Dme,			///< Идентификотор DME
			DmeCoordinates,	///< Координаты DME
			Duplicate,		///< Идентификатор множественности маршрутов в точке (Duplicate Indicator)
			Encoding,		///< Кодировка
			EuIndicator,	///< Индикатор ограничения
			Elevation,		///< Landing Threshold Elevation
			EntryReport,	///< Входное донесение 5.124
			Exceed,			///< Превышение
			Facility,		///< Facility Characteristics - 5.93
			FirLimitUpper,	///< Верхняя граница ФИР 5.121
			Fix,			///< Идентификатор ППМ
			FixCenter,		///< Центральная контрольная точка 5.144
			Frequency,		///< Частота
			FrequencyUnit,	///< Диапазон частот
			FreqPrd,		///< Защита частоты
			GsCoordinates,	///< Glide Slope Coordinates - координаты глиссадного радиомаяка
			GsPosition,		///< Glide Slope Position - положение глиссадного радиомаяка
			GuardTransmit,	///< Приём/передача
			H24,			///< Круглосуточно Y/N
			Height1,
			Height2,
			Height3,
			Height4,
			Height5,
			HeightUnit,		///< Единица измерения высоты 5.123
			Iata,			///< Код IATA
			Icao,			///< Код ICAO
			Ident,			///< Идентификатор с 2-х символьным кодом зоны
			Ident1,			///< Localizer/MLS/GLS Identifier 1 5.44 5.80
			Ident2,			///< Localizer/MLS/GLS Identifier 2 5.44 5.80
			IdentRls,		///< Идентификатор РЛС
			Ifr,			///< Instrumental flight rules
			Indicator,		///< Индикатор ФИР/УИР
			Level,			///< Эшелон
			LevelTransition,	///< Эшелон перехода \sa AltitTransition
			LocalizerPosition,	///< Позиция курсового радиомаяка
			LocalizerReference,	///< Смещение курсового радиомаяка
			MagDev,			///< Магнитное склонение
			MagneticTrue,	///< Magnetic/True индикатор
			MarkerType,		///< Тип маркерного маяка 5.99
			Merit,			///< Чувствительность, показатель качества (был Sens)
			Modulation,		///< Модуляция
			MultipleCode,	///< Код множественности 5.130
			Name,			///< Наименование
			NavClass,		///< Класс навигационного средства
			NearFir,		///< Ближайший ФИР
			NearUir,		///< Ближайший УИР
			Notam,			///< Нотам
			Order,			///< Порядок точек в многоточечном объекте
			ParityCheck,	///< Контроль чётности
			PathAndTermination,	///< Траектория пути и завершение 5.21
			PublicMilitary,	///< Public/Military indicator
			Radar,			///< 5.102
			RadiusLimit,	///< Максимальный радиус 5.145
			RecdNav,		///< Рекомендуемое навигационное средство
			Region,			///< Код региона (Region code)
			RequiredNavPerformance,	///< Требуемая навигационная характеристика - 5.211
			RemoteFacility,	///< Выносная станция связи
			RestrictiveType,///< Тип ограничения воздушного пространства 2.128
			Rho,			///< Ро 5.25
			RlsCoordinates,	///< Координаты РЛС
			Rnp,			///< Требуемая навигационная характеристика (Required Navigation Performance)
			RouteType,		///< Тип маршрута
			Runway,			///< Идентификатор ВПП
			RunwayDistance,	///< Наибольшая длина ВПП
			RunwayGradient,	///< Уклон ВПП 5.212
			SectorFacility,	///< Навигационное средство сектора 5.185
			Sectorization,	///< Разделение на сектора 5.183
			Service,		///< Service indicator - индикатор службы связи
			SignalEmission,	///< Описание ВЧ сигнала
			Speed,			///< Скорость
			SpeedLimit,		///< Ограничение скорости
			SpeedUnit,		///< Единица измерения скорости 5.122
			Stopway,		///< Концевая полоса торможения 5.79
			Theta,			///< Тэта 5.24
			Time,			///< Время
			TimeCode,		///< Временной код - 5.131
			TimeDayLight,	///< Указатель летнего времени
			TimeZone,		///< Часовой пояс
			Transition,		///< Идентификатор перехода
			Turn,			///< Направление разворота
			TurnDirectionValid,	///< Необходимость разворота в заданном направлении 5.22
			UirLimitUpper,	///< Верхняя граница УИР - 5.121
			UirLimitLower,	///< Нижняя граница УИР - 5.121
			WaypointDescription,	///< Код описания ППМ
			WaypointFormat,	///< Индикатор формата имени (Name format indicator)
			WaypointType,	///< Тип ППМ
			WaypointUsage,	///< Использование ППМ на маршруте, по сути тип воздушного пространства
			Width,			///< Ширина
			Zone,			///< 3-x символьное обозначение зоны
			// ArincData::Coordinates

			// ArincData::Int
			// ArincData::Double
			// Volume Header
			LabelNumber,
			VolumeNumber,
			ArincBegin,
			ArincEnd,
			Tracks,
			Density
		};

		/*
		\\	static
		*/

		static const char * subsectionName( Subsection ss );

		static const char * subsectionAbbr( Subsection ss );

		static const char * fieldName( Field field );

		static Arinc::Subsection subsection( const char * abbr );
};

#endif

