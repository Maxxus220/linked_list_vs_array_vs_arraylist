struct LinkNode {
    LinkNode* next;
    int val;
};

class OrderedLinkedList {
    public:
        int size;
        OrderedLinkedList();
        ~OrderedLinkedList();
        
        void add(int val);
        bool remove(int index);

    private:
        LinkNode* root;
};
