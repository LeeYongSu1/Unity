using System;

namespace Map
{
    class Program
    {
        static void Main(string[] args)
        {
            Class2 board = new Class2();
            board.Initialize(25);
            
            while (true)
            {
                Console.SetCursorPosition(0, 0);
                board.Render();
            }
        }
    }
}
