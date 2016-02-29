int number_times_appear(int number, int digit) {
	int count = 0;
	int	current = 0;
	while (number > 0) {
		current = number % 10;
		if (current == digit){
			count++;
		}
		number /= 10;
	}
	return count;
}