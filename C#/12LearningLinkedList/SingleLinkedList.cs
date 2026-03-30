namespace LearningLinkedList
{
    //定义单向链表
    class LinkedList<T>
    {
        public LinkedNode<T> head;

        public LinkedList()
        {
            head = null;
        }

        //添加节点
        public void Add(T value)
        {
            LinkedNode<T> newNode = new LinkedNode<T>(value);
            if (head == null)
            {
                head = newNode;
            }
            else
            {
                LinkedNode<T> currentNode = head;
                while (currentNode.nextNode != null)
                {
                    currentNode = currentNode.nextNode;
                }
                currentNode.nextNode = newNode;
            }
        }

        //删除节点
        public void Remove(T value)
        {
            if (head == null) return;

            if (head.Value.Equals(value)) //这里不用==,因为T可能是引用类型，==比较的是引用地址，而Equals比较的是值
            {
                head = head.nextNode;
                return;
            }

            LinkedNode<T> currentNode = head;
            while (currentNode.nextNode != null)
            {
                if (currentNode.nextNode.Value.Equals(value))
                {
                    currentNode.nextNode = currentNode.nextNode.nextNode; //跳过要删除的节点
                    return;
                }
                currentNode = currentNode.nextNode;
            }
        }
    }
}