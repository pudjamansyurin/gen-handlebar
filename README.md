# HANDLEBAR / DUMMY GENERATOR

## Progress:
- [x] Add IWDG to Handlebar 
- [x] Use external interrupt (rising/falling) rather then pooling to check the GPIO state every time (wasting CPU time) 
- [x] [Do not use same line for EXTI](https://electronics.stackexchange.com/questions/267286/external-interrupts-in-stm32f10x/269899#269899)
- [x] [Use debounce technique](http://www.emcu.it/STM32/STM32Discovery-Debounce/STM32Discovery-InputWithDebounce_Output_UART_SPI_SysTick.html)
- [x] HAL_NVIC_EnableIRQ problem 
  - [ ] ~~If the interrupt handler call RTOS API, it should be run after RTOS Scheduler start, otherwise system error.~~ 
  - [x] Or by checking is the RTOS Scheduler already start inside interrupt handler 
- [x] To measure the time between external interrupt (Select & Set button) 
  - [ ] ~~use INPUT CAPTURE TIMER~~  
  - [x] [use osDelay() between EXTERNAL INTERRUPT](https://stackoverflow.com/questions/35011016/stm32f429-external-interrupt-edge)
- [x] [ADC in Circular DMA mode to reduce CPU processing.](http://www.emcu.eu/how-to-use-3-channels-of-the-adc-in-dma-mode-using-cube-mx-and-atollic/)
