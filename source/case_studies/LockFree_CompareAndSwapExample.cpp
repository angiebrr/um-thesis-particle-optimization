bool compareAndSwap(contendedResource, expectedValue, newValue)
{
	// Executes atomically
	if(contendedResource is not expectedValue)
		return false;

	// Its value was the expected value, so change it to newValue
	contendedResource = newValue;
	return true;
}