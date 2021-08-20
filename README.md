# Int48 and Int24
Consider you have an structure which contains the following values:
1. one byte value (char)
2. two bytes value (short)
3. three bytes value (???)
4. four bytes value (int32)
5. six bytes value (???)


You Expect that total size must be (1 + 2 + 3 + 4 + 6 = 16), i.e. 16 = sizeof(YOUR_STRUCTURE), but because of absence of 3-bytes and 6-bytes type, we can't do that or it is very hard to do that.
The easiest way to handle this problem is using the class Int24.h(.cpp) for three-bytes value and Int48.h(.cpp) for six-bytes value.
Thus you could easily use this classes like primitive types.

```cpp
struct MyStruct
{
  char one_byte;
  short two_bytes;
  Int24 three_bytes;
  int32 four_bytes;
  Int48 six_bytes;
}
.
.
.
int size = sizeof(MyStruct);
cout<<"size is "<<size;
.
.
.
output: size is: 16
```

By copying the these two class patterns, you can create your costume classes which doesn't exist in the primary types list.
{Simle Change for test pull request}
