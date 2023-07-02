# linked_list_vs_array_vs_arraylist
An experiment in C++ to see the performance effects of data structure choice.

BUILT WITH CMAKE

In order to test the effectiveness of LinkedLists, ArrayLists, and Arrays, we will be
running an experiment where we will be doing sorted inserts of a random number N times 
and then remove each element in a random order. Theoretically, since the LinkedList 
should only need to change a constant # of pointers (a relatively small one at that),
it should become much more effective at larger scale. In comparison, we would expect the
Array/ArrayList to perform very poorly as each insert requires copying all elements
later in the list over. However, in reality, we see that the cost of LinkedList pointer 
traversal far outweighs the benefits of only needing to change a few pointers. This in 
largely due to the strong bias computers show to patterned and contiguous data. Due to 
the layout of cache lines and the ability of the computer to understand access patterns
the Array/ArrayList is much faster.
