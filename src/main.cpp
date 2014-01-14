
#include <iostream>

#include "ArincLine.h"
//#include "ArincLineD.h"
//
//#include "ArincObject.h"

int
main( int , char ** )
{
	//ArincObject object = "SAFRD        AD    DI011430VDU  N05165810W003550120    N05165810W003550120W0060000492  515WGEABIDJAN/F.H. BOIGNY           000051312";
	ArincLine line("SAFRD        AD    DI011430VDU  N05165810W003550120    N05165810W003550120W0060000492  515WGEABIDJAN/F.H. BOIGNY           000051312");

	//std::cout << "name =" << object->ident() << std::endl;

	//std::cout << Arinc::subsectionAbbr( Arinc::Unknown ) << std::endl;

	std::cout << line.data( Arinc::Name ).toStdString() << std::endl;
	std::cout << line.data( Arinc::Ident ).toStdString() << std::endl;
	std::cout << line.data( Arinc::Coordinates ).toCoordinates().strShort() << std::endl;
	//std::cout << ( static_cast< std::string >( line.data( Arinc::Ident ) ) ).c_str() << std::endl;

//	Coordinates c = object->coordinatesDme();

//	std::cout << geo::ortodromiaRad( Coordinates( 1.0, -50.0 ), Coordinates( 10.0, 50.0 ) ) << std::endl;

	return 0;
}
