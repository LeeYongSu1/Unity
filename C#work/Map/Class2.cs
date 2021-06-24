using System;
using System.Collections.Generic;
using System.Text;

namespace Map
{

    class Class2
    {
        public ListType[,] _list;
        public int _size;
        public enum ListType
        {
            Wall,
            Empty,
        }

        public void Initialize(int size)
        {
            _size = size;
            _list = new ListType[size, size];

            for (int y = 0; y < _size; y++)
            {
                for (int x = 0; x < _size; x++)
                {
                    if (x %2 == 0 || y %2 == 0)
                        _list[y, x] = ListType.Wall;
                    else
                        _list[y, x] = ListType.Empty;
                }
            }
            Random rand = new Random();
            for (int y = 0; y < _size; y++)
            {
                for (int x = 0; x < _size; x++)
                {
                    if (x % 2 == 0 || y % 2 == 0)
                        continue;

                    if (y == _size - 2 && x == _size - 2)
                        continue;

                    if (y == _size - 2)
                    {
                        _list[y, x + 1] = ListType.Empty;
                        continue;
                    }

                    if (x == _size - 2)
                    {
                        _list[y + 1, x] = ListType.Empty;
                        continue;
                    }

                    if (rand.Next(0, 2) == 0)
                        _list[y, x + 1] = ListType.Empty;
                    else
                        _list[y + 1, x] = ListType.Empty;
                    
                }
            }
        }

        public void Render()
        {
            for (int y = 0; y < _size; y++)
            {
                for (int x = 0; x < _size; x++)
                {
                    
                        Console.ForegroundColor = GetTileColor(_list[y,x]);
                    Console.Write('\u25cf');
                }
                Console.WriteLine();
            }
        }

        ConsoleColor GetTileColor(ListType type)
        {
            switch (type)
            {
                case ListType.Wall:
                    return ConsoleColor.Red;
                case ListType.Empty:
                    return ConsoleColor.Green;
                default:
                    return ConsoleColor.Green;
            }
        }
    }

    


}
