// bootcamp.cpp

int ChangeMaking(int cents) {
	const array<int, 6> kCoins = {100, 50, 25, 10, 5, 1};
	int num_coins = 0;
	for (int coin : coins) {
		num_coins += cents / coin;
		cents = cents % coin;
	}
	return num_coins;
}