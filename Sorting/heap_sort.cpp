/*
Heapsort is a two step algorithm.
The first step is to build a heap out of the data.
The second step begins with removing the largest element from the heap.
We insert the removed element into the sorted array. For the first element, 
this would be position 0 of the array. Next we reconstruct the heap and remove 
the next largest item, and insert it into the array. After we have removed all 
the objects from the heap, we have a sorted array. We can vary the direction of
the sorted elements by choosing a min-heap or max-heap in step one.
Heapsort can be performed in place. The array can be split into two parts,
the sorted array and the heap. The storage of heaps as arrays is diagrammed 
at Binary heap#Heap implementation.The heap's invariant is preserved after 
each extraction, so the only cost is that of extraction.
*/