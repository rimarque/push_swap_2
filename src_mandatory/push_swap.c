/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:49:19 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/20 14:54:16 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_issorted(t_list *stack)
{
	t_node	*element_a;
	t_node	*element_b;

	element_a = stack->first;
	element_b = element_a->next;
	while (element_b != stack->first)
	{
		if (element_a->val > element_b->val)
			return ;
		element_a = element_a->next;
		element_b = element_a->next;
	}
	free_stack(stack);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;
	int		i;

	if (argc <= 2)
		return (0);
	create_stack(&stack_a);
	create_stack(&stack_b);
	i = 1;
	while (i < argc)
	{
		ft_isnbr(argv[i], &stack_a);
		ft_isint(ft_atoi(argv[i]), &stack_a);
		insert_last(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	ft_isdouble(&stack_a);
	ft_issorted(&stack_a);
	algorithm(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}