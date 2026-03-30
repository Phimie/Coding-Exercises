namespace LearningLinkedList
{
    //定义链表节点
    class LinkedNode<T>
    {
        public T Value;
        public LinkedNode<T> nextNode;

        public LinkedNode(T value)
        {
            Value = value;
            nextNode = null;
        }
    }

}