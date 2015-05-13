################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../program/src/dataframe.cpp \
../program/src/main.cpp \
../program/src/mybenchmark.cpp \
../program/src/numbergenerator.cpp \
../program/src/observer.cpp \
../program/src/stackonarray.cpp 

OBJS += \
./program/src/dataframe.o \
./program/src/main.o \
./program/src/mybenchmark.o \
./program/src/numbergenerator.o \
./program/src/observer.o \
./program/src/stackonarray.o 

CPP_DEPS += \
./program/src/dataframe.d \
./program/src/main.d \
./program/src/mybenchmark.d \
./program/src/numbergenerator.d \
./program/src/observer.d \
./program/src/stackonarray.d 


# Each subdirectory must supply rules for building sources it contributes
program/src/%.o: ../program/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/serek8/workspace/Labki/program/inc" -I"/home/serek8/workspace/Labki/program/src" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


