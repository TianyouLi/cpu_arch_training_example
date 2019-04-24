"use asm";

var result = 0|0;

function fib(x) {
		x = x|0;
		if (x >>> 0 < 2) {
				return 1|0;
		} else {
				return (fib((x - 1)|0) + fib((x - 2)|0))|0;
		}
}

result = fib(45)|0;
console.log(result);
