using System;
using System.Collections.Generic;
using System.Text;

namespace _05_10_Csharp
{
    class MyList2<T>
    {
        const int DEFAULT_SIZE = 1;
        T[] _data = new T[DEFAULT_SIZE];
        public int count = 0;
        public int capacity { get { return _data.Length; } }

        public void Add(T item)
        {
            //1.공간이 충분히 남아 있는지 확인한다
            if (count >= capacity)
            {
                //공간을 다시 늘려서 확보한다.
                T[] newArray = new T[count * 2];
                for (int i = 0; i < count; i++)
                {
                    newArray[i] = _data[i];
                    _data = newArray;
                }
            }
            _data[count] = item;
            count++;
        }

        public T this[int index]
        {
            get { return _data[index]; }
            set { _data[index] = value; }
        }

        public void RemoveAt(int index)
        {
            for (int i = index; i < count -1; i++)
            {
                _data[i] = _data[i + 1];
                _data[count - 1] = default(T);
            }
            count--;
        }
    }
    class Class1
    {
    }
}
