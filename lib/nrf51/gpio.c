#include <libopencm3/nrf51/gpio.h>

void gpio_configure(unsigned gpio_number, enum PIN_CNF_ENUM direction, enum PIN_CNF_ENUM input_connection_config,
		enum PIN_CNF_ENUM pull_configuration, enum PIN_CNF_ENUM drive_configuration,
		enum PIN_CNF_ENUM sense_configuration)
{
	GPIO_PIN_CNF[gpio_number] = (direction << GPIO_PIN_CNF_DIR_OFFSET)
		| (input_connection_config << GPIO_PIN_CNF_INPUT_OFFSET)
		| (pull_configuration << GPIO_PIN_CNF_PULL_OFFSET)
		| (drive_configuration << GPIO_PIN_CNF_DRIVE_OFFSET)
		| (sense_configuration << GPIO_PIN_CNF_SENSE_OFFSET);
}

void gpio_set(unsigned gpio_number)
{
	GPIO_OUTSET = 1 << gpio_number;
}

void gpio_clear(unsigned gpio_number)
{
	GPIO_OUTCLR = 1 << gpio_number;
}

unsigned gpio_read(unsigned gpio_number)
{
	return (GPIO_IN & (1 << gpio_number)) ? 1 : 0;
}

uint32_t gpio_read_all_gpios(void)
{
	return GPIO_IN;
}

void gpio_write(unsigned gpio_number, unsigned value)
{
	* (value ? & GPIO_OUTSET : & GPIO_OUTCLR) = 1 << gpio_number;
}

void gpio_write_all_gpios(uint32_t value)
{
	GPIO_OUT = value;
}
