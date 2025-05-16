##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC = gcc
NAME	=	my_hunter

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

CFLAGS	=	-W -Wall -Wextra -Werror -I./include

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) && \
	echo "$(GREEN_SQUARE) \033[1m\033[32mCOMPILATION REUSSIE\033[0m" \
	|| \
	echo "$(RED_SQUARE) \033[1m\033[31mECHEC DE LA COMPILATION\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@) && \
	echo "$(GREEN_SQUARE) mkdir $(dir $@)" || \
	echo "$(RED_SQUARE) mkdir $(dir $@)"
	@$(CC) $(CFLAGS) -c -o $@ $< && \
	echo "$(GREEN_SQUARE) $<" || \
	echo "$(RED_SQUARE) $<"

clean:
	@rm -rf $(OBJ_DIR) && \
	echo "$(YELLOW_SQUARE_CLEAN) rm -rf $(OBJ_DIR)" || \
	echo "$(RED_SQUARE) rm -rf $(OBJ_DIR)"
	@rm -f vgcore.* && \
	echo "$(YELLOW_SQUARE_CLEAN) rm -f vgcore.*" || \
	echo "$(RED_SQUARE) rm -f vgcore.*"
	@rm -f *.log && \
	echo "$(YELLOW_SQUARE_CLEAN) rm -f coding-style-reports.log" || \
	echo "$(RED_SQUARE) rm -f coding-style-reports.log"

fclean: clean
	@rm -f $(NAME) && \
	echo "$(YELLOW_SQUARE_CLEAN) rm -f $(NAME)" || \
	echo "$(RED_SQUARE) rm -f Executable $(NAME)"

re: fclean all

style: fclean
	@clear
	@coding-style "$$PWD" . > /dev/null 2>&1
	@if [ -f coding-style-reports.log ]; then \
		major_count=$$(grep -o "MAJOR" coding-style-reports.log | wc -l); \
		minor_count=$$(grep -o "MINOR" coding-style-reports.log | wc -l); \
		info_count=$$(grep -o "INFO" coding-style-reports.log | wc -l); \
		\
		get_color() { \
			if [ $$1 -eq 0 ]; then echo "\033[32m"; \
			elif [ $$1 -gt 0 ] && [ $$1 -le 3 ]; then echo "\033[33m"; \
			elif [ $$1 -le 7 ]; then echo "\033[38;5;208m"; \
			else echo "\033[31m"; fi; \
		}; \
		\
		major_color=$$(get_color $$major_count); \
		minor_color=$$(get_color $$minor_count); \
		info_color=$$(get_color $$info_count); \
		\
		echo "$${major_color}MAJOR: $$major_count\033[0m, " \
			 "$${minor_color}MINOR: $$minor_count\033[0m, " \
			 "$${info_color}INFO: $$info_count\033[0m"; \
		\
		echo; \
		previous_file=""; \
		while IFS= read -r line; do \
			current_file=$$(echo "$$line" | cut -d':' -f1); \
			if [ "$$current_file" != "$$previous_file" ] && \
			   [ -n "$$previous_file" ]; then echo; fi; \
			previous_file="$$current_file"; \
			if echo "$$line" | grep -q "MAJOR"; then \
				echo "\033[31m$$line\033[0m"; \
			elif echo "$$line" | grep -q "MINOR"; then \
				echo "\033[33m$$line\033[0m"; \
			elif echo "$$line" | grep -q "INFO"; then \
				echo "\033[32m$$line\033[0m"; \
			else \
				echo "$$line"; \
			fi; \
		done < coding-style-reports.log; \
	else \
		echo "coding-style-reports.log not found."; \
	fi

.PHONY: all clean fclean re
