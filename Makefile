all:
	docker-compose run -u `id -u` gdbserver make $@

clean:
	docker-compose run -u `id -u` gdbserver make $@

burn:
	docker-compose run -u `id -u` gdbserver make $@

tools:
	docker-compose build

gdb:
	docker-compose up -d
	docker-compose run gdbserver arm-none-eabi-gdb --eval-command="target extended-remote gdbserver:4242" cubicle-stm32.elf
	docker-compose stop
