import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    Integer N;
    ArrayList<Long> A = new ArrayList<>();
    ArrayList<Long> S = new ArrayList<>();

    void run()
    {
        this.input();
        this.ruisekiwa();
        this.output();
    }

    void input()
    {
        Scanner sc = new Scanner(System.in);
        this.N = sc.nextInt();
        sc.nextLine();

        for(Integer i = 0; i < this.N; i++)
        {
            this.A.add(sc.nextLong());
        }

        sc.close();
    }

    void ruisekiwa()
    {
        this.S.add((long)0);
        for(Integer i = 0; i < this.N; i++)
        {
            this.S.add(this.S.get(this.S.size() - 1) + this.A.get(i));
        }
    }

    void output()
    {
        long max;
        for(Integer k = 1; k <= this.N; k++)
        {
            max = 0;
            for(Integer i = 0; i < this.N - k + 1; i++)
            {
                max = (max < (S.get(i + k) - S.get(i)) ? (S.get(i + k) - S.get(i)) : max);
            }
            System.out.println(max);
        }
    }

    public static void main(String[] args)
    {
        Main app = new Main();
        app.run();
    }
}
