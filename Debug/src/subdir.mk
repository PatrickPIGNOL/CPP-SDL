################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Exception.cpp \
../src/NullPointerException.cpp \
../src/String.cpp \
../src/main.cpp 

OBJS += \
./src/Exception.o \
./src/NullPointerException.o \
./src/String.o \
./src/main.o 

CPP_DEPS += \
./src/Exception.d \
./src/NullPointerException.d \
./src/String.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


