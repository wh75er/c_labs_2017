#include "my_strchr.h"

char *my_strchr(const char *s, int i)
{
	const char *pa;
	for (pa = s; *pa != '\0' && *pa != i; pa++);
	if (*pa == '\0')
		return NULL;
	return (char*)pa;
}

char* my_strpbrk(const char* s, const char* accept)
{
	for(const char* pa = s; *pa != '\0'; pa++){
		const char* pa_ac;
		for(pa_ac = accept; *pa_ac != '\0' && *pa_ac != *pa; pa_ac++);
		if(*pa_ac == *pa)
			return (char*)pa;
		else
			return NULL;
	}
}
