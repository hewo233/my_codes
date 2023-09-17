import java.util.Scanner;

public class Main
{
    private static int[] f;
    public static int start_fab(int x)
    {
        f =new int[x+1];
        f[0]=f[1]=1;
        return fab(x);
    }
    public static int fab(int x)
    {
        if(f[x] != 0) return f[x];
        int now = fab(x - 1)+ fab(x - 2);
        f[x] = now;
        return now;
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n;
        n = scanner.nextInt();
        System.out.println(start_fab(n));
    }
}