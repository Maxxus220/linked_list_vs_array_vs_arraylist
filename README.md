# linked_list_vs_array_vs_arraylist
An experiment in C++ to see the performance effects of data structure choice.

## Explanation
In order to test the effectiveness of LinkedLists, ArrayLists, and Arrays, this program 
implements an ordered LinkedList, ArrayList, and Array. Running the program causes N random 
integers to be added to each data structure (in order insertion) then removed randomly by index.
The time (in ms) between the first insertion and last deletion is taken to evaluate the 
effectiveness of each structure. Theoretically, since the LinkedList should only need to 
change a constant # of pointers per insertion (2 to be exact),
it should become much more effective at larger scale. In comparison, we would expect the
Array/ArrayList to perform very poorly as each insert requires copying all elements
later in the list over. However, in reality, we see that the cost of LinkedList pointer 
traversal far outweighs the benefits of only needing to change a few pointers. This in 
largely due to the strong bias computers show to patterned and contiguous data. Due to 
the layout of cache lines and the ability of the computer to understand access patterns
the Array/ArrayList is much faster despite the extra work of copying data over.

## Usage
This project is built using CMake. To build the project you must have CMake and installed.
You can build the project with these commands (assuming Unix Makefile generation).<br/>
```
mkdir build
cd build
cmake ..
make
```
This will create an executable called comparison that takes only one argument, N, the 
number of elements to be added and removed. Additionally, the ArrayList implementation
assumes an initial capacity of 1, and doubles in size whenever the capacity is exceeded.
Inside of ordered_array_list.h there is `#define STARTING_CAPACITY 1`. To change the 
initial capacity just change 1 to your desired value.
