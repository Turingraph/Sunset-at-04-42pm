The LLM recommended me some common good software engineering practice related to how to use array.

## Consult with ChatGPT No.1: Dynamic Array vs Linked List for loading input.

LLM said that I should use dynamic array for fdf input file instead of linked list for saving more space.

## Consult with ChatGPT No.2: Array of Struct vs Array of Pointer

Also LLM warn me to use array of struct over array of pointer of struct for performance reason.

According to StackOverflow ( https://stackoverflow.com/questions/42328735/array-of-structs-vs-array-of-pointers-to-structs ).

Pros of Array of Pointer
1.	You can use the last `NULL` to specify the length of array.
2.	ith `NULL` means the ith item is missing
3.	chaning the order of elements by moving pointers.
4.	You can define multiple elements as the pointer of the same element.

Cons of Array of Pointer
1.	allocating and freeing this indirect array is more cumbersome. 
2.	waste more memory than Array of struct.
3.	access i-th item slower than Array of struct.

It is note that triangles mesh in typical computer graphic does not utilize the pros of array of Pointer at all. So I have to refactor it as Array of struct instead.

## Consult with ChatGPT No.3: 1D Array is Faster.

ChatGPT warn me to use 1D array over 2D array when deal with large input. Several Stackoverflow from this post ( https://stackoverflow.com/questions/17259877/1d-or-2d-array-whats-faster ) also recommend everyone to use 1D over 2D array because 1D array is faster (because calculating `arr[col * i + j]` is faster than calculate `arr[i][j]` when `arr` is dynamic array).

So I change this

```
typedef struct t_table_fdf t_table_fdf;

struct t_table_fdf
{
	size_t			row;
	size_t			col;
	int				**arr;
	unsigned char	**r;
	unsigned char	**g;
	unsigned char	**b;
	unsigned char	**a;
};
```

to this.

```
typedef struct t_table_fdf
{
	size_t			row;
	size_t			col;
	int				*arr;
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
}	t_table_fdf;
```
