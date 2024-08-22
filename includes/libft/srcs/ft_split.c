/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:46:41 by gwagner           #+#    #+#             */
/*   Updated: 2024/06/12 12:38:44 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			count++;
			while (*(s + i) && *(s + i) != c)
				i++;
		}
		else if (*(s + i) == c)
			i++;
	}
	return (count);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

static void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
}

static char	**split(char const *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, get_word_len(&*(s + j), c));
		if (!*(array + i))
		{
			free_array(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, words);
	return (array);
}

// #include <stdio.h>
// int main()
// {
//     // Test case 1
//     const char *str1 = "Hello,world,this,is,a,test";
//     char **result1 = ft_split(str1, ',');
//     // Print the result of test case 1
//     printf("Test case 1:\n");
//     for (int i = 0; result1[i] != NULL; i++)
//     {
//         printf("%s\n", result1[i]);
//         free(result1[i]); // Free each substring
//     }
//     free(result1); // Free the array of pointers
//     // Test case 2
//     const char *str2 = "one::two:::three::::four";
//     char **result2 = ft_split(str2, ':');
//     // Print the result of test case 2
//     printf("Test case 2:\n");
//     for (int i = 0; result2[i] != NULL; i++)
//     {
//         printf("%s\n", result2[i]);
//         free(result2[i]); // Free each substring
//     }
//     free(result2); // Free the array of pointers
//     // Test case 3
//     const char *str3 = "split,with,,multiple,delimiters,";
//     char **result3 = ft_split(str3, ',');
//     // Print the result of test case 3
//     printf("Test case 3:\n");
//     for (int i = 0; result3[i] != NULL; i++)
//     {
//         printf("%s\n", result3[i]);
//         free(result3[i]); // Free each substring
//     }
//     free(result3); // Free the array of pointers
//     return 0;
// }
