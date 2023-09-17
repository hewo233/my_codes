public class Main {

    private static long[] memo;

    public static long fibonacci(int n) {
        memo = new long[n + 1];
        return fibonacciHelper(n);
    }

    private static long fibonacciHelper(int n) {
        if (n <= 1) {
            return n;
        }

        if (memo[n] != 0) {
            return memo[n];
        }

        long fib = fibonacciHelper(n - 1) + fibonacciHelper(n - 2);
        memo[n] = fib;
        return fib;
    }

    public static void main(String[] args) {
        int n = 10;
        long result = fibonacci(n);
        System.out.println("Fibonacci(" + n + ") = " + result);
    }
}