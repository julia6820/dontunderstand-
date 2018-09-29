#include <cstddef>
#include <utility>

template<typename T>
void shaker_sort(T array[], std::size_t size)
{
	for (std::size_t left_idx = 0, right_idx = size - 1;
		left_idx < right_idx;)
	{
		for (std::size_t idx = left_idx; idx < right_idx; idx++)
		{
			if (array[idx + 1] < array[idx])
			{
				std::swap(array[idx], array[idx + 1]);
			}
		}
		right_idx--;

		for (std::size_t idx = right_idx; idx > left_idx; idx--)
		{
			if (array[idx - 1] > array[idx])
			{
				std::swap(array[idx - 1], array[idx]);
			}
		}
		left_idx++;
	}
}