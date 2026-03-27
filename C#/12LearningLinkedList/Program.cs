using System;

namespace LearningLinkedList
{
    class Program
    {
        static void Main(string[] args)
        {
            LinkedList linkedList = new LinkedList();
            linkedList.Add(1);
            linkedList.Add(2);
            linkedList.Add(3);
            linkedList.Add(4);
            linkedList.Add(5);

            Console.WriteLine("Linked List:");
            linkedList.Print();

            Console.WriteLine("\nReversed Linked List:");
            linkedList.Reverse();
            linkedList.Print();
        }
    }
}
