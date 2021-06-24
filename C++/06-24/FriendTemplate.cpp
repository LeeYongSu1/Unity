//#include "Default.h"
//
//template <typename T>
//class Point
//{
//private:
//    T xpos, ypos;
//public:
//    Point(T x = 0, T y = 0) : xpos(x), ypos(y)
//    {  }
//    void ShowPosition() const
//    {
//        cout << '[' << xpos << ", " << ypos << ']' << endl;
//    }
//    //friend를 선언 했지만 클래스 밖에 존재하는 클래스라 위의 템플릿의 영향을 받지 않는다.
//    friend Point<int> operator+(const Point<int>&, const Point<int>&);
//    friend ostream& operator<<(ostream& os, const Point<int>& pos);
//};
//
//Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2)
//{
//    return Point<int>(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
//}
//
//
//ostream& operator<<(ostream& os, const Point<int>& pos)
//{
//    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
//    return os;
//}
//
//int main(void)
//{
//    Point<int> pos1(2, 4);
//    Point<int> pos2(4, 8);
//    Point<int> pos3 = operator+(pos1, pos2);
//    cout << pos1 << pos2 << pos3;
//
//    return 0;
//}