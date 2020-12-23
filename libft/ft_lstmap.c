/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:00:10 by oelkhams          #+#    #+#             */
/*   Updated: 2019/04/20 21:02:26 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*maillon;

	if (lst != NULL)
	{
		maillon = malloc(sizeof(void));
		maillon = f(lst);
		maillon->next = ft_lstmap(lst->next, f);
		return (maillon);
	}
	return (NULL);
}
