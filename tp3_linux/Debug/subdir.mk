################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Controller.c \
../Employee.c \
../arr.c \
../main.c \
../matOp.c \
../parser.c \
../utn.c 

OBJS += \
./Controller.o \
./Employee.o \
./arr.o \
./main.o \
./matOp.o \
./parser.o \
./utn.o 

C_DEPS += \
./Controller.d \
./Employee.d \
./arr.d \
./main.d \
./matOp.d \
./parser.d \
./utn.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


