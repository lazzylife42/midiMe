/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midiMe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:21:49 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/09 23:25:41 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pico/stdlib.h"

int is_prime(int n) {
	if (n <= 1) return 0;
	if (n <= 3) return 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;

	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;
	}
	return 1;
}

int main()
{
  stdio_init_all();

  const uint LED_PIN = 25;
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

	stdio_init_all();
	gpio_put(LED_PIN, 1);
	clock_t start_time = clock();
	int limit = 1000000;

	printf("Nombres premiers jusqu'a %d :\n", limit);

	for (int i = 2; i <= limit; i++) {
		if (is_prime(i)) {
			printf("%d ", i);
		}
	}

	printf("\n");

	clock_t end_time = clock();
	double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Temps d'execution : %f secondes\n", cpu_time_used);
	gpio_put(LED_PIN, 0);
/*  
  while (true)
  {
	gpio_put(LED_PIN, 1);
	printf("ON\n");
	sleep_ms(1000);
	gpio_put(LED_PIN, 0);
	printf("OFF\n");
	sleep_ms(1000);
  }
*/  
  return 0;
}


/*
#include "pico/stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_prime(int n) {
	if (n <= 1) return 0;
	if (n <= 3) return 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;

	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;
	}
	return 1;
}

int main()
{
	stdio_init_all();
	clock_t start_time = clock();
	int limit = 1000000;

	printf("Nombres premiers jusqu'a %d :\n", limit);

	for (int i = 2; i <= limit; i++) {
		if (is_prime(i)) {
			printf("%d ", i);
		}
	}

	printf("\n");

	clock_t end_time = clock();
	double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Temps d'execution : %f secondes\n", cpu_time_used);

	return 0;
}
*/
