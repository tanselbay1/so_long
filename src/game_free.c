/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:53:43 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/08/17 10:53:53 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_list(t_tile *head)
{
	t_tile	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}