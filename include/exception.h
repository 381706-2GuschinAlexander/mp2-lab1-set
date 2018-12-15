#pragma once

void ExThrow(int a)
{
	switch (a)
	{
	case 0:
		throw("Negative lenght/size");
	case 1:
		throw("Index is out of range");
	default:
		throw("Undocumeted throw");
	}
}