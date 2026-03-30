using System;
namespace LearningLinkedList
{
    class Program
    {
        static void Main(string[] args)
        {
            #region  测试简单单向列表
            LinkedList<int> linkedList = new LinkedList<int>();
            for (int i = 0; i < 5; i++)
            {
                linkedList.Add(i);
            }
            linkedList.Remove(2);
            //遍历链表
            LinkedNode<int> currentNode = linkedList.head;
            while (currentNode != null)
            {
                Console.WriteLine(currentNode.Value);
                currentNode = currentNode.nextNode;
            }

            Console.WriteLine("请按任意键继续...");
            Console.ReadKey();
            #endregion
        }
    }
}