/* Core kernel objects */
case K_OBJ_ALERT: return "alert";
case K_OBJ_MSGQ: return "msgq";
case K_OBJ_MUTEX: return "mutex";
case K_OBJ_PIPE: return "pipe";
case K_OBJ_SEM: return "sem";
case K_OBJ_STACK: return "stack";
case K_OBJ_THREAD: return "thread";
case K_OBJ_TIMER: return "timer";
case K_OBJ__THREAD_STACK_ELEMENT: return "_thread_stack_element";
/* Driver subsystems */
case K_OBJ_DRIVER_ADC: return "adc driver";
case K_OBJ_DRIVER_AIO_CMP: return "aio_cmp driver";
case K_OBJ_DRIVER_COUNTER: return "counter driver";
case K_OBJ_DRIVER_CRYPTO: return "crypto driver";
case K_OBJ_DRIVER_DMA: return "dma driver";
case K_OBJ_DRIVER_FLASH: return "flash driver";
case K_OBJ_DRIVER_GPIO: return "gpio driver";
case K_OBJ_DRIVER_I2C: return "i2c driver";
case K_OBJ_DRIVER_I2S: return "i2s driver";
case K_OBJ_DRIVER_IPM: return "ipm driver";
case K_OBJ_DRIVER_PINMUX: return "pinmux driver";
case K_OBJ_DRIVER_PWM: return "pwm driver";
case K_OBJ_DRIVER_ENTROPY: return "entropy driver";
case K_OBJ_DRIVER_RTC: return "rtc driver";
case K_OBJ_DRIVER_SENSOR: return "sensor driver";
case K_OBJ_DRIVER_SPI: return "spi driver";
case K_OBJ_DRIVER_UART: return "uart driver";
