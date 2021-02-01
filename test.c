# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
#define TO_STRING(x) (#x)

int main()
{
	printf("%s\n", TO_STRING(123));
}
