#include <stdlib.h>
#include <zephyr/types.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/__assert.h>
#include <string.h>
#include <zephyr/kernel.h>

#define LED0_NODE DT_ALIAS(led0)

struct led {
  struct gpio_dt_spec spec;
  uint8_t num;
};

static const struct led led0 = {
  .spec = GPIO_DT_SPEC_GET_OR(LED0_NODE, gpios, 0),
  .num = 0,
};

int cnt = 0;

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);


void blink(const struct led *led, uint32_t sleep_ms, uint32_t id)
{
	const struct gpio_dt_spec *spec = &led->spec;
	int ret;

	if (!device_is_ready(spec->port)) {
		printk("Error: %s device is not ready\n", spec->port->name);
		return;
	}

	ret = gpio_pin_configure_dt(spec, GPIO_OUTPUT);
	if (ret != 0) {
		printk("Error %d: failed to configure pin %d (LED '%d')\n",
			ret, spec->pin, led->num);
		return;
	}

		gpio_pin_set(spec->port, spec->pin, cnt % 2);

		//struct printk_data_t tx_data = { .led = id, .cnt = cnt };

		//size_t size = sizeof(struct printk_data_t);
		//char *mem_ptr = k_malloc(size);
		//__ASSERT_NO_MSG(mem_ptr != 0);

		//memcpy(mem_ptr, &tx_data, size);

		//k_fifo_put(&printk_fifo, mem_ptr);

		k_msleep(sleep_ms);
		cnt++;
	
}

// This is the actual work to be done
void blink_work_handler(struct k_work *work) {
  blink(&led0, 100, 0);
}

// This macro defines the work item
K_WORK_DEFINE(blink_work, blink_work_handler);

// This function is called on every timer expiry
void blink_submit(struct k_timer *timer_id) {
  k_work_submit(&blink_work);
}

// Initialize the timer
//k_timer_init(&blink_timer, blink_submit, NULL);
K_TIMER_DEFINE(blink_timer, blink_submit, NULL);

void main(void) {
  k_timer_start(&blink_timer, K_SECONDS(2), K_SECONDS(1));
}
