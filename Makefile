all: up
			@echo "\033[32mDocker Compose is up and running\033[0m"

clean: down
			@docker images -q | xargs docker rmi -f
			@echo "\033[33mDocker Compose is down and cleaned\033[0m"

fclean: clean
			@docker system prune -a -f
			@docker volume prune -f
			@docker network prune -f
			@rm -rf ./srcs/data/db/*
			@rm -rf ./srcs/data/wp/*
			@echo "\033[31mDocker cache cleaned\033[0m"

up:
			@docker-compose -f ./srcs/docker-compose.yml up -d

down:
			@docker-compose -f ./srcs/docker-compose.yml down

re: clean
		@make up
