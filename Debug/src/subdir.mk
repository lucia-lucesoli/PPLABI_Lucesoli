################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/PrimerParcial.c \
../src/arcades.c \
../src/informes.c \
../src/inputs.c \
../src/salones.c 

OBJS += \
./src/PrimerParcial.o \
./src/arcades.o \
./src/informes.o \
./src/inputs.o \
./src/salones.o 

C_DEPS += \
./src/PrimerParcial.d \
./src/arcades.d \
./src/informes.d \
./src/inputs.d \
./src/salones.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


