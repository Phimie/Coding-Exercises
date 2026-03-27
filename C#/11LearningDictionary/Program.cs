using System.Collections.Generic;
namespace LearningDictionary
{
    class Program
    {
        static void Main(string[] args)
        {
            //Dictionary<TKey, TValue> 是一个泛型集合类，用于存储键值对
            //对比HashTable，Dictionary<TKey, TValue> 是类型安全的，并且性能更好
            //因为避免了装箱和拆箱操作
            //现代的C#开发中，推荐使用Dictionary<TKey, TValue> 而不是HashTable
            Dictionary<string, string> myDictionary = new Dictionary<string, string>();

            //增
            myDictionary.Add("Hello", "A greeting");
            myDictionary.Add("World", "The earth, together with all of its countries and peoples");

            //删
            myDictionary.Remove("Hello");

            //改
            myDictionary["World"] = "The planet we live on";

            //查
            Console.WriteLine(myDictionary["World"]);

            if (myDictionary.ContainsKey("Hello"))  //检查键是否存在
            {
                Console.WriteLine(myDictionary["Hello"]);
            }
            else
            {
                Console.WriteLine("Key 'Hello' does not exist.");
            }

            //遍历
            foreach (KeyValuePair<string, string> kvp in myDictionary)  //KeyValuePair<TKey, TValue> 是一个结构体，表示字典中的一个键值对
            {
                Console.WriteLine($"Key: {kvp.Key}, Value: {kvp.Value}");
            }





            Console.WriteLine("按任意键退出...");
            Console.ReadKey();
        }
    }
}