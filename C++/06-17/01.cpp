//#include "Default.h"
//
//class Point
//{
//private:
//	int xpos, ypos;
//public:
//	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
//	{
//
//	}
//	void ShowPosition()const
//	{
//		cout << "[" << xpos << ", " << ypos << "]" << endl;
//	}
//	Point operator+(const Point& ref)
//	{
//		Point pos(xpos + ref.xpos, ypos + ref.ypos);
//			return pos;
//	}
//	friend Point operator-(const Point& pos1, const Point& pos2);
//	Point operator*(const Point& ref)
//	{
//		Point pos(xpos * ref.xpos, ypos * ref.ypos);
//		return pos;
//	}
//	friend Point operator/(const Point& pos1, const Point& pos2);
//
//	Point& operator++()
//	{
//		xpos += 1;
//		ypos += 1;
//		return *this;
//	}
//	const Point operator++(int)
//	{
//		const Point retobj(xpos, ypos);
//		xpos += 1;
//		ypos += 1;
//		return retobj;
//	}
//	friend const Point operator--(Point& ref, int);
//
//};
//Point operator-(const Point& pos1, const Point& pos2)
//{
//	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
//	return pos;
//}
//const Point operator--(Point& ref, int)
//{
//	const Point retobj(ref);
//	ref.xpos -= 1;
//	ref.ypos -= 1;
//	return retobj;
//}
//
//Point operator/(const Point& pos1, const Point& pos2)
//{
//	Point pos(pos1.xpos / pos2.xpos, pos1.ypos / pos2.ypos);
//	return pos;
//}
//
//int main(void)
//{
//	/*Point pos1(3, 4);
//	Point pos2(10, 20);
//	Point pos3 = pos1.operator+(pos2);
//	Point pos4 = operator-(pos1, pos2);
//	Point pos5 = pos1.operator*(pos2);
//	Point pos6 = operator/(pos1, pos2);
//
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//	pos3.ShowPosition();
//	pos4.ShowPosition();
//	pos5.ShowPosition();
//	pos6.ShowPosition();*/
//
//	Point pos(1, 2);
//	//++pos;
//	/*pos.operator++();
//	pos.ShowPosition();
//	++(++pos);
//	pos.ShowPosition();*/
//	Point cpy;
//	cpy = pos--;
//	cpy.ShowPosition();
//	pos.ShowPosition();
//
//	cpy = pos++;
//	cpy.ShowPosition();
//	pos.ShowPosition();
//	
//	return 0;
//}