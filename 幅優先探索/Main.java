/**
 * 競技プログラミング勉強会用のコード
 * ABC007 C 幅優先探索
 * Java 解答例
 * くそコード
 */

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class Main
{
    Integer sx, sy, gx, gy;  // スタートの座標, ゴールの座標
    Integer R, C;  // 迷路のサイズ
    ArrayList<String> mazeMap = new ArrayList<>();  // 迷路
    ArrayList<ArrayList<Boolean>> isAlreadyArrived = new ArrayList<>();  // すでにたどり着いたか

    void run()
    {
        this.input();
        this.bfs();
    }

    /* 入力 */
    void input()
    {
        Scanner sc = new Scanner(System.in);
        this.R = Integer.parseInt(sc.next());
        this.C = Integer.parseInt(sc.next());
        sc.nextLine();

        this.sy = Integer.parseInt(sc.next());
        this.sx = Integer.parseInt(sc.next());
        this.sy--; this.sx--;
        sc.nextLine();

        this.gy = Integer.parseInt(sc.next());
        this.gx = Integer.parseInt(sc.next());
        this.gy--; this.gx--;
        sc.nextLine();

        for(Integer i = 0; i < this.R; i++)
        {
            this.mazeMap.add(sc.nextLine());
        }

        for(Integer i = 0; i < this.R; i++)
        {
            this.isAlreadyArrived.add(new ArrayList<>());
            for(Integer j = 0; j < this.C; j++)
            {
                if(this.R.equals(i) && this.C.equals(j)) this.isAlreadyArrived.get(i).add(true);
                this.isAlreadyArrived.get(i).add(false);
            }
        }
    }

    /* 幅優先探索 */
    void bfs()
    {
        Queue<ArrayList<Integer>> queue = new ArrayDeque<>();  // キュー
        ArrayList<Integer> pop;  // キューから取り出される座標と移動距離
        queue.add(new ArrayList<>(Arrays.asList(this.sy, this.sx, 0)));

        while(true)
        {
            pop = queue.poll();

            // もしゴールならば
            if(pop.get(0).equals(this.gy) && pop.get(1).equals(this.gx))
            {
                System.out.println(pop.get(2));
                break;
            }

            // 移動できる4方向の確認
            for(Integer i = -1; i <= 1; i++)
            {
                for(Integer j = -1; j <= 1; j++)
                {
                    // 2重ループで発生する余計な移動をしない (3項演算子で実装してゴメン)
                    if(((i > -i ? i : -i) + (j > -j ? j : -j)) != 1) continue;

                    Integer nextY = pop.get(0) + i, nextX = pop.get(1) + j;
                    // 範囲外に出ない
                    if(nextX < 0 && nextY < 0 && nextY >= this.R && nextX >= this.C) continue;

                    // まだ行ったことのない道であれば
                    if(!this.isAlreadyArrived.get(nextY).get(nextX) && this.mazeMap.get(nextY).charAt(nextX) == '.')
                    {
                        // キューに追加
                        queue.add(new ArrayList<>(Arrays.asList(nextY, nextX, pop.get(2) + 1)));
                        // 到達した
                        this.isAlreadyArrived.get(nextY).set(nextX, true);
                    }
                }
            }
        }
    }

    public static void main(String[] args)
    {
        Main app = new Main();
        app.run();
    }
}
