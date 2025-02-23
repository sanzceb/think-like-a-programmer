# Chapter 3: Solving Problems with Arrays

This chapter is dedicated to solving problems with arrays.

## Review of C++ used

Programming skills required

- Use of fixed size arrays:

```cpp
int tenIntegerArray[10];
```

- Sorting elements with `qsort`

## Review of Powershell used

An array is a data structure that's designed to store a collection of items.
The items can be the same type or different types. To enforce a certain type
we can cast:

```powershell
[Int32[]]$ia = @(1500, 2230, 3350, 4000)
```


### Array Fundamentals with Powershell

#### Store

```powershell
$ia[0] = 1
```

#### Copy

```powershell
$ia2 = $ia[0..$ia.count]
```

#### Retrieval and Search

```powershell
[Int32[]]$numbers = @(4, 5, 9, 12, -4, 0, -57, 30987, -287, 1) # Length 10
$numbersCount = $numbers.count
$targetValue = 12
$targetPos = 0
while (($numbers[$targetPos] -ne $targetValue) -and ($targetPos -lt $numbersCount)) {
	$targetPos += 1
}
```

#### Criterion-Based Search

```powershell
[Int32[]]$numbers = @(4, 5, 9, 12, -4, 0, -57, 30987, -287, 1) # Length 10
$maxValue = $numbers[0]
$numbers.foreach({
	if ($_ -gt $maxValue) {
		$maxValue = $_
	}
})
```

#### Sort

```powershell
$ia | Sort-Object
```

