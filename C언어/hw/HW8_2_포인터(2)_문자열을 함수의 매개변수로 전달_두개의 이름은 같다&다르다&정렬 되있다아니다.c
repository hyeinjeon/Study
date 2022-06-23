#include <stdio.h>
int stringCompare(const char *s1, const char *s2)
{
	int i, j;
	for(i = 0; *(s1 + i) != '\0'; i++);
	for(j = 0; *(s2 + j) != '\0'; j++);

	if(i != j)
	{
		if (*s1 < *s2)
			return 1;
		else
			return -1;
	}
	else
	{
		for(i = 0; *(s1 + i) != '\0'; i++)
		{
			if(*(s1 + i) != *(s2 + i))
			{
				if(*(s1 + i) < *(s2 + i))
					return 1;
			}
			else
				return 0;
			}
	}
}
void stringCat(char *s1, const char *s2)
{
	for(; *s1 != '\0'; s1++);
	for(; *s2 != '\0'; s2++)
		*s1++ = *s2;
	*s1 = '\0';
}
void stringChange(char *s, char ch, char newCh)
{
	int i;
	for(i = 0; *(s + i) != '\0'; i++)
		if(*(s + i) == ch)
			*(s + i) = newCh;
}
int main(void)
{
	char name1[20];
	char name2[20];

	printf("Enter the first name: ");
	scanf("%s", name1);
	printf("Enter the second name: ");
	scanf("%s", name2);

	if(stringCompare(name1, name2) == 0)
		printf("두개의 이름은 같다\n");
	else if (stringCompare(name1, name2) == 1)
		printf("두개의 이름은 다르며 정렬되어있다\n");
	else
		printf("두개의 이름은 다르며 정렬되어있지않다\n");

	stringCat(name1, name2);
	printf("The concatenated name is %s\n", name1);

	stringChange(name1, 'u', 'x');
	printf("The changed name is %s\n", name1);
}