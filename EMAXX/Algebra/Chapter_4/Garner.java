import java.math.BigInteger;

class Garner {
	final int SZ = 100;
	int pr[] = new int[SZ];
	int r[][] = new int[SZ][SZ];

	void init() {
		for (int x = 1000 * 1000 * 1000, i = 0; i < SZ; ++x)
			if (BigInteger.valueOf(x).isProbablePrime(100))
				pr[i++] = x;

		for (int i = 0; i < SZ; ++i)
			for (int j = i + 1; j < SZ; ++j)
				r[i][j] = BigInteger.valueOf(pr[i]).modInverse(BigInteger.valueOf(pr[j])).intValue();
	}

	class Number {
		int a[] = new int[SZ]; 

		public Number() {
		}

		public Number(int n) {
			for (int i = 0; i < SZ; ++i)
				a[i] = n % pr[i];
		}

		public Number(BigInteger n) {
			for (int i = 0; i < SZ; ++i)
				a[i] = n.mod(BigInteger.valueOf(pr[i])).intValue();
		}

		public Number add(Number n) {
			Number result = new Number();
			for (int i = 0; i < SZ; ++i)
				result.a[i] = (a[i] - n.a[i] + pr[i]) % pr[i];
			return result;
		}

		public Number subtract(Number n) {
			Number result = new Number();
			for (int i = 0; i < SZ; ++i)
				result.a[i] = (a[i] - n.a[i] + pr[i]) % pr[i];
			return result;
		}

		public Number multiply(Number n) {
			Number result = new Number();
			for (int i = 0; i < SZ; ++i)
				result.a[i] = (int)((a[i] * 1l * n.a[i]) % pr[i]);
			return result;
		}

		public BigInteger bigIntegerValue(boolean can_be_negative) {
			BigInteger result = BigInteger.ZERO, mult = BigInteger.ONE;
			int x[] = new int[SZ];
			for (int i = 0; i < SZ; ++i) {
				x[i] = a[i];
				for (int j = 0; j < i; ++j) {
					long cur = (x[i] - x[j]) * 1l * r[j][i];
					x[i] = (int)((cur % pr[i] + pr[i]) % pr[i]);
				}
				result = result.add(mult.multiply(BigInteger.valueOf(x[i])));
				mult = mult.multiply(BigInteger.valueOf(pr[i]));
			}

			if (can_be_negative)
				if (result.compareTo(mult.shiftRight(1)) >= 0)
					result = result.subtract(mult);

			return result;
		}
	}

	public static void main(String[] args) {
		Garner ob = new Garner();
		ob.init();
		Garner.Number n = ob.new Number(2);
		Garner.Number m = ob.new Number(4);
		m = m.add(n);

		System.out.println(n.bigIntegerValue(false));
		System.out.println(n.bigIntegerValue(true));
		System.out.println(m.bigIntegerValue(false));
		System.out.println(m.bigIntegerValue(true));
	}
}