using System;
using System.Collections.Generic;
using System.Text;

namespace _05_10_Csharp
{
    class Room<T>
    {
        public T Data;
        public Room<T> Next;
        public Room<T> Prev;

    }

    class RoomList<T>
    {
        public Room<T> Head = null; //첫번째
        public Room<T> Tail = null; //마지막
        public int Count = 0;

        public Room<T> AddLast(T data)
        {
            Room<T> newRoom = new Room<T>();
            newRoom.Data = data;

            //만약에 아직 방이 아예 없었다면, 새로 추가한 방이 곧 Head이다
            if (Head == null)
                Head = newRoom;
            //101 102 103 104
            //기존의 [마지막 방]과 [새로 추가되는 방]을 연결한다.
            if (Tail != null)
            {
                Tail.Next = newRoom;
                newRoom.Prev = Tail;
            }
            //[새로 추가되는 방]을 [마지막 방]으로 인정한다.
            Tail = newRoom;
            Count++;
            return newRoom;
        }
        //101 102 103 104 105
        public void Remove(Room<T> room)
        {
            //[기존의 첫번째 방의 다음 방]을 [첫번 째 방]으로 인정한다.
            if (Head == room)
                Head = Head.Next;
            //[기존의 마지막 방의 이전 방]을 [마지막 방]으로 인정한다.
            if (Tail == room)
                Tail = Tail.Prev;

            if (room.Prev != null)
                room.Prev.Next = room.Next;

            if (room.Next != null)
                room.Next.Prev = room.Prev;

            Count--;
        }
    }

    class Board
    {
        public int[] _data = new int[25];//배열
        public LinkedList<int> _data3 = new LinkedList<int>();

        public void Initialize()
        {
            
        }
    }
}
