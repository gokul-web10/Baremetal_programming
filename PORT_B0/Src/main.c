volatile unsigned int *RCC_CR      = (volatile unsigned int*)0x40023800;
volatile unsigned int *RCC_CFGR    = (volatile unsigned int*)0x40023808;
volatile unsigned int *RCC_AHB1ENR = (volatile unsigned int*)0x40023830;

volatile unsigned int *GPIOB_MODER = (volatile unsigned int*)0x40020400;
volatile unsigned int *GPIOB_ODR   = (volatile unsigned int*)0x40020414;

void delay()
{
	 for (int i = 0; i < 4000000; i++) __asm("NOP");
}

int main(void)
{
        *RCC_CR &= ~(1<<16);
        *RCC_CR |=  (1<<16);

        *RCC_CFGR &= ~(1<<3);
        *RCC_CFGR |= (1<<3);

        *RCC_AHB1ENR |= (1<<2);

        *GPIOB_MODER &= ~(1<<0);
        *GPIOB_MODER |= (1<<0);


        while(1)
            {
                *GPIOB_ODR &= ~(1 << 0);
                delay();
                *GPIOB_ODR |= (1 << 0);
                delay();
            }
}
