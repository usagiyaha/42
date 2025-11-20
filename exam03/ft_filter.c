
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

// function to compare n bytes of two strings
int ft_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;
    while (i < n) 
    {
        if (s1[i] == '\0' || s2[i] == '\0') 
            return s1[i] - s2[i];
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return 0;
}

// function to find the target string and replace it with *
void ft_filter(const char *str, const char *target)
{
    size_t i = 0;
    size_t tlen = strlen(target);

    if (tlen == 0) 
    {                 
        write(1, str, strlen(str));
        write(1, "\n", 1);
        return;
    }

    while (str[i]) {
        if (ft_strncmp(&str[i], target, tlen) == 0) 
        {
            write(1, "*", 1);    
            i += tlen;              
        } 
        else 
        {
            write(1, &str[i], 1); 
            i++;
        }
    }
    write(1, "\n", 1);
}

// int main(void)
// {
//     const char *str = "hello, world, hello!";
//     const char *ta  = "el";
//     ft_filter(str, ta);             
//     return 0;
// }

int main(int argc, char **argv)
{
	char temp[BUFFER_SIZE];
	char *buffer;
	char *res = NULL;
	int total_read = 0;
	ssize_t bytes;

	if (argc != 2)
		return 1;
	while (bytes =  read(0, temp, BUFFER_SIZE) > 0)
	{
		buffer = realloc(res, (total_read + bytes + 1));
		if (!buffer)
		{
			perror("realloc:");
			free(res);
			return 1;
		}
		res = buffer;
		memmove(res + total_read, temp, bytes);
		total_read += bytes;
		res[total_read] = '\0';
	}
	if (bytes < 0)
	{
		free(res);
		perror("read:");
		return 1;
	}
	if (!res)
	{
		free(res);
		return 1;
	}
	ft_filter(res, argv[1]);
	free(res);
	return 0;
}
