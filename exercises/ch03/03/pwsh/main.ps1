# CmdLet to throw an error when good practices are violated
Set-StrictMode -Version Latest

function IsSorted {
	[OutputType([Boolean])]
	param(
		[Parameter(Mandatory)]
		[Int32[]]$intArray
	)
	$size = $intArray.count
	for ($i = 1; $i -lt $size; $i++){
		if ($intArray[$i-1] -gt $intArray[$i]) {
			return $false
		}
	}
	return $true
}

# Different function invocations
$sortedArray = @(1, 2, 3, 4)
$unsortedArray = @(1, 4, 2, 3)

IsSorted -intArray $sortedArray | Write-Host
Write-Host(IsSorted($sortedArray))

IsSorted -intArray $unsortedArray | Write-Host
Write-Host(IsSorted($unsortedArray))

