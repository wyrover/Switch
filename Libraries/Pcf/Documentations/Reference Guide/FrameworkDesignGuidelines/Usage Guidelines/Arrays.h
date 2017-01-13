/// @page ArraysPage Arrays
///
/// <b>✓ DO</b> prefer using collections over arrays in public APIs. The Guidelines for Collections section provides details about how to choose between collections and arrays.
///
/// <b>X DO NOT</b> use read-only array fields. The field itself is read-only and can't be changed, but elements in the array can be changed.
///
/// <b>✓ CONSIDER</b> using jagged arrays instead of multidimensional arrays.
///
/// A jagged array is an array with elements that are also arrays. The arrays that make up the elements can be of different sizes, leading to less wasted space for some sets of data (e.g., sparse matrix) compared to multidimensional arrays. Furthermore, the Pcf optimizes index operations on jagged arrays, so they might exhibit better runtime performance in some scenarios.
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref UsageGuidelinesPage
