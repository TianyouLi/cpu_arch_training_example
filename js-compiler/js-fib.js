var result = 0;

function fib(x) {
		if (x < 2) {
				return 1;
		} else {
				return fib(x - 1) + fib(x - 2);
		}
}

result = fib(45);
console.log(result);
