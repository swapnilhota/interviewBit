int power(long long a, long long b, int& mod) {
 	if (b == 0)
		return 1;

 	long long res = power(a, b / 2, mod);
	res = (res * res) % mod;
	
	if (b % 2)
		res = (res * a) % mod;

	return res;
}

int Solution::pow(int x, int n, int d) {
    if (x == 0)
        return 0;
        
    int res = power(x, n, d);
    if (res < 0)
        return d + (res % d);
        
    return res;
}
