import java.util.Scanner;
import java.util.ArrayList;

public class Main
{
    Integer N;
    ArrayList<Long> A = new ArrayList<>();
    ArrayList<Long> S = new ArrayList<>();
    Long mod = (long)1000000007;
    void run()
    {
        this.input();
        this.ruisekiwa();
        this.output();
    }

    void input()
    {
        Scanner in = new Scanner(System.in);
        this.N = in.nextInt();
        in.nextLine();
        for(Integer i = 0; i < this.N; i++)
        {
            this.A.add(in.nextLong());
        }

        in.close();
    }

    void ruisekiwa()
    {
        this.S.add((long)0);
        for(Integer i = 0; i < this.N; i++)
        {
            this.S.add(this.S.get(i) + this.A.get(i));
        }
    }

    void output()
    {
        Long ans = (long)0;
        for(Integer i = 0; i < N - 1; i++)
        {
            ans += A.get(i) * ((S.get(N) - S.get(i + 1)) % mod);
            ans %= mod;
        }
        System.out.println(ans);
    }


    public static void main(String[] args)
    {
        Main app = new Main();
        app.run();
    }
}
