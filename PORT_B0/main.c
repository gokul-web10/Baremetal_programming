volatile unsigned int *RCC_CR      = (volatile unsigned int *)0x40023800;
volatile unsigned int *RCC_CFGR    = (volatile unsigned int *)0x40023808;
volatile unsigned int *RCC_AHB1ENR = (volatile unsigned int *)0x40023830;

volatile unsigned int *GPIOC_MODER = (volatile unsigned int *)0x40020800;
volatile unsigned int *GPIOC_ODR   = (volatile unsigned int *)0x40020814;

void delay()
{
	 for (int i = 0; i < 4000000; i++) __asm("NOP");
}

int main(void)
{
    // Enable HSE (or HSI assumed)
    *RCC_CR &= ~(1 << 16);         // Disable HSE
    *RCC_CR |=  (1 << 16);         // Enable HSE
    while (!(*RCC_CR & (1 << 17))); // Wait till HSE is ready

    // Clock configuration - use HSE as system clock
    *RCC_CFGR &= ~(0x3);            // Clear SW bits
    *RCC_CFGR |= (1 << 0);          // Select HSE as system clock
    while (((*RCC_CFGR >> 2) & 0x3) != 1); // Wait until HSE is used

    // Enable GPIOC clock
    *RCC_AHB1ENR |= (1 << 2);

    // Set PC13 as output (MODER13 = 01)
    *GPIOC_MODER &= ~(3 << 26);     // Clear bits
    *GPIOC_MODER |=  (1 << 26);     // Set MODER13 to 01 (Output)

    while (1)
    {
        *GPIOC_ODR &= ~(1 << 13);  // LED ON (low on PC13)
        delay();
        *GPIOC_ODR |= (1 << 13);   // LED OFF (high on PC13)
        delay();
    }
}
