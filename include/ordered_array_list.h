#define STARTING_CAPACITY 1
class OrderedArrayList {
    public:
        int size;
        OrderedArrayList();
        ~OrderedArrayList();

        void add(int val);
        bool remove(int index);
    
    private:
        int capacity;
        int* array;
};
