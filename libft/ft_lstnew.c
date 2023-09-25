/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:17:42 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/12 20:51:23 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstnew(void *content)
{
	t_list  *new;

	new = (t_list*)malloc(sizeof(*new));
	if (!new)
    	return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// void print_list(t_list *list, void (*print_func)(void *)) {
//     t_list *current = list;

//     while (current != NULL) {
//         print_func(current->content);
//         current = current->next;
//     }

//     printf("\n");
// }

// // Fonction de rappel pour afficher un entier
// void print_int(void *data) {
//     int *value = (int *)data;
//     printf("%d ", *value);
// }

// // Fonction de rappel pour afficher un flottant
// void print_float(void *data) {
//     float *value = (float *)data;
//     printf("%f ", *value);
// }

// // Fonction de rappel pour afficher une chaîne de caractères
// void print_string(void *data) {
//     char *value = (char *)data;
//     printf("%s ", value);
// }


// t_list* create_node(void *content) {
//     t_list *new_node = (t_list*)malloc(sizeof(t_list));
//     if (new_node == NULL) {
//         printf("Erreur lors de l'allocation de mémoire.\n");
//         exit(1);
//     }

//     new_node->content = content;
//     new_node->next = NULL;

//     return new_node;
// }

// t_list* create_linked_list(void * content_array[], int size) {
//     if (size <= 0)
//         return NULL;

//     t_list *head = create_node(content_array[0]);
//     t_list *current = head;

//     for (int i = 1; i < size; i++) {
//         t_list *new_node = create_node(content_array[i]);
//         current->next = new_node;
//         current = current->next;
//     }

//     return head;
// }

// void    ft_lstadd_front(t_list **lst, t_list *new)
// {
//     if (!lst)
//         return ;
//     new->next = *lst;
//     *lst = new;
// }

// int    ft_lstsize(t_list *lst)
// {
//     int i;

//     i = 0;
//     while (lst)
//     {
//         i++;
//         lst = lst->next;
//     }
//     return (i);
// }

// t_list  *ft_lstlast(t_list *lst)
// {
//     while (lst->next != NULL)
//         lst = lst->next;
//     return (lst);
// }

// void    ft_lstadd_back(t_list **lst, t_list *new)
// {
//     t_list  *last;
    
//     if (!lst)
//         *lst = new;
//     else
//     {
//         last = ft_lstlast(*lst);
//         last->next = new;
//     }
// }

// void del(void *content) {
//     if (content == NULL)
//         return;
// }

// void    ft_lstdelone(t_list *lst, void (*del)(void *))
// {
//     del(lst->content);
//     free(lst);
// }

// void    ft_lstclear(t_list **lst, void (*del)(void *))
// {
//     t_list  *pos;
    
//     pos = *lst;
//     if (!lst)
//         return ;
//     while (pos)
//     {
//         ft_lstdelone(*lst, del);
//         pos = (*lst)->next;
//         *lst = pos;
//     }
//     *lst = NULL;
// }

// int main()
// {
//     t_list  *list;
//     int num1 = 1;
//     int num2 = 2;
//     int num3 = 3;
//     int num4 = 4;
//     void *array[] = {&num1, &num2, &num3};
//     int size = sizeof(array) / sizeof(array[0]);

//     list = create_linked_list(array, size);
//     print_list(list, print_int);
//     t_list **lst = &list;
//     // int size2 = ft_lstsize(list);
//     t_list *new = ft_lstnew(&num4);
//     ft_lstadd_back(lst, new);
    
//     print_list(new, print_int);
//     print_list(list, print_int);
//     ft_lstclear(lst, del);
//     print_list(list, print_int);
//     // printf("size = %d", size2);
//     // list = ft_lstlast(list);
//     // print_list(list, print_int);
// }