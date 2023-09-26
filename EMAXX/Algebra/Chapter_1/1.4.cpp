#include <iostream>

using namespace std;

// Linear Diphantine Equations

/**
 * 
 *  The general form ax + by = c
 *  Where a,b,c are given integers and x,y are unknown integers
 * 
 *  From this, we consider several classical problems 
 *  on these equations
 *  
 *  	-> finding one solution
 * 	-> finding all solutions
 * 	-> finding the number of solutions and the solutions
 * 		themselves in a given interval
 * 	-> finding a solution with minimum value of x + y
 *  
 * 
 * 	a*Xg*[c/g] + b*Yg*[c/g] = c
 * 
 * 	Therfore one of the solutions
 *    of diophantine equation is:
 * 	
 * 	x0 = xg*[c/g]
 * 	y0 = yg*[c/g]
 * 
 * 
 * 
 * 
 * 
 *  Getting all solutions
 * 	a*x0 + b*y0 = c
 * 	
 * 	a*(x0+[b/g]) + b*(y-[a/g])
 * 		= a*x0 + b*y0 + a*[b/g] - b*[a/g] = c
 * 
 * 	All the numbers of the form
 * 		x = x0 + k*[b/g];
 * 		y = y0 - k*[a/g];
 * 	are solutions of the given diophantine equation.
*/

int gcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1;
	int d = gcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

// finding a solution
bool find_any_soluton(int a, int b, int c, int &x0, int &y0, int &g) {
	g = gcd(abs(a), abs(b), x0, y0);
	if (c % g) {
		return false;
	}

	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}

// int main() {
// 	int a, b, c, x0, y0, g;

// 	a = 100, b = 35;
// 	find_any_soluton(a,b,c,x0,y0,g);
// 	cout << x0 << " " << y0 << " " << g << " " << c << '\n';
// }

// Finding the number of solutions and the solutions
// in a  given interval

void shift_solution(int &x, int &y, int a, int b, int cnt) {
	x += cnt * b;
	y -= cnt * b;
}


int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
	int x, y, g;
	if (!find_any_soluton(a,b,c,x,y,g))
		return 0;

	a /= g;
	b /= g;

	int sign_a = a > 0 ? 1 : -1;
	int sign_b = b > 0 ? 1 : -1;

	shift_solution(x,y,a,b,(minx - x) / b);
	if (x < minx)
		shift_solution(x,y,a,b,sign_b);
	if (x > maxx)
		return 0;

	int lx1 = x;
	shift_solution(x,y,a,b,(maxx - x) / b);
	if (x > maxx)
		shift_solution(x,y,a,b,-sign_b);
	
	shift_solution(x,y,a,b,(maxx - x) / b);
	if (x > maxx)
		shift_solution(x,y,a,b,-sign_b);
	int rx1 = x;

	shift_solution(x,y,a,b, -(miny - y) / a);
	if (y < miny)
		shift_solution(x,y,a,b,-sign_a);
	if (y > maxy)
		return 0;
	int lx2 = x;

	shift_solution(x,y,a,b,-(maxy - y) / a);
	if (y > maxy)
		shift_solution(x,y,a,b,sign_a);
	int rx2 = x;

	if (lx2 > rx2)
		swap(lx2, rx2);
	int lx = max(lx1, lx2);
	int rx = max(rx1, rx2);

	if (lx > rx)
		return 0;
	return (rx - lx) / abs(b) + 1;
}

int main() {
	int a, b, c, minx, maxx, miny, maxy;
	// cin >> a >> b >> minx >> maxx >> miny >> maxy;
	a = 55, b = 80, maxx = 10, maxy = 10, minx = 10, miny = 10;
	cout << find_all_solutions(a,b,c,minx,maxx,miny,maxy) << '\n';
}