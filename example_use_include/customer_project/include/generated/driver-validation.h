#ifndef __DRIVER_VALIDATION_GEN_H__
#define __DRIVER_VALIDATION_GEN_H__
#define _SYSCALL_DRIVER_GEN(ptr, op, driver_lower_case, driver_upper_case) \
	do { \
		_SYSCALL_OBJ(ptr, K_OBJ_DRIVER_##driver_upper_case); \
		_SYSCALL_DRIVER_OP(ptr, driver_lower_case##_driver_api, op); \
	} while (0)


#define _SYSCALL_DRIVER_ADC(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, adc, ADC)

#define _SYSCALL_DRIVER_AIO_CMP(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, aio_cmp, AIO_CMP)

#define _SYSCALL_DRIVER_COUNTER(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, counter, COUNTER)

#define _SYSCALL_DRIVER_CRYPTO(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, crypto, CRYPTO)

#define _SYSCALL_DRIVER_DMA(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, dma, DMA)

#define _SYSCALL_DRIVER_FLASH(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, flash, FLASH)

#define _SYSCALL_DRIVER_GPIO(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, gpio, GPIO)

#define _SYSCALL_DRIVER_I2C(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, i2c, I2C)

#define _SYSCALL_DRIVER_I2S(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, i2s, I2S)

#define _SYSCALL_DRIVER_IPM(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, ipm, IPM)

#define _SYSCALL_DRIVER_PINMUX(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, pinmux, PINMUX)

#define _SYSCALL_DRIVER_PWM(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, pwm, PWM)

#define _SYSCALL_DRIVER_ENTROPY(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, entropy, ENTROPY)

#define _SYSCALL_DRIVER_RTC(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, rtc, RTC)

#define _SYSCALL_DRIVER_SENSOR(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, sensor, SENSOR)

#define _SYSCALL_DRIVER_SPI(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, spi, SPI)

#define _SYSCALL_DRIVER_UART(ptr, op) _SYSCALL_DRIVER_GEN(ptr, op, uart, UART)
#endif /* __DRIVER_VALIDATION_GEN_H__ */
