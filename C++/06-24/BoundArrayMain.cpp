//#include "ArrayTemplate.h"
//#include "PointTemplate.h"
//
//int main(void)
//{
//
//	BoundCheckArray<Point<int>> oarr1(3);
//	oarr1[0] = Point<int>(3, 4);
//	oarr1[1] = Point<int>(5, 6);
//	oarr1[2] = Point<int>(7, 8);
//
//	for (int i = 0; i < oarr1.GetArrLen(); i++)
//		oarr1[i].ShowPosition();
//
//	BoundCheckArray<Point<double>> oarr2(3);
//	oarr2[0] = Point<double>(3.14, 4.1);
//	oarr2[1] = Point<double>(5.23, 6.5);
//	oarr2[2] = Point<double>(7.56, 8.9);
//
//	for (int i = 0; i < oarr2.GetArrLen(); i++)
//		oarr2[i].ShowPosition();
//
//	typedef Point<int>* POINT_PTR;
//	BoundCheckArray<POINT_PTR> oparr(3);
//	oparr[0] = new Point<int>(11, 12);
//	oparr[1] = new Point<int>(13, 14);
//	oparr[2] = new Point<int>(15, 16);
//
//	for (int i = 0; i < oparr.GetArrLen(); i++)
//		oparr[i]->ShowPosition();
//
//	for (int i = 0; i < oparr.GetArrLen(); i++)
//		delete oparr[i];
//
//
//	return 0;
//}