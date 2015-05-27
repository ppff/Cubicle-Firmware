# Binaries will be generated with this name (.elf, .bin, .hex, etc)
PROJ_NAME=cubicle-stm32

SRCS=Src/main.c
SRCS+=Src/LEDs/CUB_LEDs.c
SRCS+=Src/event/CUB_event.c
SRCS+=Src/text/CUB_text.c
SRCS+=Src/CUB.c
SRCS+=Src/application.c

# Normally you shouldn't need to change anything below this line!
#######################################################################################

##########
# STLINK
##########
STLINK=/home/cubicle/stlink

#############
#cross tools
#############
CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy

#########
# CFLAGS
#########
#CFLAGS  = -g -O2 -Wall
CFLAGS  = -g -Wall -std=gnu99
CFLAGS += -T$(LDSCRIPT)
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -I.
CFLAGS += -I/usr/arm-none-eabi/lib

CFLAGS += -lrdimon #--specs=rdimon.specs 

#########
# ARM DEF
#########
CFLAGS += -IDrivers/CMSIS/Include/

##################
# STM32F4xx Drivers
##################

CFLAGS += -IDrivers/CMSIS/Device/ST/STM32F4xx/Include
SRCS += Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c

CFLAGS += -IDrivers/STM32F4xx_HAL_Driver/Inc
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sd.c
SRCS += Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_sdmmc.c


########################
# specific to STM32F429
########################

DEFS = -DSTM32F429xx

SRCS += Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc/startup_stm32f429xx.s

LDSCRIPT = SW4STM32/cubicle\ Configuration/STM32F429ZITx_FLASH.ld

#########
# BSP
#########

CFLAGS += -IInc
SRCS += Src/main.c
SRCS += Src/stm32f4xx_hal_msp.c
SRCS += Src/stm32f4xx_it.c
SRCS += Src/gpio.c
SRCS += Src/spi.c
SRCS += Src/freertos.c
SRCS += Src/bsp_driver_sd.c
SRCS += Src/fatfs.c
SRCS += Src/sdio.c

##########
# FreeRTOS
##########

CFLAGS += -IMiddlewares/Third_Party/FreeRTOS/Source/include
CFLAGS += -IMiddlewares/Third_Party/FreeRTOS/Source/portable
CFLAGS += -IMiddlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS
CFLAGS += -IMiddlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F
SRCS +=  $(wildcard Middlewares/Third_Party/FreeRTOS/Source/*.c)
SRCS +=  $(wildcard Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/*.c)
SRCS +=  $(wildcard Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/*.c)
SRCS += Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c

#########
# FatFS
#########
CFLAGS += -IMiddlewares/Third_Party/FatFs/src
CFLAGS += -IMiddlewares/Third_Party/FatFs/src/drivers
SRCS += Middlewares/Third_Party/FatFs/src/drivers/sd_diskio.c
SRCS += $(wildcard Middlewares/Third_Party/FatFs/src/*.c)
SRCS += Middlewares/Third_Party/FatFs/src/option/syscall.c
SRCS += Middlewares/Third_Party/FatFs/src/option/unicode.c

##########
# Rules
##########
OBJS = $(SRCS:.c=.o)

.PHONY: proj

all: proj

proj: $(PROJ_NAME).elf

$(PROJ_NAME).elf: $(SRCS)
	$(CC) $(CFLAGS) $(DEFS) $(LDFLAGS) $^ -o $@
	$(OBJCOPY) -O ihex $(PROJ_NAME).elf $(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin

clean:
	rm -f *.o $(PROJ_NAME).elf $(PROJ_NAME).hex $(PROJ_NAME).bin

# Flash the STM32F4
burn: proj
	$(STLINK)/st-flash write $(PROJ_NAME).bin 0x8000000
