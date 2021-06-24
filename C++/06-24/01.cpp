#include "Default.h"

template <typename T>
class Point
{
private:
    T xpos, ypos;
public:
    Point(T x = 0, T y = 0) : xpos(x), ypos(y)
    {  }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    //friend를 선언 했지만 클래스 밖에 존재하는 클래스라 위의 템플릿의 영향을 받지 않는다.
    friend Point<int> operator+(const Point<int>&, const Point<int>&);
    friend ostream& operator<<(ostream& os, const Point<int>& pos);
};

Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2)
{
    return Point<int>(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}

ostream& operator<<(ostream& os, const Point<int>& pos)
{
    os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
    return os;
}

template <typename T>
class SimpleDataWrapper
{
private:
    T mdata;
public:
    SimpleDataWrapper(T data): mdata(data){}
    void ShowDataInfo(void)
    {
        cout << "Data: " << mdata << endl;
    }
};

template <>
class SimpleDataWrapper<string>
{
private:
    string mdata;
    //char* mdata;
public:
    SimpleDataWrapper(string data)
    {
        //mdata = new char[strlen(data) + 1];
        //strcpy_s(mdata, strlen(data) + 1, data);
        mdata = data;
    }
    void ShowDataInfo(void)
    {
        cout << "String: " << mdata << endl;
        cout << "Length: " << mdata.length() << endl;
    }
};

template<>
class SimpleDataWrapper <Point<int>>
{
private:
    Point<int> mdata;
public:
    SimpleDataWrapper(int x, int y): mdata(x, y)
    {}
    void ShowDataInfo(void)
    {
        mdata.ShowPosition();
    }
};

int main(void)
{
    SimpleDataWrapper<int> iwrap(170);
    iwrap.ShowDataInfo();

    SimpleDataWrapper<string> swrap("Class Template Specialization");
    swrap.ShowDataInfo();

    SimpleDataWrapper<Point<int>> poswrap(3, 7);
    poswrap.ShowDataInfo();
    

    return 0;
}