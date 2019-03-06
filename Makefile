NAME=ft_ls
FLAGS=-Wall -Wextra -Werror

all:$(NAME)
$(NAME):
	#make -C libft/
	gcc $(FLAGS) -c *.c
	gcc $(FLAGS) *.o libft/libft.a -o $(NAME)
clean:
	#make -C libft/ clean
	rm -rf *.o
fclean:clean
	#make -C libft/ fclean
	rm -rf $(NAME)
re:fclean all