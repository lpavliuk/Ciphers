CC=gcc
CFLAGC=-Wall -Werror -Wextra
DIR=files/
NAME1=atbash
NAME2=caesar
NAME3=vigenere
NAME4=deciphercaesar
NAME5=deciphervigenere

all: $(NAME1)

$(NAME1): $(NAME2)
	$(CC) $(CFLAGC) $(DIR)$(NAME1).c -o $(NAME1)

$(NAME2): $(NAME3)
	$(CC) $(CFLAGC) $(DIR)$(NAME2).c -o $(NAME2)

$(NAME3): $(NAME4)
	$(CC) $(CFLAGC) $(DIR)$(NAME3).c -o $(NAME3)

$(NAME4): $(NAME5)
	$(CC) $(CFLAGC) $(DIR)$(NAME4).c -o $(NAME4)

$(NAME5):  
	$(CC) $(CFLAGC) $(DIR)$(NAME5).c -o $(NAME5)

clean:
	rm -f files/*.swo
	rm -f files/*.swp
	rm -f files/*~

fclean: clean
	rm -f $(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5)

re: fclean all
