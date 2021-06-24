using System;
using System.Collections.Generic;
using System.Text;

namespace _05_10_Csharp
{
    
    class Room2<T>
    {
        public T Data;
        public Room2<T> Next;
        public Room2<T> Prev;
    }

    class RoomList2<T>
    {
        public int count = 0;
        public Room2<T> Head = null;
        public Room2<T> Tail = null;

        public Room2<T> AddLast(T data)
        {
            Room2<T> newRoom = new Room2<T>();
            newRoom.Data = data;

            if (Head == null)
                Head = newRoom;

            if (Tail != null)
                Tail.Next = newRoom;

            Tail = newRoom;
            count++;
            return newRoom;
        }
        //101 102 103 104
        public void Remove(Room2<T> room)
        {
            if (Head == room)
                Head = Head.Next;

            if (Tail == room)
                Tail = Tail.Prev;

            if (room.Prev != null)
                room.Prev.Next = room.Next;

            if (room.Next != null)
                room.Next.Prev = room.Prev;

            count--;
        }
    }

    class Class2
    {
    }
}
