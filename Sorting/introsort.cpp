/*
Introsort or introspective sort is a sorting algorithm designed by David Musser in 1997. 
It begins with quicksort and switches to heapsort when the recursion depth exceeds a level 
based on (the logarithm of) the number of elements being sorted. It is the best of both worlds, 
with a worst-case O(n log n) runtime and practical performance comparable to quicksort on 
typical data sets. Since both algorithms it uses are comparison sorts, it too is a comparison sort.
In quicksort, one of the critical operations is choosing the pivot: the element around which the 
list is partitioned. The simplest pivot selection algorithm is to take the first or the last 
element of the list as the pivot, causing poor behavior for the case of sorted or nearly sorted input. 
Niklaus Wirth's variant uses the middle element to prevent these occurrences, degenerating to O(nÂ²) 
for contrived sequences. The median-of-3 pivot selection algorithm takes the median of the first, 
middle, and last elements of the list; however, even though this performs well on many real-world 
inputs, it is still possible to contrive a median-of-3 killer list that will cause dramatic 
slowdown of a quicksort based on this pivot selection technique. Such inputs could potentially 
be exploited by an aggressor, for example by sending such a list to an Internet server for sorting 
as a denial of service attack. Musser reported that on a median-of-3 killer sequence of 100,000 elements,
introsort's running time was 1/200 that of median-of-3 quicksort. Musser also considered the effect
on caches of Sedgewick's delayed small sorting, where small ranges are sorted at the end in a 
single pass of insertion sort. He reported that it could double the number of cache misses, 
but that its performance with double-ended queues was significantly better and should be retained 
for template libraries, in part because the gain in other cases from doing the sorts immediately was not great

*/