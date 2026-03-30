namespace LearningLinkedList
{
    //定义双向链表
    class LinkedNodeD<T>
    {
        public T Value;
        public LinkedNodeD<T> nextNode;
        public LinkedNodeD<T> lastNode;
        public LinkedNodeD(T value)
        {
            Value = value;
            nextNode = null;
            lastNode = null;
        }
    }

    class DoubleLinkedList<T>
    {
        public LinkedNodeD<T> head;

        public DoubleLinkedList()
        {
            head = null;
        }

        public void Add(T value)
        {
            LinkedNodeD<T> newNode = new LinkedNodeD<T>(value);
            if (head == null)
            {
                head = newNode;
            }
            else
            {
                LinkedNodeD<T> currentNode = head;
                while (currentNode.nextNode != null)
                {
                    currentNode = currentNode.nextNode;
                }
                currentNode.nextNode = newNode;
                newNode.lastNode = currentNode;
            }
        }
        public void Remove(T value)
        {
            if (head == null) return;
            if (head.Value.Equals(value))
            {
                head = head.nextNode;
                if (head != null)
                {
                    head.lastNode = null;
                }
                return;
            }
            LinkedNodeD<T> currentNode = head;
            while (currentNode.nextNode != null)
            {
                if (currentNode.nextNode.Value.Equals(value))
                {
                    LinkedNodeD<T> deleteNode = currentNode.nextNode;
                    currentNode.nextNode = deleteNode.nextNode;

                    if (deleteNode.nextNode != null)
                    {
                        deleteNode.nextNode.lastNode = currentNode;
                    }
                    return;
                }
                currentNode = currentNode.nextNode;
            }
        }
    }
}
