#ifndef LIBOPENCM3_NRF51_GPIO_H
#define LIBOPENCM3_NRF51_GPIO_H

#include <libopencm3/cm3/common.h>

/* NRF51 gpio register addresses */
enum
{
	GPIO_BASE_ADDRESS	= 0x50000000,
	GPIO_OUT_REG_OFFSET	= 0x504,
	GPIO_OUTSET_REG_OFFSET	= 0x508,
	GPIO_OUTCLR_REG_OFFSET	= 0x50c,
	GPIO_IN_REG_OFFSET	= 0x510,
	GPIO_DIR_REG_OFFSET	= 0x514,
	GPIO_DIRSET_REG_OFFSET	= 0x518,
	GPIO_DIRCLR_REG_OFFSET	= 0x51c,
	/* PIN_CNF below is an array, there are 32 registers,
	 * one for each pin */
	GPIO_PIN_CNF_REG_OFFSET	= 0x700,
		/* PIN_CNF bitfield offsets (offset in bits in the PIN_CNF register) */
		GPIO_PIN_CNF_DIR_OFFSET		= 0,
		GPIO_PIN_CNF_INPUT_OFFSET	= 1,
		GPIO_PIN_CNF_PULL_OFFSET	= 2,
		GPIO_PIN_CNF_DRIVE_OFFSET	= 8,
		GPIO_PIN_CNF_SENSE_OFFSET	= 16,
};

#define GPIO_OUT	MMIO32(GPIO_BASE_ADDRESS + GPIO_OUT_REG_OFFSET)
#define GPIO_OUTSET	MMIO32(GPIO_BASE_ADDRESS + GPIO_OUTSET_REG_OFFSET)
#define GPIO_OUTCLR	MMIO32(GPIO_BASE_ADDRESS + GPIO_OUTCLR_REG_OFFSET)
#define GPIO_IN		MMIO32(GPIO_BASE_ADDRESS + GPIO_IN_REG_OFFSET)
#define GPIO_DIR	MMIO32(GPIO_BASE_ADDRESS + GPIO_DIR_REG_OFFSET)
#define GPIO_DIRSET	MMIO32(GPIO_BASE_ADDRESS + GPIO_DIRSET_REG_OFFSET)
#define GPIO_DIRCLR	MMIO32(GPIO_BASE_ADDRESS + GPIO_DIRCLR_REG_OFFSET)
#define GPIO_PIN_CNF	(&MMIO32(GPIO_BASE_ADDRESS + GPIO_PIN_CNF_REG_OFFSET))

enum PIN_CNF_ENUM
{
	PIN_CNF_DIR_INPUT		= 0,
	PIN_CNF_DIR_OUTPUT		= 1,

	PIN_CNF_INPUT_CONNECT		= 0,
	PIN_CNF_INPUT_DISCONNECT	= 1,

	PIN_CNF_PULL_DISABLED		= 0,
	PIN_CNF_PULL_PULLDOWN		= 1,
	PIN_CNF_PULL_PULLUP		= 3,

	PIN_CNF_DRIVE_S0S1		= 0,
	PIN_CNF_DRIVE_H0S1		= 1,
	PIN_CNF_DRIVE_S0H1		= 2,
	PIN_CNF_DRIVE_H0H1		= 3,
	PIN_CNF_DRIVE_D0S1		= 4,
	PIN_CNF_DRIVE_D0H1		= 5,
	PIN_CNF_DRIVE_S0D1		= 6,
	PIN_CNF_DRIVE_H0D1		= 7,

	PIN_CNF_SENSE_DISABLED		= 0,
	PIN_CNF_SENSE_HIGH		= 1,
	PIN_CNF_SENSE_LOW		= 3,
};

void gpio_configure(unsigned gpio_number, enum PIN_CNF_ENUM direction, enum PIN_CNF_ENUM input_connection_config,
		enum PIN_CNF_ENUM pull_configuration, enum PIN_CNF_ENUM drive_configuration,
		enum PIN_CNF_ENUM sense_configuration);
void gpio_set(unsigned gpio_number);
void gpio_clear(unsigned gpio_number);
unsigned gpio_read(unsigned gpio_number);
uint32_t gpio_read_all_gpios(void);
void gpio_write(unsigned gpio_number, unsigned value);
void gpio_write_all_gpios(uint32_t value);

#endif /* LIBOPENCM3_NRF51_GPIO_H */
