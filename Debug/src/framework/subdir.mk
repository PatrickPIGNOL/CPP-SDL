################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/framework/GraphicComponent.cpp \
../src/framework/IGraphicComponent.cpp \
../src/framework/Panel.cpp 

OBJS += \
./src/framework/GraphicComponent.o \
./src/framework/IGraphicComponent.o \
./src/framework/Panel.o 

CPP_DEPS += \
./src/framework/GraphicComponent.d \
./src/framework/IGraphicComponent.d \
./src/framework/Panel.d 


# Each subdirectory must supply rules for building sources it contributes
src/framework/%.o: ../src/framework/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


