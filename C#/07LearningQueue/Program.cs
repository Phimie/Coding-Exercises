using System.Collections;
namespace LearningQueue
{
    class Program
    {
        static void Main(string[] args)
        {

            //队列:先进先出
            Queue queue = new Queue();

            //入队
            queue.Enqueue("a");
            queue.Enqueue(1);
            queue.Enqueue(true);
            queue.Enqueue(3.14);
            //出队
            Console.WriteLine(queue.Dequeue());

            //查
            Console.WriteLine(queue.Peek());
            if (queue.Contains(1))
            {
                Console.WriteLine("队列中包含1");
            }

            //遍历队列
            //方法一: 使用foreach循环
            foreach (var item in queue)
            {
                Console.WriteLine(item);
            }
            //方法二: 使用while循环和Count属性
            while (queue.Count > 0)
            {
                Console.WriteLine(queue.Dequeue());
            }

            //方法三: 使用ToArray方法将队列转换为数组
            object[] array = queue.ToArray();
            foreach (var item in array)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine("请按任意键继续...");
            Console.ReadKey();

        }
    }
}