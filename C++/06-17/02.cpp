//#include "Default.h"
//
//class Point
//{
//private:
//    int xpos, ypos;
//public:
//    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
//    {  }
//    void ShowPosition() const
//    {
//        cout << '[' << xpos << ", " << ypos << ']' << endl;
//    }
//    Point& operator+=(const Point& pos1)
//    {
//        Point pos(xpos + pos1.xpos, ypos + pos1.ypos);
//        return pos;
//    }
//    Point& operator-=(const Point& pos1)
//    {
//        Point pos(xpos - pos1.xpos, ypos - pos1.ypos);
//        return pos;
//    }
//    Point operator*(int times)
//    {
//        Point pos(xpos * times, ypos * times);
//        return pos;
//    }
//    friend Point operator*(int times, Point& ref);
//   friend Point operator-(const Point& pos1, const Point& pos2);
//   friend bool operator==(const Point& pos1, const Point& pos2);
//   friend bool operator!=(const Point& pos1, const Point& pos2);
//};
//
//Point operator-(const Point& pos1, const Point& pos2)
//{
//    Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
//
//    return pos;
//}
//Point operator*(int times, Point& ref)
//{
//    return ref * times;
//}
//
//bool operator==(const Point& pos1, const Point& pos2)
//{
//    if (pos1.xpos == pos2.xpos || pos1.ypos == pos2.ypos)
//        return true;
//    else
//        return false;
//}
//bool operator!=(const Point& pos1, const Point& pos2)
//{
//    if (pos1.xpos == pos2.xpos || pos1.ypos == pos2.ypos)
//        return false;
//    else
//        return true;
//}
//
//
//
//int main(void)
//{
//    /*bool pos4;
//    Point pos(5, 10);
//    Point pos1(3, 6);
//    Point pos2 = pos.operator+=(pos1);
//    Point pos3 = pos.operator-=(pos1);
//    pos2.ShowPosition();
//    pos3.ShowPosition();
//    
//    cout << std::boolalpha;
//    cout << (pos == pos1) << endl;*/
//
//    Point pos(1, 2);
//    Point cpy;
//    cpy = pos * 3;
//    cpy.ShowPosition();
//    cpy = pos * 3 * 2;
//    cpy.ShowPosition();
//    
//    return 0;
//}