/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_flip2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:37:16 by hseong            #+#    #+#             */
/*   Updated: 2022/02/05 17:40:58 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	flip_word(char *buf, ssize_t front, ssize_t back);

int	main(void)
{
	char	buf[100002] = {0, };
	ssize_t	idx = 0;
	ssize_t	len;
	ssize_t	word_front = 0;
	ssize_t	word_back;

	len = read(0, buf, 100001);
	if (buf[len - 1] == '\n')
		--len;
	while (idx < len)
	{
		if (buf[idx] == ' ')
		{
			word_back = idx - 1;
			flip_word(buf, word_front, word_back);
			word_front = idx + 1;
		}
		else if (buf[idx] == '<')
		{
			word_back = idx - 1;
			flip_word(buf, word_front, word_back);
			while (/*idx < len &&*/ buf[idx] != '>')
				++idx;
			word_front = idx + 1;
		}
		++idx;
	}
	if (word_front < len - 1)
		flip_word(buf, word_front, len - 1);	
	write(1, buf, len + 1);
	return (0);
}

void	flip_word(char *buf, ssize_t front, ssize_t back)
{
	char	temp;

	if (back <= front)
		return ;
	while (front < back)
	{
		temp = buf[front];
		buf[front] = buf[back];
		buf[back] = temp;
		++front;
		--back;
	}
}
