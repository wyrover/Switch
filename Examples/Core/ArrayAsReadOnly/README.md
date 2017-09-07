# ArrayAsReadOnly
This code example wraps an array in a read-only ReadOnlyCollection<T>.

## Output
```
The string array initially contains the following values:
   0 : The
   1 : quick
   2 : brown
   3 : fox

The read-only IList contains the following values:
   0 : The
   1 : quick
   2 : brown
   3 : fox

System::NotSupportedException - Collection is read-only.

After changing the third element, the string array contains the following values:
   0 : The
   1 : quick
   2 : RED
   3 : fox

After changing the third element, the read-only IList contains the following values:
   0 : The
   1 : quick
   2 : RED
   3 : fox
```
