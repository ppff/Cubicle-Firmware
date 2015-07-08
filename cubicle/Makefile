# Binaries will be generated with this name (.elf, .bin, .hex, etc)
PROJ_NAME=cubicle-stm32

##########
# DEFINES
##########
DEFINES = -DJSMN_PARENT_LINKS
######## - DEFINES

##########
# STLINK
##########
STLINK=/home/cubicle/stlink
######## - STLINK

#############
# cross tools
#############
CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
######## - cross tools

################
# COMMON CFLAGS
################

CFLAGS  = -g -Wall -std=gnu99
CFLAGS += -T$(LDSCRIPT)
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -I.
CFLAGS += -I/usr/arm-none-eabi/lib

CFLAGS += -lrdimon #--specs=rdimon.specs 
CFLAGS += $(DEFINES)

######## - COMMON CFLAGS

#########
# ARM DEF
#########
CFLAGS += -IDrivers/CMSIS/Include/
######## - ARM DEF

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

######## - STM32F4xx Drivers


########################
# specific to STM32F429
########################

DEFS = -DSTM32F429xx

SRCS += Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc/startup_stm32f429xx.s

LDSCRIPT = SW4STM32/cubicle\ Configuration/STM32F429ZITx_FLASH.ld

######## - specific to STM32F429

############
# FreeRTOS
############

CFLAGS += -IFreeRTOS/Source/include
CFLAGS += -IFreeRTOS/Source/portable
CFLAGS += -IFreeRTOS/Source/CMSIS_RTOS
CFLAGS += -IFreeRTOS/Source/portable/GCC/ARM_CM4F
SRCS +=  $(wildcard FreeRTOS/Source/*.c)
SRCS +=  $(wildcard FreeRTOS/Source/CMSIS_RTOS/*.c)
SRCS +=  $(wildcard FreeRTOS/Source/portable/GCC/ARM_CM4F/*.c)
SRCS += FreeRTOS/Source/portable/MemMang/heap_4.c

######## - FreeRTOS

##########
# COMMON
##########

CFLAGS += -ICOMMON
SRCS += $(wildcard COMMON/*.c)

######## - COMMON

#########
## APP ##
#########

CFLAGS += -IAPP
SRCS += $(wildcard APP/*.c)

#########
# BDD
#########

CFLAGS += -IAPP/BDD
SRCS += $(wildcard APP/BDD/*.c)

#### FatFs ####
CFLAGS += -IAPP/BDD/FatFs/src
CFLAGS += -IAPP/BDD/FatFs/src/drivers
SRCS += APP/BDD/FatFs/src/drivers/sd_diskio.c
SRCS += $(wildcard APP/BDD/FatFs/src/*.c)
SRCS += APP/BDD/FatFs/src/option/syscall.c
SRCS += APP/BDD/FatFs/src/option/unicode.c

######## - BDD

##########
# CUB
##########

CFLAGS += -IAPP/CUB
SRCS += $(wildcard APP/CUB/*.c)

######## - CUB

##########
# TFT
##########

CFLAGS += -IAPP/TFT
SRCS += $(wildcard APP/TFT/*.c)

######## - TFT

##########
# USB
##########

CFLAGS += -IAPP/USB
SRCS += $(wildcard APP/USB/*.c)

######## - USB

######## - APP

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
