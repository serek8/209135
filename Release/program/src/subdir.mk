################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../program/src/main.cpp \
../program/src/mybenchmark.cpp 

OBJS += \
./program/src/main.o \
./program/src/mybenchmark.o 

CPP_DEPS += \
./program/src/main.d \
./program/src/mybenchmark.d 


# Each subdirectory must supply rules for building sources it contributes
program/src/%.o: ../program/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/serek8/workspace/Labki/program/inc" -I"/home/serek8/workspace/Labki/program/src" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


