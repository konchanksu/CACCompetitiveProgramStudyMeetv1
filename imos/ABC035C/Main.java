import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    Integer N, Q;
    ArrayList<Integer> A = new ArrayList<>();
    Integer ans = 0;
    Integer l, r;
    void run()
    {
        this.input();
        this.output();
    }

    void input()
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        Q = sc.nextInt();
        sc.nextLine();

        this.resetArrayList();

        for(Integer i = 0; i < Q; i++)
        {
            l = sc.nextInt();
            r = sc.nextInt();
            sc.nextLine();
            A.set(l - 1, A.get(l - 1) + 1);
            A.set(r, A.get(r) - 1);
        }
    }

    void output()
    {
        for(Integer i = 0; i < N; i++)
        {
            ans += A.get(i);
            System.out.print(ans % 2);
        }
        System.out.println();
    }

    void resetArrayList()
    {
        for(Integer i = 0; i < N + 1; i++)
        {
            A.add(0);
        }
    }

    public static void main(String[] args)
    {
        Main app = new Main();
        app.run();
    }
}
