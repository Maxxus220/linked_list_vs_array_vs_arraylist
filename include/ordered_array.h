class OrderedArray {
    public:
        OrderedArray(int capacity);
        ~OrderedArray();

        void add(int val);
        bool remove(int index);

        int size;
    
    private:
        int* array;
};
