using System.Collections;
namespace LearningHashtable
{
    class Program
    {
        static void Main(string[] args)
        {
            //哈希表
            //增
            Hashtable hashtable = new Hashtable();
            hashtable.Add("Name", "John");
            hashtable.Add("Age", 30);
            hashtable.Add("City", "New York");
            Console.WriteLine("Name: " + hashtable["Name"]);
            Console.WriteLine("Age: " + hashtable["Age"]);
            Console.WriteLine("City: " + hashtable["City"]);

            //查
            if (hashtable.ContainsKey("Name"))
            {
                Console.WriteLine("Key 'Name' exists in the hashtable.");
            }

            //删
            hashtable.Remove("Age");

            //改
            hashtable["City"] = "Los Angeles";

            //遍历
            //DictionaryEntry是一个结构体，表示哈希表中的一个键值对
            foreach (DictionaryEntry entry in hashtable)
            {
                Console.WriteLine($"{entry.Key}: {entry.Value}");
            }
        }
    }
}